#include <stdio.h>
#include <string>
#include <iostream>

#include "lexer.h"
#include "tokens.h"
#include "parser.h"
#include "ASTEvaluator.cpp"

using namespace std;

int main() {
    lexer mylexer;
    ASTEvaluator evaluator;
    
    vector<token> finalvectorlist = mylexer.lexerinput("x + 4");
    cout<<"\nList of Tokens \n";
    for (size_t i = 0; i < finalvectorlist.size(); i++) {
        cout << "Token type: " << finalvectorlist[i].getTokentype() << " Token value: " << finalvectorlist[i].getTokenvalue() << endl;
    }
    
    parser myparser;
    ASTNode* parserNode = myparser.parseProgram(finalvectorlist);
    int result = evaluator.evaluate(parserNode); 
    cout << "\nFinal Result "<< result;
	return 0;
}

