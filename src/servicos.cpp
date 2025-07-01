#include "servicos.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// implementacao do modulo do servico de conta

bool MSC::create(Account &account) {
    string cpf = account.getCPF().getCPF();

    // procura o cpf no map
    if(accounts.find(cpf) == accounts.end()) { // cpf nao existe no map, podemos inseri-lo
        accounts[cpf] = account;
        cout << "SERVIÇO: Conta para o CPF " << cpf << " criada no banco de dados." << endl;
        return true;
    } else { // o cpf ja existe no map, nao pode criar nova conta
        cout << "SERVIÇO: Erro ao criar, CPF " << cpf << " já possui uma conta." << endl;
        return false;
    }
}

bool MSC::read(Account* account) {
    string cpf = account->getCPF().getCPF();
    auto iterator = accounts.find(cpf);

    // procura a conta a ser lida
    if (iterator != accounts.end()) {
        *account = iterator->second; // retorna o objeto conta armazenado no sistema para o dado cpf
        cout << "SERVIÇO: Conta do CPF " << cpf << " lida com sucesso." << endl;
        return true;
    } else { // conta do cpf nao encontrada
        cout << "SERVIÇO: Erro ao ler, conta do CPF " << cpf << " não encontrada." << endl;
        return false;
    }
}

bool MSC::edit(Account& account) {
    string cpf = account.getCPF().getCPF();

    // procura a conta associada ao cpf
    if (accounts.find(cpf) != accounts.end()) {
        accounts[cpf] = account;
        cout << "SERVIÇO: Conta do CPF " << cpf << " editada com sucesso." << endl;
        return true;
    } else {
        cout << "SERVIÇO: Erro ao editar, CPF " << cpf << " não possui conta associada." << endl;
        return false;
    }
}

bool MSC::exclude(CPF& cpf) {
    string cpfStr = cpf.getCPF();

    // erase() retorna o numero de elementos removidos
    if (accounts.erase(cpfStr) > 0) {
        cout << "SERVIÇO: Conta do CPF " << cpfStr << " excluída com sucesso." << endl;
        return true;
    }
    cout << "SERVIÇO: Erro ao excluir, CPF " << cpfStr << " não encontrado." << endl;
    return false;
}

// implementacao do modulo do servico de autenticacao

bool MSA::autenticate(CPF& cpf, Password& senha) {
    Account account;
    account.setCPF(cpf.getCPF());

    // usa o serviço de conta para ler os dados da conta
    if (accountService->read(&account)) {
        // se a conta foi encontrada, compara a senha
        if (account.getPassword().getPassword() == senha.getPassword()) {
            cout << "SERVIÇO: Autenticação bem-sucedida para o CPF " << cpf.getCPF() << endl;
            return true;
        }
    }
    cout << "SERVIÇO: Falha na autenticação para o CPF " << cpf.getCPF() << ". Tente novamente."<< endl;
    return false;
}

// implementacao do modulo de servico de investimento

// metodos para carteira

bool MSI::create(Wallet& wallet) {
    string codeStr = wallet.getCode().getCode();
    if (wallets.find(codeStr) == wallets.end()) {
        wallets[codeStr] = wallet;
        cout << "SERVIÇO: Carteira de código " << codeStr << " criada." << endl;
        return true;
    }
    cout << "SERVIÇO: Erro, carteira com código " << codeStr << " já existe." << endl;
    return false;
}

bool MSI::read(Wallet* wallet) {
    string codeStr = wallet->getCode().getCode();
    auto iterator = wallets.find(codeStr);
    if (iterator != wallets.end()) {
        *wallet = iterator->second;
        return true;
    }
    return false;
}

bool MSI::edit(Wallet& wallet) {
    string codeStr = wallet.getCode().getCode();
    if (wallets.find(codeStr) != wallets.end()) {
        wallets[codeStr] = wallet;
        return true;
    }
    return false;
}

bool MSI::excludeWallet(Code& code) { // adicionar verificacao para ver se a carteira tem order associada antes de deletar
    if (wallets.erase(code.getCode()) > 0) {
        return true;
    }
    return false;
}

bool MSI::listWallets() {
    cout << "\n--- LISTA DE CARTEIRAS NO SERVIÇO ---" << endl;

    // declara um iterador para o mapa de carteiras
    map<string, Wallet>::iterator it;

    // se nao houver carteiras, informa o usuario e retorna
    if (wallets.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
        cout << "----------------------------------\n" << endl;
        return true;
    }

    // percorre o mapa
    for (it = wallets.begin(); it != wallets.end(); ++it) {
        Wallet carteiraAtual = it->second;

        cout << "Código: " << carteiraAtual.getCode().getCode()
                  << ", Nome: " << carteiraAtual.getName().getName()
                  << ", Perfil: " << carteiraAtual.getProfile().getProfile() << endl;
    }

    cout << "-------------------------------------\n" << endl;
    return true;
}


// metodos para ordem

bool MSI::create(Order& order) {
    string orderCodeStr = order.getCode().getCode();
    if (orders.find(orderCodeStr) != orders.end()) {
        cout << "SERVIÇO: Erro, ordem com código " << orderCodeStr << " já existe." << endl;
        return false;
    }

    string dealCode = order.getDeal().getDeal();
    tuple<int, int, int> dateTuple = order.getDate().getDate();
    char formattedDate[9];
    sprintf(formattedDate, "%04d%02d%02d", get<2>(dateTuple), get<1>(dateTuple), get<0>(dateTuple));
    string dateStr(formattedDate);

    string line;
    double price = -1.0;
    ifstream Archive("DADOS_HISTORICOS.TXT");
    if (!Archive.is_open()) {
        cerr << "SERVIÇO: Erro fatal, não foi possível abrir DADOS_HISTORICOS.TXT" << endl;
        return false;
    }

    int line_count = 0;
    while (getline(Archive, line)) {
        line_count++;

        string dateFromFile = line.substr(2, 8);
        string codeFromFile = line.substr(12, 12);

        if (dateFromFile == dateStr && codeFromFile.find(dealCode) != string::npos) {
            price = stod(line.substr(113, 13)) / 100.0;
            break;
        }
    }

    Archive.close();

    if (price < 0) {
        cout << "SERVIÇO: Erro, código de negociação não encontrado para a data especificada." << endl;
        return false;
    }

    Order finalOrder = order;
    Money calculatedPrice;
    double finalPrice = price * finalOrder.getQuantity().getQuantity();
    calculatedPrice.setMoney(finalPrice);
    finalOrder.setMoney(calculatedPrice);

    orders[orderCodeStr] = finalOrder;
    cout << "SERVIÇO: Ordem " << orderCodeStr << " criada com preço calculado de " << finalPrice << endl;
    return true;
}


bool MSI::read(Order* order) {
    string codeStr = order->getCode().getCode();
    auto it = orders.find(codeStr);
    if (it != orders.end()) {
        *order = it->second;
        return true;
    }
    return false;
}

bool MSI::excludeOrder(Code& code) {
    if (orders.erase(code.getCode()) > 0) {
        return true;
    }
    return false;
}

bool MSI::listOrders() {
    cout << "\n--- LISTA DE ORDENS NO SERVIÇO ---" << endl;

    // se nao houver ordens, informa o usuario e retorna
    if (orders.empty()) {
        cout << "Nenhuma ordem cadastrada." << endl;
        cout << "----------------------------------\n" << endl;
        return true;
    }

    // declara um iterador para o mapa de ordens.
    map<string, Order>::iterator it;

    // percorre o mapa
    for (it = orders.begin(); it != orders.end(); ++it) {
        Order currentOrder = it->second;

        // recupera a data para formatar
        tuple<int, int, int> dataTuple = currentOrder.getDate().getDate();
        char date[11];
        sprintf(date, "%02d/%02d/%04d", get<0>(dataTuple), get<1>(dataTuple), get<2>(dataTuple));

        // imprime os dados da ordem
        cout << "Código da Ordem: " << currentOrder.getCode().getCode()
                  << " | Código de Negociação: " << currentOrder.getDeal().getDeal()
                  << " | Data: " << date
                  << " | Preço: " << currentOrder.getMoney().getMoney()
                  << " | Quantidade: " << currentOrder.getQuantity().getQuantity() << endl;
    }

    cout << "----------------------------------\n" << endl;
    return true;
}
