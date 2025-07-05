// controladores.hpp

#ifndef CONTROLADORES_HPP_INCLUDED
#define CONTROLADORES_HPP_INCLUDED

#include "interfaces.hpp"

// declaracao do controlador de menu

class MAMenu : public IUMenu {
    private:
        IAA* ctrlAuth;
        IAC* ctrlAccount;
        IAI* ctrlInvestment;
    public:
        void setControlers(IAA* ctrlAuth, IAC* ctrlAccount, IAI* ctrlInvestment) {
            this->ctrlAuth = ctrlAuth;
            this->ctrlAccount = ctrlAccount;
            this->ctrlInvestment = ctrlInvestment;
        }
        void execute() override;
};


// declaracao do controlador de autenticacao

class MAA : public IAA {
    private:
        ISA* serviceAuth; // ponteiro para a interface de servico
    public:
        // metodo que conecta controlador ao servico de autenticacao
        void setAuthenticationService(ISA* service) {
            this->serviceAuth = service;
        }
        bool autenticate(CPF* cpf) override;
};

// declaracao do controlador de conta

class MAC : public IAC {
    private:
        ISC* accountService; // ponteiro para a interface de servico
    public:
        // metodo que conecta controlador ao servico de autenticacao
        void setAccountService(ISC* service) {
            this->accountService = service;
        }
        void create() override;
        void execute(const CPF& cpf) override;
};

// declaracao do controlador de investimento

class MAI : public IAI {
    private:
        ISI* investmentService; // ponteiro para a interface de servico
    public:
        // metodo que conecta controlador ao servico de autenticacao
        void setInvestmentService(ISI* service) {
            this->investmentService = service;
        }
        void execute(Account& account) override;
};

#endif // CONTROLADORES_HPP_INCLUDED