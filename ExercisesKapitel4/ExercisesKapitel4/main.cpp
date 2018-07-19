#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct solutions{
    double x1;
    double x2;
};

bool isPrime(int n)
{
    if(n==1)
    {
        return false;
    }
    for(int i = 2 ; i < n; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

solutions solve_quad_equation(double a, double b, double c)
{
    solutions s;
    s.x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
    s.x2 = (-b - sqrt(b*b-4*a*c))/(2*a);
    return s;
}



int main()
{
    /*vector<double> numbers;
    cout << "Geben sie die Zahlen nacheinander ein:\n";
    for(double n; cin>>n;)
    {
        numbers.push_back(n);
    }
    sort(numbers.begin(),numbers.end());
    double median;
    if(numbers.size()%2==0)
    {
        median = (numbers[numbers.size()/2] + numbers[numbers.size()/2-1])/2;
        
    }else{
        median = numbers[numbers.size()/2];
    }
    
    cout << "Der Median ist: " << median << '\n';
    */
   /* vector<double> strecken = {1,3,4,2,10};//strecken zwischen zwei benachbarten Städten
    double sum = 0;
    for(double d : strecken)
    {
        sum+=d;
    }
    cout << "Die summe aller Strecken ist " << sum << '\n';
    double smallest_distance = strecken[0];
    double greatest_distance = smallest_distance;
    for(double d : strecken)
    {
        if(d < smallest_distance)
        {
            smallest_distance = d;
        }
        else if(d > greatest_distance)
        {
            greatest_distance = d;
        }
    }
    cout << "Der größte Abstand ist: " << greatest_distance << " und der kleinste Abstand ist " << smallest_distance << '\n';
    */
   /* vector<string> numbers_as_strings = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    string s;
    cin >> s;
    int n;
    for(int i = 0; i < numbers_as_strings.size(); i++)
    {
        if(numbers_as_strings[i].compare(s)==0)
        {
            n = i;
        }
    }
    cout << n << '\n';
    */
    
    /*vector<int> primes;
    for(int i = 1; i < 100; i++)
    {
        if(isPrime(i))
            primes.push_back(i);
    }
    for(int i : primes)
        cout << i << " ";
    cout << '\n';
    */
    
    /*vector<int> primes;
    constexpr int n = 200;
    vector<bool> vec(n-1,true);//[2,100]
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i])
        {
            primes.push_back(i+2);
            for(int j = 2; (i+2)*j<=n;j++)
            {
                vec[(i+2)*j-2]= false;
            }
        }
    }
    for(int i : primes)
    {
        cout << i << " ";
    }
    cout << '\n';
    */
    
    double a,b,c;
    cin >> a >> b >> c;
    solutions s = solve_quad_equation(a, b, c);
    cout << "x1= " << s.x1 << " x2= " << s.x2 << '\n';
    
    
    return 0;
}
