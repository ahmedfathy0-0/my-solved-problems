/*

 ██████╗███╗   ███╗██████╗ ██████╗ ███████╗
██╔════╝████╗ ████║██╔══██╗╚════██╗╚════██║
██║     ██╔████╔██║██████╔╝ █████╔╝    ██╔╝
██║     ██║╚██╔╝██║██╔═══╝ ██╔═══╝    ██╔╝
╚██████╗██║ ╚═╝ ██║██║     ███████╗   ██║
 ╚═════╝╚═╝     ╚═╝╚═╝     ╚══════╝   ╚═╝



*/



#include <iostream>
// Hash function using the division method


// Function to hash a key into an array
void hash_LinearProbing(int arr[], int key, int size) {
    // Calculate the index for the key using the hash function
    int index ;
    for (int i = 0; i < size; i++) {
        index = (key + i) % size; // Hash function (linear probing)
        // If the calculated index is not empty, it means a collision has occurred.
        // Collision in hashing is a situation where a newly inserted key maps to an already occupied slot in the hash table.
        // To resolve this collision, we use a method called linear probing.
        // Linear probing is a collision resolving technique in Open Addressed Hash tables.
        // Whenever a collision occurs, linear probing searches for the next empty slot and inserts the key.
        // Another method to handle collisions is chaining. In chaining, each slot of the hash table is a linked list,
        // so when a collision occurs, the key is just added to the end of the linked list in the collided slot.
        // For more details on chaining, please go to Chaining solution 
        if (arr[index] == 0) {
            arr[index] = key;
            return; // Exit the function

        }

    }
}
void hash_QuadraticProbing(int arr[], int key, int size) {
	// Calculate the index for the key using the hash function
    int c1=0, c2=1; // Constants for the quadratic probing ,they can be any values
	int index;
    for (int i = 0; i < size; i++) {
		index = (key + c1*i + c2 * i*i) % size; // Hash function (quadratic probing)
		// If the calculated index is not empty, it means a collision has occurred.
		// Collision in hashing is a situation where a newly inserted key maps to an already occupied slot in the hash table.
		// To resolve this collision, we use a method called quadratic probing.
		// Quadratic probing is a collision resolving technique in Open Addressed Hash tables.
		// Whenever a collision occurs, quadratic probing searches for the next empty slot by adding the square of the offset to the hash value.

        if (arr[index] == 0) {
			arr[index] = key;
			return; // Exit the function

		}

	}
}
void hash_doubleHashing(int arr[], int key, int size) {
	// Calculate the index for the key using the hash function
	int prime = 7; // Prime number for the double hashing
	int index,index2;
    for (int i = 0; i < size; i++) {
        index2 = prime-(key%prime); // Second hash function ,it can be any function
		index = (key + i * index2) % size; // Hash function (double hashing)


		// If the calculated index is not empty, it means a collision has occurred.
		// Collision in hashing is a situation where a newly inserted key maps to an already occupied slot in the hash table.
		// To resolve this collision, we use a method called double hashing.
		// Double hashing is a collision resolving technique in Open Addressed Hash tables.
		// Whenever a collision occurs, double hashing searches for the next empty slot by adding the product of the offset and the second hash value to the hash value.

        if (arr[index] == 0) {
			arr[index] = key;
			return; // Exit the function

		}

	}
}

/*Open addressing is not typically used if keys can be deleted, use 
chaining instead
*/

int main()
{
    int key = 35;  // The key to be hashed
    int size = 10; // The size of the hash table 

    std::cout << std::endl;

    // Initialize an array to store the hashed keys
    int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };

    // Hash multiple keys into the array
    hash_LinearProbing(arr, 35, 10);
    hash_LinearProbing(arr, 45, 10);
    hash_LinearProbing(arr, 55, 10);
    hash_LinearProbing(arr, 65, 10);
    hash_LinearProbing(arr, 75, 10);
    hash_LinearProbing(arr, 85, 10);
    hash_LinearProbing(arr, 95, 10);
    hash_LinearProbing(arr, 105, 10);
    hash_LinearProbing(arr, 115, 10);
    hash_LinearProbing(arr, 125, 10);
    hash_LinearProbing(arr, 135, 10);
    hash_LinearProbing(arr, 145, 10);
    hash_LinearProbing(arr, 155, 10);
    hash_LinearProbing(arr, 165, 10);

    // Print the array to see the distribution of hashed keys
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
 