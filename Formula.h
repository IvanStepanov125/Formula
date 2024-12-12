#include <iostream>
#include "Stack.h"


class Formula{
private:
    std::string _expressioni;
    Stack<std::string> _codeStack;
public:
    Formula(std::string exp);
    bool CheckBrackets(){
        size_t open_count=0;
        size_t close_count =0;
        if (_expressioni.find_first_of(')')<_expressioni.find_first_of('(') )
            return 0;
        for(size_t i=0; i<_expressioni.length();i++){
            if(_expressioni[i]=='(')
                open_count++;
            if(_expressioni[i]==')'){
                close_count++;
                if(close_count<=open_count){
                    open_count--;
                    close_count--;
                }
                else
                return 0;
            }
            if(open_count!=0 && close_count!=0)
                return 0;
            
        }
    }
    bool CheckFormula();
    void EnderYariableValues();
    std::string BuildPosttix();
    double Calculate();
};