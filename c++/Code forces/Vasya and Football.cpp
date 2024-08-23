#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
    string Th, Ta;
    cin >> Th >> Ta;
    int n;
    cin >> n;
    int time = 0;
    char team, card;
    int teammember;
    vector<int> team1(100, 0);
    vector<int> team2(100, 0);
    string output="";
    for (int i=0 ; i<n ;i++){
        cin>>time>>team>>teammember>>card;
        if(card =='y'){
            if(team == 'h'){
                  team1[teammember]++;
            }
            else{
                team2[teammember]++;
            }
        }
        else{
            if(team =='h'){
               if(team1[teammember]==1){
                   team1[teammember]++;
                }
                else{
                    team1[teammember]+=2;
                }
            }
            else{
                if(team2[teammember]==1){
                    team2[teammember]++;
                }
                else{
                    team2[teammember]+=2;
                }
            }
        }

        if(team == 'h' && team1[teammember]==2){
            output = output +  Th + " " + to_string(teammember) + " " + to_string(time) + "\n";
        }
        else if(team == 'a' && team2[teammember]==2){
            output = output +Ta + " " + to_string(teammember) + " " + to_string(time)+ "\n";
        }


    }
    cout<<output;
    return  0;

}