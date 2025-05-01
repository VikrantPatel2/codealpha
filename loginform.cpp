#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function for registration
void registration() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Enter Username: ";
    cin >> username;

    // Check if user already exists
    ifstream checkFile(username + ".txt");
    if (checkFile.is_open()) {
        cout << "Username already exists. Try a different one.\n";
        checkFile.close();
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file(username + ".txt");
    if (file.is_open()) {
        file << username << endl;
        file << password;
        file.close();
        cout << "Registration Successful!\n";
    } else {
        cerr << "Error creating user file.\n";
    }
}

// Function for login
void login() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter Username: ";
    cin >> username;

    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "No such user found.\n";
        return;
    }

    string stored_username, stored_password;
    getline(file, stored_username);
    getline(file, stored_password);

    cout << "Enter Password: ";
    cin >> password;

    if (stored_username == username && stored_password == password) {
        cout << "Login Successful!\n";
    } else {
        cout << "Invalid Credentials.\n";
    }
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n=== Login and Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
