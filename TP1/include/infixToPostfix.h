#include <iostream>

using namespace std;

class InfixToPostfix {
    public:
        string CleanSpaces(string str);
        bool IsOperator(char caracter);
        int Priority(char op);
        int CheckPriority(char first, char second);
        string ConvertToPostfix(string formula, string valoracao);
};