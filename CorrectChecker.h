#pragma once
#include "Stack.h"

class CorrectChecker{
private:
    Stack<char> _brackets;
public:
    bool CheckBrackets(const std::string& tmp);
};