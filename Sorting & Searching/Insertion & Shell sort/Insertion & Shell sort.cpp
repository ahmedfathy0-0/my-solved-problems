#include <iostream>

void insertionSort_asc_L2R(int arr[], int n)//ascending order Left to Right
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) { //change to < for descending order
			arr[j + 1] = arr[j];//move elements greater than key to one position ahead of their current position(shift right)
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void insertionSort_asc_R2L(int arr[], int n)//ascending order Right to Left
{
	int i, key, j;
	for (i = n - 2; i >= 0; i--) {//start from the second last element
		key = arr[i];
		j = i + 1;
		while (j < n && arr[j] < key) { //change to > for descending order  !!Check the condition of the while loop and the while loop in L2R 
			arr[j - 1] = arr[j];//move elements greater than key to one position ahead of their current position(shift left)
			j = j + 1;
		}
		arr[j - 1] = key;
	}
}

void ShellSort_asc_L2R(int arr[], int n) {
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is gap sorted
		for (int i = gap; i < n; i++) {
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];
			int j;
			// shift earlier gap-sorted elements up until the correct location for a[i] is found
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {//change to < for descending order

				//here u can get the diffrence that between it and insersion sort every iteration j-=gap
				arr[j] = arr[j - gap];
			}
			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}

void ShellSort_asc_R2L(int arr[], int n) {
	// Start with a big gap, then reduce the gap
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is gap sorted
		for (int i = n - gap - 1; i >= 0; i--) {
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];
			int j;
			// shift earlier gap-sorted elements up until the correct location for a[i] is found
			for (j = i; j < n - gap && arr[j + gap] < temp; j += gap) { //change to > for descending order
				//here u can get the diffrence that between it and insersion sort every iteration j+=gap
				arr[j] = arr[j + gap];
			}
			// put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}



int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ShellSort_asc_R2L(arr, n);
	std::cout << "Shell Sorted array: \n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	int arr2[] = { 64, 25, 12, 22, 11 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	insertionSort_asc_R2L(arr2, n2);
	std::cout << "insertion Sorted array: \n";
	for (int i = 0; i < n2; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	return 0;
}