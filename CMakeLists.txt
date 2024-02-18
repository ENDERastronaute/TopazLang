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
        ConfigManager.cpp
        headers/ConfigManager.h
        FileManager.cpp
        headers/FileManager.h
        Console.cpp
        headers/Console.h
)

target_include_directories(TopazLang PUBLIC headers)
