#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace ::std;

struct Person {
    string name, state, city, address, relation, phoneNumber;
    int ZIP, dayOfBirth, monthOfBirth, yearOfBirth;

    // Overloaded operators

    //<<
    friend void operator<<(ostream& coutObject, const Person& printTarget) {
        coutObject << "\nName: " << printTarget.name
            << "\nDOB: " << printTarget.monthOfBirth << " "
            << printTarget.dayOfBirth << " " << printTarget.yearOfBirth
            << "\nAddress: " << printTarget.address
            << "\nCity: " << printTarget.city
            << "\nState: " << printTarget.state
            << "\nZIP: " << printTarget.ZIP
            << "\nPhone number: " << printTarget.phoneNumber
            << "\nRelationship: " << printTarget.relation;
    }

    //==
    bool operator==(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;
        if (temp1 == temp2) {
            return true;
        }
        else {
            return false;
        }
    }

    //>=
    bool operator>=(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;
        if (temp1 >= temp2) {

            return true;
        }
        else {
            return false;
        }
    }

    //<=
    bool operator<=(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;
        if (temp1 <= temp2) {

            return true;
        }
        else {
            return false;
        }
    }

    //>
    bool operator>(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;

        if (temp1 > temp2) {
            return true;
        }
        else {
            return false;
        }
    }

    //<
    bool operator<(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;

        if (temp1 < temp2) {
            return true;
        }
        else {
            return false;
        }
    }

    //!=
    bool operator!=(const Person& right) {
        string temp1, temp2;
        temp1 = (string)this->name;
        temp2 = (string)right.name;

        if (temp1 != temp2) {
            return true;
        }
        else {
            return false;
        }
    }
};

// Read from file to objects
void readFile(string fileName, vector<Person>& people) {
    Person prsn;
    fstream file;
    file.open(fileName, ios::in);
    if (!file.is_open())
        cout << "\nError opening file.\n";
    else {
        while (!file.eof()) {
            getline(file, prsn.name);
            file >> prsn.monthOfBirth;
            file >> prsn.dayOfBirth;
            file >> prsn.yearOfBirth;
            file.ignore(999, '\n'); // Ignore the next new line (don't need after
            // getlines since they're delimited by newlines)
            getline(file, prsn.address);
            getline(file, prsn.city);
            getline(file, prsn.state);
            file >> prsn.ZIP;
            file.ignore(999, '\n');
            getline(file, prsn.phoneNumber);
            getline(file, prsn.relation);
            people.push_back(prsn);
        }
    }
}