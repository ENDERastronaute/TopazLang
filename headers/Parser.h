//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_PARSER_H
#define TOPAZLANG_PARSER_H

#include <vector>
#include <string>
#include <memory>
#include "AST.h"
#include "Token.h"

struct Parser {
    explicit Parser(std::vector<Token>&, std::vector<std::unique_ptr<ASTNode>>&);

    void parse();

private:
    std::vector<std::unique_ptr<ASTNode>>& ast;
    std::vector<Token>& tokens;
    Token* currentToken = new Token();
    int currentIndex;

    void advance(bool = false);
    bool expect(Token::Type, bool = false);
};


#endif //TOPAZLANG_PARSER_H
