/*

    ___      __  __      ___    ____   ____
  ,"___".   F  \/  ]    F _ ", / _  `.F___ ]
  FJ---L]  J |\__/| L  J `-' |J_/-7 .'`--7 /
 J |   LJ  | |`--'| |  |  __/F`-:'.'.'  / //
 | \___--. F L    J J  F |__/ .' ;_J__ J  L
 J\_____/FJ__L    J__LJ__|   J________LJ__L
  J_____F |__L    J__||__L   |________||__|



*/







#include <iostream>
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void Merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // calculate the size of the first subarray
    int n2 = r - m; // calculate the size of the second subarray

    // create temp arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    // Merge the temp arrays while comparing the elements
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { // change to >= for descending order
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Deallocate the memory
    delete[] L;
    delete[] R;
}

// Main function that sorts arr[l..r] using Merge()
void Merge_asc_L2R(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        Merge_asc_L2R(arr, l, m);
        Merge_asc_L2R(arr, m + 1, r);

        // Merge the sorted halves
        Merge(arr, l, m, r);
    }
}

// Main function that sorts arr[l..r] using Merge()
void Merge_asc_R2L(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves in reverse order
        Merge_asc_R2L(arr, m + 1, r);
        Merge_asc_R2L(arr, l, m);

        // Merge the sorted halves
        Merge(arr, l, m, r);
    }
}



int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Merge_asc_R2L(arr, 0, n - 1);
    //Merge_asc_L2R(arr, 0, n - 1);
    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}