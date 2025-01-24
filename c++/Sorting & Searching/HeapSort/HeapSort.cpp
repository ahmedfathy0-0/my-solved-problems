
/*

________/\\\\\\\\\__/\\\\____________/\\\\__/\\\\\\\\\\\\\______/\\\\\\\\\______/\\\\\\\\\\\\\\\_
 _____/\\\////////__\/\\\\\\________/\\\\\\_\/\\\/////////\\\__/\\\///////\\\___\/////////////\\\_
  ___/\\\/___________\/\\\//\\\____/\\\//\\\_\/\\\_______\/\\\_\///______\//\\\_____________/\\\/__
   __/\\\_____________\/\\\\///\\\/\\\/_\/\\\_\/\\\\\\\\\\\\\/____________/\\\/____________/\\\/____
	_\/\\\_____________\/\\\__\///\\\/___\/\\\_\/\\\/////////___________/\\\//____________/\\\/______
	 _\//\\\____________\/\\\____\///_____\/\\\_\/\\\_________________/\\\//_____________/\\\/________
	  __\///\\\__________\/\\\_____________\/\\\_\/\\\_______________/\\\/______________/\\\/__________
	   ____\////\\\\\\\\\_\/\\\_____________\/\\\_\/\\\______________/\\\\\\\\\\\\\\\__/\\\/____________
		_______\/////////__\///______________\///__\///______________\///////////////__\///______________



*/
+



#include <iostream>

using namespace std;
void Heapify_Max(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify_Max(arr, n, largest);
	}
}
void Heapify_Min(int arr[], int n, int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] < arr[smallest])
		smallest = left;
	if (right < n&& arr[right] < arr[smallest])
		smallest = right;
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		Heapify_Min(arr, n, smallest);
	}
}

void HeapSort_asc_R2L(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)//build max heap
		Heapify_Max(arr, n, i);
	for (int i = n - 1; i > 0; i--) {//swap the root node with the last node
		swap(arr[0], arr[i]);
		Heapify_Max(arr, i, 0);//heapify the root node Notice that we make the arr size equal to i to exclude the last elements
	}
}

void HeapSort_desc_L2R(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)//build min heap
		Heapify_Min(arr, n, i);
	for (int i = n - 1; i > 0; i--) {//swap the root node with the last node
		swap(arr[0], arr[i]);
		Heapify_Min(arr, i, 0);//heapify the root node Notice that we make the arr size equal to i to exclude the last elements
	}
}



int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort_desc_L2R(arr, n);
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	int arr2[] = { 64, 25, 12, 22, 11 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	HeapSort_asc_R2L(arr2, n2);
	cout << "Sorted array: \n";
	for (int i = 0; i < n2; i++)
		cout << arr2[i] << " ";
	cout << endl;

	return 0;




}