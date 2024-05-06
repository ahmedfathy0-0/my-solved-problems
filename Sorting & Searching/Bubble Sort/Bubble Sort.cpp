
/*

  ______   ___      ___    _______    _______  _________
 /" _  "\ |"  \    /"  |  |   __ "\  /"     "\("       "\
(: ( \___) \   \  //   |  (. |__) :)(__/\    :)\___/   :/
 \/ \      /\\  \/.    |  |:  ____/     / ___/    /   //
 //  \ _  |: \.        |  (|  /        // \___  __\  ./
(:   _) \ |.  \    /:  | /|__/ \      (:  /  "\(:  \_/ \
 \_______)|___|\__/|___|(_______)      \_______)\_______)



*/


#include <iostream>
void BubbleSort_asc_R2L(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {//ascending order to change to descending change to <
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void BubbleSort_asc_L2R(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = n - 1; j > n - i - 1; j--) {
			if (arr[j] < arr[j - 1]) {//ascending order to change to descending change to >
				std::swap(arr[j], arr[j - 1]);
			}
		}
	}
}
int main() {
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort_asc_R2L(arr, n);
	//BubbleSort_asc_L2R(arr, n);
	std::cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return 0;
}