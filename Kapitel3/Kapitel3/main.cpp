#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Bitte gib deinen Vornamen und Alter ein:\n";
    string vorname;
    int alter;
    cin >> vorname >> alter;
    cout << "Hallo, " << vorname << ", " << alter << '\n';
    string nachname;
    cout << "Bitte gib deinen Nachnamen ein:\n";
    cin >>nachname;
    string name = vorname + ' ' + nachname;
    cout << "Hallo, " << name << '\n';
    if(vorname < nachname)
        cout << "Dein Vorname kommt im Alphabet vor deinem Nachnamen\n";
    char number{127}; // {} checks if the conversion works only literals
    int a = 128;
    
    
    return 0;
}
