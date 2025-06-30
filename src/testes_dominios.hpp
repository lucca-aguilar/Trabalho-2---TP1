#ifndef TESTES_DOMINIOS_HPP_INCLUDED
#define TESTES_DOMINIOS_HPP_INCLUDED

#include "dominios.hpp"

class TUProfile{
    private:
        static const string VALID_PROFILE_1;
        static const string VALID_PROFILE_2;
        static const string VALID_PROFILE_3;
        static const string INVALID_PROFILE;
        Profile *profile;
        int state; 
        void setUp(); 
        void tearDown(); 
        void validProfile(); 
        void invalidProfile();

    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();      
};

class TUName{
    private:
        const static string VALID_NAME;
        const static string INVALID_NAME_1;
        const static string INVALID_NAME_2;
        const static string INVALID_NAME_3;
        Name *name;
        int state;
        void setUp();
        void tearDown();
        void validName();
        void invalidName();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUMoney{
private:
    Money* money;
    const static double VALID_MONEY;
    const static double INVALID_MONEY;
    int state;
    void setUp();
    void tearDown();
    void validMoney();
    void invalidMoney();

public:
    static const int SUCCESS = 0;
    static const int FAILURE = -1;
    int run();
};

class TUDeal{
    private:
        Deal *deal;
        const static string VALID_DEAL;
        const static string INVALID_DEAL_1;
        const static string INVALID_DEAL_2;
        int state;
        void setUp();
        void tearDown();
        void validDeal();
        void invalidDeal();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUCPF {
    private:
        const static string VALID_CPF;
        const static string INVALID_CPF_1;
        const static string INVALID_CPF_2;
        const static string INVALID_CPF_3;
        const static string INVALID_CPF_4;
        CPF *cpf;
        int state;
        void setUp();
        void tearDown();
        void validCPF();
        void invalidCPF();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

class TUPassword {
    private:
        static const string VALID_PASSWORD;
        static const string INVALID_PASSWORD_WRONG_LENGTH;
        static const string INVALID_PASSWORD_INVALID_CHARACTER;
        static const string INVALID_PASSWORD_DUPE;
        static const string INVALID_PASSWORD_NO_UPPER;
        static const string INVALID_PASSWORD_NO_LOWER;
        static const string INVALID_PASSWORD_NO_DIGIT;
        static const string INVALID_PASSWORD_NO_SPECIAL;
        Password *password;
        int state;
        void setUp();
        void tearDown();
        void validPassword();
        void invalidPassword();
        void invalidPasswordTryCatch(const string);

    public:
        static const int SUCCESS = 0;
        static const int FAILURE = -1;
        int run();
};

class TUCode {
    private:
        const static string VALID_CODE;
        const static string INVALID_CODE_1;
        const static string INVALID_CODE_2;
        Code *code;
        int state;
        void setUp();
        void tearDown();
        void validCode();
        void invalidCode();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};
class TUQuantity {
    private:
        const static string VALID_QUANTITY;
        const static string INVALID_QUANTITY_1;
        const static string INVALID_QUANTITY_2;
        Quantity *quantity;
        int state;
        void setUp();
        void tearDown();
        void validQuantity();
        void invalidQuantity();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};
class TUDate {
    private:
        const static int VALID_DAY;
        const static int VALID_MONTH;
        const static int VALID_YEAR;
        const static int INVALID_DAY;
        const static int INVALID_MONTH;
        const static int INVALID_YEAR;
        Date *date;
        int state;
        void setUp();
        void tearDown();
        void validDate();
        void invalidDate();
    public:
        const static int SUCCESS = 0;
        const static int FAILURE = -1;
        int run();
};

#endif