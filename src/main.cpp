#include <stdio.h>
#include <string>
#include <iostream>

#include "lexer.cpp"

using namespace std;

int main() {
    lexer mylexer;
    vector<token> finalvectorlist = mylexer.lexerinput("10 - aU 84  + 'THIS IS A TEST OF THE QUOTATION SYSTEM'  (1 * ARGENTINA 98 / 4)");
    cout<<"\nList of Tokens \n";
    for (size_t i = 0; i < finalvectorlist.size(); i++) {
        cout << "Token type: " << finalvectorlist[i].getTokentype() << " Token value: " << finalvectorlist[i].getTokenvalue() << endl;
    }
	return 0;
}

