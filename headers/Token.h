//
// Created by leny on 08.02.24.
//

#ifndef TOPAZLANG_TOKEN_H
#define TOPAZLANG_TOKEN_H


class Token {
public:
    enum Type {
        WHITESPACE,
        EOF_
    };

    Token();

    Type type;
};


#endif //TOPAZLANG_TOKEN_H
