//
// Created by user on 12/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

class DeckFileNotFound : public std::exception{
public:
    const std::string what() const { return "Deck File Error: File not found\n";}
};

class DeckFileFormatError : public std::exception{
    int m_line;
public:
    DeckFileFormatError(int line) : m_line(line) {};
    const std::string what() const { return "Deck File Error: File format error in line \n" << m_line;}
};

class DeckFileInvalidSize : public std::exception{
public:
    const std::string what() const { return "Deck File Error: Deck size is invalid\n";}
};

#endif //EX4_EXCEPTION_H
