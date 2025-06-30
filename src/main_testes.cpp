#include "dominios.hpp"
#include "entidades.hpp"
#include "testes_dominios.hpp"
#include "testes_entidades.hpp"

using namespace std;

int main(){

    cout << "TESTES DE CLASSES DE DOMINIO" << endl;

    cout << "Teste Unitario: Nome" << endl;
    TUName testeName;
    switch(testeName.run()){
        case TUName::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUName::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: CPF" << endl;
    TUCPF testeCPF;
    switch(testeCPF.run()){
        case TUCPF::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUCPF::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Negociacao" << endl;
    TUDeal testeDeal;
    switch(testeDeal.run()){
        case TUDeal::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUDeal::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Dinheiro" << endl;
    TUMoney testeMoney;
    switch(testeMoney.run()){
        case TUMoney::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUMoney::FAILURE: cout << "FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Perfil" << endl;
    TUProfile testeProfile;
    switch(testeProfile.run()){
        case TUProfile::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUProfile::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Senha" << endl;
    TUPassword testePassword;
    switch(testePassword.run()){
        case TUPassword::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUPassword::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Codigo" << endl;
    TUCode testeCodigo;
    switch(testeCodigo.run()){
        case TUCode::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUCode::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Quantidade" << endl;
    TUQuantity testeQuantidade;
    switch(testeQuantidade.run()){
        case TUQuantity::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUQuantity::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Data" << endl;
    TUDate testeData;
    switch(testeData.run()){
        case TUDate::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUDate::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "TESTES DE CLASSES DE ENTIDADE" << endl;

    cout << "Teste Unitario: Ordem" << endl;
    TUOrder testeOrdem;
    switch(testeOrdem.run()){
        case TUOrder::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUOrder::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Carteira" << endl;
    TUWallet testeCarteira;
    switch(testeCarteira.run()){
        case TUWallet::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUWallet::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    cout << "Teste Unitario: Conta" << endl;
    TUAccount testeConta;
    switch(testeConta.run()){
        case TUAccount::SUCCESS: cout << "Resultado do teste unitario: SUCESSO\n" << endl;
        break;
        case TUAccount::FAILURE: cout << "Resultado do teste unitario: FALHA\n" << endl;
        break;
    }

    return 0;
}