#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <vector>

using namespace std;


struct Student {
    string studentID;
    string fullName;
    string programmeCode;
    int yearOfStudy;
    double cgpa;
    string contactNumber;
};

struct Node {
    Student data;
    Node* next;
};


// =========================================================
// HELPER
// =========================================================
Node* createNode(Student s) {
    Node* newNode = new Node;
    newNode->data = s;
    newNode->next = nullptr;
    return newNode;
}

bool idExists(Node* head, const string& id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.studentID == id) return true;
        current = current->next;
    }
    return false;
}

void clearList(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void pressEnterToContinue() {
    cout << "\nPress Enter to return to Main Menu...";
    cin.ignore();
    cin.get();
}

// =========================================================
// 1. INSERTION OPERATIONS
// Time Complexity: O(1) for Beginning, O(n) for End/Position
// =========================================================


//  Insert at Beginning
void insertAtBeginning(Node* &head, Student s) {
    if (idExists(head, s.studentID)) {
        cout << " Duplicate Student ID detected: " << s.studentID << endl; // Error
        return;
    }
    Node* newNode = createNode(s);
    newNode->next = head;
    head = newNode;
}



//  Insert at End
void insertAtEnd(Node* &head, Student s) {
    if (idExists(head, s.studentID)) {
        cout << " Duplicate Student ID detected: " << s.studentID << endl; // Error
        return;
    }
    Node* newNode = createNode(s);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


// Insert at Specific Position (0-indexed)
void insertAtPosition(Node* &head, Student s, int position) {
    if (idExists(head, s.studentID)) {
        cout << " Duplicate Student ID detected: " << s.studentID << endl; // Error
        return;
    }
    if (position < 0) {
        cout << " Invalid position!" << endl; // Error
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, s);
        return;
    }
    
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << " Position is out of bounds!" << endl; // Error
        return;
    }
    
    Node* newNode = createNode(s);
    newNode->next = temp->next;
    temp->next = newNode;
}

// =========================================================
// 2. DELETION OPERATIONS
// Time Complexity: O(n) because of linear pointer traversal
// =========================================================
bool deleteByID(Node* &head, const string& id) {
    if (head == nullptr) {
        cout << "[ERROR] Empty structure operation invalid." << endl;
        return false;
    }
    
    Node* temp = head;
    Node* prev = nullptr;
    
    if (temp != nullptr && temp->data.studentID == id) {
        head = temp->next;
        delete temp;
        return true;
    }
    
    while (temp != nullptr && temp->data.studentID != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << " Record with ID " << id << " non-existent." << endl; //Error
        return false;
    }
    
    prev->next = temp->next;
    delete temp;
    return true;
}

// =========================================================
// 3. SEARCH OPERATIONS (Linear Search Only)
// Time Complexity: O(n) 
// =========================================================

// Linear Search by Student ID
Node* searchByID(Node* head, const string& id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.studentID == id) return current;
        current = current->next;
    }
    return nullptr;
}

//  Linear Search by Full Name
Node* searchByName(Node* head, const string& name) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.fullName == name) return current;
        current = current->next;
    }
    return nullptr;
}

// =========================================================
// 4. SORTING OPERATIONS (Bubble Sort)
// Time Complexity: O(n²)
// =========================================================




void sortByCGPA(Node* head, bool ascending = true) {
    if (head == nullptr || head->next == nullptr) return;
    
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;
    
    do {
        swapped = false;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            bool condition = ascending ? (ptr1->data.cgpa > ptr1->next->data.cgpa)
                                       : (ptr1->data.cgpa < ptr1->next->data.cgpa);
            if (condition) {
                
                Student temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}










// =========================================================
// 5. DISPLAY & TRAVERSAL OPERATIONS
// Time Complexity: O(n)
// =========================================================


void displayAll(Node* head) {
    if (head == nullptr) {
        cout << "The structure is currently empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->data.studentID 
             << " | Name: " << current->data.fullName 
             << " | Programme: " << current->data.programmeCode
             << " | Year: " << current->data.yearOfStudy
             << " | CGPA: " << current->data.cgpa << endl;
        current = current->next;
    }
}


int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// =========================================================
// CSV FILE PARSING ENGINE
// =========================================================
string resolveDataFilePath(const string& filename) {
    vector<filesystem::path> candidates;
    filesystem::path cwd = filesystem::current_path();

    candidates.push_back(filesystem::path(filename));
    candidates.push_back(cwd / filename);
    candidates.push_back(cwd.parent_path() / filename);
    candidates.push_back(cwd.parent_path().parent_path() / filename);

    for (const auto& path : candidates) {
        if (filesystem::exists(path) && filesystem::is_regular_file(path)) {
            return path.string();
        }
    }

    return filename;
}

bool findStudentInAllDatasets(const string& id, string& foundFile) {
    vector<string> files = {"students_500.csv", "students_2000.csv", "students_8000.csv", "students_30000.csv"};

    for (const auto& fileName : files) {
        string resolvedPath = resolveDataFilePath(fileName);
        ifstream file(resolvedPath);
        if (!file.is_open()) continue;

        string line;
        getline(file, line);
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string currentID;
            getline(ss, currentID, ',');
            if (currentID == id) {
                foundFile = fileName;
                return true;
            }
        }
    }

    return false;
}

void loadFromCSV(Node* &head, const string& filename) {
    string resolvedFilename = resolveDataFilePath(filename);
    ifstream file(resolvedFilename);
    if (!file.is_open()) {
        cout << "Could not open dataset file: " << filename << endl; // Error
        return;
    }
    clearList(head);
    string line;
    getline(file, line);
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, prog, yearStr, cgpaStr, contact;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, prog, ',');
        getline(ss, yearStr, ',');
        getline(ss, cgpaStr, ',');
        getline(ss, contact, ',');
        
        if (id.empty() || name.empty() || cgpaStr.empty()) continue;
        
        try {
            int year = stoi(yearStr);
            double cgpa = stod(cgpaStr);
            if (cgpa < 0.0 || cgpa > 4.0) continue; 
            
            Student s = {id, name, prog, year, cgpa, contact};
            insertAtEnd(head, s);
        } catch (...) {
            cout << "Error parsing line: " << line << endl; 
            continue;
        }
    }
    file.close();
}


void runAllDatasetsBenchmark();

// =========================================================
// MAIN EXECUTIVE INTERFACE
// =========================================================
int main() {
    Node* head = nullptr;
    int choice;
    string filename = "";

    system("cls");
    cout << "=== STUDENT RECORD MANAGEMENT SYSTEM (Role 3: Linked List) ===\n";
    cout << "Select a dataset size to load initially:\n";
    cout << "1. students_500.csv\n";
    cout << "2. students_2000.csv\n";
    cout << "3. students_8000.csv\n";
    cout << "4. students_30000.csv\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;

    if (choice == 1) filename = "students_500.csv";
    else if (choice == 2) filename = "students_2000.csv";
    else if (choice == 3) filename = "students_8000.csv";
    else if (choice == 4) filename = "students_30000.csv";
    else {
        cout << "Invalid choice. Exiting system.\n";
        return 0;
    }

    loadFromCSV(head, filename);

    do {
        system("cls"); 
        cout << "=========================================================\n";
        cout << "                      SYSTEM MENU                        \n";
        cout << "=========================================================\n";
        cout << "1. Display All Student Records\n";
        cout << "2. Sort Records by CGPA (Bubble Sort) -> Auto Displays List\n";
        cout << "3. Search Student by ID (Linear Search)\n";
        cout << "4. Search Student by Name (Linear Search)\n";
        cout << "5. Insert a New Student Record\n";
        cout << "6. Delete a Student Record by ID\n";
        cout << "7. Check Total Record Count\n";
        cout << "8. RUN FULL AUTOMATED TIME BENCHMARK ON ALL 4 DATASETS\n"; 
        cout << "9. Exit Program\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                displayAll(head);
                pressEnterToContinue();
                break;
            case 2:
                system("cls");
                cout << "Sorting records via Bubble Sort... please wait...\n";
                sortByCGPA(head, true);
                cout << "[SUCCESS] Dataset items re-ordered successfully!\n\n";
                displayAll(head);
                pressEnterToContinue();
                break;
            case 3: {
                system("cls");
                string targetID;
                cout << "Enter Student ID to find: "; cin >> targetID;
                Node* result = searchByID(head, targetID);
                if (result != nullptr) cout << "[FOUND] Name: " << result->data.fullName << "\n";
                else {
                    string foundFile;
                    if (findStudentInAllDatasets(targetID, foundFile)) {
                        cout << "[NOT FOUND IN LOADED DATASET] This ID exists in: " << foundFile << "\n";
                    } else {
                        cout << "[NOT FOUND]\n";
                    }
                }
                pressEnterToContinue();
                break;
            }
            case 4: {
                system("cls");
                string targetName;
                cout << "Enter Full Name to search: "; cin.ignore(); getline(cin, targetName);
                Node* result = searchByName(head, targetName);
                if (result != nullptr) cout << "[FOUND] ID: " << result->data.studentID << "\n";
                else cout << "[NOT FOUND]\n";
                pressEnterToContinue();
                break;
            }
            case 5: {
                system("cls");
                Student s; int insChoice;
                cout << "Enter ID: "; cin >> s.studentID;
                cout << "Enter Name: "; cin.ignore(); getline(cin, s.fullName);
                cout << "Enter Programme: "; cin >> s.programmeCode;
                cout << "Enter Year: "; cin >> s.yearOfStudy;
                cout << "Enter CGPA: "; cin >> s.cgpa;
                cout << "Enter Contact: "; cin >> s.contactNumber;
                cout << "\n1. Head\n2. Tail\n3. Position\nChoice: "; cin >> insChoice;
                if (insChoice == 1) insertAtBeginning(head, s);
                else if (insChoice == 2) insertAtEnd(head, s);
                else if (insChoice == 3) { int pos; cout << "Enter index: "; cin >> pos; insertAtPosition(head, s, pos); }
                pressEnterToContinue();
                break;
            }
            case 6: {
                system("cls");
                string targetID;
                cout << "Enter ID to delete: "; cin >> targetID;
                if (deleteByID(head, targetID)) cout << "[SUCCESS]\n";
                else cout << "[FAILED]\n";
                pressEnterToContinue();
                break;
            }
            case 7:
                system("cls");
                cout << "Total Active Nodes: " << countNodes(head) << "\n";
                pressEnterToContinue();
                break;
            case 8:
                system("cls");
                runAllDatasetsBenchmark();
                pressEnterToContinue();
                break;
            case 9:
                system("cls");
                cout << "Goodbye!\n";
                break;
        }
    } while (choice != 9);

    clearList(head);
    return 0;
}







void runAllDatasetsBenchmark() {
    vector<string> files = {"students_500.csv", "students_2000.csv", "students_8000.csv", "students_30000.csv"};
    for (const auto &f : files) {
        Node* headLocal = nullptr;
        cout << "Benchmarking dataset: " << f << "\n";

        auto t1 = chrono::high_resolution_clock::now();
        loadFromCSV(headLocal, f);
        auto t2 = chrono::high_resolution_clock::now();
        auto loadMs = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
        cout << "  Load time: " << loadMs << " ms\n";

        t1 = chrono::high_resolution_clock::now();
        sortByCGPA(headLocal, true);
        t2 = chrono::high_resolution_clock::now();
        auto sortMs = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
        cout << "  Sort time: " << sortMs << " ms\n";

        cout << "  Total nodes: " << countNodes(headLocal) << "\n\n";
        clearList(headLocal);
    }
}

