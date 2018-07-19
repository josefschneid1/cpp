#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    constexpr int pi = 3.1415; //constexpr symbolic constant at compile time
    constexpr int c = 299792458;
    constexpr int a = pi - 5;
    cout << "Bitte geben sie eine Zahl ein:\n";
    int n;
    cin >> n;
    const int d = n;//const can't be changed after init
    
    vector<int> v = {1,2,3,4};
    vector<int> vi(6); // 6 ints mit 0
    vector<string> vs(4);//4 string mit ""
    for(int x : v)
    {
        cout << x << ", ";
    }
    cout << '\n';
    
    cout << "Bitte geben sie getrennt von whitespace Temperaturen ein:\n";
    vector<double> temps;
    for(double t; cin>>t;)
    {
        temps.push_back(t);
    }
    
    double sum = 0;
    for(double t : temps)
    {
        sum+= t;
    }
    cout << "Average temp = " << sum/temps.size() << '\n';
    
    
}
