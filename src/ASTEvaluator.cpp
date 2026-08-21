#include "astnode.h"
#include <string>
#include <iostream>
using namespace std;
class ASTEvaluator{
    //RUNTIME/SEMANTIC ERRORS BELONG IN THE EVALUATOR HERE!
    public:
        int evaluate(ASTNode* node){
            NumberNode* numberNode= dynamic_cast<NumberNode*>(node);
            if (numberNode){
                int number = stoi(numberNode->value);
                return number;
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