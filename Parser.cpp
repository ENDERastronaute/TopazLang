//
// Created by leny on 08.02.24.
//

#include "Parser.h"

Parser::Parser(std::vector<Token> &tokens, std::vector<std::unique_ptr<ASTNode>> &ast) : tokens(tokens), ast(ast) {
    currentIndex = 0;
    currentToken = &tokens[currentIndex];
}

void Parser::parse() {
    do {
    } while (expect(Token::EOF_));
}

void Parser::advance(const bool whitespace) {
    if (whitespace) {
        currentIndex++;
        currentToken = &tokens[currentIndex];

        return;
    }

    do {
        currentIndex++;

    } while (tokens[currentIndex].type == Token::WHITESPACE);

    currentToken = &tokens[currentIndex];
}

bool Parser::expect(const Token::Type type, const bool further) {
    if (further) {
        return tokens[currentIndex + 1].type == type;
    }

    return currentToken->type != type;
}
