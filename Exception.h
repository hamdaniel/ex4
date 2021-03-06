#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

class DeckFileNotFound : public std::exception
{

public:

    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
    int m_line;
    std::string m_message;
public:
    explicit DeckFileFormatError(int line) : std::exception(), m_line(line)
    {
        m_message = "Deck File Error: File format error in line " + std::to_string(m_line);
    }
    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

class DeckFileInvalidSize : public std::exception{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

class InvalidInput : public std::exception{
public:
    const char* what() const noexcept override
    {
        return "Received input is invalid";
    }
};

#endif //EX4_EXCEPTION_H
