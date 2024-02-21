//
// Created by leny on 08.02.24.
//

#include "Lexer.h"

void Lexer::tokenize(std::vector<Token>& tokens, const std::string& line) {
    char current;
    int currentPos = 0;
    int startPos;
    std::string temp;

    while (currentPos < line.length()) {
        current = line[currentPos];
        startPos = currentPos;

        if (current == ' ' || current == '\n') {
            currentPos++;
            temp = current;
            tokens.emplace_back(Token::WHITESPACE, temp, startPos, currentPos, line);

        } else if (isdigit(current)) {
            temp.clear();

            do {
                temp += line[currentPos];
                currentPos++;
            } while (isdigit(line[currentPos]) || line[currentPos] == '.');

            tokens.emplace_back(Token::NUMBER, temp, startPos, currentPos, line);

        } else if (isalpha(current)) {
            temp.clear();

            do {
                temp += line[currentPos];
                currentPos++;
            } while (isalpha(line[currentPos]));

            if (std::binary_search(std::begin(keywords), std::end(keywords), temp)) {
                tokens.emplace_back(Token::KEYWORD, temp, startPos, currentPos, line);
                return;
            }

            tokens.emplace_back(Token::ALPHA, temp, startPos, currentPos, line);

        }
    }

    tokens.emplace_back(Token::EOF_, "", startPos, currentPos);
}