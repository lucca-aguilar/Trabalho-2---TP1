#ifndef SERVICOS_HPP_INCLUDED
#define SERVICOS_HPP_INCLUDED

#include <map>
#include "interfaces.hpp"

using namespace std;

// implementacao do modulo de servico de conta
class MSC : public ISC {
    private:
        map<string, Account> accounts; // criacao de map para armazenar as contas
    public:
        bool create(Account& account) override; // override sobrescreve metodo virtual puro
        bool read(Account* account) override;
        bool edit(Account& account) override;
        bool exclude(CPF& cpf) override;
};

// implementacao do modulo de servico de autenticacao
class MSA : public ISA {
    private:
        ISC* accountService; // ponteiro para o servico de conta para verificacao das credenciais
    public:
        MSA(ISC* accountService) : accountService(accountService){} // genuinamente nao entendi muito bem isso aqui
        bool autenticate(CPF& cpf, Password& password) override;
};

// implementacao do modulo de servico de investimento
class MSI : public ISI {
    private:
        map<string, Wallet> wallets; // cria mapa para armazenar carteiras
        map<string, Order> orders; // cria mapa para armazenar ordens
    public:
        // metodos para carteira
        bool create(Wallet& wallet) override;
        bool read(Wallet* wallet) override;
        bool edit(Wallet& wallet) override;
        bool excludeWallet(Code& code) override;
        bool listWallets() override;

        // metodos para ordem
        bool create(Order& order) override;
        bool read(Order* order) override;
        bool excludeOrder(Code& code) override;
        bool listOrders() override;
};

#endif