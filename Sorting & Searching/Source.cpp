#include <iostream>

using namespace std;
void ShellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(arr[min_idx], arr[i]);
	}
}	
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void insertionSort(int arr[], int n)
{
	int i, key, j;
    for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
        while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L, *R;
	L = new int[n1];
	R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int LinearSearch(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

bool ProbabilitySearch(int list[], int last, int target, int& Iocn) {
	// Find target in the list
	for (int i = 0; i <= last; ++i) {
		if (list[i] == target) {
			// Target found
			Iocn = i; // Storing index of the element containing target
			if (i > 0) {
				// If target is not already the first element, move it up one location
				swap(list[i], list[i - 1]);
			}
			return true; // Return true, indicating target found
		}
	}
	// Target not found
	return false; // Return false, indicating target not found
}
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		// If the element is present at the middle itself
		if (arr[mid] == x)
			return mid;
		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}
	// We reach here when element is not
	// present in array
	return -1;
}





int main()
{
	
	//int arr[] = { 12, 11, 13, 5, 6, 7 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//bubbleSort(arr, n);
	//selectionSort(arr, n);
	//insertionSort(arr, n);
	//quickSort(arr, 0, n - 1);
	//mergeSort(arr, 0, n - 1);
	//ShellSort(arr, n);
	int x = 40;
	//int result = LinearSearch(arr, n, x);

	//int myList[] = { 5, 3, 8, 2, 10 }; // Example list
	//int size = sizeof(myList) / sizeof(myList[0]); // Size of the list
	//int target = 8; // Target to search for
	//int last = size - 1; // Index of the last element in the list
	//int Iocn = -1; // Index of the element containing the target (initially set to -1)

	//bool found = ProbabilitySearch(myList, last, target, Iocn);

	//// Output the result
	//if (found) {
	//	cout << "Target found at index: " << Iocn << endl;
	//	cout << "Updated list after moving the target up in priority: ";
	//	for (int i = 0; i < size; ++i) {
	//		cout << myList[i] << " ";
	//	}
	//	cout << endl;
	//}
	//else {
	//	cout << "Target not found in the list." << endl;
	//}
	int sortedArr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(sortedArr) / sizeof(sortedArr[0]);


	int result = binarySearch(sortedArr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;


	/*for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;*/

	return 0;
}