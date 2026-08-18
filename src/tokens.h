#pragma once

#include <string>

enum tokens{
    TOKEN_NONE,
    //Identifiers
    TOKEN_VARIABLE,
    //Symbols
    //MAYBE ADD EXPONENTS??
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_SEMICOLON,
    TOKEN_EQUALITY,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLICATION,
    TOKEN_DIVISION,
    //literals
    TOKEN_NUMBER,
    TOKEN_STRING
};

class token{
    private:
        tokens tokentype;
        std::string tokenvalue;
    public:
        token(tokens tokentype, std::string tokenvalue);
        token();
        
        std::string getTokenvalue() const;
        tokens getTokentype() const;
};