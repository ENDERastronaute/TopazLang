#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <thread>
#include "Console.h"
#include "AST.h"
#include "Lexer.h"
#include "Token.h"

int main() {
    std::string source;
    std::vector<Token> tokens;
    std::vector<std::unique_ptr<ASTNode>> ast;

    std::ifstream file(source);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file.");
    }

    std::string line;

    while (std::getline(file, line)) {
        Lexer::tokenize(tokens, line);
    }
}
