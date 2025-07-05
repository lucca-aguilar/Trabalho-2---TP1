#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <iostream>
#include <string>
#include <regex>

using std::string;
using namespace std;

/**
 * @class Code
 * @brief Representa o código de identificação.
 * 
 * Código é um identificador único atribuído a algo com o objetivo de diferenciá-lo dos demais dentro de um sistema.
 * Pode ser composto por números, letras ou uma combinação de ambos, sendo utilizado para facilitar a organização,localização e manipulação de dados. 
 * Em contextos financeiros, um código pode representar uma carteira, entre outros.
 * 
 */
class Code{
    private:
        /**
         * @brief String que registra o código informado.
         *
        */
        string code;
        /**
         * @brief O método validate verifica se o código de identificação é válido.
         *
         * Verifica se o código informado é composto apenas por números e se possui exatamente cinco caracteres.
         * 
         * @param input_code Código a ser validado.
         * @throw invalid_argument se o código for inválido .
        */
        void validate(string);

    public:
        /**
         * @brief O método setCode registra o código de identificação.
         * 
         * Define um valor ao atributo interno code, responsável por armazenar codigo de identificação.
         * Antes de atribuir o valor, ela realiza a validação ao chamar o método validate, garantindo que a entrada siga os padrões estabelecidos.
         * 
         * @param input_code representa valor do código.
        */
        void setCode(string);
        /**
         * @brief O método getCode retorna o código de identificação.
         *
         * Permite o acesso externo ao valor armazenado no atributo interno code. 
         *
         * @return String contendo o código registrado.
        */
        string getCode();
};

inline string Code::getCode(){
    return code;
}

inline void Code::setCode(string input_code){
    validate(input_code);
    this->code = input_code;
}

/**
 * @class CPF
 * @brief Representa o CPF do usuário.
 * 
 * CPF (Cadastro de Pessoas Físicas) é um número único de identificação emitido pela Receita Federal do Brasil para cada cidadão do país. 
 * Ele serve para identificar cada pessoa física em diversas situações, como transações bancárias, contratos e cadastros em geral. 
 * O CPF possui 11 dígitos numéricos e inclui mecanismos para garantir sua autenticidade.
 */
class CPF {
    private:
        /**
         * @brief Define o tamanho do CPF para 11 digitos.
        */
        static const int SIZE = 11;
        /**
         * @brief String que armazena o CPF.
        */
        string cpf;
        /**
         * @brief Verifica se o CPF informado é válido.
         *
         * Este método realiza as seguintes verificações, lançando exceção em caso de falha:
         * 
         * - A string contém exatamente 11 dígitos numéricos.
         * - Não contém caracteres especiais.
         * - Não são todos os dígitos iguais.
         * - O primeiro dígito verificador.
         * - O segundo dígito verificador.
         *
         * @param input_cpf String que representa o CPF.
         * @throw invalid_argument se o CPF for inválido. 
        */
        void validate(string cpf); 
    public:
        /**
         * @brief O método setCPF registra o CPF.
         * 
         * Define um valor ao atributo interno cpf, responsável por armazenar o CPF do usuário.
         * Antes de atribuir o valor, ela realiza a validação ao chamar o método validate, garantindo que a entrada siga os padrões estabelecidos.
         * 
         * @param input_cpf representa valor do CPF.
        */
        void setCPF(string cpf);
        /**
         * @brief O método getCPF retorna o CPF.
         *
         * Permite o acesso externo ao valor armazenado no atributo interno cpf. 
         *
         * @return String contendo o CPF registrado.
        */
        string getCPF() const;
};

inline string CPF::getCPF() const {
    return cpf;
}

inline void CPF::setCPF(string input_cpf) {
    validate(input_cpf);
    this->cpf = input_cpf;
}

/**
 * @class Date
 * 
 * @brief Representa a data de uma operação
 * 
 * Data de uma operação na bolsa representa um momento temporal que indica o instante em que uma transação financeira foi realizada. 
 * Essa data é fundamental para identificar, registrar e controlar as operações, sendo utilizada para: 
 * 
 * - Fins contábeis;
 * - Fiscais; 
 * - Para o cálculo dos prazos de liquidação dos ativos negociados.
 * Possui formato DD/MM/AAAA.
 */
class Date{
    private:
        /**
         * @brief Registra o dia; 
        */
        int day;
        /**
         * @brief Registra o mês; 
        */
        int month;
        /**
         * @brief Registra o ano; 
        */
        int year;
        /**
         * @brief Verifica se a data informada é válida
         * 
         * Se a data informada seguir o  seguinte padrão será considerado válido:
         * 
         * - Intervalos corretos para dia, mês e ano;
         * - Validação para meses com 30 dias;
         * - Consideração de anos bissextos para o mês de fevereiro.
         * 
         * @param input_day Representa o dia.
         * @param input_month Representa o mês.
         * @param input_year Representa o ano.
         * 
         * @throw invalid_argument se a data for inválida.
        */
        void validate(int, int, int);
    public:
        /**
         * @brief O método setDate registra a data.
         * 
         * Define um valor aos atributos internos day, month e year, responsável por armazenar a data da operação.
         * Antes de atribuir o valor, ela realiza a validação ao chamar o método validate, garantindo que a entrada siga os padrões estabelecidos.
         * 
         * @param input_day Representa o dia.
         * @param input_month Representa o mês.
         * @param input_year Representa o ano.
        */
        void setDate(int , int , int);
        /**
         * @brief O método getDate retorna a data.
         *
         * Fornece acesso externo aos valores de day, month e year armazenados internamente,
         * como de uma tupla de inteiros em formato DD/MM/AAAA.
         *
         * @return Tuple contendo dia, mês e ano, respectivamente
        */
        tuple<int, int, int> getDate();

};

inline tuple<int, int, int> Date::getDate() {
    return tuple<int, int, int>(day, month, year);
}

inline void Date::setDate(int input_day, int input_month, int input_year){
    validate(input_day, input_month, input_year);
    this->day = input_day;
    this->month = input_month;
    this->year = input_year;
}

/**
 * @class Money
 * @brief Responsável por defir a quantidade de dinheiro armazenado. 
 * 
 * Dinheiro é qualquer bem ou objeto geralmente aceito como meio de troca na compra e venda de bens e serviços. 
 * 
*/
class Money {
    private:
        /**
         * @brief Define quantidade mínima de dinheiroa ser investido como 0.01.
         */
        static constexpr double MIN_MONEY = 0.01;
        /**
         * @brief Define quantidade máxiima de dinheiroa ser investido como 1000000000.00.
        */
        static constexpr double MAX_MONEY = 1000000000.00;
        /**
         * @brief Valor interno que registra a quantidade de dinheiro aplicado.
        */
        double money;
        /**
         * @brief O método validate verifica se a quantidade de dinheiro é válido. 
         * 
         * Verifica se a quantidade de recursos investidos está entre os valores máximo e mínimo.
         * Se for inválido, uma exceção é lançada.
         * 
         * @param input_money Quantidade a ser validada.
         * @throw invalid_argument se a quantidade de dinheiro estiver fora dos limites estabelecidos.
        */
        void validate(double); 
    public:
        /**
         * @brief O método setMoney atribui a quantidade de dinheiro
         * 
         * Determina um valor ao atributo interno money, responsável por armazenar a quantidade de dinheiro investido.
         * Antes de registrar, realiza a validação da quantidade informada ao chamar o método validate, garantindo que esteja entre os valores estabelecidos. 
         * 
         * @param input_money representa a quantidade de dinheiro informada pelo usuário.
        */
        void setMoney(double);
        /**
         * @brief O método getMoney retorna a investido.
         *
         * Acessa o atributo interno 'money' e retorna o valor armazenado.
         *
         * @return a quantidade de dinheiro aplicado.
        */
        double getMoney();
}; 

inline double Money::getMoney(){
      return money;
}

inline void Money::setMoney(double input_money){
    validate(input_money);
    this->money = input_money;
}

/**
 * @class Deal
 * @brief Representa o identificador do negócio realizado.
 * 
 * Negócio refere-se a uma transação ou operação financeira, como compra ou venda de ativos. 
 * O identificador do negócio é utilizado para conseguir encontrar, no sistema do banco, determinada operação realizada.
 * Nesse caso, o código de negociação é um identificador único que representa uma transação específica.
 * Esse código pode ser composto por letras e números, facilitando a identificação e o rastreamento de transações financeiras.
 * 
*/
class Deal{
    private:
        /**
         * @brief Define o tamanho máximo do código de negociação como 12 caracteres.
         */
        static const int max_length = 12;
        /**
         * @brief String que registra o identificador do negócio (código de negociação).
         *
        */
        string deal;
        /**
         * @brief O método validate verifica se o código de negociação é válido.
         *
         * Verifica se o código informado possui no máximo 12 caracteres e se contém apenas letras, números e espaços em branco.
         * O código não pode conter caracteres especiais e nem espaços em branco repetidos.
         * Em caso de entrada inválida, uma exceção é lançada, impedindo a atribuição do valor à variável deal.
         * Essa validação é chamada ao passar um parâmetro para o método setDeal.
         * 
         * @param input_deal Código a ser validado, passado pelo método setDeal.
         * @throw invalid_argument se o código for inválido.
        */
        void validate(string);
    public:
        /**
         * @brief O método setDeal registra o código de negociação.
         * 
         * Define um valor ao atributo interno deal, responsável por armazenar o código de negociação.
         * Antes de atribuir o valor, ela realiza a validação ao chamar o método validate, garantindo que a entrada siga os padrões estabelecidos. 
         * 
         * @param input_deal representa o código de negociação informado pelo usuário.
        */
        void setDeal(string);
        /**
         * @brief O método getDeal retorna o código de negociação.
         *
         * Acessa o atributo interno 'deal' e retorna o valor armazenado.
         *
         * @return String contendo o código de negociação registrado.
        */
        string getDeal();
};

inline string Deal::getDeal(){
    return deal;
}

inline void Deal::setDeal(string input_deal){
    validate(input_deal);
    this->deal = input_deal;
}

/**
 * @class Name
 * @brief Responsável por armazenar o nome do investidor.
 * 
 * Nome é a designação que identifica uma pessoa, podendo ser composto por um ou mais nomes e sobrenomes. 
 * É utilizado para distinguir indivíduos e facilitar a comunicação.
 * No que diz respeito a investimentos, o nome é um dado essencial para identificar o investidor e associá-lo a suas transações financeiras.
 * 
*/
class Name{
    private:
        /**
         * @brief Define o tamanho máximo do nome como 20 caracteres.
         */
        static const int max_length = 20;
        /**
         * @brief String que registra o nome informado.
         *
        */
        string name;
        /**
         * @brief O método validate verifica se o nome é válido.
         *
         * Verifica se o nome informado possui no máximo 20 caracteres e se contém apenas letras, espaços em branco e números.
         * O nome não pode conter caracteres especiais.
         * Em caso de entrada inválida, uma exceção é lançada, impedindo a atualização do valor armazenado na variável name.
         * Essa validação é chamada ao passar um parâmetro para o método setName.
         * 
         * @param input_name Nome a ser validado, passado pelo método setName.
         * @throw invalid_argument se o nome for inválido.
        */
        void validate(string);
    public:
        /**
         * @brief O método setName registra o nome do investidor.
         * 
         * Define um valor ao atributo interno name, responsável por armazenar o nome do investidor.
         * Antes de atribuir o valor, ela realiza a validação chamando o método validate, garantindo que a entrada siga os padrões estabelecidos. 
         * 
         * @param input_name representa o nome informado pelo usuário.
         */
        void setName(string);
        /**
         * @brief O método getName retorna o nome do investidor.
         *
         * Acessa o atributo interno 'name' e retorna o valor armazenado.
         *
         * @return String contendo o nome registrado.
        */
        string getName();
};

inline string Name::getName(){
    return name;
}

inline void Name::setName(string input_name){
    validate(input_name);
    this->name = input_name;
}

/************************************************************************************************************************************//**
 * @class Password
 * @brief Classe construída para a validação e armazenamento de senhas de usuário.
 * 
 * A classe Password armazena a senha do usuário, que deve ser validada conforme seu tamanho e os
 * caracteres que a compõe. A senha deve ter 6 caracteres, sem poder possuir caracteres duplicados. 
 * A senha deve ter, no mínimo:
 * 
 * - Uma letra maiúscula
 * - Uma letra minúscula
 * - Um dígito numérico
 * - Um caractere especial dentre (#, $, % e &)
 * 
****************************************************************************************************************************************/

class Password {
    private :
       /************************************************************************************************************************************//**
         * @brief Enum que abstrai valores correspondentes às necessidades da senha armazenada.
         * 
         * Os valores são:
         * 
         * - DIGIT = 0
         * - SPECIAL_CHARACTER = 1
         * - LOWER = 2
         * - UPPER = 3
         * 
        ****************************************************************************************************************************************/
        enum CONDITIONS {DIGIT, SPECIAL_CHARACTER, LOWER, UPPER};

        /************************************************************************************************************************************//**
         * @brief Constante que determina o tamanho obrigatório da senha.
        ****************************************************************************************************************************************/
        const static int PASSWORD_SIZE = 6;

        /************************************************************************************************************************************//**
         * @brief Armazena a senha do usuário.
        ****************************************************************************************************************************************/
        string user_password;

        /************************************************************************************************************************************//**
         * @brief O método validate verifica a validação de uma dada string.
         * 
         * Dada uma string, esse metodo verifica se ela é válida ou não conforme as seguintes especificações: 
         * 
         * - Possui 6 caracteres
         * - Sem caracteres duplicados
         * - No mínimo uma letra maiúscula
         * - No mínimo uma letra minúscula
         * - No mínimo um dígito numérico
         * 
         * @param input_password String to be validated
        ****************************************************************************************************************************************/
        void validate(string input_password);

    public :
        /************************************************************************************************************************************//**
         * @brief O método setPassword define o valor armazenado como a string de input, caso esta seja válida.
         * 
         * Atua como interface para definir a senha do usuário, chamando o método validate para validar a string de input. 
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @param input_password String a ser armazenada dentro da instância de classe
        ****************************************************************************************************************************************/
        void setPassword (string input_password);

        /************************************************************************************************************************************//**
         * @brief O método getPassword retorna o valor de senha armazenado na instância de classe. 
         * 
         * Atua como interface para acesso do atributo privado 'user_password'.
         * Permite a leitura externa do código, mantendo o encapsulamento da classe.
         * 
         * @return A senha armazenada na instâcia de classe.
        ****************************************************************************************************************************************/
        string getPassword();
};

inline void Password::setPassword (string input_password) {
    validate(input_password);
    user_password = input_password;
}

inline string Password::getPassword() {
    return user_password;
}

/** 
 * @class Profile
 * @brief Responsável por representar o perfil do investidor.
 * 
 * O perfil de investidor define o grau de tolerância ao risco e influencia diretamente nas recomendações de investimento.
 * Os perfis usados são:
 * 
 * - Conservador: prioriza segurança e estabilidade;
 * - Moderado: busca equilíbrio entre risco e retorno;
 * - Agressivo: aceita maiores riscos em troca de maior rentabilidade.
 * 
*/
class Profile{
  private:
    /**
     * @brief Define o perfil conservador.
    */
    inline static const string CONSERVATIVE = "Conservador";
    /**
     * @brief Define o perfil moderado.
    */
    inline static const string MODERATE = "Moderado"; 
    /**
     * @brief Define o perfil agressivo.
    */
    inline static const string AGGRESSIVE = "Agressivo"; 
    /**
     * @brief String que registra o perfil informado.
    */
    string profile;
    /**
     * @brief O método format garante que a entrada siga os padrões estabelecidos 
     * 
     * Formata a string de entrada de modo que a primeira letra fique maiúscula e as demais, minúsculas.
     * 
     * @param input_profile representa o perfil informado.
     * @return Perfil de investidor formatado.
    */
    string format(string);
    /**
     * @brief O método validate verifica se o perfil é válido 
     * 
     * Verifica se a entrada corresponde a um dos valores permitidos.
     * Se a entrada for diferente, uma exceção é lançada, impedindo a atribuição do valor à variável profile.
     * 
     *@throw invalid_argument se o perfil inserido não corresponder aos perfis válidos.
    */
    void validate(string input_profile);  

  public:
    /**
     * @brief O método setProfile atribui o tipo de investidor.
     * 
     * Define um valor ao atributo interno profile, responsável por armazenar o tipo de investidor.
     * Antes de atribuir o valor, ela realiza a validação do perfil informado ao chamar o método validate, garantindo que seja um dos três permitidos.
     * 
     * @param input_profile representa o perfil de investidor informado pelo usuário.
    */
    void setProfile(string);
    /**
     * @brief O método getProfile retorna o perfil de investidor.
     *
     * Este método acessa o atributo interno 'profile' e retorna o valor armazenado.
     *
     * @return String contendo o perfil de investidor atual.
    */
    string getProfile();
}; 


inline string Profile::format(string input_profile){

  transform(input_profile.begin(), input_profile.end(), input_profile.begin(), ::tolower);

  if (!input_profile.empty()) {
    input_profile[0] = toupper(input_profile[0]);
  }
  return input_profile;

}

inline void Profile :: setProfile (string input_profile){
    validate(input_profile);
    this->profile = input_profile;
}

inline string Profile :: getProfile(){
  return profile;
}

/**
 * @class Quantity
 * @brief Representa a quantidade de um item ou ativo financeiro.
 * 
 * Quantidade refere-se ao número total de unidades de um determinado item, ativo ou recurso. 
 * Em contextos financeiros e de investimento, representa o volume de elementos adquiridos, movimentados ou mantidos, como cotas de um fundo.
 * Esse valor é essencial para o controle patrimonial e o cálculo de rendimentos.
 * 
*/
class Quantity{
    private:
        /**
        * @brief String que registra a quantidade
        */
        string quantity;
        /**
         * @brief O método validate verifica se a quantidade é válida.
         *
         * Verifica se a string contém apenas números. 
         * Depois converte a string para inteiro e analisa se o valor está dentro dos limites permitidos.
         * Caso não corresponda ao esperado, uma exceção é lançada e a atribuição à variável quantity é impedida.
         *
         * @param input_quantity Representa a quantidade a ser validada.
         * @throws invalid_argument se a entrada for inválida.
        */
        void validate(string);
        /**
        * @brief Quantidade validade e convertida para inteiro
        */
        int final_quantity = -1;
    public:
        /**
         * @brief O método setQuantity registra a quantidade de ativos.
         * 
         * Define um valor ao atributo interno final_quantity, responsável por armazenar a quantidade.
         * Antes de atribuir o valor, ela realiza a validação ao chamar o método validate, garantindo que a entrada siga os padrões estabelecidos.
         * 
         * @param input_quantity representa a quantidade informada pelo usuário.
        */ 
        void setQuantity(string);
        /**
         * @brief O método getQuantity retorna o a quantidade registrada.
         *
         * Permite o acesso externo ao valor armazenado no atributo interno final_quantity.
         *
         * @return Inteiro contendo o valor atribuído à quantidade.
        */
        int getQuantity();
};

inline int Quantity::getQuantity(){
    return final_quantity;
}

inline void Quantity::setQuantity(string input_quantity){
    validate(input_quantity);
    this->final_quantity = final_quantity;
}

#endif
