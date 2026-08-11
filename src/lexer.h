#pragma once
#include <string>
#include <vector>

#include "tokens.h"

using namespace std;

class lexer{
    public:
        vector<token> lexerinput(string source_code);
};