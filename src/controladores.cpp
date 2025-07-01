#include "controladores.hpp"
#include <iostream>
#include <string>

// implementacao do controlador de menu

void MAMenu::execute() {
    CPF loggedInUserCpf;
    bool isAuthenticated = false;
    int choice;

    while (true) {
        if (!isAuthenticated) {
            // menu deslogado
            cout << "\n========= Bem-vindo ao Sistema de Investimentos =========" << endl;
            cout << "1. Criar nova conta" << endl;
            cout << "2. Autenticar" << endl;
            cout << "3. Sair" << endl;
            cout << "========================================================" << endl;
            cout << "Escolha uma opcao: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    ctrlAccount->create();
                    break;
                case 2:
                    isAuthenticated = ctrlAuth->autenticate(&loggedInUserCpf);
                    break;
                case 3:
                    cout << "Encerrando o sistema..." << endl;
                    return; 
                default:
                    cout << "Opcao invalida. Tente novamente." << endl;
                    break;
            }
        } else {
            // menu logado
            cout << "\n========= Menu Principal (Logado) =========" << endl;
            cout << "Usuario: " << loggedInUserCpf.getCPF() << endl;
            cout << "1. Gerenciar minha conta" << endl;
            cout << "2. Acessar investimentos" << endl;
            cout << "3. Deslogar" << endl;
            cout << "==========================================" << endl;
            cout << "Escolha uma opcao: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    ctrlAccount->execute(loggedInUserCpf);
                    break;
                case 2:
                    ctrlInvestment->execute();
                    break;
                case 3:
                    isAuthenticated = false;
                    cout << "Voce foi desconectado." << endl;
                    break;
                default:
                    cout << "Opcao invalida. Tente novamente." << endl;
                    break;
            }
        }
    }
}

// implementacao do controlador de autenticacao

bool MAA::autenticate(CPF* cpf) {
    string cpfStr, passwordStr;

    cout << "--- Autenticacao de Usuario ---" << endl;
    cout << "Digite seu CPF: ";
    cin >> cpfStr;
    cout << "Digite sua senha: ";
    cin >> passwordStr;

    try {
        Password password;
        password.setPassword(passwordStr);
        cpf->setCPF(cpfStr);

        // chama o serviço de autenticacao
        if (serviceAuth->autenticate(*cpf, password)) {
            cout << "CONTROLADOR: Autenticacao bem-sucedida." << endl;
            return true;
        }
    } catch (const invalid_argument& e) {
        // captura excecoes das classes de dominio
        cout << "CONTROLADOR: Erro de formato nos dados -> " << e.what() << endl;
    }

    cout << "CONTROLADOR: CPF ou senha invalidos." << endl;
    return false;
}

// implementacao do controlador de conta

void MAC::create() {
    string nameStr, cpfStr, passwordStr;

    cout << "\n--- Criacao de Nova Conta ---" << endl;
    cout << "Digite o nome: ";
    cin.ignore(); // limpa buffer
    getline(cin, nameStr);
    cout << "Digite o CPF (apenas numeros): ";
    cin >> cpfStr;
    cout << "Digite a senha (6 caracteres, com maiuscula, minuscula, numero e especial #,$,%,&): ";
    cin >> passwordStr;

    try {
        Account newAccount;
        Name name;
        CPF cpf;
        Password password;

        name.setName(nameStr);
        cpf.setCPF(cpfStr);
        password.setPassword(passwordStr);

        newAccount.setName(name.getName());
        newAccount.setCPF(cpf.getCPF());
        newAccount.setPassword(password.getPassword());

        if (accountService->create(newAccount)) {
            cout << "CONTROLADOR: Conta criada com sucesso!" << endl;
        } else {
            cout << "CONTROLADOR: Nao foi possivel criar a conta. CPF ja pode existir." << endl;
        }

    } catch (const invalid_argument& e) {
        cout << "CONTROLADOR: Erro ao criar conta. Dado invalido: " << e.what() << endl;
    }
}

void MAC::execute(CPF& cpf) {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n--- Menu de Gerenciamento da Conta ---" << endl;
        cout << "CPF Logado: " << cpf.getCPF() << endl;
        cout << "1. Visualizar dados da conta" << endl;
        cout << "2. Editar nome ou senha" << endl;
        cout << "3. Excluir minha conta" << endl;
        cout << "4. Voltar ao menu principal" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        switch (choice) {
            case 1: { // visualizar dados
                Account account;
                account.setCPF(cpf.getCPF());
                if (accountService->read(&account)) {
                    cout << "\n--- Dados da Conta ---" << endl;
                    cout << "Nome: " << account.getName().getName() << endl;
                    cout << "CPF: " << account.getCPF().getCPF() << endl;
                } else {
                    cout << "ERRO: Nao foi possivel encontrar os dados da conta." << endl;
                }
                break;
            }
            case 2: { // editar dados
                Account accountToEdit;
                accountToEdit.setCPF(cpf.getCPF());
                
                // leitura dos dados atuais
                if (!accountService->read(&accountToEdit)) {
                    cout << "ERRO: Conta nao encontrada para edicao." << endl;
                    break;
                }

                string newNameStr, newPasswordStr;
                cout << "\n--- Edicao de Conta ---" << endl;
                cout << "Digite o novo nome (deixe em branco para nao alterar): ";
                cin.ignore();
                getline(cin, newNameStr);
                cout << "Digite a nova senha (deixe em branco para nao alterar): ";
                getline(cin, newPasswordStr);

                try {
                    if (!newNameStr.empty()) {
                        Name newName;
                        newName.setName(newNameStr);
                        accountToEdit.setName(newName.getName());
                    }
                    if (!newPasswordStr.empty()) {
                        Password newPassword;
                        newPassword.setPassword(newPasswordStr);
                        accountToEdit.setPassword(newPassword.getPassword());
                    }

                    if (accountService->edit(accountToEdit)) {
                        cout << "CONTROLADOR: Conta atualizada com sucesso!" << endl;
                    } else {
                        cout << "CONTROLADOR: Falha ao atualizar a conta." << endl;
                    }

                } catch (const invalid_argument& e) {
                    cout << "CONTROLADOR: Erro. Dado invalido: " << e.what() << endl;
                }
                break;
            }
            case 3: { // excluir conta
                char confirmation;
                cout << "\nATENCAO: Esta acao e irreversivel." << endl;
                cout << "Deseja realmente excluir sua conta? (S/N): ";
                cin >> confirmation;

                if (confirmation == 'S' || confirmation == 's') {
                    if (accountService->exclude(cpf)) {
                        cout << "CONTROLADOR: Conta excluida com sucesso." << endl;
                        running = false; // sai do menu da conta
                    } else {
                        cout << "CONTROLADOR: Nao foi possivel excluir a conta." << endl;
                    }
                } else {
                    cout << "CONTROLADOR: Operacao de exclusao cancelada." << endl;
                }
                break;
            }
            case 4: { // voltar
                running = false;
                break;
            }
            default: {
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
            }
        }
    }
}

// implementacao do controlador de investimentos

void MAI::execute() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\n========== Menu de Investimentos ==========" << endl;
        cout << "1. Criar nova carteira de investimentos" << endl;
        cout << "2. Criar nova ordem" << endl;
        cout << "3. Listar minhas carteiras" << endl;
        cout << "4. Listar todas as ordens" << endl;
        cout << "5. Excluir carteira" << endl;
        cout << "6. Excluir ordem" << endl;
        cout << "7. Voltar ao menu principal" << endl;
        cout << "=========================================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> choice;

        switch (choice) {
            case 1: { // criar carteira
                string codeStr, nameStr, profileStr;
                cout << "\n--- Nova Carteira ---" << endl;
                cout << "Digite o codigo da carteira (5 digitos): ";
                cin >> codeStr;
                cout << "Digite o nome da carteira: ";
                cin.ignore();
                getline(cin, nameStr);
                cout << "Digite o perfil (Conservador, Moderado, Agressivo): ";
                cin >> profileStr;

                try {
                    Wallet newWallet;
                    Code code;
                    Name name;
                    Profile profile;

                    code.setCode(codeStr);
                    name.setName(nameStr);
                    profile.setProfile(profileStr);

                    newWallet.setCode(code.getCode());
                    newWallet.setName(name.getName());
                    newWallet.setProfile(profile.getProfile());

                    if (investmentService->create(newWallet)) {
                        cout << "CONTROLADOR: Carteira criada com sucesso!" << endl;
                    } else {
                        cout << "CONTROLADOR: Falha ao criar carteira. Codigo ja existe." << endl;
                    }
                } catch (const invalid_argument& e) {
                    cout << "CONTROLADOR: Erro. Dado invalido: " << e.what() << endl;
                }
                break;
            }
            case 2: { // criar ordem
                string orderCodeStr, dealCodeStr, dateStr, quantityStr, walletCodeStr;
                cout << "\n--- Nova Ordem ---" << endl;
                cout << "Digite o codigo da ordem (5 digitos): ";
                cin >> orderCodeStr;
                cout << "Digite o codigo de negociacao do papel (ex: IVVB11): ";
                cin >> dealCodeStr;
                cout << "Digite a data (formato DDMMAAAA): ";
                cin >> dateStr;
                cout << "Digite a quantidade: ";
                cin >> quantityStr;
                cout << "Digite o codigo da carteira a qual esta ordem pertence: ";
                cin >> walletCodeStr;


                try {
                    Order newOrder;
                    Code orderCode, walletCode;
                    Deal dealCode;
                    Date date;
                    Quantity quantity;

                    orderCode.setCode(orderCodeStr);
                    walletCode.setCode(walletCodeStr);
                    dealCode.setDeal(dealCodeStr);
                    quantity.setQuantity(quantityStr);

                    // validacao e conversao dos dados
                    int day = std::stoi(dateStr.substr(0, 2));
                    int month = std::stoi(dateStr.substr(2, 2));
                    int year = std::stoi(dateStr.substr(4, 4));
                    date.setDate(day, month, year);

                    newOrder.setCode(orderCode);
                    newOrder.setDeal(dealCode);
                    newOrder.setDate(date);
                    newOrder.setQuantity(quantity);
                    // o preco e calculado na camada de servico

                    if (investmentService->create(newOrder)) {
                        cout << "CONTROLADOR: Ordem criada e preco calculado com sucesso!" << endl;
                    } else {
                        cout << "CONTROLADOR: Falha ao criar ordem. Verifique os dados." << endl;
                    }

                } catch (const invalid_argument& e) {
                    cout << "CONTROLADOR: Erro. Dado invalido: " << e.what() << endl;
                }
                break;
            }
            case 3: { // listar carteiras
                investmentService->listWallets();
                break;
            }
            case 4: { // listar ordens
                investmentService->listOrders();
                break;
            }
            case 5: { // excluir carteira
                string codeStr;
                cout << "Digite o codigo da carteira a ser excluida: ";
                cin >> codeStr;
                try {
                    Code code;
                    code.setCode(codeStr);
                    if(investmentService->excludeWallet(code)) {
                        cout << "CONTROLADOR: Carteira excluida com sucesso." << endl;
                    } else {
                        cout << "CONTROLADOR: Falha ao excluir. Carteira nao encontrada ou possui ordens." << endl;
                    }
                } catch(const invalid_argument& e) {
                     cout << "CONTROLADOR: Erro. Codigo invalido: " << e.what() << endl;
                }
                break;
            }
            case 6: { // excluir ordem
                string codeStr;
                cout << "Digite o codigo da ordem a ser excluida: ";
                cin >> codeStr;
                try {
                    Code code;
                    code.setCode(codeStr);
                    if(investmentService->excludeOrder(code)) {
                        cout << "CONTROLADOR: Ordem excluida com sucesso." << endl;
                    } else {
                        cout << "CONTROLADOR: Falha ao excluir. Ordem nao encontrada." << endl;
                    }
                } catch(const invalid_argument& e) {
                     cout << "CONTROLADOR: Erro. Codigo invalido: " << e.what() << endl;
                }
                break;
            }
            case 7: { // voltar
                running = false;
                break;
            }
            default: {
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
            }
        }
    }
}
