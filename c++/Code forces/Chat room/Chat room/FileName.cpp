#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isHello(const string& s) {
	string target = "hello";
	queue <int> pos;
	int j = 0;
	bool flag = true;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == target[j]) {
			if (s[i] == 'h' && flag) {
				flag = false;
			}
			if (s[i] == 'h') {
				pos.push(i);
			}
			++j;
			if (j == target.size()) {
				return true;
			}
		}
		if (i == s.size() + 1 && pos.size() != 0) {
			i = pos.front();
			pos.pop();
			j = 0;
		}
	}
	return false;
}


int main() {
	string input;
	cin >> input;
	if (isHello(input)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}