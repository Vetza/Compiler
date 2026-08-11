#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "lexer.h"
#include "tokens.h"

vector<token> lexer::lexerinput(string source_code){
    vector<token> tokens;
    int cursor = 0;
    
    int source_code_size = source_code.size();
    //Iterate through the source code string
    while (cursor < source_code_size){
        char currentCharacter = source_code[cursor]; //A single element of a C++ string is a char not another string

        //Characters have numeric character codes; in ASCII-compatible encodings, '0' through '9' have consecutive values, allowing this range check.
        if (isspace(currentCharacter)){
            while (isspace(currentCharacter)){
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
                final_number += currentCharacterString;
                
                cursor ++;
                if (cursor < source_code_size){
                    currentCharacter = source_code[cursor]; 
                } else{break;}
            }
            //CREATE TOKEN OBJECT ONCE NUMBER STRING CREATED AT END
            token createdToken = token(TOKEN_NUMBER, final_number);
            tokens.push_back(createdToken);

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
            token createdToken = token(TOKEN_VARIABLE, final_variable);
            tokens.push_back(createdToken);
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
            token createdToken = token(TOKEN_STRING, quotation);
            tokens.push_back(createdToken);                 
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
            token createdToken = token(TOKEN_STRING, quotation);
            tokens.push_back(createdToken); 
            cursor++;               
        }
        else{
            switch (currentCharacter){
                // brackets issue- WHEN TO BEGIN, WHEN TO END!!
                case '(':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_OPEN_PAREN, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;
                }
                case ')':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_CLOSE_PAREN, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;
                }
                case ';':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_SEMICOLON, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;                            
                }
                case '=':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_EQUALITY, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;                            
                }
                case '+':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_PLUS, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;                            
                }
                case '-':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_MINUS, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;                            
                }
                case '*':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_MULTIPLICATION, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;
                    break;                            
                }
                case '/':{
                    string currentCharacterString(1,currentCharacter);
                    token createdToken = token(TOKEN_DIVISION, currentCharacterString);
                    tokens.push_back(createdToken);
                    cursor ++;                      
                }
            }
        }
        
    }
    return tokens;     
}
