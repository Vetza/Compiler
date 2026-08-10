#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum tokens{
    //Identifiers
    TOKEN_VARIABLE,
    //Symbols
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_SEMICOLON,
    TOKEN_EQUALITY,
    //literals
    TOKEN_NUMBER,
    TOKEN_STRING
};

class token{
    private:
        tokens tokentype;
        string tokenvalue;
    public:
        token(tokens tokentype, string tokenvalue){
            this->tokentype = tokentype;
            this->tokenvalue = tokenvalue;
        }
        
        string getTokenvalue(){return tokenvalue;}
        tokens getTokentype(){return tokentype;}
};

class lexer{
    public:
        void lexerinput(string source_code){
            int cursor = 0;
                        
            //Iterate through the source code string
            while (cursor < source_code.size()){
//                cout << "\n" << cursor;
                
                char currentCharacter = source_code[cursor]; //A single element of a C++ string is a char not another string

                //Characters have numeric character codes; in ASCII-compatible encodings, '0' through '9' have consecutive values, allowing this range check.
                if (currentCharacter >='0' && currentCharacter <= '9'){
                    string final_number = "";
                    
                    while (currentCharacter >='0' && currentCharacter <= '9'){
                        string currentCharacterString(1,currentCharacter);
                        
                        cout << "\nNumber spotted: " << currentCharacterString; 
                        final_number += currentCharacterString;
                        
                        cursor ++;
                        currentCharacter = source_code[cursor];
                    }
                    cout << "\n" << final_number;
                    //CREATE TOKEN OBJECT ONCE NUMBER STRING CREATED AT END
                    token createdToken = token(TOKEN_NUMBER, final_number);
                    cout<<"\n Token type" << createdToken.getTokentype();
                    cout<<"\n Token value" << createdToken.getTokenvalue();

                }
                else{
                    cout << "\nFailed to spot number";
                }
                cursor ++;
                cout << "\n Increment to " << cursor;
            }
            
//            while currentToken != NULL{
//                
//            }
// HOW DO WE ITERATE THROUGH THE SOURCE CODE, WITH A CURSOR TO FOLLOW OUR MOVEMENT AND KEEP TRACK OF WHERE WE ARE??
/*
 * we need to look ahead for example if there is an =, if followed by >, then it is not an equal symbol. For now we will iterate one at a time thought
*/            
        }
};

int main()
{
//	string str = "My name is Muhammed";
//    vector<string> words = split(str, ' ');
    
//    for (int i = 0; i < words.size(); i++){
//        cout << words[i] << endl; 
//    }
    lexer mylexer;
    mylexer.lexerinput("Go3455555      89tt,47s90");
    
	return 0;
}

