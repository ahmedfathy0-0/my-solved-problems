#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;



int main()
{

    vector<long long > input(3);
    for (long long  i = 0; i < 3; i++)
    {
        cin >> input[i];
    }
    vector<long long> ans(3,0);
    ans[2]=INT_MAX;
    vector<long long> prev(3,0);
    if(input[0]>=input[2]) {
        for (int i = input[2]; i <= input[0]; i += input[2]) {
            prev[1] = i / input[2]; //B
            int num = input[0] - i;
            int remain = num % input[1];
            prev[0] = (num - remain) / input[1]; //A
            prev[2] = remain;//Remain
            if (prev[2] < ans[2]) { //Remain
                ans = prev;
            } else if (prev[2] == ans[2]) {
                if (prev[1] > ans[1]) {//B
                    ans = prev;
                }
            }
        }
    }
    else
    {
       if(input[0]<input[1]){
           ans[0]=0; //A
           ans[1]=0; //B
           ans[2]=input[0]; // Remain
       }
         else {
           ans[1] = 0;//B
           ans[0] = input[0] / input[1];//A
           ans[2] = input[0] % input[1];//Remain
       }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    return 0;
}
