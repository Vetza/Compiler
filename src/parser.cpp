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
                cout<< "\ncursor position "<<cursor;
                
                switch(currentToken){
                    case TOKEN_VARIABLE:
                        cout<<" Found a variable";
                        parsePrimary(tokensList[cursor]);
                        break; 
                    case TOKEN_OPEN_PAREN:
                        cout<<" Found an open bracket";
                        break; 
                    case TOKEN_CLOSE_PAREN:
                        cout<<" Found a closing bracket";
                        break; 
                    case TOKEN_SEMICOLON:
                        cout<<" Found a semicolon";
                        break; 
                    case TOKEN_EQUALITY:
                        cout<<" Found an equal sign";
                        break; 
                    case TOKEN_PLUS:{
                        cout<<" Found a plus sign";
                        ASTNode* leftNode = parsePrimary(tokensList[cursor-1]);
                        ASTNode* rightNode = parsePrimary(tokensList[cursor+1]);
                        ASTNode* node = parseBinary(tokensList[cursor], leftNode, rightNode);
                        cout<< "\nNode Value: "<<node->value << " Node left: "<<node->left->value<<" Node right: "<<node->right->value;
                        break;                         
                    }
                      case TOKEN_MINUS:{
                        cout<<" Found a minus sign";
                        ASTNode* leftNode = parsePrimary(tokensList[cursor-1]);
                        ASTNode* rightNode = parsePrimary(tokensList[cursor+1]);
                        ASTNode* node = parseBinary(tokensList[cursor], leftNode, rightNode);
                        cout<< "\nNode Value: "<<node->value << " Node left: "<<node->left->value<<" Node right: "<<node->right->value;
                        break;                          
                      }
                      case TOKEN_MULTIPLICATION:{
                        cout<<" Found a multiplication sign";
                        ASTNode* leftNode = parsePrimary(tokensList[cursor-1]);
                        ASTNode* rightNode = parsePrimary(tokensList[cursor+1]);
                        ASTNode* node = parseBinary(tokensList[cursor], leftNode, rightNode);
                        cout<< "\nNode Value: "<<node->value << " Node left: "<<node->left->value<<" Node right: "<<node->right->value;
                        break;                           
                      }
                      case TOKEN_DIVISION:{
                        cout<<" Found a division sign";
                        ASTNode* leftNode = parsePrimary(tokensList[cursor-1]);
                        ASTNode* rightNode = parsePrimary(tokensList[cursor+1]);
                        ASTNode* node = parseBinary(tokensList[cursor], leftNode, rightNode);
                        cout<< "\nNode Value: "<<node->value << " Node left: "<<node->left->value<<" Node right: "<<node->right->value;
                        break;                           
                      }
                      case TOKEN_NUMBER:{
                        cout<<" Found a number";
                        ASTNode* node = parsePrimary(tokensList[cursor]);
                        cout<< "\nNode Value: "<<node->value;
                        break;                         
                    }
                      case TOKEN_STRING:
                        cout<<" Found a string";
                        parsePrimary(tokensList[cursor]);
                       break; 
                }
                cursor ++;
            }
        }
        // identify primary expressions- which are expressions that can exist on their own without needing a binary operator
        ASTNode* parsePrimary(token primaryToken){
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
            if(primaryToken.getTokentype() == TOKEN_STRING){
                cout<<"\nThis is a string";
                return new StringNode(primaryToken.getTokenvalue());
            }
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
};
    