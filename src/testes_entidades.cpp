#include <stdexcept>
#include <string>
#include "testes_entidades.hpp"

const string TUOrder::VALID_QUANTITY = "100";
const string TUOrder::VALID_DEAL = "123456";
const string TUOrder::VALID_CODE = "12345";
const int TUOrder::VALID_MONEY = 100.00;
const int TUOrder::VALID_DAY = 10;
const int TUOrder::VALID_MONTH = 1;
const int TUOrder::VALID_YEAR = 2006;

void TUOrder::setUp() {
    order = new Order();
    date = new Date();
    date->setDate(VALID_DAY, VALID_MONTH, VALID_YEAR);
    money = new Money();
    money->setMoney(VALID_MONEY);
    quantity = new Quantity();
    quantity->setQuantity(VALID_QUANTITY);
    code = new Code();
    code->setCode(VALID_CODE);
    deal = new Deal();
    deal->setDeal(VALID_DEAL);
    state = SUCCESS;
}

void TUOrder::tearDown() {
    delete date;
    delete money;
    delete quantity;
    delete code;
    delete deal;
    delete order;
}

void TUOrder::testCenario(){
    int quantity_value = 100;
    order->setCode(*code);
    if(order->getCode().getCode() != VALID_CODE){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de código" << endl;
    }
    order->setDeal(*deal);
    if(order->getDeal().getDeal() != VALID_DEAL){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de negócio" << endl;
    }
    order->setDate(*date);
    if(order->getDate().getDate() != tuple(VALID_DAY, VALID_MONTH, VALID_YEAR)){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de data" << endl;
    }
    order->setMoney(*money);
    if(order->getMoney().getMoney() != VALID_MONEY){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de preço" << endl;
    }
    order->setQuantity(*quantity);
    if(order->getQuantity().getQuantity() != quantity_value){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de quantidade" << endl;
    }
}

int TUOrder::run() {
    setUp();
    testCenario();
    tearDown();
    return state;
}

const string TUWallet::VALID_CODE = "12345";
const string TUWallet::VALID_NAME = "Lucca Santos Aguilar";
const string TUWallet::VALID_PROFILE = "Conservador";

void TUWallet::setUp() {
    wallet = new Wallet();
    code = new Code();
    code->setCode(VALID_CODE);
    name = new Name();
    name->setName(VALID_NAME);
    profile = new Profile();
    profile->setProfile(VALID_PROFILE);
    state = SUCCESS;
}

void TUWallet::tearDown() {
    delete code;
    delete profile;
    delete name;
    delete wallet;
}

void TUWallet::testCenario(){
    wallet->setCode(code->getCode());
    if(wallet->getCode().getCode() != VALID_CODE){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de código." << endl;
    }
    wallet->setName(name->getName());
    if(wallet->getName().getName() != VALID_NAME){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir nome." << endl;
    }
    wallet->setProfile(profile->getProfile());
    if(wallet->getProfile().getProfile() != VALID_PROFILE){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir tipo de perfil." << endl;
    }
}

int TUWallet::run() {
    setUp();
    testCenario();
    tearDown();
    return state;
}

const string TUAccount::VALID_CPF = "03334959180";
const string TUAccount::VALID_NAME = "Lucca Santos Aguilar";
const string TUAccount::VALID_PASSWORD = "Ab12#&";

void TUAccount::setUp() {
    account = new Account();
    cpf = new CPF();
    cpf->setCPF(VALID_CPF);
    name = new Name();
    name->setName(VALID_NAME);
    password = new Password();
    password->setPassword(VALID_PASSWORD);
    state = SUCCESS;
}

void TUAccount::tearDown() {
    delete cpf;
    delete name;
    delete password;
    delete account;
}

void TUAccount::testCenario(){
    account->setCPF(cpf->getCPF());
    if(account->getCPF().getCPF() != VALID_CPF){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir valor de CPF." << endl;
    }
    account->setName(name->getName());
    if(account->getName().getName() != VALID_NAME){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir nome." << endl;
    }
    account->setPassword(password->getPassword());
    if(account->getPassword().getPassword() != VALID_PASSWORD){
        state = FAILURE;
        cout << "Erro: Não foi possível atribuir senha." << endl;
    }
}

int TUAccount::run() {
    setUp();
    testCenario();
    tearDown();
    return state;
}