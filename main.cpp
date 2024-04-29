#include "listHeader.h"

using namespace::std;

int main() {

    //Variables
    vector<Person> people; //Vector to store objects
    LinkedList<Person> prsnList; //Linked list

    readFile("people.txt", people); //Creates person objects from the file to populate the people vector

    for (int i = 0; i < people.size(); i++) { //Adds each object within the vector into the linked list
        prsnList.add(people[i]); //Objects are automatically sorted when added via the add function
    }

    //Using the copy constructor to make a duplicate list
    LinkedList<Person> copiedList(prsnList);
    cout << "\n=====================================\nCoped List:";
    copiedList.printData(); //Printing the contents of the copied linked list
    cout << "\n=====================================\n";

    //Checking for list membership using the isMember method
    cout << "Testing membership:\n\n\n";
    if (prsnList.isMember(people[1]))
        cout << people[1].name << " is a member of this list.";
    else
        cout << people[1].name << " is not a member of this list.";
    cout << "\n\n=====================================\n";

    //Inserting another Donald Duck into the list at the first position using the insert method
    cout << "Testing insertData:";
    prsnList.insertData(people[1], 0);
    prsnList.printData(); //Printing the contents of the original list after the second donald duck is inserted
    cout << "\n=====================================\n";

    //Removing the additional Donald Duck from the first position in the list using the remove method
    cout << "Testing removeData:";
    prsnList.removeData(0);
    prsnList.printData(); //Printing the contents of the original list after the second donald duck is removed
    cout << "\n=====================================\n";

    //Reversing the list with the reverseList method
    cout << "Testing reverseList:";
    prsnList.reverseList();
    prsnList.printData();
    cout << "\n=====================================\n";

    //Testing the search method by looking for Goof Goofy in the list
    cout << "Testing search:\n";
    cout << people[3].name << " is in index " << prsnList.search(people[3]) << '\n';
    cout << "\n\n=====================================\n";

    //No "sort" methodx added as the add method automatically sorts data as it is appended to the list.
}
