#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <algorithm>
using namespace std;

/*
    Term->Zahl|Term Operator Term|(Term)
    Operator->+|-|/|*
*/

struct Token{
    char kind;
    double value;
};

bool isValidOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    else
        return false;
}

bool isValidBracket(char c)
{
    if(c==')'||c=='(')
        return true;
    else
        return false;
}

vector<Token> inputToTokenStream(istream& input)
{
    vector<Token> tokenStream;
    string eingabe;
    getline(input, eingabe);
    int stack = 0;
    while(!eingabe.empty())
    {
        if(isnumber(eingabe.at(0)))//Zahl
        {
            int index = 0;
            while(index < eingabe.size() && isnumber(eingabe.at(index)))
                index++;
            tokenStream.push_back(Token{'n',stod(eingabe.substr(0,index))});
            eingabe = eingabe.substr(index);
            
        }else if(tokenStream.size()>0
                 && (tokenStream[tokenStream.size()-1].kind==')' || tokenStream[tokenStream.size()-1].kind=='n')
                 &&isValidOperator(eingabe.at(0)))//Operator
        {
            tokenStream.push_back(Token{eingabe.at(0)});
            eingabe = eingabe.substr(1);
            
        }else if(isValidBracket(eingabe.at(0)))//Klammer
        {
            if(eingabe.at(0)== '(')
                stack++;
            else{
                if(stack < 1 || isValidOperator(tokenStream[tokenStream.size()-1].kind))
                {
                    throw invalid_argument("MathError");
                }else
                    stack--;
                
            }
            tokenStream.push_back(Token{eingabe.at(0)});
            eingabe = eingabe.substr(1);
            
        }else if(eingabe.at(0)==' ')//Leerzeichen
        {
            eingabe = eingabe.substr(1);
        }else{//Nicht gültiges Zeichen
            throw invalid_argument("MathError");
        }
        
    }
    if(stack>0 || isValidOperator(tokenStream[tokenStream.size()-1].kind))
        throw invalid_argument("MathError");
    
    return tokenStream;
}

void printTokenStream(ostream& ausgabe, vector<Token> stream)
{
    for(Token t : stream)
    {
        if(t.kind=='n')
        {
            ausgabe << t.value << ", ";
        }else{
            ausgabe << t.kind << ", ";
        }
    }
    ausgabe << '\n';
}

int main()
{
    try {
        vector<Token>tokenStream = inputToTokenStream(cin);
        printTokenStream(cout, tokenStream);
    } catch (invalid_argument e) {
        cout << e.what() << '\n';
    }
    
    return 0;
}


