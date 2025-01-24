#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;



class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        set<string> result;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i!=j && checkPattern(words[j],words[i]))
                {
                    result.insert(words[i]);
                    //break;
                }
            }
        }
        vector<string> res;
        for(auto it=result.begin();it!=result.end();it++)
        {
            res.push_back(*it);
        }
        return res;
        
    }
    void computePattern(vector<int>& p,string pattern)
    {
        for(int q=1;q<pattern.size();q++)
        {
            int k=p[q-1];
            while(k>0 && pattern[k]!=pattern[q])
            {
                k=p[k-1];
            }
            if(pattern[k]==pattern[q])
            {
                k++;
            }
            p[q]=k;
        }
    }
    bool checkPattern(string text,string pattern)
    {
        vector<int> p(pattern.size(),0);
        computePattern(p,pattern);
        int q=0;
        for(int i=0;i<text.size();i++)
        {
            while(q>0 && pattern[q]!=text[i])
            {
                q=p[q-1];
            }
            if(pattern[q]==text[i])
            {
                q++;
            }
            if(q==pattern.size())
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"mass","as","hero","superhero"};
    vector<string> result = s.stringMatching(words);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}