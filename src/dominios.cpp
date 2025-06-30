#include "dominios.hpp"

void Code::validate(string input_code){
    regex rgx("[0-9]*");

    if(!regex_match(input_code, rgx)){
        throw invalid_argument("Codigo invalido: Caracter(es) invalido(s).\n");
    }

    int limit = 5;
    if(input_code.length() != limit){
        throw invalid_argument("Codigo invalido: Tamanho invalido.\n");
    }
}

void CPF::validate(string input_cpf){
    if(input_cpf.size() != SIZE) {
        throw invalid_argument("CPF invalido: Tamanho invalido.\n");
    }

    regex pattern("^\\d{11}$");
    if (!regex_match(input_cpf, pattern)) {
        throw invalid_argument("CPF invalido: Caracter(es) invalido(s).\n");
    }        

    bool all_digits_equal = true;
    for(int i = 1; i < SIZE; i++) {
        if(input_cpf[i] != input_cpf[0]) {
            all_digits_equal = false;
            break;
        }
    }
    if (all_digits_equal) {
        throw invalid_argument("CPF invalido: O CPF deve conter digitos diferentes.\n");
    }

    int sum = 0;
    for(int i = 0; i < 9; i++) {
        sum += (input_cpf[i] - '0') * (10 - i);
    }

    int first_digit = (sum * 10) % 11;
    if(first_digit == 10 || first_digit == 11) {
        first_digit = 0;
    }

    if(first_digit != (input_cpf[9] - '0')) {
        throw invalid_argument("CPF invalido: CPF inexistente.\n");
    }

    sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += (input_cpf[i] - '0') * (11 - i);
    }

    int second_digit = (sum * 10) % 11;
    if(second_digit == 10 || second_digit == 11){
        second_digit = 0;
    }

    if(second_digit != (input_cpf[10] - '0')) {
        throw invalid_argument("CPF invalido: CPF inexistente.\n");
    }
}

void Date::validate(int input_day, int input_month, int input_year){
    if (input_day < 1 || input_day > 31 || input_month == 2 && input_day > 29 || input_month == 2 && input_day == 29 && input_year % 4 != 0 || (input_month == 4 || input_month == 6 || input_month == 9 || input_month == 11 && input_day > 30)){
        throw invalid_argument("Data invalida: Dia invalido.\n");
    }
    if (input_year < 0 || input_year > 2025){
        throw invalid_argument("Data invalida: Ano invalido.\n");
    }
    if (input_month < 1 || input_month > 12){
        throw invalid_argument("Data invalida: Mes invalido.\n");
    }
}

void Money::validate(double input_money) {
    if (input_money < MIN_MONEY || input_money > MAX_MONEY) {
        throw invalid_argument("Dinheiro invalido: O valor inserido esta fora dos limites.\n");
    }
}

void Deal::validate(string input_deal){
    regex rgx("[a-zA-Z0-9 ]*");

    if(input_deal.length() > max_length){
        throw invalid_argument("Negociacao invalida: Tamanho invalido.\n");
    }

    if(!regex_match(input_deal, rgx)){
        throw invalid_argument("Negociacao invalida: Caracter(es) invalido(s).\n");
    }
}

void Name::validate(string input_name){
    regex rgx("[a-zA-Z0-9 ]*");
    if(input_name.length() > max_length){
        throw invalid_argument("Nome invalido: Tamanho invalido.\n");
    }
    if(!regex_match(input_name, rgx)){
        throw invalid_argument("Nome invalido: Caracter(es) invalido(s).\n");
    }
    for(int i = 0; i < input_name.length()-1; i++){
        if(input_name[i] == ' ' && input_name[i+1] == ' '){
            throw invalid_argument("Nome invalido: Espacos consecutivos invalidos.\n");
            break;
        }
    }
}

void Password::validate(string input_password) {
    if (input_password.size() != PASSWORD_SIZE) {
        throw invalid_argument("Tamanho invalido.\n");
    }

    bool conditions[4] = {0};

    for (int current_char = 0; current_char < 6; current_char++) {
        for (int iterator = 0; iterator < current_char; iterator++) {
            if (input_password[current_char] == input_password[iterator]) {
                throw invalid_argument("Caracter duplicado.\n");
            }
            
        }

        bool invalid_character_check = false;
        if (input_password[current_char] >= '0' && input_password[current_char] <= '9') {
            conditions[DIGIT] = true;
        } else if (input_password[current_char] >= '#' && input_password[current_char] <= '&') {
            conditions[SPECIAL_CHARACTER] = true;
        } else if (input_password[current_char] >= 'a' && input_password[current_char] <= 'z') {
            conditions[LOWER] = true;
        } else if (input_password[current_char] >= 'A' && input_password[current_char] <= 'Z') {
            conditions[UPPER] = true;
        } else {
            invalid_character_check = true;
        }

        if (invalid_character_check) {
            throw invalid_argument("Caracter(es) invalido(s).\n");
        }
        
    }

    for (int condition_check = 0; condition_check < 4; condition_check++)
    {
        if (conditions[condition_check] == false) {
            switch (condition_check) {
                case DIGIT : 
                    throw invalid_argument("A senha deve conter ao menos um digito numerico.\n");
                    break;
                case SPECIAL_CHARACTER :
                    throw invalid_argument("A senha deve conter ao menos um caracter especial.\n");
                    break;
                case LOWER :
                    throw invalid_argument("A senha deve conter ao menos uma letra minuscula.\n");
                    break;
                case UPPER :
                    throw invalid_argument("A senha deve conter ao menos uma letra maiuscula.\n");
                    break;
                default : 
                    throw invalid_argument("Erro desconhecido");
            }    
        }
    }
}

void Profile::validate(string input_profile){
    if (input_profile != CONSERVATIVE && input_profile != MODERATE && input_profile != AGGRESSIVE){
        throw invalid_argument("Perfil invalido: Tipo de investidor invalido\n"); 
    }
}

void Quantity::validate(string input_quantity){
    int maximum = 1000000;
    int minimum = 1;
    regex rgx ("[0-9]*");
    if(!regex_match(input_quantity, rgx)){
        throw invalid_argument("Quantidade invalida: Caracter(es) invalido(s).\n");
    }
    final_quantity = std::stoi(input_quantity);
    if(final_quantity < minimum || final_quantity > maximum){
        throw invalid_argument("Quantidade invalida: O valor inserido esta fora dos limites.");
    }
}