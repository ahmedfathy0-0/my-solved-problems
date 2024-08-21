/*

 ___  __ __  ___  ___  ___
|  _>|  \  \| . \<_  >|_  |
| <__|     ||  _/ / /  / /
`___/|_|_|_||_|  <___>/_/


*/






#include <iostream>
int LinearSearch(int arr[], int n, int x)//called sequential search too
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Function to search x in the given array
void sentinelSearch(int arr[], int n, int key)
{
	// Last element of the array
	int last = arr[n - 1];
	// Element to be searched is
	// placed at the last index
	arr[n - 1] = key;
	int i = 0;
	while (arr[i] != key)
		i++;
	// Put the last element back
	arr[n - 1] = last;
	if ((i < n - 1) || (arr[n - 1] == key))
		std::cout << key << " is present at index " << i;
	else
		std::cout << "Element Not found";
}





int ProbabilitySearch(int list[], int last, int target) {
	// Find target in the list
	int Iocn = -1;
	for (int i = 0; i <= last; ++i) {
		if (list[i] == target) {
			// Target found
			Iocn = i; // Storing index of the element containing target
			if (i > 0) {
				// If target is not already the first element, move it up one location
				std::swap(list[i], list[i - 1]);
				// that line make the probability of the target to be found first higher
			}
			return Iocn; // Return true, indicating target found
		}
	}
	// Target not found
	return Iocn; // Return false, indicating target not found
}

int main() {
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = LinearSearch(arr, n, x);
	(result == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Probability Search\n";
	int list[] = { 2, 3, 4, 10, 40 };
	int last = sizeof(list) / sizeof(list[0]) - 1;
	int target = 10;
	int result2 = ProbabilitySearch(list, last, target);
	(result2 == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result2;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Second time to search for the same target " << std::endl;
	std::cout << std::endl;

	int result3 = ProbabilitySearch(list, last, target);
	(result3 == -1) ? std::cout << "Element is not present in array"
		: std::cout << "Element is present at index " << result3;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Sentinel Search\n";
	int arr2[] = { 2, 3, 4, 10, 40 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int x2 = 10;
	sentinelSearch(arr2, n2, x2);
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}