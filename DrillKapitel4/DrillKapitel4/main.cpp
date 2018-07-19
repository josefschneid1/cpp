#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr double m_in_cm = 100;
constexpr double in_in_cm = 2.54;
constexpr double ft_in_inch = 12;

double convert_to_m(double n, string unit)
{
    if(unit.compare("cm")==0)
    {
        n/=m_in_cm;
    }
    else if(unit.compare("in")==0)
    {
        n=n*in_in_cm/m_in_cm;
    }else if(unit.compare("ft")==0)
    {
        n= n * ft_in_inch * in_in_cm/m_in_cm;
    }
    return n;
}

int main()
{
    /*double a;
     double b;
     while(cin>>a>>b)
     {
     if(a!=b)
     {
     if(a<b)
     {
     cout << "the smaller value is " << a << " and the larger value is " << b << '\n';
     }
     else
     {
     cout << "the smaller value is " << b << " and the larger value is " << a << '\n';
     
     }
     if(abs(a-b) < 0.01)
     {
     cout << "the numbers are almost equal\n";
     }
     }
     else
     {
     cout << "the numbers are equal\n";
     }
     
     }*/
    
    bool first = true;
    double largest = 0;
    string largest_unit;
    double smallest = 0;
    string smallest_unit;
    string temp_unit;
    int count = 0;
    double sum = 0; // in m
    vector<double> values; // in m
    for(double n; cin >> n >> temp_unit;)
    {
        if(temp_unit.compare("m")==0 || temp_unit.compare("cm")==0 || temp_unit.compare("in")==0 ||temp_unit.compare("ft")==0 || first)
        {
            cout << "Value entered: " << n << " " << temp_unit << '\n';
            if(first)
            {
                largest = n;
                largest_unit = temp_unit;
                smallest = n;
                smallest_unit = temp_unit;
                first = false;
            }else{
                if(convert_to_m(n,temp_unit) > convert_to_m(largest, largest_unit))
                {
                    largest = n;
                    largest_unit = temp_unit;
                    cout << "the largest so far\n";
                }else if(convert_to_m(n,temp_unit) < convert_to_m(smallest, smallest_unit))
                {
                    smallest = n;
                    smallest_unit = temp_unit;
                    cout << "the smallest so far\n";
                }
            }
            ++count;
            sum+= convert_to_m(n, temp_unit);
            values.push_back(convert_to_m(n, temp_unit));
        }else{
            cout << "Unit is not allowed!\n";
        }
    }
    cout << "The smallest value was : " << smallest << " " << smallest_unit << " and the largest value  was : " << largest << " " << largest_unit <<"\nNumbers entered: " << count << " Sum of numbers in m: " << sum << '\n';
    sort(values.begin(), values.end());
    for(double d : values)
    {
        cout << d << " ";
    }
    cout << '\n';
    
    
    return 0;
}

