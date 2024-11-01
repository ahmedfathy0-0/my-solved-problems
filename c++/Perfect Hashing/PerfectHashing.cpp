#include <iostream>
#include <vector>
using namespace std;
//Perfect hashing using two levels of hashing
// that function is mentioned as a graph in the Lecture slides

void hash_PerfectHashing(vector<vector<int>>& arr, int key) {
	int a = 3, b = 42, prime = 101;// Constants for the perfect hashing ,they can be any values
	int outer_hash = ((a * key + b) % prime) % arr.size(); // First hash function
	int inner_hash = ((arr[outer_hash][1] * key + arr[outer_hash][2]) % prime) % arr[outer_hash][0]; // Second hash function
	arr[outer_hash][inner_hash+3] = key;
}


int main() {
	vector<vector<int>> arr = { {}, {},{},{},{},{},{}, {},{} };
	arr[0].resize(4, 0);
	arr[2].resize(12, 0);
	arr[5].resize(4, 0);
	arr[7].resize(19, 0);
	arr[0] = { 1,0,0,0 };
	arr[2] = {9, 10, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	arr[5] = { 1, 0, 0, 0 };
	arr[7] = { 16, 23,88,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
	
	hash_PerfectHashing(arr, 10);
	hash_PerfectHashing(arr, 60);
	hash_PerfectHashing(arr, 72);
	hash_PerfectHashing(arr, 75);
	hash_PerfectHashing(arr, 70);
	hash_PerfectHashing(arr, 40);
	hash_PerfectHashing(arr, 52);
	hash_PerfectHashing(arr, 22);
	hash_PerfectHashing(arr, 37);
	//print the hash table
	for (int i = 0; i < arr.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
