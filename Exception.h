//
// Created by user on 12/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <iostream>
#include <string>
#include <exception>

const int FILEFORMATERRORMESSAGELEN = 44;
class DeckFileNotFound : public std::exception{
public:
    const char* what() const noexcept { return "Deck File Error: File not found\n";}
};

class DeckFileFormatError : public std::exception{
    int m_line;
public:
    DeckFileFormatError(int line) : m_line(line) {};
    const char* what() const noexcept
    {
        int temp = m_line;
        int numLen=0;
        while(temp){
            temp/=10;
            numLen++;
        }
        char* message = new char(FILEFORMATERRORMESSAGELEN+numLen+1);
        message="Deck File Error: File format error in line ";
        int currentDigit=numLen;
        while(currentDigit){
            temp = m_line;
            for(int i=0; i<currentDigit-1;i++){
                temp/=10;
            }
            for(int i=0; i<numLen-1-currentDigit;i++){
                temp%=10;
            }
            message[FILEFORMATERRORMESSAGELEN-currentDigit-1] = '0' + temp;
            currentDigit--;
        }
        message[FILEFORMATERRORMESSAGELEN+numLen-1]='\n';
        message[FILEFORMATERRORMESSAGELEN+numLen]='\0';
        return message;
    }
};

class DeckFileInvalidSize : public std::exception{
public:
    const char* what() const noexcept { return "Deck File Error: Deck size is invalid\n";}
};

#endif //EX4_EXCEPTION_H
