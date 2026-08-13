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
                cout<<"\nThis is a number";
                
                //cannot just return "number", as it is a numbernode object. new returns a pointer to the newly created object
                return new NumberNode(primaryToken.getTokenvalue());
                //BUT WITH NEW, WE ARE RESPONSIBLE FOR DESTROYING THIS OBJECT
            }
            if(primaryToken.getTokentype() == TOKEN_VARIABLE){
                cout<<"\nThis is a variable";
                return new VariableNode(primaryToken.getTokenvalue());
            }
//            if(primaryToken.getTokentype() == TOKEN_STRING){
//                cout<<"\nThis is a string";
//                return new StringNode(primaryToken.getTokenvalue());
//            }
            return nullptr;
        }
        
        ASTNode* parseBinary(token primaryToken, ASTNode* left, ASTNode* right){
            if (primaryToken.getTokentype() == TOKEN_PLUS){
                cout<<"\nPlus symbol";
                return new BinaryNode(primaryToken.getTokenvalue(), left, right);
            }
            if (primaryToken.getTokentype() == TOKEN_MINUS){
                cout<<"\nMinus symbol";
                return new BinaryNode(primaryToken.getTokenvalue(), left, right);
            }
            if (primaryToken.getTokentype() == TOKEN_MULTIPLICATION){
                cout<<"\nMultiplication symbol";
                return new BinaryNode(primaryToken.getTokenvalue(), left, right);
            }
            if (primaryToken.getTokentype() == TOKEN_DIVISION){
                cout<<"\nDivision symbol";
                return new BinaryNode(primaryToken.getTokenvalue(), left, right);
            }
            return nullptr;
        }
        
        //pass a reference to the original cursor
        //must return the root node
        ASTNode* parseExpression(vector<token> tokensList, size_t& cursor){
            ASTNode* left = nullptr;
            ASTNode* right = nullptr;
            ASTNode* root = nullptr;
            token binaryToken;
            token currentToken = tokensList[cursor];
            while ((cursor < tokensList.size()) && (currentToken.getTokentype() != TOKEN_SEMICOLON)){
                if ((currentToken.getTokentype() == TOKEN_VARIABLE) || (currentToken.getTokentype() == TOKEN_NUMBER) || (currentToken.getTokentype() == TOKEN_STRING)){
                    if (left == nullptr){
                        left = parsePrimary(currentToken);
                    } else{
                        right = parsePrimary(currentToken);
                    }
                } else{
                    binaryToken = currentToken;
                }
                cout<<"\nEUREKA "<<currentToken.getTokenvalue();
                cursor++;
                if (cursor < tokensList.size()){
                    currentToken = tokensList[cursor];
                } else{
                    break;
                }
            }
            root = parseBinary(binaryToken, left, right);
            return root;
        }
};
    