/*

 ██████╗███╗   ███╗██████╗ ██████╗ ███████╗
██╔════╝████╗ ████║██╔══██╗╚════██╗╚════██║
██║     ██╔████╔██║██████╔╝ █████╔╝    ██╔╝
██║     ██║╚██╔╝██║██╔═══╝ ██╔═══╝    ██╔╝
╚██████╗██║ ╚═╝ ██║██║     ███████╗   ██║
 ╚═════╝╚═╝     ╚═╝╚═╝     ╚══════╝   ╚═╝



*/

#include <iostream>
#include "LinkedList.h"
// Hash function using the division method
int HashFunction_Division(int key, int size)
{
    // The division method operates by dividing the key by the size of the hash table
    // and returning the remainder. This method is simple and effective, especially when
    // the size is a prime number not close to a power of 2.
    return key % size;
}

// Function to hash a key into an array of linked lists (chaining)
void hash_Chaining(LinkedList<int>* arr, int key, int size)
{
    // Calculate the index for the key using the hash function
    int index = HashFunction_Division(key, size);

    // If the linked list at the calculated index is empty, insert the key at the front of the list
    if (arr[index].isEmpty())
    {
        arr[index].insertFront(key);
    }
    else
    {
        // If the linked list at the calculated index is not empty, it means a collision has occurred.
        // Collision in hashing is a situation where a newly inserted key maps to an already occupied slot in the hash table.
        // To resolve this collision, we use a method called chaining.
        // In chaining, each slot of the hash table is a linked list, so when a collision occurs, the key is just added to the end of the linked list in the collided slot.
        arr[index].insertEnd(key); // We can use insertFront here as well
    }
}

int main()
{
    int size = 10; // The size of the hash table 

    // Initialize an array of linked lists to store the hashed keys
    LinkedList<int>* arr = new LinkedList<int>[size];

    // Hash multiple keys into the array
    hash_Chaining(arr, 32, size);
    hash_Chaining(arr, 41, size);
    hash_Chaining(arr, 53, size);
    hash_Chaining(arr, 69, size);
    hash_Chaining(arr, 77, size);
    hash_Chaining(arr, 33, size);
    hash_Chaining(arr, 47, size);
    hash_Chaining(arr, 56, size);
    hash_Chaining(arr, 61, size);
    hash_Chaining(arr, 73, size);
    // Keys 85, 95, 105, 115, 125 will cause collisions as they hash to the same indices as the previous keys
    hash_Chaining(arr, 85, size);
    hash_Chaining(arr, 95, size);
    hash_Chaining(arr, 105, size);
    hash_Chaining(arr, 115, size);
    hash_Chaining(arr, 125, size);

    // Print the array to see the distribution of hashed keys
    for (int i = 0; i < size; i++) {
        std::cout << "Index " << i << ": ";
        arr[i].printList();
        std::cout << std::endl;
    }

    delete[] arr;

    return 0;
}

