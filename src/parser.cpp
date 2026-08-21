#include <iostream>

#include "parser.h"

using namespace std;

int parser::getPrecedence(tokens type){
    switch(type){
        case TOKEN_PLUS:
        case TOKEN_MINUS:
            return 20;
        case TOKEN_MULTIPLICATION:
        case TOKEN_DIVISION:
            return 40;

        default:
            return -1;
    }
}
        
ASTNode* parser::parseProgram(const vector<token>& tokensList){
    size_t cursor = 0;
    size_t vectorSize = tokensList.size();
    ASTNode* root = nullptr;
    while (cursor < vectorSize){
        tokens currentToken = tokensList[cursor].getTokentype();
        if ((currentToken == TOKEN_VARIABLE) || (currentToken == TOKEN_NUMBER) || (currentToken == TOKEN_OPEN_PAREN)){
                root = parseExpression(tokensList, cursor);
                cout<< "\nRoot Value: "<<root->value;
                if(root->left){
                    cout<< " Root left: "<<root->left->value;
                }
                if(root->right){
                    cout<< " Root right: "<<root->right->value;
                }
        }
        cursor ++;
    }
    return root;
}

// identify primary expressions- which are expressions that can exist on their own without needing a binary operator
// THESE ARE THE EXPRESSIONS THAT WILL LIE ON EITHER SIDE OF THE BINARY OPERATOR! PARENTHESIS COUNT HERE!!        
ASTNode* parser::parsePrimary(token primaryToken, const vector<token>& tokensList, size_t& cursor){
    //GET RID OF PRIMARY TOKEN USE TOKENSLIST AND CURSORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
// maybe use switches here instead            
    if(primaryToken.getTokentype() == TOKEN_NUMBER){
        //cannot just return "number", as it is a numbernode object. new returns a pointer to the newly created object
        return new NumberNode(primaryToken.getTokenvalue());
        //BUT WITH NEW, WE ARE RESPONSIBLE FOR DESTROYING THIS OBJECT
    }
    if(primaryToken.getTokentype() == TOKEN_VARIABLE){
        return new VariableNode(primaryToken.getTokenvalue());
    }
    
    if(primaryToken.getTokentype() == TOKEN_OPEN_PAREN){
        cursor ++;
        if (cursor < tokensList.size()){
            primaryToken = tokensList[cursor];
        }        
        ASTNode* result = parseExpression(tokensList, cursor);
        
        if (cursor < tokensList.size() && tokensList[cursor].getTokentype() == TOKEN_CLOSE_PAREN){
            cursor++;
        }
        
        return result;
    }
//            if(primaryToken.getTokentype() == TOKEN_STRING){
//                cout<<"\nThis is a string";
//                return new StringNode(primaryToken.getTokenvalue());
//            }
    return nullptr;
}
        
ASTNode* parser::parseBinary(ASTNode* left, size_t& cursor, const vector<token>& tokensList, int currentPrecedence){
    ASTNode* tempRight = nullptr;
    token currentOperator = tokensList[cursor];
    token currentToken = tokensList[cursor];

    cursor ++;
    if (cursor < tokensList.size()){
        currentToken = tokensList[cursor];
    }
    while ((cursor < tokensList.size()) && (currentToken.getTokentype() != TOKEN_SEMICOLON) && (currentToken.getTokentype() != TOKEN_CLOSE_PAREN)){
        //if binary
        if ((currentToken.getTokentype() == TOKEN_PLUS) || (currentToken.getTokentype() == TOKEN_MINUS) || (currentToken.getTokentype() == TOKEN_MULTIPLICATION) || (currentToken.getTokentype() == TOKEN_DIVISION)){
            int newPrecedence = getPrecedence(currentToken.getTokentype());
            if (newPrecedence>currentPrecedence){
                tempRight = parseBinary(tempRight, cursor, tokensList, newPrecedence);
                if (cursor < tokensList.size()) {
                    currentToken = tokensList[cursor];
                }
            }else{break;}   
        }
        //if primary
        else if ((currentToken.getTokentype() == TOKEN_VARIABLE) || (currentToken.getTokentype() == TOKEN_NUMBER) || (currentToken.getTokentype() == TOKEN_STRING)){
            tempRight = parsePrimary(tokensList[cursor], tokensList, cursor);
            cursor ++;
            if (cursor < tokensList.size()){
            currentToken = tokensList[cursor];
            }
        }
        else if ((currentToken.getTokentype() == TOKEN_OPEN_PAREN)){
            tempRight = parsePrimary(currentToken, tokensList, cursor);

            if (cursor < tokensList.size()){
            currentToken = tokensList[cursor];
            }
        }
    }
    
    ASTNode* result = new BinaryNode(currentOperator.getTokenvalue(), left, tempRight);
    cout<<"\nResult value: "<<result->value << " Result left: "<< result->left->value << 
    " Result right: " << result->right->value;
    return result;
    
}
        
//pass a reference to the original cursor
//must return the root node
ASTNode* parser::parseExpression(const vector<token>& tokensList, size_t& cursor){
    ASTNode* left = nullptr;
    token currentToken = tokensList[cursor];
    while ((cursor < tokensList.size()) && (currentToken.getTokentype() != TOKEN_SEMICOLON) && (currentToken.getTokentype() != TOKEN_CLOSE_PAREN)){
        if ((currentToken.getTokentype() == TOKEN_VARIABLE) || (currentToken.getTokentype() == TOKEN_NUMBER) || (currentToken.getTokentype() == TOKEN_OPEN_PAREN)){
            
            left = parsePrimary(currentToken, tokensList, cursor);
            if (currentToken.getTokentype() != TOKEN_OPEN_PAREN){
                cursor ++;
            }
            if (cursor < tokensList.size()){
                currentToken = tokensList[cursor];
            } else{break;}
            
        } else if ((currentToken.getTokentype() == TOKEN_PLUS) || (currentToken.getTokentype() == TOKEN_MINUS) || (currentToken.getTokentype() == TOKEN_MULTIPLICATION) || (currentToken.getTokentype() == TOKEN_DIVISION)){
            left = parseBinary(left, cursor, tokensList, getPrecedence(currentToken.getTokentype()));
             if (cursor < tokensList.size()){
                currentToken = tokensList[cursor];
            }
        }
    }
    return left;
}
    