#include <iostream>
void SelectionSort_asc_L2R(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;//assume the minimum element is the first element
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {//ascending order to change to descending change to >
				min = j; //find the index of the minimum element
			}
		}
		if (min != i) {
			std::swap(arr[i], arr[min]);//swap the minimum element with the first element
		}
	}
}
void SelctionSort_asc_R2L(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		int max = i;//assume the maximum element is the last element
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[max]) {//descending order to change to ascending change to <
				max = j; //find the index of the maximum element
			}
		}
		if (max != i) {
			std::swap(arr[i], arr[max]);//swap the maximum element with the last element
		}
	}
}



int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectionSort_asc_L2R(arr, n);
	std::cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}