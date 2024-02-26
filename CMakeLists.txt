cmake_minimum_required(VERSION 3.27)
project(TopazLang)

set(CMAKE_CXX_STANDARD 23)

add_executable(TopazLang main.cpp
        Parser.cpp
        headers/Parser.h
        Lexer.cpp
        headers/Lexer.h
        Token.cpp
        headers/Token.h
        AST.cpp
        headers/AST.h
        Console.cpp
        headers/Console.h
        Manager.cpp
        headers/Manager.h
        SymbolTable.cpp
        headers/SymbolTable.h
)

target_include_directories(TopazLang PUBLIC headers)
