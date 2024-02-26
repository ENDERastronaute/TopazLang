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
            tokens.emplace_back(Token::WHITESPACE, temp, startPos, currentPos - 1, line);
            temp = "";

        } else if (isdigit(current)) {
            temp.clear();

            do {
                temp += line[currentPos];
                currentPos++;
            } while (isdigit(line[currentPos]) || line[currentPos] == '.');

            tokens.emplace_back(Token::NUMBER, temp, startPos, currentPos - 1, line);
            temp = "";

        } else if (isalpha(current)) {
            temp.clear();

            do {
                temp += line[currentPos];
                currentPos++;
            } while (isalpha(line[currentPos]));

            if (keywords[temp]) {
                tokens.emplace_back(Token::KEYWORD, temp, startPos, currentPos - 1, line);

                temp = "";
                return;
            }

            tokens.emplace_back(Token::ALPHA, temp, startPos, currentPos - 1, line);
            temp = "";

        }
        else if (current == '+') {
            currentPos++;

            if (line[currentPos] == '+') {
                currentPos++;
                tokens.emplace_back(Token::INC, "++", startPos, currentPos - 1, line);
                return;
            }

            else if (line[currentPos] == '=') {
                currentPos++;
                tokens.emplace_back(Token::ADQ, "+=", startPos, currentPos - 1, line);
                return;
            }

            tokens.emplace_back(Token::ADD, "+", startPos, currentPos - 1, line);
        }
        else if (current == '-') {
            currentPos++;

            if (line[currentPos] == '-') {
                currentPos++;
                tokens.emplace_back(Token::DEC, "--", startPos, currentPos - 1, line);
                return;
            }
            else if (line[currentPos] == '=') {
                currentPos++;
                tokens.emplace_back(Token::SUQ, "-=", startPos, currentPos - 1, line);
                return;
            }

            tokens.emplace_back(Token::SUB, "-", startPos, currentPos - 1, line);
        }
        else if (current == '*') {
            currentPos++;

            if (line[currentPos] == '=') {
                currentPos++;
                tokens.emplace_back(Token::MUQ, "*=", startPos, currentPos - 1, line);
                return;
            }
            else if (line[currentPos] == '*') {
                currentPos++;

                if (line[currentPos] == '=') {
                    currentPos++;
                    tokens.emplace_back(Token::SQQ, "**=", startPos, currentPos - 1, line);
                    return;
                }

                tokens.emplace_back(Token::SQR, "**", startPos, currentPos - 1, line);
                return;
            }

            tokens.emplace_back(Token::MLT, "*", startPos, currentPos - 1, line);
        }
        else if (current == '/') {
            currentPos++;

            if (line[currentPos] == '/') {
                do {
                    currentPos++;
                }
                while (line[currentPos] != '\n');
                return;
            }
            else if (line[currentPos] == '*') {
                do {
                    currentPos++;
                }
                while (line[currentPos] != '/' && line[++currentPos] != '*');
                return;
            }
            else if (line[currentPos] == '=') {
                currentPos++;
                tokens.emplace_back(Token::DIQ, "/=", startPos, currentPos - 1, line);
                return;
            }

            tokens.emplace_back(Token::DIV, "/", startPos, currentPos - 1, line);
        }
        else if (current == '%') {
            currentPos++;

            if (line[currentPos] == '=') {
                currentPos++;
                tokens.emplace_back(Token::MOQ, "%=", startPos, currentPos - 1, line);
                return;
            }

            tokens.emplace_back(Token::MOD, "%", startPos, currentPos - 1, line);
        }

    }

    tokens.emplace_back(Token::EOF_, "", startPos, currentPos);
}
