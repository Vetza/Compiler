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

string token::getTokenvalue(){return tokenvalue;}
tokens token::getTokentype(){return tokentype;}
