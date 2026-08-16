#include <stdio.h>
#include <string>
#include <iostream>

#include "lexer.h"
#include "tokens.h"

#include "parser.cpp"

using namespace std;

int main() {
    lexer mylexer;
    vector<token> finalvectorlist = mylexer.lexerinput("4 * 5 * 8");
    cout<<"\nList of Tokens \n";
    for (size_t i = 0; i < finalvectorlist.size(); i++) {
        cout << "Token type: " << finalvectorlist[i].getTokentype() << " Token value: " << finalvectorlist[i].getTokenvalue() << endl;
    }
    
    parser myparser;
    myparser.parseProgram(finalvectorlist);
    
	return 0;
}

