#include <vector>
#include <iostream>

#include "tokens.h"

using namespace std;

//===================================================================================================================================================
//base class
class ASTNode{
    public:
        //pointer to point to any node
        ASTNode* left;
        ASTNode* right;
        string value;
        
        ASTNode(string value){
            this->value = value;
            left = nullptr; 
            right = nullptr;
        }
        
        virtual ~ASTNode() = default;
};

//derived class
class NumberNode: public ASTNode{
    public:
        //"Before constructing the NumberNode, construct its ASTNode base-class portion using value."
        NumberNode(string value):ASTNode(value){}
};

class VariableNode: public ASTNode{
    public:
        VariableNode(string value):ASTNode(value){}
};

class StringNode: public ASTNode{
    public:
        StringNode(string value):ASTNode(value){}
};

class BinaryNode: public ASTNode{
    public:
        //in this case value will be the '+' or '-' and other symbols
        BinaryNode(string value, ASTNode* left, ASTNode* right):ASTNode(value){
            this->left = left;
            this->right = right;
        }
};

//===================================================================================================================================================
class parser{
    public:
        int getPrecedence(tokens type){
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
        
        void parseProgram(vector<token> tokensList){
            size_t cursor = 0;
            size_t vectorSize = tokensList.size();
            cout<<"\nSize of vector list: "<< vectorSize;
            while (cursor < vectorSize){
                tokens currentToken = tokensList[cursor].getTokentype();
                
                if ((currentToken == TOKEN_VARIABLE) || (currentToken == TOKEN_NUMBER)){
                        ASTNode* root = parseExpression(tokensList, cursor);
                        cout<< "\nRoot Value: "<<root->value << " Root left: "<<root->left->value<<" Root right: "<<root->right->value;   
                }
                cursor ++;
            }
        }
        // identify primary expressions- which are expressions that can exist on their own without needing a binary operator
// THESE ARE THE EXPRESSIONS THAT WILL LIE ON EITHER SIDE OF THE BINARY OPERATOR! PARENTHESIS COUNT HERE!!        
        ASTNode* parsePrimary(token primaryToken){
// maybe use switches here instead            
            if(primaryToken.getTokentype() == TOKEN_NUMBER){
         
                
                //cannot just return "number", as it is a numbernode object. new returns a pointer to the newly created object
                return new NumberNode(primaryToken.getTokenvalue());
                //BUT WITH NEW, WE ARE RESPONSIBLE FOR DESTROYING THIS OBJECT
            }
            if(primaryToken.getTokentype() == TOKEN_VARIABLE){
           
                return new VariableNode(primaryToken.getTokenvalue());
            }
//            if(primaryToken.getTokentype() == TOKEN_STRING){
//                cout<<"\nThis is a string";
//                return new StringNode(primaryToken.getTokenvalue());
//            }
            return nullptr;
        }
        
        ASTNode* parseBinary(ASTNode* left, size_t& cursor, vector<token> tokensList, int currentPrecedence){
            cout << "\nENTER parseBinary: cursor=" << cursor << " token=" << tokensList[cursor].getTokenvalue();
            ASTNode* tempRight = nullptr;
            token currentOperator = tokensList[cursor];
            token currentToken = tokensList[cursor];
//            int currentPrecedence = getPrecedence(currentToken.getTokentype());

            cursor ++;
            if (cursor < tokensList.size()){
                currentToken = tokensList[cursor];
            }
            
            while ((cursor < tokensList.size()) && (currentToken.getTokentype() != TOKEN_SEMICOLON)){
                //if binary
                cout<<"\nOld Precedence: "<<currentPrecedence << " Token being checked: "<< currentToken.getTokenvalue();
                if ((currentToken.getTokentype() == TOKEN_PLUS) || (currentToken.getTokentype() == TOKEN_MINUS) || (currentToken.getTokentype() == TOKEN_MULTIPLICATION) || (currentToken.getTokentype() == TOKEN_DIVISION)){
                    int newPrecedence = getPrecedence(currentToken.getTokentype());
                    cout<<"\nNew Precedence: "<<newPrecedence;
                    if (newPrecedence>currentPrecedence){
//                        currentPrecedence = newPrecedence;
                        cout << "\nBEFORE RECURSION";
                        cout << "\nRECURSING WITH LEFT = "
     << (tempRight ? tempRight->value : "NULL");
                        tempRight = parseBinary(tempRight, cursor, tokensList, newPrecedence);
                        cout << "\nAFTER RECURSION";
                    }else{break;}   
                }
                //if primary
                else if ((currentToken.getTokentype() == TOKEN_VARIABLE) || (currentToken.getTokentype() == TOKEN_NUMBER) || (currentToken.getTokentype() == TOKEN_STRING)){
                    tempRight = parsePrimary(tokensList[cursor]);
                    cursor ++;
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
        ASTNode* parseExpression(vector<token> tokensList, size_t& cursor){
            ASTNode* left = nullptr;
            ASTNode* ASTtree = nullptr;
            token currentToken = tokensList[cursor];
            while ((cursor < tokensList.size()) && (currentToken.getTokentype() != TOKEN_SEMICOLON)){
                if ((currentToken.getTokentype() == TOKEN_VARIABLE) || (currentToken.getTokentype() == TOKEN_NUMBER) || (currentToken.getTokentype() == TOKEN_STRING)){
                    left = parsePrimary(currentToken);
                    cursor++;
                    if (cursor < tokensList.size()){
                        currentToken = tokensList[cursor];
                    } else{break;}
                } else if ((currentToken.getTokentype() == TOKEN_PLUS) || (currentToken.getTokentype() == TOKEN_MINUS) || (currentToken.getTokentype() == TOKEN_MULTIPLICATION) || (currentToken.getTokentype() == TOKEN_DIVISION)){
                    ASTtree = parseBinary(left, cursor, tokensList, getPrecedence(currentToken.getTokentype()));
                    cursor++;
        
                     if (cursor < tokensList.size()){
                        currentToken = tokensList[cursor];
                    }
                }
       
            }
            return ASTtree;
        }
};
    