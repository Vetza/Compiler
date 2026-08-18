#include <string>
using namespace std;

#include "tokens.h"

token::token(tokens tokentype, string tokenvalue){
    this->tokentype = tokentype;
    this->tokenvalue = tokenvalue;
}

token::token(){
    tokentype = TOKEN_NONE;
    tokenvalue = "";
}

string token::getTokenvalue() const {return tokenvalue;}
tokens token::getTokentype() const {return tokentype;}
