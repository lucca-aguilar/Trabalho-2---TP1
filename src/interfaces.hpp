#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

// ======== Menu ========

/**
 * @class IUMenu
 * 
 * @brief Interface para controle geral do sistema
 * 
 * Essa interface atua como ponto de entrada do sistema, direcionando o usuário para a parte de autenticação,
 * conta e investimento
 */
class IUMenu {
    public:
        /**
         * @brief Método responsável por iniciar a execução do menu.
         * 
         * Este método deve ser implementado para exibir o menu inicial, capturar as decisões do usuário
         * e distribuir as chamadas aos respectivos módulos. 
         */
        virtual void execute() = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de IUMenu sejam corretamente destruídos, evitando vazamentos de memória.
         */
        virtual ~IUMenu() {}
};

// ======== Interfaces da Camada de Apresentação ========

/**
 * @class IAA
 * 
 * @brief Interface da camada de apresentação para autenticação.
 *
 * Responsável por iniciar o processo de autenticação a partir dos dados fornecidos pelo usuário.
 * Atua como intermediária entre a entrada do usuário e a lógica implementada no serviço.
 */

class IAA {
    public:
        /**
         * @brief Solicita autenticação com base no CPF do usuário.
         * 
         * @param cpf Ponteiro para o CPF fornecido.
         * 
         * @return true se a autenticação for bem-sucedida.
         */
        virtual bool autenticate(CPF* cpf) = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de IAA sejam corretamente destruídos, evitando vazamentos de memória.
         */
        virtual ~IAA() {}
};

/**
 * @class IAC
 * 
 * @brief Interface da camada de apresentação para conta.
 * 
 * Atua como intermediária entre a entrada do usuário e a lógica implementada no serviço.
 */

class IAC {
    public:
        /**
         * @brief Inicia o processo de criação de uma nova conta.
         */
        virtual void create() = 0;

        /**
         * @brief Executa os serviços disponíveis para um usuário já autenticado.
         * 
         * @param cpf Referência ao CPF do usuário autenticado.
         */
        virtual void execute(CPF& cpf) = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de IAC sejam corretamente destruídos, evitando vazamentos de memória.
         */

        virtual ~IAC() {}
};

/**
 * @class IAI
 * 
 * @brief Interface da camada de apresentação para investimento.
 *
 * Fornece acesso aos serviços de carteira e ordens de investimento,
 * sendo responsável por intermediar as ações do usuário com o módulo de serviço.
 */
class IAI {
    public:
        /**
         * @brief Inicia a execução dos serviços de investimento disponíveis ao usuário.
         */
        virtual void execute() = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de IAI sejam corretamente destruídos, evitando vazamentos de memória.
         */
        virtual ~IAI() {}
};

// ======== Interfaces da Camada de Serviço ========

/**
 * @class ISA
 * 
 * @brief Interface da camada de serviço para autenticação de usuários.
 *
 * Implementa a lógica de verificação de dados para obter acesso ao sistema.
 */
class ISA {
    public:
        /**
         * @brief Verifica se o CPF e senha informados correspondem a um usuário válido.
         * 
         * @param cpf Referência ao CPF do usuário.
         * 
         * @param password Referência à senha fornecida.
         * 
         * @return true se as credenciais forem válidas.
         */
        virtual bool autenticate(CPF& cpf, Password& password) = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de ISA sejam corretamente destruídos, evitando vazamentos de memória.
         */

        virtual ~ISA() {}
};

/**
 * @class ISC
 * 
 * @brief Interface da camada de serviço responsável pelo gerenciamento de contas.
 *
 * Define as operações de CRUD (Create, Read, Update, Delete) relacionadas a contas de usuário.
 */
class ISC {
    public:
        /**
         * @brief Cria uma nova conta.
         * 
         * @param account Referência à conta a ser criada.
         * 
         * @return true se a conta for criada com sucesso.
         */
        virtual bool create(Account& account) = 0;

        /**
         * @brief Lê os dados de uma conta existente.
         * 
         * @param account Ponteiro para a conta a ser lida.
         * 
         * @return true se os dados forem carregados com sucesso.
         */
        virtual bool read(Account* account) = 0;

        /**
         * @brief Edita as informações de uma conta existente.
         * 
         * @param account Referência à conta a ser atualizada.
         * 
         * @return true se a conta for atualizada com sucesso.
         */
        virtual bool edit(Account& account) = 0;

        /**
         * @brief Exclui uma conta do sistema com base no CPF.
         * 
         * @param cpf Referência ao CPF do titular da conta.
         * 
         * @return true se a exclusão for bem-sucedida.
         */
        virtual bool exclude(CPF& cpf) = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de ISC sejam corretamente destruídos, evitando vazamentos de memória.
         */

        virtual ~ISC() {}
};

/**
 * @class ISI
 * 
 * @brief Interface da camada de serviço responsável por carteiras e ordens de investimento.
 *
 * Agrupa as operações disponíveis para gerenciamento completo de carteiras e ordens vinculadas a uma conta.
 */
class ISI {
    public:
        ///@name Operações sobre Carteiras 
        ///@{

        /**
         * @brief Cria uma nova carteira de investimentos.
         * 
         * @param wallet Referência à carteira a ser registrada.
         * 
         * @return true se a carteira for criada com sucesso.
         */
        virtual bool create(Wallet& wallet) = 0;

        /**
         * @brief Lê os dados de uma carteira existente.
         * 
         * @param wallet Ponteiro para a carteira a ser consultada.
         * 
         * @return true se os dados forem carregados com sucesso.
         */
        virtual bool read(Wallet* wallet) = 0;

        /**
         * @brief Edita os dados de uma carteira.
         * 
         * @param wallet Referência à carteira a ser modificada.
         * 
         * @return true se a modificação for concluída.
         */
        virtual bool edit(Wallet& wallet) = 0;

        /**
         * @brief Exclui uma carteira com base em seu código identificador.
         * 
         * @param code Referência ao código da carteira.
         * 
         * @return true se a exclusão for bem-sucedida.
         */
        virtual bool excludeWallet(Code& code) = 0;

        /**
         * @brief Lista todas as carteiras registradas no sistema.
         * 
         * @return true se a listagem for bem-sucedida.
         */
        virtual bool listWallets() = 0;

        /// @}

        ///@name Operações sobre Ordens 
        ///@{

        /**
         * @brief Cria uma nova ordem de investimento.
         * 
         * @param order Referência à ordem a ser registrada.
         * 
         * @return true se a ordem for criada com sucesso.
         */
        virtual bool create(Order& order) = 0;

        /**
         * @brief Lê os dados de uma ordem existente.
         * 
         * @param order Ponteiro para a ordem a ser consultada.
         * 
         * @return true se os dados forem carregados com sucesso.
         */
        virtual bool read(Order* order) = 0;

        /**
         * @brief Exclui uma ordem com base em seu código identificador.
         * 
         * @param code Referência ao código da ordem.
         * 
         * @return true se a exclusão for bem-sucedida.
         */
        virtual bool excludeOrder(Code& code) = 0;

        /**
         * @brief Lista todas as ordens registradas no sistema.
         * 
         * @param code Referência ao código da ordem.
         * 
         * @return true se a listagem for bem-sucedida.
         */
        virtual bool listOrders(Code& code) = 0;

        /**
         * @brief Destrutor virtual.
         * 
         * Permite que objetos derivados de ISI sejam corretamente destruídos, evitando vazamentos de memória.
         */

        virtual ~ISI() {}
};

#endif
