#include <iostream>
#include <string>
using namespace std;

int main (){
    string s;
    cin >> s;
    int ab1 = s.find("AB");
    int ba1 = s.find("BA", ab1 + 2);
    int ba2 = s.find("BA");
    int ab2 = s.find("AB", ba2 + 2);
   

    if((ab1 != -1 && ba1 != -1) || (ab2 != -1 && ba2 != -1)){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;

}