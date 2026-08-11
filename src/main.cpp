#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum tokens{
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
            
            int source_code_size = source_code.size();
            //Iterate through the source code string
            while (cursor < source_code_size){
//                cout << "\n" << cursor;
                
                char currentCharacter = source_code[cursor]; //A single element of a C++ string is a char not another string

                //Characters have numeric character codes; in ASCII-compatible encodings, '0' through '9' have consecutive values, allowing this range check.
                if (isspace(currentCharacter)){
                    while (isspace(currentCharacter)){
                        cout<<"\nEMPTY SPACE, SKIPPING";
                        cursor ++;
                        if (cursor < source_code_size){
                            currentCharacter = source_code[cursor]; 
                        } else{break;}
                    }
                }
                else if (currentCharacter >='0' && currentCharacter <= '9'){
                    string final_number = "";
                    
                    while (currentCharacter >='0' && currentCharacter <= '9'){
                        string currentCharacterString(1, currentCharacter);
                        
                        cout << "\nNumber spotted: " << currentCharacterString; 
                        final_number += currentCharacterString;
                        
                        cursor ++;
                        if (cursor < source_code_size){
                            currentCharacter = source_code[cursor]; 
                        } else{break;}
                    }
                    cout << "\n" << final_number;
                    //CREATE TOKEN OBJECT ONCE NUMBER STRING CREATED AT END
                    token createdToken = token(TOKEN_NUMBER, final_number);
                    cout<<"\n Token type " << createdToken.getTokentype();
                    cout<<"\n Token value " << createdToken.getTokenvalue();

                }
                else if ((currentCharacter >= 'A' && currentCharacter <= 'Z') || (currentCharacter >= 'a' && currentCharacter <= 'z')) {
                    string final_variable = "";
                    while((currentCharacter >= 'A' && currentCharacter <= 'Z') || (currentCharacter >= 'a' && currentCharacter <= 'z')){
                        string currentCharacterString(1, currentCharacter);
                        final_variable += currentCharacterString;
                        
                        cursor++;
                        if (cursor < source_code_size){
                            currentCharacter = source_code[cursor]; 
                        } else{break;}
                    }
                    cout<<"\nFinal variable: "<< final_variable;
                    token createdToken = token(TOKEN_VARIABLE, final_variable);
                    cout<<"\n Token type " << createdToken.getTokentype();
                    cout<<"\n Token value " << createdToken.getTokenvalue();
                }
                else if (currentCharacter == '"'){
                    string quotation = "";
                    cursor ++;
                    if (cursor < source_code_size){
                        currentCharacter = source_code[cursor]; 
                    } else{break;}
                    while ((currentCharacter != '"')){
                        quotation += currentCharacter;
                        cursor++;
                        if (cursor < source_code_size){
                            currentCharacter = source_code[cursor]; 
                        } else{break;}
                    }
                    cout<<"\nFinal QUOTATION: "<< quotation;
                    token createdToken = token(TOKEN_STRING, quotation);
                    cout<<"\n Token type " << createdToken.getTokentype();
                    cout<<"\n Token value " << createdToken.getTokenvalue();                    
                    cursor++;                  
                }   
                else if (currentCharacter == '\''){
                    string quotation = "";
                    cursor ++;
                    if (cursor < source_code_size){
                        currentCharacter = source_code[cursor]; 
                    } else{break;}
                    while (currentCharacter != '\''){
                        quotation += currentCharacter;
                        cursor++;
                        if (cursor < source_code_size){
                            currentCharacter = source_code[cursor]; 
                        } else{break;}
                    }
                    cout<<"\nFinal QUOTATION: "<< quotation;
                    token createdToken = token(TOKEN_STRING, quotation);
                    cout<<"\n Token type " << createdToken.getTokentype();
                    cout<<"\n Token value " << createdToken.getTokenvalue();  
                    cursor++;               
                }
                else{
                    cout << "\nFailed to spot number, checking symbols";
                    switch (currentCharacter){
                        // brackets issue- WHEN TO BEGIN, WHEN TO END!!
                        case '(':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_OPEN_PAREN, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;
                        }
                        case ')':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_CLOSE_PAREN, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;
                        }
                        case ';':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_SEMICOLON, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;                            
                        }
                        case '=':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_EQUALITY, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;                            
                        }
                        case '+':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_PLUS, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;                            
                        }
                        case '-':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_MINUS, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;                            
                        }
                        case '*':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_MULTIPLICATION, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;
                            break;                            
                        }
                        case '/':{
                            string currentCharacterString(1,currentCharacter);
                            token createdToken = token(TOKEN_DIVISION, currentCharacterString);
                            cout<<"\n Token type " << createdToken.getTokentype();
                            cout<<"\n Token value " << createdToken.getTokenvalue();
                            cursor ++;                      
                        }
                    }
                }
            }
            
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
    mylexer.lexerinput("10 - aU 84  + 'THIS IS A TEST OF THE QUOTATION SYSTEM'  (1 * ARGENTINA 98 / 4)");
    
	return 0;
}

