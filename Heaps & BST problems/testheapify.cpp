#include <iostream>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr, i,largest);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}
int main() {
    int arr[] = {2,6,8,3,9};
    int N = sizeof(arr) / sizeof(arr[0]);

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}