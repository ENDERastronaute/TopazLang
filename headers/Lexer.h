//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_LEXER_H
#define TOPAZLANG_LEXER_H

#include <vector>
#include <string>
#include <fstream>
#include "ConfigManager.h"
#include "Token.h"

struct Lexer {
    static void tokenize(std::vector<Token>&);
};


#endif //TOPAZLANG_LEXER_H
