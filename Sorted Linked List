/*
 Author: Noran Mohamed Mokhtar
*/

#include <iostream>
#include <stdexcept>

using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;       // Value stored in the node
    Node* next;     // Pointer to the next node in the list
    Node(int val);  // Constructor to initialize the node
};

// Class representing a sorted linked list
class SortedLinkedList {
private:
    Node* head; // Pointer to the first node in the list

public:
    SortedLinkedList();  // Constructor to initialize an empty list

    void insert(int value);  // Inserts a new value while maintaining order
    void remove(int index);  // Removes a node at a specific index

    // Overloaded operators for output and indexing
    friend ostream& operator<<(ostream& os, const SortedLinkedList& list); // Output operator
    int operator[](int index); // Access an element by its index

    ~SortedLinkedList(); // Destructor to free allocated memory
};

// Constructor for Node
Node::Node(int val) {
    data = val;     // Set node value
    next = nullptr; // Initialize next pointer as null
}

// Constructor for SortedLinkedList
SortedLinkedList::SortedLinkedList() {
    head = nullptr; // Initializes head as nullptr (empty list)
}

// Inserts a new node in the correct position to keep the list sorted
void SortedLinkedList::insert(int value) {
    Node* newNode = new Node(value); // Create a new node with the given value

    // If the list is empty or the new value is the smallest, insert at the beginning (head)
    if (head == nullptr || (value < head->data)) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;

        // Traverse the list to find the correct insertion position
        while (current->next != nullptr && (value > current->next->data)) {
            current = current->next;
        }

        // Insert the new node at the found position (after the current node)
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Removes the node at the specified index
void SortedLinkedList::remove(int index) {
    if (head == nullptr || index < 0) { // Ensure the list is not empty and index is valid
        return; // No action
    }

    Node* to_delete; // Pointer to the node to be deleted

    if (index == 0) { // Remove the first node
        to_delete = head;
        head = head->next;
    } else {
        Node* current = head;

        // Traverse to the node before the one to be deleted
        for (int i = 0; i < index - 1; i++) {
            if (current->next == nullptr) {
                return; // Exit if index is out of bounds
            }
            current = current->next;
        }

        if (current->next == nullptr) {
            return; // Exit if index is out of bounds
        }

        // Remove the node and update the pointers
        to_delete = current->next;
        current->next = to_delete->next;
    }

    delete to_delete; // Free memory of the deleted node
}

// Overloaded operator<< to print the sorted linked list
ostream &operator<<(ostream &os, const SortedLinkedList &list) {
    Node* current = list.head; // Start from the first node
    os << "[";
    // Traverse the list and print the values
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    os << "]";
    return os;
}

// Overloaded indexing operator to access elements by index
int SortedLinkedList::operator[](int index) {
    Node* current = head;

    // Traverse the list to find the required index
    for (int i = 0; i < index; i++) {
        if (current == nullptr) {
            throw out_of_range("Index out of bounds"); // Handle invalid index access
        }
        current = current->next;
    }

    if (current == nullptr) { // Handle invalid index access
        throw out_of_range("Index out of bounds");
    }

    return current->data;
}

// Destructor to release memory and prevent memory leaks
SortedLinkedList::~SortedLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function to test the sorted linked list
int main() {
    SortedLinkedList L; // Create an instance of the sorted linked list

    // Test Case 1: Inserting elements into the sorted linked list
    cout << "\nTest Case 1: Inserting Elements into the Sorted Linked List" << endl;
    cout << "Inserting: 5, 8, 7, 6, 6" << endl;
    L.insert(5); // L = [5]
    L.insert(8); // L = [5, 8]
    L.insert(7); // L = [5, 7, 8]
    L.insert(6); // L = [5, 6, 7, 8]
    L.insert(6); // L = [5, 6, 6, 7, 8]
    cout << "Sorted Linked List: " << endl;
    cout << L << endl; // Output: [5, 6, 6, 7, 8]

    // Test Case 2: Accessing elements using the index operator
    cout << "\nTest Case 2: Accessing Elements Using Index Operator" << endl;
    try {
        cout << "Accessing index 2: ";
        cout << L[2] << endl; // Output: 6
        cout << "Accessing index 10: ";
        cout << L[10] << endl; // Throws an out_of_range exception
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Test Case 3: Deleting elements from the linked list
    cout << "\nTest Case 3: Deleting Elements from the Linked List" << endl;
    cout << "Removing index 0: " << endl;
    L.remove(0); // L = [6, 6, 7, 8]
    cout << L << endl; // Output: [6, 6, 7, 8]

    cout << "Removing index 100: " << endl;
    L.remove(100); // No change (out of bounds)
    cout << L << endl; // Output: [6, 6, 7, 8]

    cout << "Removing index 2: " << endl;
    L.remove(2); // L = [6, 6, 8]
    cout << L << endl; // Output: [6, 6, 8]

    cout << "Removing index 2: " << endl;
    L.remove(2); // L = [6, 6]
    cout << L << endl; // Output: [6, 6]

    cout << "Program completed successfully." << endl;

    return 0;
}
