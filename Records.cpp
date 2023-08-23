#include <iostream>
using namespace std;

// Node class to represent each employee record
class Node {
private:
    int empID;
    string name;
    double salary;
    Node* left;
    Node* right;

public:
    Node(int id, string n, double s) {
        empID = id;
        name = n;
        salary = s;
        left = NULL;
        right = NULL;
    }

    // Getter methods to access private data members
    int getEmpID() {
        return empID;
    }

    string getName() {
        return name;
    }

    double getSalary() {
        return salary;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }
void setLeft(Node* node) {
        this->left = node;
    }

    void setRight(Node* node) {
        this->right = node;
    }

};

// Binary Search Tree class to store and manage employee records
class BST {
private:
    Node* root;

    // print the existing employee record
    void printInOrder(Node* node) {
        if (node != NULL) {
            printInOrder(node->getLeft());
            cout << "ID: " << node->getEmpID() << ", Name: " << node->getName() << ", Salary: " << node->getSalary() << endl;
            printInOrder(node->getRight());
        }
    }

public:
    BST() {
        root = NULL;
    }

    // method to search for an employee record by ID
    Node* search(int id) {
        Node* current = root;
        while (current != NULL) {
            if (current->getEmpID() == id) {
                return current;
            } else if (current->getEmpID() > id) {
                current = current->getLeft();
            } else {
                current = current->getRight();
            }
        }
        return NULL;
    }

    // method to insert a new employee record
    void insert(int id, string name) {
    	 int empid = id % 1000;
    	 int salary = id % 100000;
        Node* new_node = new Node(empid, name, salary);
        if (root == NULL) {
            root = new_node;
        } else {
            Node* current = root;
            while (true) {
                if (current->getEmpID() == id) {
                    delete new_node;
                    return;
                } else if (current->getEmpID() > id) {
                    if (current->getLeft() == NULL) {
                        current->setLeft(new_node);
                        break;
                    } else {
                        current = current->getLeft();
                    }
                } else {
                    if (current->getRight() == NULL) {
                        current->setRight(new_node);
                        break;
                    } else {
                        current = current->getRight();
                    }
                }
            }
        }
    }

    void printEmployeeRecords() {
        if (root == NULL) {
            cout << "No employee records found." << endl;
        } else {
            // Traverse the tree in-order to print the existing records
            cout << "Existing Employee Records:" << endl;
            printInOrder(root);
            cout << endl;
        }
    }
};

int main() {
    BST bst;

    bst.insert(123456789, "Fahad");

    int choice;
    while (true) {
        cout << "Enter 1 to check the existing record" << endl;
        cout << "Enter 2 to insert a new employee record" << endl;
        cout << "Enter 3 to search for an employee record" <<endl;
                cout << "Enter 4 to exit" << endl << endl;
        cin >> choice;

        if (choice == 1) {
            bst.printEmployeeRecords();
        } else if (choice == 2) {
            int id;
            string name;
            double salary;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            
            bst.insert(id, name);
        } else if (choice == 3) {
            int id;
            cout << "Enter employee ID: ";
            cin >> id;
            Node* result = bst.search(id);
            if (result != NULL) {
                cout << "Employee found:--> " << endl;
                cout << "ID: " << result->getEmpID() << endl;
                cout << "Name: " << result->getName() << endl;
                cout << "Salary: " << result->getSalary() << endl << endl;
            } else {
                cout << "Employee not found" << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
        cout << endl;
    }

    return 0;
}

