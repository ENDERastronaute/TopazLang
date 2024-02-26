//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_LEXER_H
#define TOPAZLANG_LEXER_H

#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Token.h"

struct Lexer {
    static void tokenize(std::vector<Token>&, const std::string&);

private:
    static inline std::unordered_map<std::string, int> keywords {
        {"import", 1},
        {"export", 1},
        {"function", 1},
        {"class", 1}
    };
};


#endif //TOPAZLANG_LEXER_H
