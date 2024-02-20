//
// Created by leny on 08.02.24.
//

#include "Lexer.h"

Lexer::Lexer(std::vector<Token> &tokens, const std::string& line) : tokens(tokens), line(line) {}

void Lexer::tokenize() {
    while (currentPos < line.length())
    {
        current = line[currentPos];

        if (isdigit(current))
        {
            makeNumber();
        }
        else if (isalpha(current))
        {
            makeAlpha();
        }

    }
}

void Lexer::makeNumber() {
    temp.clear();

    do {
        temp += line[currentPos];
        currentPos++;
    } while (isdigit(line[currentPos]) || line[currentPos] == '.');

    tokens.emplace_back(Token::NUMBER, temp);
}

void Lexer::makeAlpha() {
    temp.clear();

    do {
        temp += line[currentPos];
        currentPos++;
    } while (isalpha(line[currentPos]));

    if (std::binary_search(std::begin(keywords), std::end(keywords), temp)) {
        tokens.emplace_back(Token::KEYWORD, temp);
        return;
    }

    tokens.emplace_back(Token::ALPHA, temp);
}