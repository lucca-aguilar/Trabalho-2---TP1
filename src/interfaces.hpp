#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

class IUMenu {
    public:
        virtual void execute() = 0;
        virtual ~IUMenu() {}
};

// interfaces das camadas de apresentacao
class IAA { // interface da camada de apresentacao do servico de autenticacao
    public:
        virtual bool autenticate(CPF* cpf) = 0; // metodo virtual puro para solicitar autenticacao de usuario no sistema
        virtual ~IAA(){} // destruidor virtual padrao
};

class IAC { // interface da camada de apresentacao para os servicos de conta
    public:
        virtual void create() = 0; // metodo virtual puro para solicitar a criacao de uma nova conta
        virtual void execute(const CPF& cpf) = 0; // metodo virtual puro para iniciar a execucao de servicos para usuario ja autenticado
        virtual ~IAC(){} // destruidos virtual padrao
};

class IAI { // interface da camada de apresentacao para os servicos de investimento
    public:
        virtual void execute(Account& account) = 0; // inicia a execucao dos servicos de investimento
        virtual ~IAI(){} // destruidor virtual padrao
};

// interfaces da camada de servico

class ISA { // interface da camada de servico para autenticacao
    public:
        virtual bool autenticate(CPF& cpf, Password& password) = 0; // metodo virtual puro para validar as credenciais de um usuario
        virtual ~ISA(){} // destruidor virtual padrao
};

class ISC { // interface da camada de servico para gerenciamento de contas
    public: 
        virtual bool create(Account& account) = 0; // metodo virtual puro para criar conta
        virtual bool read(Account* account) = 0; // metodo virtual puro para ler conta
        virtual bool edit(Account& account) = 0; // metodo virtual puro para editar conta
        virtual bool exclude(const CPF& cpf) = 0; // metodo virtual puro para excluir conta
        virtual ~ISC(){} // destruidor virtual padrao
};

class ISI { // interface da camada de servico para gerenciamento de investimentos
    public:
        // metodos para carteira
        virtual bool create(Wallet& wallet) = 0; // metodo virtual puro para criar carteira
        virtual bool read(Wallet* wallet) = 0; // metodo virtual puro para ler carteira
        virtual bool edit(Wallet& wallet) = 0; // metodo virtual puro para editar carteira
        virtual bool excludeWallet(Code& code) = 0; // metodo virtual puro para excluir carteira
        virtual bool listWallets() = 0; // metodo virtual puro para listar carteiras

        // metodos para ordem
        virtual bool create(Order& order) = 0; // metodo virtual puro para criar ordem
        virtual bool read(Order* order) = 0; // metodo virtual puro para ler ordem
        // ordens nao podem ser editadas!!
        virtual bool excludeOrder(Code& code) = 0; // metodo virtual puro para excluir ordem
        virtual bool listOrders(Code& code) = 0; // metodo virtual puro para listar ordens

        virtual ~ISI(){} // destruidor virtual padrao
};

#endif 