/*

    _______   ,---.    ,---..-------.   .`````-. ,----------.
   /   __  \  |    \  /    |\  _(`)_ \ /   ,-.  \'..-------,(
  | ,_/  \__) |  ,  \/  ,  || (_ o._)|(___/  |   |   _ _   //
,-./  )       |  |\_   /|  ||  (_,_) /      .'  /   (_I_) //
\  '_ '`)     |  _( )_/ |  ||   '-.-'   _.-'_.-'   (_(=)_)/
 > (_)  )  __ | (_ o _) |  ||   |     _/_  .'       (_I_)/
(  .  .-'_/  )|  (_,_)  |  ||   |    ( ' )(__..--.   ,-'/
 `-'`-'     / |  |      |  |/   )   (_{;}_)      |  )  (
   `._____.'  '--'      '--'`---'    (_,_)-------'  `---'



*/






#include <iostream>
// Function to implement binary search on a sorted array
void BinarySearch(int arr[], int n, int x)
{
    int left = 0; // Initialize left pointer
    int right = n - 1; // Initialize right pointer

    // Continue the loop until the pointers overlap
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid point to divide the array into two halves

        // If x is present at the mid, we have found the element
        if (arr[mid] == x)
        {
            std::cout << x << " is present at index " << mid;
            return;
        }

        // If x is greater, ignore left half by updating the left pointer
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half by updating the right pointer
        else
            right = mid - 1;
    }

    // If we reach here, then the element was not present in the array
    std::cout << "Element Not found";
}

void Binary_recursive(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
		int mid = left + (right - left) / 2;
		// If the element is present at the middle itself
        if (arr[mid] == x)
        {
			std::cout << x << " is present at index " << mid;
			return;
		}
		// If element is smaller than mid, then it can only be present in left subarray
		if (arr[mid] > x)
			Binary_recursive(arr, left, mid - 1, x);
		// Else the element can only be present in right subarray
		else
			Binary_recursive(arr, mid + 1, right, x);
	}
	else
		std::cout << "Element Not found";
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	BinarySearch(arr, n, x);
    //Binary_recursive(arr, 0, n - 1, x);
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}