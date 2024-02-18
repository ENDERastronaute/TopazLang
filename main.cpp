#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <memory>
#include <atomic>
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
    std::atomic<float> lexingProgress(0);
    uintmax_t lexingTotal = std::filesystem::file_size(source);

    std::thread progressbar(Console::progressBar, std::ref(lexingProgress), std::ref());

    while (std::getline(file, line)) {
        Lexer::tokenize(tokens);
    }
}
