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
    Lexer(std::vector<Token>&, const std::string&);

    void tokenize();

private:
    static inline constexpr std::string keywords[3] = {
            "import",
            "export",
            "function"
    };

    static void makeNumber();
    static void makeAlpha();
};


#endif //TOPAZLANG_LEXER_H
