#pragma once

#include <vector>
#include <cstddef>

#include "tokens.h"
#include "astnode.h"

class parser{
    public:
        int getPrecedence(tokens type);
        
        ASTNode* parseProgram(const std::vector<token>& tokensList);
            
        ASTNode* parsePrimary(token primaryToken, const std::vector<token>& tokensList, std::size_t& cursor);
        
        ASTNode* parseBinary(ASTNode* left, std::size_t& cursor, const std::vector<token>& tokensList, int currentPrecedence);
        
        ASTNode* parseExpression(const std::vector<token>& tokensList, std::size_t& cursor);
};
    