#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int nnames, nlogs;
    cin >> nnames >> nlogs;
    unordered_map<string, string> names;

    for(int i=0; i<nnames; i++){
        string name, ip;
        cin >> name >> ip;
        names[ip] = name;
    }
    string output={};
    for (int i =0 ;i< nlogs; i++){
        string log, ip;
        cin >> log >> ip;
        output += log + " " + ip +" "+ " #" + names[ ip.substr(0, ip.size() - 1)] + "\n";
    }
    cout << output;
    return 0;

}