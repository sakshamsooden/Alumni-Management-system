#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

struct Alumni {
    string name;
    int year;
    string department;
    string profession;
    string enrollmentNumber;
    Alumni* next;
};


class AlumniList {
private:
    Alumni* head;
    stack<Alumni*> Stack;
    queue<Alumni*> Queue;

public:
    AlumniList() {
        head = nullptr;
    }

    void addAlumni(string name, int year, string department, string profession, string enrollmentNumber) {
        Alumni* newAlumni = new Alumni();
        newAlumni->name = name;
        newAlumni->year = year;
        newAlumni->department = department;
        newAlumni->profession = profession;
        newAlumni->enrollmentNumber = enrollmentNumber;
        newAlumni->next = head;
        head = newAlumni;
        Stack.push(newAlumni);
        Queue.push(newAlumni);
        cout << "Alumni added successfully." << endl;
    }

    void deleteAlumni(string name) {
        Alumni* temp = head;
        Alumni* prev = nullptr;

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Alumni not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Alumni deleted successfully." << endl;
    }

    void searchAlumniByName(string name) {
        Alumni* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Alumni Found:" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Year: " << temp->year << endl;
                cout << "Department: " << temp->department << endl;
                cout << "Profession: " << temp->profession << endl;
                cout << "Enrollment Number: " << temp->enrollmentNumber << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Alumni not found." << endl;
    }

    void searchAlumniByYear(int year) {
        Alumni* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->year == year) {
                if (!found) {
                    cout << "Alumni Found for Year " << year << ":" << endl;
                }
                cout << "Name: " << temp->name << endl;
                cout << "Department: " << temp->department << endl;
                cout << "Profession: " << temp->profession << endl;
                cout << "Enrollment Number: " << temp->enrollmentNumber << endl;
                cout << "--------------------------" << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No alumni found for the year " << year << "." << endl;
        }
    }

    void searchAlumniByDepartment(string department) {
        Alumni* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->department == department) {
                if (!found) {
                    cout << "Alumni Found in Department: " << department << ":" << endl;
                }
                cout << "Name: " << temp->name << endl;
                cout << "Year: " << temp->year << endl;
                cout << "Profession: " << temp->profession << endl;
                cout << "Enrollment Number: " << temp->enrollmentNumber << endl;
                cout << "--------------------------" << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No alumni found in the department " << department << "." << endl;
        }
    }

    void updateAlumni(string name) {
        Alumni* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Alumni found. Enter new details: " << endl;
                cout << "Enter Year: ";
                cin >> temp->year;
                cout << "Enter Department: ";
                cin.ignore();
                getline(cin, temp->department);
                cout << "Enter Profession: ";
                getline(cin, temp->profession);
                cout << "Enter Enrollment Number: ";
                getline(cin, temp->enrollmentNumber);
                cout << "Alumni details updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Alumni not found." << endl;
    }

    void sortAlumniByYear() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        for (Alumni* i = head; i != nullptr; i = i->next) {
            for (Alumni* j = i->next; j != nullptr; j = j->next) {
                if (i->year > j->year) {
                    swap(i->name, j->name);
                    swap(i->year, j->year);
                    swap(i->department, j->department);
                    swap(i->profession, j->profession);
                    swap(i->enrollmentNumber, j->enrollmentNumber);
                }
            }
        }
        cout << "Alumni list sorted by year." << endl;
    }

    void sortAlumniByEnrollmentNumber() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        for (Alumni* i = head; i != nullptr; i = i->next) {
            for (Alumni* j = i->next; j != nullptr; j = j->next) {
                if (i->enrollmentNumber > j->enrollmentNumber) {
                    swap(i->name, j->name);
                    swap(i->year, j->year);
                    swap(i->department, j->department);
                    swap(i->profession, j->profession);
                    swap(i->enrollmentNumber, j->enrollmentNumber);
                }
            }
        }
        cout << "Alumni list sorted by enrollment number." << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        Alumni* temp = head;
        while (temp != nullptr) {
            file << temp->name << endl;
            file << temp->year << endl;
            file << temp->department << endl;
            file << temp->profession << endl;
            file << temp->enrollmentNumber << endl;
            temp = temp->next;
        }

        file.close();
        cout << "Alumni records saved to file." << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading." << endl;
            return;
        }

        while (file) {
            Alumni* newAlumni = new Alumni();
            getline(file, newAlumni->name);
            file >> newAlumni->year;
            file.ignore();
            getline(file, newAlumni->department);
            getline(file, newAlumni->profession);
            getline(file, newAlumni->enrollmentNumber);
            file.ignore();

            newAlumni->next = head;
            head = newAlumni;
        }

        file.close();
        cout << "Alumni records loaded from file." << endl;
    }

    void displayAlumni() {
        Alumni* temp = head;
        if (temp == nullptr) {
            cout << "No alumni records found." << endl;
            return;
        }
        cout << "Alumni Records:" << endl;
        while (temp != nullptr) {
            cout << "Name: " << temp->name << endl;
            cout << "Year: " << temp->year << endl;
            cout << "Department: " << temp->department << endl;
            cout << "Profession: " << temp->profession << endl;
            cout << "Enrollment Number: " << temp->enrollmentNumber << endl;
            cout << "--------------------------" << endl;
            temp = temp->next;
        }
    }

    ~AlumniList() {
        Alumni* current = head;
        while (current != nullptr) {
            Alumni* next = current->next;
            delete current;
            current = next;
        }
    }

void printAlumniInReverse() {
    if (!head) {
        cout << "No alumni records to display in reverse!" << endl;
        return;
    }

    stack<Alumni*> reverseStack;
    Alumni* temp = head;


    while (temp) {
        reverseStack.push(temp);
        temp = temp->next;
    }


    cout << "Alumni Records in Reverse Order:" << endl;
    while (!reverseStack.empty()) {
        Alumni* current = reverseStack.top();
        reverseStack.pop();

        cout << "Enrollment No: " << current->enrollmentNumber << endl;
        cout << "Name: " << current->name << endl;
        cout << "Graduation Year: " << current->year << endl;
        cout << "Department: " << current->department << endl;
        cout << "Profession: " << current->profession << endl;
        cout << "---------------------------" << endl;
    }
}
void processAlumniRecords() {
    if (Queue.empty()) {
        cout << "No alumni records to process!" << endl;
        return;
    }

    cout << "Processing alumni records in FIFO order:" << endl;
    while (!Queue.empty()) {
        Alumni* current = Queue.front();
        Queue.pop();

        cout << "Processing Alumni:" << endl;
        cout << "Enrollment No: " << current->enrollmentNumber << endl;
        cout << "Name: " << current->name << endl;
        cout << "Graduation Year: " << current->year << endl;
        cout << "Department: " << current->department << endl;
        cout << "Profession: " << current->profession << endl;
        cout << "---------------------------" << endl;
    }
}
};

int main() {
    AlumniList alumniList;
    int choice;
    string name, department, profession, enrollmentNumber;
    int year;
    string filename = "alumni_records.txt";

    do {
        cout << "\nJIIT Noida Alumni Network Management System\n";
        cout << "1. Add Alumni\n";
        cout << "2. Delete Alumni\n";
        cout << "3. Search Alumni by Name\n";
        cout << "4. Search Alumni by Year\n";
        cout << "5. Search Alumni by Department\n";
        cout << "6. Update Alumni Details\n";
        cout << "7. Sort Alumni by Year\n";
        cout << "8. Sort Alumni by Enrollment Number\n";
        cout << "9. Display All Alumni\n";
        cout << "10. Save Alumni Records to File\n";
        cout << "11. Load Alumni Records from File\n";
        cout << "12. Print in reverse using stack\n";
        cout <<"13. Print added alumni records using queue\n";
        cout <<"14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Department: ";
            cin.ignore();
            getline(cin, department);
            cout << "Enter Profession: ";
            getline(cin, profession);
            cout << "Enter Enrollment Number: ";
            getline(cin, enrollmentNumber);
            alumniList.addAlumni(name, year, department, profession, enrollmentNumber);
            break;
        case 2:
            cout << "Enter Name of Alumni to delete: ";
            cin.ignore();
            getline(cin, name);
            alumniList.deleteAlumni(name);
            break;
        case 3:
            cout << "Enter Name of Alumni to search: ";
            cin.ignore();
            getline(cin, name);
            alumniList.searchAlumniByName(name);
            break;
        case 4:
            cout << "Enter Year to search: ";
            cin >> year;
            alumniList.searchAlumniByYear(year);
            break;
        case 5:
            cout << "Enter Department to search: ";
            cin.ignore();
            getline(cin, department);
            alumniList.searchAlumniByDepartment(department);
            break;
        case 6:
            cout << "Enter Name of Alumni to update: ";
            cin.ignore();
            getline(cin, name);
            alumniList.updateAlumni(name);
            break;
        case 7:
            alumniList.sortAlumniByYear();
            break;
        case 8:
            alumniList.sortAlumniByEnrollmentNumber();
            cout<<"Alumni sorted on the basis of enrollment number"<<endl;
            break;
        case 9:
            alumniList.displayAlumni();
            break;
        case 10:
            alumniList.saveToFile(filename);
            break;
        case 11:
            alumniList.loadFromFile(filename);
            break;
        case 12:
            alumniList.printAlumniInReverse();
            break;
        case 13:
            alumniList.processAlumniRecords();
            break;
        case 14:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 14);

    return 0;
}
