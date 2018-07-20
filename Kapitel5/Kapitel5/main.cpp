#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

double div_number(double a, double b)
{
    if(b==0)
        throw invalid_argument("Teilen durch 0");
    return a/b;
}

int fib(int n)
{
    if(n==0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

double root_of_quad_eq(double a, double b, double c)
{
    double determ = b*b-4*a*c;
    if(determ<0)
        throw invalid_argument("Determinante kleiner null");
    return sqrt(determ);
}



int main()
{
    /*vector<int> vec = {1,2,3,4,5};
    try {
        cout << vec.at(5) << '\n';
    } catch (out_of_range e) {
        cout << "Out of range\n";
    }
    
    double a = 5;
    double b = 0;
    try {
        double c = div_number(a, b);
    } catch (invalid_argument e) {
        cout << e.what() << '\n';
    }*/
    
    //cout << fib(5) << '\n';
    
    /*int fib1 = 0;
    int fib2 = 1;
    int n;
    cin >> n;
    while(n>0)
    {
        int temp = fib1;
        fib1 = fib2;
        fib2 = fib2 + temp;
        n--;
        
    }
    cout << fib1 << '\n';
    */
    
    /*double a,b,c;
    cin >> a >> b >> c;
    double sol1,sol2;
    try{
        sol1 = (-b+root_of_quad_eq(a, b, c))/(2*a);
        sol2 = (-b-root_of_quad_eq(a, b, c))/(2*a);
        cout << "x1= " << sol1 << " x2= " << sol2 << '\n';
    }catch(invalid_argument e)
    {
        cout << e.what() << '\n';
    }*/
    
    //Bulls and Cows
    vector<int> numbers = {1,2,3,4};
    vector<int> input;
    bool finished = false;
    int n = 0;
    cout<< "Lets play the game bulls and cows\n";
   
    while(!finished)
    {
        cout << "Enter 4 digits: ";
        cin >>n;
        if(n<1000 || n >= 10000)
        {
            cout << "You did not enter 4 digits!\n";
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }
        while(input.size()<4)
        {
            int first_digit = n / pow(10,numbers.size()-input.size()-1);
            n = n - (first_digit *pow(10,numbers.size()-input.size()-1));
            input.push_back(first_digit);
        }
        int cows = 0;
        int bulls = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            for(int j = 0; j < input.size(); j++)
            {
                if(numbers[i]==input[j]){
                    cows++;
                    if(i==j)
                    {
                        bulls++;
                    }
                }
            }
        }
        if(bulls==4){
            cout << "Korrekt!\n";
            finished = true;
        }else{
            cout << "Bulls= " << bulls << " Cows = " << cows << '\n';
        }
        input.clear();
    }
    
    return 0;
}
