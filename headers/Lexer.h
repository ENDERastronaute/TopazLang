//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_LEXER_H
#define TOPAZLANG_LEXER_H

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Token.h"

struct Lexer {
    static void tokenize(std::vector<Token>&, const std::string&);

private:
    static inline constexpr std::string keywords[3] = {
            "import",
            "export",
            "function"
    };
};


#endif //TOPAZLANG_LEXER_H
