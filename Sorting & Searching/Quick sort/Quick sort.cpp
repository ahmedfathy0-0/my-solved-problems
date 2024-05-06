#include <iostream>

// function to rearrange array (find the partition point)
int partition(int arr[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = arr[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {//change to >= for descending order

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            std::swap(arr[i], arr[j]);
        }
    }

    // swap pivot with the greater element at i
    std::swap(arr[i + 1], arr[high]);

    // return the partition point
    return (i + 1);
}

void QuickSort_asc_R2L(int arr[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(arr, low, high);

        // recursive call on the left of pivot
        QuickSort_asc_R2L(arr, low, pi - 1);

        // recursive call on the right of pivot
        QuickSort_asc_R2L(arr, pi + 1, high);
    }
}
void QuickSort_desc_L2R(int arr[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(arr, low, high);

        // recursive call on the right of pivot
        QuickSort_desc_L2R(arr, pi + 1, high);

        // recursive call on the left of pivot
        QuickSort_desc_L2R(arr, low, pi - 1);


    }
}


int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort_asc_R2L(arr, 0, n - 1);
    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}