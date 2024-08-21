#include <iostream>
using namespace std;
#include <string>
#include <map>


int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	string s = s1 + s2;
	map <char, int>  m1;
	for (int i = 0; i < s.size(); i++)
	{
		m1[s[i]]++;
	}
	for (int i = 0; i < s3.size(); i++)
	{
		m1[s3[i]]--;
		
	}
	for (auto i : m1)
	{
		if (i.second != 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}


