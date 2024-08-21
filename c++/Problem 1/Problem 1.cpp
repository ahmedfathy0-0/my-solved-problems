
// TODO: WRITE YOUR NAME AND ID
// STUDENT NAME: ahmed fathy mohamed
// STUDENT ID:   9230162

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

// =========================== STACK Code ==================================

template<typename T>
class ArrayStack  //Dont change this (nn)
{
private:
	T* items;		// Array of stack items
	int      top;                   // Index to top of stack
	const int STACK_SIZE;

public:

	ArrayStack(int MaxSize = 100) : STACK_SIZE(MaxSize)
	{
		items = new T[STACK_SIZE];
		top = -1;
	}  // end default constructor

	bool isEmpty() const
	{
		return top == -1;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (top == STACK_SIZE - 1) return false;	//Stack is FULL

		top++;
		items[top] = newEntry;
		return true;
	}  // end push

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		top--;
		return true;
	}  // end pop

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}  // end peek

	//Destructor
	~ArrayStack()
	{
		delete[]items;
	}

}; // end ArrayStack

// =========================== QUEUE Code ==================================

template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
public:

	Node()
	{
		next = nullptr;
	}

	Node(const T& r_Item)
	{
		item = r_Item;
		next = nullptr;
	}

	Node(const T& r_Item, Node<T>* nextNodePtr)
	{
		item = r_Item;
		next = nextNodePtr;
	}

	void setItem(const T& r_Item)
	{
		item = r_Item;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	Node<T>* getNext() const
	{
		return next;
	}

};

template <typename T>
class LinkedQueue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:

	LinkedQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;

	}

	bool isEmpty() const
	{
		return (frontPtr == nullptr);
	}

	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		// Insert the new node
		if (isEmpty())	//special case if this is the first node to insert
			frontPtr = newNodePtr; // The queue is empty
		else
			backPtr->setNext(newNodePtr); // The queue was not empty

		backPtr = newNodePtr; // New node is the last node now
		return true;
	} // end enqueue

	bool dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
			backPtr = nullptr;

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;
		return true;
	}

	bool peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;
	}

	~LinkedQueue()
	{
		T temp;

		//Free (Dequeue) all nodes in the queue
		while (dequeue(temp));
	}

	// Copy Constructor
	LinkedQueue(const LinkedQueue<T>& LQ)
	{
		Node<T>* NodePtr = LQ.frontPtr;
		if (!NodePtr) //LQ is empty
		{
			frontPtr = backPtr = nullptr;
			return;
		}

		//insert the first node
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		frontPtr = backPtr = ptr;
		NodePtr = NodePtr->getNext();

		//insert remaining nodes
		while (NodePtr)
		{
			Node<T>* ptr = new Node<T>(NodePtr->getItem());
			backPtr->setNext(ptr);
			backPtr = ptr;
			NodePtr = NodePtr->getNext();
		}
	}

};

template < typename T>
void PrintQueue(LinkedQueue<T> Q)
{
	T K;
	while (Q.dequeue(K))
		cout << K << " ";
	cout << endl;
}
//end of queue class

// =========================== The Required Function ==================================


// TODO
void FreqMirror(LinkedQueue<int>& input, LinkedQueue<char> ops)
{
	// TODO: implement this function and don't change its prototype
	LinkedQueue <int> temp1;
	LinkedQueue <int> out;
	int x;
	int count = 0;
	char OPS;
	while (!input.isEmpty()) {
		count = 0;
		input.peek(x);
		if (x < 0) {
			input.dequeue(x);
			out.enqueue(x);
			ops.dequeue(OPS);
			continue;
		}
		while (input.peek(x) && x >= 0) {
			input.dequeue(x);
			temp1.enqueue(x);
			count++;
		}
		if (! input.peek(x)) {

			while (temp1.dequeue(x)) {
				out.enqueue(x);
			}
			break;
		}
		if (x < 0) {
			input.dequeue(x);
			temp1.enqueue(x);
			count++;
		}
		if (ops.dequeue(OPS)) {
			int frq = 0;
			int previous;
			if (OPS == 'F') {
				temp1.peek(x);
				previous = x;
				while (x >= 0) {
					temp1.dequeue(x);
					if (previous == x) {
						frq++;
						temp1.peek(x);
						if (x < 0) {
							out.enqueue(previous);
							out.enqueue(frq);
						}
					}
					else {
						out.enqueue(previous);
						out.enqueue(frq);
						previous = x;
						temp1.peek(x);
						frq = 1;
						if (x < 0) {
							out.enqueue(previous);
							out.enqueue(frq);
						}
				    }
				}
				if (x < 0) {
					temp1.dequeue(x);
					out.enqueue(x);
				}

			}
			else if (OPS == 'M') {
				ArrayStack<int> temp;
				LinkedQueue<int> temp2;
				if (count == 1) {
					temp1.dequeue(x);
					out.enqueue(x);
				}
				for (int i = 0;i < count / 2;i++) {
					temp1.dequeue(x);
					temp2.enqueue(x);
				}
				temp1.peek(x);
				for (int i = 0;x >= 0;i++) {
					temp1.dequeue(x);
					temp.push(x);
					temp1.peek(x);
				}
				for (int i = 0; !temp.isEmpty() || !temp2.isEmpty();i++) {
					if (temp.isEmpty()) {
						temp2.dequeue(x);
						out.enqueue(x);
					}
					else if (temp2.isEmpty()) {
						temp.pop(x);
						out.enqueue(x);
					}
					else {
						int y = 0;
						temp.pop(x);
						temp2.dequeue(y);
						out.enqueue(x + y);
					}
				}
				temp1.peek(x);
				if (x < 0) {
					temp1.dequeue(x);
					out.enqueue(x);
				}

			}


		}

		
	}

	while (out.dequeue(x)) {
		input.enqueue(x);
	}




}



// =========================== Main ==================================

int main()
{
	// Note: Don't change the main function.
	int n;
	int element;
	cin >> n;
	LinkedQueue<int> input;
	for (int i = 0; i < n; i++)
	{
		cin >> element;
		input.enqueue(element);
	}
	int n2;
	char operation;

	cin >> n2;
	LinkedQueue<char> ops;
	for (int i = 0; i < n2; i++)
	{
		cin >> operation;
		ops.enqueue(operation);
	}
	FreqMirror(input, ops);
	PrintQueue(input);

	// Note: Don't change the main function.
	return 0;
}






















// nn