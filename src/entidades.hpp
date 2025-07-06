#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"

/**
 * @class Account
 * @brief A entidade Account representa a conta de um usuário. 
 * 
 * Representa uma entidade digital que identifica de forma única um indivíduo dentro de um sistema. 
 * A conta de usuário agrupa informações pessoais e credenciais de autenticação, permitindo:  
 * 
 * - O acesso a funcionalidades específicas;
 * - A personalização da experiência do sistema; 
 * - A vinculação a dados ou recursos pertencentes ao usuário.
 * 
 * Para criar a conta as seguintes informações são utilizadas:
 * 
 * - CPF;
 * - Nome; 
 * - Senha. 
*/
class Account {
    private:
        /**
         * @brief Define o CPF do investidor.
        */
        CPF cpf;
        /**
         * @brief Define o nome do investidor.
        */
        Name name;
        /**
         * @brief Define a senha associada a conta.
        */
        Password password;
        /**
         * @brief Define o saldo de dinheiro na conta.
         */
        Money balance;
    public: 
        /**
         * @brief O método getCPF retorna o CPF do investidor.
         * 
         * Acessa o atributo privado do tipo CPF e retorna o valor registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto CPF correspondente ao CPF do usuário.
        */
        CPF getCPF();
        /**
         * @brief O método setCPF é utilizado para armazenar o CPF do investidor. 
         * 
         * Atua como uma interface para registrar o CPF do usuário,
         * atribui o valor recebido ao objeto interno cpf. 
         * 
         * @param cpf representa o CPF do investidor. 
        */
        void setCPF(string input_cpf);
        /**
         * @brief O método getName retorna o nome do usuário.
         * 
         * Acessa o atributo privado do tipo Name e retorna o que está armazenado
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Name correspondente ao nome do investidor.
        */
        Name getName();
        /**
         * @brief O método setName é utilizado para armazenar o nome do investidor. 
         * 
         * Atua como uma interface para registrar o nome do usuário,
         * atribui o valor recebido ao objeto interno name. 
         * 
         * @param name representa o nome do investidor. 
        */
        void setName(string input_name);
        /**
         * @brief O método getPassword retorna a senha do investidor.
         * 
         * Acessa o atributo privado do tipo Password e retorna o que está armazenado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Password correspondente a senha do usuário.
        */
        Password getPassword();
        /**
         * @brief O método setPassword é utilizado para registrar a senha. 
         * 
         * Atua como uma interface para armazenar a senha do investidor,
         * atribui o valor recebido ao objeto interno password. 
         * 
         * @param password representa a senha usuário. 
        */
        void setPassword(string input_password);
        /**
         * @brief O método getBalance retorna o saldo de dinheiro na conta, que representa a soma do saldo de cada uma das carteiras.
         * 
         * Acessa o atributo privado do tipo Money e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Money correspondente ao saldo de dinheiro na conta.
        */
        Money getBalance();
        /**
         * @brief O método setBalance é utilizado para definir o saldo de dinheiro na conta. 
         * 
         * Atua como uma interface para registrar o saldo do usuário,
         * atribui o valor recebido ao objeto interno balance. 
         * 
         * @param input_balance representa o saldo de dinheiro na conta do investidor. 
        */
        void setBalance(double input_balance);
};

inline CPF Account::getCPF() {
    return cpf;
}

inline void Account::setCPF(string input_cpf) {
    this->cpf.setCPF(input_cpf);
}

inline Name Account::getName() {
    return name;
}

inline void Account::setName(string input_name) {
    this->name.setName(input_name);
}

inline Password Account::getPassword() {
    return password;
}

inline void Account::setPassword(string input_password) {
    this->password.setPassword(input_password);
}

inline Money Account::getBalance() {
    return balance;
}

inline void Account::setBalance(double input_balance) {
    this->balance.setMoney(input_balance);
}

/**
 * @class Order
 * @brief A entidade Order representa uma ordem de compra ou venda de um ativo financeiro. 
 * 
 * Uma ordem é uma instrução dada por um investidor para comprar ou vender um ativo financeiro em uma bolsa de valores. 
 * As ordens podem ser de diferentes tipos, como ordens de mercado, ordens limitadas, entre outras.
 * 
 * Para criar a ordem utiliza-se as seguintes informações:
 * - Codigo identificador da carteira;
 * - Código identificador da Negociação (operação); 
 * - Data em que a operação foi realizada; 
 * - Preço do ativo.; 
 * - Quantidade. 
*/
class Order{
    private:
        /**
         * @brief Define o código identificador da carteira à qual a ordem pertence.
        */
        Code code;
        /**
         * @brief Define o código identificador da negociação (operação).
        */
        Deal deal;
        /**
         * @brief Define a data em que a operação foi realizada.
        */
        Date date;
        /**
         * @brief Define o montante envolvido na operação.
        */
        Money money;
        /**
         * @brief Define a quantidade de ativos envolvidos na operação.
        */
        Quantity quantity;
        /**
         * @brief Define a carteira à qual a ordem pertence.
        */
        Code walletCode;
    public:
        /**
         * @brief O método getCode retorna o código identificador da carteira.
         * 
         * Acessa o atributo privado do tipo Code e retorna o valor registrado (nesse caso, um objeto da classe Code).
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Code correspondente ao código de identificação.
        */
        Code getCode();
        /**
         * @brief O método setCode é utilizado para definir o código de identificação da carteira. 
         * 
         * Atua como uma interface para registrar o código de identificação,
         * atribui o valor recebido ao objeto interno Code. 
         * 
         * @param code representa o código de identificação. 
        */
        void setCode(Code code);
        /**
         * @brief O método getDeal retorna o código identificador da negociação (operação).
         * 
         * Acessa o atributo privado do tipo Deal e retorna o valor registrado (nesse caso, um objeto da classe Deal).
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Deal correspondente ao código de negociação.
        */
        Deal getDeal();
        /**
         * @brief O método setDeal é utilizado para definir o código identificador da negociação (operação). 
         * 
         * Atua como uma interface para registrar o código de negociação,
         * atribui o valor recebido ao objeto interno Deal. 
         * 
         * @param deal representa o código de negociação. 
        */
        void setDeal(Deal deal);
        /**
         * @brief O método getDate retorna a data em que a operação foi realizada.
         * 
         * Acessa o atributo privado do tipo Date e retorna o valor registrado (nesse caso, um objeto da classe Date).
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Date correspondente à data da operação.
        */
        Date getDate();
        /**
         * @brief O método setDate é utilizado para definir a data em que a operação foi realizada. 
         * 
         * Atua como uma interface para registrar a data da operação,
         * atribui o valor recebido ao objeto interno Date. 
         * 
         * @param date representa a data da operação. 
        */
        void setDate(Date date);
        /**
         * @brief O método getMoney retorna o montante envolvido na operação.
         * 
         * Acessa o atributo privado do tipo Money e retorna o valor registrado (nesse caso, um objeto da classe Money).
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Money correspondente ao montante da operação.
        */
        Money getMoney();
        /**
         * @brief O método setMoney é utilizado para definir o montante envolvido na operação. 
         * 
         * Atua como uma interface para registrar o montante da operação,
         * atribui o valor recebido ao objeto interno Money. 
         * 
         * @param money representa o montante da operação. 
        */
        void setMoney(Money money);
        /**
         * @brief O método getQuantity retorna a quantidade de ativos envolvidos na operação.
         * 
         * Acessa o atributo privado do tipo Quantity e retorna o valor registrado (nesse caso, um objeto da classe Quantity).
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Quantity correspondente à quantidade de ativos.
        */
        Quantity getQuantity();
        /**
         * @brief O método setQuantity é utilizado para definir a quantidade de ativos envolvidos na operação. 
         * 
         * Atua como uma interface para registrar a quantidade de ativos,
         * atribui o valor recebido ao objeto interno Quantity. 
         * 
         * @param quantity representa a quantidade de ativos. 
        */
        void setQuantity(Quantity quantity);
        /**
         * @brief O método setWallet é utilizado para definir a carteira à qual a ordem pertence.
         * 
         * Atua como uma interface para registrar o endereço da carteira associada à ordem,
         * atribui o valor recebido ao objeto interno Wallet.
         * 
         * @param wallet representa a carteira associada à ordem.
        */
        void setWalletCode(Code walletCode);
        /**
         * @brief O método getWallet retorna a carteira à qual a ordem pertence.
         * 
         * Acessa o atributo privado do tipo Wallet e retorna o valor registrado (nesse caso, um objeto da classe Wallet).
         * Permite a leitura externa da carteira, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Wallet correspondente à carteira da ordem.
        */
        Code getWalletCode();
};

inline Code Order::getCode(){
    return code;
}

inline void Order::setCode(Code code) {
    this->code = code;
}

inline Deal Order::getDeal(){
    return deal;
}

inline void Order::setDeal(Deal deal) {
    this->deal = deal;
}

inline Date Order::getDate(){
    return date;
}

inline void Order::setDate(Date date) {
    this->date = date;
}

inline Money Order::getMoney(){
    return money;
}

inline void Order::setMoney(Money money) {
    this->money = money;
}

inline Quantity Order::getQuantity(){
    return quantity;
}

inline void Order::setQuantity(Quantity quantity) {
    this->quantity = quantity;
}

inline void Order::setWalletCode(Code walletCode) {
    this->walletCode = walletCode;
}

inline Code Order::getWalletCode() {
    return walletCode;
}

/**
 * @class Wallet
 * @brief A entidade Wallet representa uma carteira de investimentos. 
 * 
 * Uma carteira de investimentos é o conjunto de ativos financeiros que um investidor possui, como ações, títulos e fundos. 
 * Sua composição depende do perfil do investidor e dos objetivos financeiros.
 * 
 * Para criar a carteira utiliza-se as seguintes informações:
 * - Codigo identificador;
 * - Nome do usuário; 
 * - Perfil de investidor. 
 * 
 */
class Wallet {
    private:
        /**
         * @brief Define o código identificador da carteira.
        */
        Code code;
        /**
         * @brief Define o nome.
        */ 
        Name name;
        /**
         * @brief Define o perfil do investidor.
        */
        Profile profile;
        /**
         * @brief Define o saldo de dinheiro na carteira ao se considerar o preço de todas as ordens pertencentes a ela.
        */
        Money balance;
        /**
         * @brief Define o proprietário da conta.
         */
        Account* accountOwner;
         /**
         * @brief Define a quantidade de ordens registradas nessa carteira.
        */
        int orders_count = 0;
    public:
        /**
         * @brief O método setCode é utilizado para definir o código de identificação da carteira. 
         * 
         * Atua como uma interface para registrar o código de identificação,
         * atribui o valor recebido ao objeto interno Code. 
         * 
         * @param code representa o código de identificação. 
        */
        void setCode(string code);
        /**
         * @brief O método getCode retorna o código de identificação da carteira.
         * 
         * Acessa o atributo privado do tipo Code e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Code correspondente ao código de identificação.
        */
        Code getCode();
        /**
         * @brief O método setName é utilizado para definir o nome do investidor 
         * 
         * Atua como uma interface para registrar o nome do usuário,
         * atribui a string recebida ao objeto interno Name.
         * 
         * @param name representa o nome do investidor. 
        */
        void setName(string name);
        /**
         * @brief O método getName retorna o nome do investidor.
         * 
         * Acessa o atributo privado do tipo Name e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Name correspondente ao nome do usuário.
        */
        Name getName();
        /**
         * @brief O método setProfile é utilizado para definir o perfil do investidor 
         * 
         * Atua como uma interface para registrar o perfil do investidor,
         * atribui a string recebida ao objeto interno Profile.
         * 
         * @param profile representa o tipo de investidor. 
        */
        void setProfile(string profile);
        /**
         * @brief O método getProfile retorna o perfil do investidor.
         * 
         * Acessa o atributo privado do tipo Profile e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Profile correspondente ao perfil do investidor.
        */
        Profile getProfile();
        /**
         * @brief O método getOrdersCount retorna a quantidade de ordens registradas nessa carteira.
         * 
         * Acessa o atributo privado do tipo int e retorna o valor registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Inteiro correspondente à quantidade de ordens registradas.
        */
        int getOrdersCount();
        /**
         * @brief O método increaseOrdersCount incrementa a quantidade de ordens registradas nessa carteira.
         * 
         * Este método é utilizado para atualizar o contador de ordens sempre que uma nova ordem é adicionada à carteira.
         * Ele simplesmente incrementa o valor do atributo orders_count em 1.
         */
        void increaseOrdersCount();
        /**
         * @brief O método decreaseOrdersCount decrementa a quantidade de ordens registradas nessa carteira.
         * 
         * Este método é utilizado para atualizar o contador de ordens sempre que uma ordem é removida da carteira.
         * Ele verifica se o contador é maior que zero antes de decrementá-lo, evitando valores negativos.
         */
        void decreaseOrdersCount();
        /**
         * @brief O método setBalance é utilizado para definir o saldo de dinheiro na carteira.
         * 
         * Atua como uma interface para registrar o saldo de dinheiro,
         * atribui o valor recebido ao objeto interno Money.
         * 
         * @param money representa o saldo de dinheiro na carteira. 
        */
        void setBalance(double money);
        /**
         * @brief O método getBalance retorna o saldo de dinheiro na carteira.
         * 
         * Acessa o atributo privado do tipo Money e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto Money correspondente ao saldo de dinheiro na carteira.
        */
        Money getBalance();
        /**
         * @brief O método setAccountOwner é utilizado para definir o CPF do proprietário da conta.
         * 
         * Atua como uma interface para registrar o CPF do proprietário,
         * atribui o valor recebido ao objeto interno CPF.
         * 
         * @param cpf representa o CPF do proprietário da conta. 
        */
        void setAccountOwner(Account* account);
        /**
         * @brief O método getAccountOwner retorna o CPF do proprietário da conta.
         * 
         * Acessa o atributo privado do tipo CPF e retorna o valor atualmente registrado.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return Objeto CPF correspondente ao proprietário da conta.
        */
        Account* getAccountOwner();
};

inline void Wallet::setCode(string code){
    this->code.setCode(code);
}

inline Code Wallet::getCode() {
    return code;
}

inline void Wallet::setName(string name){
    this->name.setName(name);
}

inline Name Wallet::getName() {
    return name;
}

inline void Wallet::setProfile(string profile){
    this->profile.setProfile(profile);
}

inline Profile Wallet::getProfile() {
    return profile;
}

inline int Wallet::getOrdersCount() {
    return orders_count;
}

inline void Wallet::increaseOrdersCount() {
    orders_count++;
}

inline void Wallet::decreaseOrdersCount() {
    if (orders_count > 0) {
        orders_count--;
    }
}

inline void Wallet::setBalance(double money) {
    this->balance.setMoney(money);
}

inline Money Wallet::getBalance() {
    return balance;
}

inline void Wallet::setAccountOwner(Account* account) {
    this->accountOwner = account;
}

inline Account* Wallet::getAccountOwner() {
    return accountOwner;
}

#endif
