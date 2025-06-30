#include "testes_dominios.hpp"

const string TUProfile::VALID_PROFILE_1 = "Conservador";
const string TUProfile::VALID_PROFILE_2 = "Moderado";
const string TUProfile::VALID_PROFILE_3 = "Agressivo";
const string TUProfile::INVALID_PROFILE = "Colchao";

void TUProfile::setUp() {
    profile = new Profile();
    state = SUCCESS;
}

void TUProfile::tearDown() {
    delete profile;
}

void TUProfile::validProfile() {
    try {
        cout << "Valor testado: " << VALID_PROFILE_1 << endl;
        profile->setProfile(VALID_PROFILE_1);
        if (profile->getProfile() != VALID_PROFILE_1) {
            state = FAILURE;
        }
        cout << "Perfil registrado com sucesso!" << endl;

        cout << "Valor testado: " << VALID_PROFILE_2 << endl;
        profile->setProfile(VALID_PROFILE_2);
        if (profile->getProfile() != VALID_PROFILE_2) {
            state = FAILURE;
        }
        cout << "Perfil registrado com sucesso!" << endl;

        cout << "Valor testado: " << VALID_PROFILE_3 << endl;
        profile->setProfile(VALID_PROFILE_3);
        if (profile->getProfile() != VALID_PROFILE_3) {
            state = FAILURE;
        }
        cout << "Perfil registrado com sucesso!" << endl;
    }
    catch (invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
}

void TUProfile::invalidProfile() {
    try {
        cout << "Valor testado: " << INVALID_PROFILE << endl;
        profile -> setProfile(INVALID_PROFILE);
        state = FAILURE;
   }
   catch (invalid_argument &e) {
        if (profile -> getProfile() == ""){
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
}

int TUProfile::run() {
    setUp();
    validProfile();
    invalidProfile();
    tearDown();
    return state;
}

const string TUName::VALID_NAME = "Arthur Soares";
const string TUName::INVALID_NAME_1 = "Arthur  Soares";
const string TUName::INVALID_NAME_2 = "Arthur Soares12312311251341";
const string TUName::INVALID_NAME_3 = "Arthur@Soares";

void TUName::setUp(){
    name = new Name();
    state = SUCCESS;
}

void TUName::tearDown(){
    delete name;
}

void TUName::validName(){
    try{
        cout << "Valor testado: " << VALID_NAME << endl;
        name->setName(VALID_NAME);
        if(name->getName() != VALID_NAME)
            state = FAILURE;
    }
    catch (invalid_argument &e){
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "Nome registrado com sucesso!" << endl;
}

void TUName::invalidName(){
    try{
        cout << "Valor testado: " << INVALID_NAME_1 << endl;
        name->setName(INVALID_NAME_1);
        state = FAILURE;
    }
    catch (invalid_argument &e){
        if(name->getName() == INVALID_NAME_1)
            state = FAILURE;
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_NAME_2 << endl;
        name->setName(INVALID_NAME_2);
        state = FAILURE;
    }
    catch (invalid_argument &e){
        if(name->getName() == INVALID_NAME_2)
            state = FAILURE;
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_NAME_3 << endl;
        name->setName(INVALID_NAME_3);
        state = FAILURE;
    }
    catch (invalid_argument &e){
        if(name->getName() == INVALID_NAME_3)
            state = FAILURE;
        cout << "Erro - " << e.what();
    }
}

int TUName::run(){
    setUp();
    validName();
    invalidName();
    tearDown();
    return  state;
}

const double TUMoney::VALID_MONEY = 1000.00;
const double TUMoney::INVALID_MONEY = -10.00;

void TUMoney::setUp() {
  money = new Money();
  state = SUCCESS;
}

void TUMoney::tearDown() {
  delete money;
}

void TUMoney::validMoney() {
  try {
    cout << "Valor testado: " << VALID_MONEY << endl;
    money->setMoney(VALID_MONEY);

    if (money->getMoney() != VALID_MONEY) {
       state = FAILURE;
    }
  }

  catch (invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
  }
  cout << "Dinheiro registrado com sucesso!" << endl;
}

void TUMoney::invalidMoney() {
  try {
    cout << "Valor testado: " << INVALID_MONEY << endl;
    money->setMoney(INVALID_MONEY);
    state = FAILURE;
  }
  catch (invalid_argument &e) {
    if (money -> getMoney() == 0.00){
      state = FAILURE;
    }
    cout << "Erro - " << e.what();
  }
}

int TUMoney::run() {
  setUp();
  validMoney();
  invalidMoney();
  tearDown();
  return state;
}

const string TUDeal::VALID_DEAL = "1234AARt";
const string TUDeal::INVALID_DEAL_1 = "fuvbwjvbwefgwiufgqebeiufga";
const string TUDeal::INVALID_DEAL_2 = "SdADDD#";

void TUDeal::setUp(){
    deal = new Deal();
    state = SUCCESS;
}

void TUDeal::tearDown(){
    delete deal;
}

void TUDeal::validDeal(){
    try{
        cout << "Valor testado: " << VALID_DEAL << endl;
        deal->setDeal(VALID_DEAL);
        if(deal->getDeal() != VALID_DEAL){
            state = FAILURE;
        }
    }
    catch (invalid_argument &e){
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "Negociacao registrada com sucesso!" << endl;
}

void TUDeal::invalidDeal(){
    try{
        cout << "Valor testado: " << INVALID_DEAL_1 << endl;
        deal->setDeal(INVALID_DEAL_1);
        state = FAILURE;
    }
    catch(invalid_argument &e){
        if(deal->getDeal() == INVALID_DEAL_1){
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
    try{
        cout << "Valor testado: " << INVALID_DEAL_2 << endl;
        deal->setDeal(INVALID_DEAL_2);
        state = FAILURE;
    }
    catch(invalid_argument &e){
        if(deal->getDeal() == INVALID_DEAL_2){
            state = FAILURE;
        }
        cout << "Erro: " << e.what();
    }
}

int TUDeal::run(){
    setUp();
    validDeal();
    invalidDeal();
    tearDown();
    return state;
}

const string TUCPF::VALID_CPF = "03334959180";
const string TUCPF::INVALID_CPF_1 = "11111abc111";
const string TUCPF::INVALID_CPF_2 = "0333495918";
const string TUCPF::INVALID_CPF_3 = "11111111111";
const string TUCPF::INVALID_CPF_4 = "23007451010";

void TUCPF::setUp(){
    cpf = new CPF();
    state = SUCCESS;
}

void TUCPF::tearDown(){
    delete cpf;
}

void TUCPF::validCPF(){
    try{
        cout << "Valor testado: " << VALID_CPF << endl;
        cpf->setCPF(VALID_CPF);
        if(cpf->getCPF() != VALID_CPF) {
            state = FAILURE;
        }
    } catch(invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "CPF registrado com sucesso!" << endl;
}

void TUCPF::invalidCPF(){
    try{
        cout << "Valor testado: " << INVALID_CPF_1 << endl;
        cpf->setCPF(INVALID_CPF_1);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(cpf->getCPF() == INVALID_CPF_1) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_CPF_2 << endl;
        cpf->setCPF(INVALID_CPF_2);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(cpf->getCPF() == INVALID_CPF_2) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_CPF_3 << endl;
        cpf->setCPF(INVALID_CPF_3);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(cpf->getCPF() == INVALID_CPF_3) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_CPF_4 << endl;
        cpf->setCPF(INVALID_CPF_4);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(cpf->getCPF() == INVALID_CPF_4) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
}

int TUCPF::run(){
    setUp();
    validCPF();
    invalidCPF();
    tearDown();
    return state;
}

const string TUPassword::VALID_PASSWORD = "Ab12#&";
const string TUPassword::INVALID_PASSWORD_WRONG_LENGTH = "Ab123#&";
const string TUPassword::INVALID_PASSWORD_INVALID_CHARACTER = "Ab12!)";
const string TUPassword::INVALID_PASSWORD_DUPE = "Ab11#&";
const string TUPassword::INVALID_PASSWORD_NO_UPPER = "ab12#&";
const string TUPassword::INVALID_PASSWORD_NO_LOWER = "AB12#&";
const string TUPassword::INVALID_PASSWORD_NO_DIGIT = "Abcd#&";
const string TUPassword::INVALID_PASSWORD_NO_SPECIAL = "Abcd12";

void TUPassword::setUp() {
    password = new Password();
    state = SUCCESS;
}

void TUPassword::tearDown() {
    delete password;
}

void TUPassword::validPassword() {
    try {
        cout << "Valor testado: " << VALID_PASSWORD << endl;
        password->setPassword(VALID_PASSWORD);
        if (password->getPassword() != VALID_PASSWORD) {
            state = FAILURE;
        }
    } catch (invalid_argument &e) {
        state = FAILURE;
    }
    cout << "Senha registrada com sucesso!" << endl;
}

void TUPassword::invalidPasswordTryCatch(string constant) {
    try {
        cout << "Valor testado: " << constant << endl;
        password->setPassword(constant);
        state = FAILURE;
    } catch (invalid_argument &e) {
        if (password->getPassword() == constant) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
}

void TUPassword::invalidPassword() {
    invalidPasswordTryCatch(INVALID_PASSWORD_WRONG_LENGTH);
    invalidPasswordTryCatch(INVALID_PASSWORD_INVALID_CHARACTER);
    invalidPasswordTryCatch(INVALID_PASSWORD_DUPE);
    invalidPasswordTryCatch(INVALID_PASSWORD_NO_UPPER);
    invalidPasswordTryCatch(INVALID_PASSWORD_NO_LOWER);
    invalidPasswordTryCatch(INVALID_PASSWORD_NO_DIGIT);
    invalidPasswordTryCatch(INVALID_PASSWORD_NO_SPECIAL);
}

int TUPassword::run() {
    setUp();
    validPassword();
    invalidPassword();
    tearDown();
    return state;
}

const string TUCode::VALID_CODE = "12345";
const string TUCode::INVALID_CODE_1 = "abcdef";
const string TUCode::INVALID_CODE_2 = "123";

void TUCode::setUp(){
    code = new Code();
    state = SUCCESS;
}

void TUCode::tearDown(){
    delete code;
}

void TUCode::validCode(){
    try{
        cout << "Valor testado: " << VALID_CODE << endl;
        code->setCode(VALID_CODE);
        if(code->getCode() != VALID_CODE) {
            state = FAILURE;
        }
    } catch(invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "Codigo registrado com sucesso!" << endl;
}

void TUCode::invalidCode(){
    try{
        cout << "Valor testado: " << INVALID_CODE_1 << endl;
        code->setCode(INVALID_CODE_1);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(code->getCode() == INVALID_CODE_1) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_CODE_2 << endl;
        code->setCode(INVALID_CODE_2);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(code->getCode() == INVALID_CODE_2) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
}

int TUCode::run(){
    setUp();
    validCode();
    invalidCode();
    tearDown();
    return state;
}

const string TUQuantity::VALID_QUANTITY = "3";
const string TUQuantity::INVALID_QUANTITY_1 = "10000000";
const string TUQuantity::INVALID_QUANTITY_2 = "abcd";

void TUQuantity::setUp(){
    quantity = new Quantity();
    state = SUCCESS;
}

void TUQuantity::tearDown(){
    delete quantity;
}

void TUQuantity::validQuantity(){
    try{
        cout << "Valor testado: " << VALID_QUANTITY << endl;
        quantity->setQuantity(VALID_QUANTITY);
        if(quantity->getQuantity() != stoi(VALID_QUANTITY)) {
            state = FAILURE;
        }
    } catch(invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "Quantidade registrada com sucesso!" << endl;
}

void TUQuantity::invalidQuantity(){
    try{
        cout << "Valor testado: " << INVALID_QUANTITY_1 << endl;
        quantity->setQuantity(INVALID_QUANTITY_1);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(quantity->getQuantity() == stoi(INVALID_QUANTITY_1)) {
            state = SUCCESS;
        }
        cout << "Erro - " << e.what();
    }

    try{
        cout << "Valor testado: " << INVALID_QUANTITY_2 << endl;
        quantity->setQuantity(INVALID_QUANTITY_2);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(quantity->getQuantity() == -1) {
            state = SUCCESS;
        }
        cout << "Erro - " << e.what();
    }
}

int TUQuantity::run(){
    setUp();
    validQuantity();
    invalidQuantity();
    tearDown();
    return state;
}

const int TUDate::VALID_DAY = 1;
const int TUDate::VALID_MONTH = 5;
const int TUDate::VALID_YEAR = 2025;
const int TUDate::INVALID_DAY = 32;
const int TUDate::INVALID_MONTH = 13;
const int TUDate::INVALID_YEAR = 2000;

void TUDate::setUp(){
    date = new Date();
    state = SUCCESS;
}

void TUDate::tearDown(){
    delete date;
}

void TUDate::validDate(){
    try{
        cout << "Valor testado: " << VALID_DAY << "/" << VALID_MONTH << "/" << VALID_YEAR << endl;
        date->setDate(VALID_DAY, VALID_MONTH, VALID_YEAR);
        if(date->getDate() != tuple(VALID_DAY, VALID_MONTH, VALID_YEAR)) {
            state = FAILURE;
        }
    } catch(invalid_argument &e) {
        state = FAILURE;
        cout << "Erro - " << e.what();
    }
    cout << "Data registrada com sucesso!" << endl;
}

void TUDate::invalidDate(){
    try{
        cout << "Valor testado: " << INVALID_DAY << "/" << INVALID_MONTH << "/" << INVALID_YEAR << endl;
        date->setDate(INVALID_DAY, INVALID_MONTH, INVALID_YEAR);
        state = FAILURE;
    } catch (invalid_argument &e){
        if(date->getDate() == tuple(INVALID_DAY, INVALID_MONTH, INVALID_YEAR)) {
            state = FAILURE;
        }
        cout << "Erro - " << e.what();
    }
}

int TUDate::run(){
    setUp();
    validDate();
    invalidDate();
    tearDown();
    return state;
}
