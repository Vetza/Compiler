#include "astnode.h"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class ASTEvaluator{
    //RUNTIME/SEMANTIC ERRORS BELONG IN THE EVALUATOR HERE!
    private:
        //for testing, add in variable x
        unordered_map<string, int> symbolMap = { {"x", 4} };
        
    public:
        int evaluate(ASTNode* node){
            NumberNode* numberNode= dynamic_cast<NumberNode*>(node);
            if (numberNode){
                int number = stoi(numberNode->value);
                return number;
            }

            VariableNode* variableNode = dynamic_cast<VariableNode*>(node);
            if (variableNode){
                cout<<"\nVariable spotted!";
                //lookup value in symbol table, dont create it here, then return the value!S
                auto iterator = symbolMap.find(variableNode->value);
                if (iterator != symbolMap.end()){
                    int variableVal = iterator->second;
                    return variableVal;
                }
                else{
                    cout<<"\nUndefined Variable: "<<variableNode->value;
                }
            }
            
            BinaryNode* binaryNode = dynamic_cast<BinaryNode*>(node);
            if (binaryNode){
                int left = evaluate(node->left);
                int right = evaluate(node->right);
                
                if (binaryNode->value == "+"){
                    return (left + right);
                } 
                if (binaryNode->value == "-"){
                    return (left - right);
                } 
                if (binaryNode->value == "*"){
                    return (left * right);
                } 
                if (binaryNode->value == "/"){
                    if (right != 0){
                        return (left / right);
                    } else{
                        cout<<"\nDivision by zero error!";
                    }
                }                 
            }
            
            return 0;             
        }
};