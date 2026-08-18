#pragma once

#include <string>

class ASTNode{
    public:
        //pointer to point to any node
        ASTNode* left;
        ASTNode* right;
        std::string value;
        
        ASTNode(std::string value);       
        virtual ~ASTNode() = default;
};

//derived class
class NumberNode: public ASTNode{
    public:
        //"Before constructing the NumberNode, construct its ASTNode base-class portion using value."
        NumberNode(std::string value);
};

class VariableNode: public ASTNode{
    public:
        VariableNode(std::string value);
};

class StringNode: public ASTNode{
    public:
        StringNode(std::string value);
};

class BinaryNode: public ASTNode{
    public:
        //in this case value will be the '+' or '-' and other symbols
        BinaryNode(std::string value, ASTNode* left, ASTNode* right);
};
