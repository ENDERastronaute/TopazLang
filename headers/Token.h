//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_TOKEN_H
#define TOPAZLANG_TOKEN_H

#include <string>


struct Token {
    enum Type {
        WHITESPACE,
        NUMBER,
        KEYWORD,
        ALPHA,
        ADD,
        SUB,
        MLT,
        DIV,
        MOD,
        INC,
        DEC,
        ADQ,
        SUQ,
        MUQ,
        SQR,
        SQQ,
        DIQ,
        MOQ,
        GRT,
        LST,
        GRQ,
        LSQ,
        EOF_
    };

    Type type;
    std::string value;
    int startPos;
    int endPos;
    std::string line;
};


#endif //TOPAZLANG_TOKEN_H
