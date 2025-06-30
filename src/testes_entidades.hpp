#ifndef TESTES_ENTIDADES_HPP_INCLUDED
#define TESTES_ENTIDADES_HPP_INCLUDED
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"

class TUOrder {
    private: 
        Order *order;
        Date *date;
        Money *money;
        Quantity *quantity;
        Code *code;
        Deal *deal;
        const static int VALID_MONEY;
        const static string VALID_QUANTITY;
        const static string VALID_DEAL;
        const static string VALID_CODE;
        const static int VALID_DAY;
        const static int VALID_MONTH ;
        const static int VALID_YEAR ;
        void setUp();
        void tearDown();
        void testCenario();
        int state;
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUWallet {
    private: 
        Wallet *wallet;
        Code *code;
        Name *name;
        Profile *profile;
        const static string VALID_CODE;
        const static string VALID_NAME;
        const static string VALID_PROFILE;
        void setUp();
        void tearDown();
        void testCenario();
        int state;
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUAccount {
    private: 
        Account *account;
        CPF *cpf;
        Name *name;
        Password *password;
        const static string VALID_CPF;
        const static string VALID_NAME;
        const static string VALID_PASSWORD;
        void setUp();
        void tearDown();
        void testCenario();
        int state;
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

#endif // TESTES_ENTIDADES_HPP_INCLUDED