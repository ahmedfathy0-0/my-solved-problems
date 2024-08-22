#include <iostream>
#include <string>
using namespace std;

int main (){
    string s;
    cin >> s;
    int a = s.find("AB");
    int b = s.find("BA");

    if(b ==-1 || a == -1){
        cout << "NO";
        return 0;
    }
    if (b != a+1 && a != b+1){
        cout << "YES";
        return 0;
    }
    else {
        cout << "NO";
        return 0;
    }
}