#include "personStruct.h"
using namespace ::std;
template <class T> class LinkedList {
protected:
    struct ListNode {
        ListNode* next;
        T data;
        ListNode(T dataValue, ListNode* p = nullptr) {
            this->data = dataValue;
            next = p;
        }
    };
    ListNode* head;

public:
    // Constructors
    LinkedList() { head = nullptr; }; // Constructor

    // Methods
    void printData();
    void add(T data);                      // Adds and sorts a new node
    void insertData(T data, int position); // Insert data into a list
    void removeData(int position);         // Remove data from a list
    void reverseList();       // Rearrange list to be in reverse order
    int search(T targetData); // Returns position of the node containing a value
    bool isMember(T targetData, ListNode* current = nullptr, int x = 0);

    static ListNode* copyList(ListNode* lNode) { // Copies a node in the linked
        // list (for copy constructor)
        if (lNode == nullptr)
            return nullptr;
        else {
            ListNode* endCopy = copyList(lNode->next);
            return new ListNode(lNode->data, endCopy);
        }
    };

    LinkedList(const LinkedList& original) { // Copy Constructor
        head = copyList(original.head);
    };
    // Destructor
    ~LinkedList() {};
};

// Print Data
template <class T> void LinkedList<T>::printData() {
    if (head != nullptr) {
        ListNode* current = head;
        cout << (current->data);
        cout << endl;                      // Prints the first node data
        while (current->next != nullptr) { // Starts loop
            current = current->next;         // Goes to next node
            cout << current->data;
            cout << endl; // Prints node data
        }
    }
    else
        cout << "List is empty";
}
// Add
template <class T>
void LinkedList<T>::add(T data) { // This should sort in ascending order
    ListNode* current, * previous;
    if (head == nullptr ||
        head->data >= data) // If the beginning is null or greater than new
        head = new ListNode(data, head);
    // head points to a the new node
    else {

        previous = head;
        current = head->next;
        while (current != nullptr &&
            current->data < data) { // Otherwise, loop while current isnt null
            previous = current;          // AND current data is less than data
            current = current->next;
        }
        previous->next = new ListNode(
            data,
            current); // Then set second to last node's next pointer to a new node
    }
}

// isMember
template <class T>
bool LinkedList<T>::isMember(T targetData, ListNode* current, int x) {
    if (x == 0) {
        current = this->head;
        x++;
    }
    if (current == nullptr)
        return false;
    else if (targetData == current->data)
        return true;
    else
        return isMember(targetData, current->next, x);
}

// search
template <class T> int LinkedList<T>::search(T targetData) {
    ListNode* current = this->head;    // Grabs head node
    int i = 0;                         // Initializes an iterator to 0
    while (current != nullptr) {       // checks for nullptr, loops if none
        if (targetData == current->data) // Checks for target data
            return i;
        else {
            current = current->next; // Moves to next node if not found
            i++;
        }
    }
    return -1;
}

// Insert Data
template <class T> void LinkedList<T>::insertData(T data, int position) {
    if (position < 0) { // Skips negative values
        cout << "skipping function call to insertData; Position cannot be less "
            "than zero.";
    }
    else {
        ListNode* current = this->head, * previous; // Grabs head node
        for (int i = 0; i < position + 1;
            i++) {            // Iterates through each node of the list
            if (head == nullptr) // If list is empy, nothing happens
                cout << "List is empty";
            else if (current == nullptr) // If the end of the list is reached, just
                // append the data to the end
                previous->next = new ListNode(data, current);
            else {
                if (i == position) { // Otherwise, check the current position against
                    // the given index
                    if (i ==
                        0) // If the given index is 0, insert straight into the head node
                        head = new ListNode(data, head);
                    else
                        previous->next =
                        new ListNode(data, current); // Otherwise, insert into the list

                }
                else { // If not at the right index, set our previous to current and
                    // current to next
                    previous = current;
                    current = current->next;
                }
            }
        }
    }
}

// Remove Data
template <class T> void LinkedList<T>::removeData(int position) {
    ListNode* current = this->head, * previous;
    if (current == nullptr)
        cout << "List is empty";
    else {
        if (position == 0)
            this->head = current->next;
        else {
            for (int i = 1; i <= (position); i++) {
                previous = current;
                current = current->next;
                if (i == position) {
                    if (current->next != nullptr)
                        previous->next = current->next;
                    else
                        previous->next = nullptr;
                }
            }
        }
    }
}

// Reverse list
template <class T> void LinkedList<T>::reverseList() {

    ListNode* current, * previous, * pNext;
    previous = nullptr;
    current = this->head;
    if (current == nullptr)
        cout << "List is empty.";
    else {
        pNext = current->next;
        while (pNext != nullptr) {
            current->next = previous;

            previous = current;
            current = pNext;
            pNext = pNext->next;
        }
        head = current;
        head->next = previous;
    }
}
