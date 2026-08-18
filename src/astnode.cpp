#include "astnode.h"
#include <string>

ASTNode::ASTNode(std::string value){
    this->value = value;
    left = nullptr; 
    right = nullptr;
}

//derived class

NumberNode::NumberNode(std::string value):ASTNode(value){}

VariableNode::VariableNode(std::string value):ASTNode(value){}

StringNode::StringNode(std::string value):ASTNode(value){}

//in this case value will be the '+' or '-' and other symbols
BinaryNode::BinaryNode(std::string value, ASTNode* left, ASTNode* right):ASTNode(value){
    this->left = left;
    this->right = right;
}
