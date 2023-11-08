// Hash Map
// Group Project #4
// Drew Clark, Thomas Bendall, Christelle Mbemba
// 11/7/2023

// Author: Drew Clark
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// DC
// Prints Options
void printMenu(){
    cout << "H: prints this menu" << endl;
    cout << "I: insert key-value pair" << endl;
    cout << "R: remove key-value pair" << endl;
    cout << "F: find value from key" << endl;
    cout << "C: clear hashMap" << endl;
    cout << "E: Is hashMap empty" << endl;
    cout << "Q: Quit" << endl << endl;
}

// DC
// Calls the .find() function
// Prints status
void search(string pin, const unordered_map<string, int> hM){
    auto itr = hM.find(pin);
    if(itr != hM.end()){
        cout << "Found!" << endl << endl;
    }
    else{
        cout << "Not Found!" << endl << endl;
    }
}

// DC
// Driver
int main(){
    unordered_map<string, int> hashMap;

    // Input Variables
    string key;
    int count = 0;

    // Intial Call to printMenu
    printMenu();

    // DC
    // Do while loop implementation of the unordered_map library
    do{
        // DC
        // Prints all elements of the HashMap
        for(const auto& pair : hashMap){
            cout << pair.first << ": " << pair.second << endl;
        }

        // Command Inputs
        char cmd;
        cout << "command: ";
        cin >> cmd;
        cout << endl;

        // DC
        // Switch to determine operation
        switch(cmd){
            case 'H':
                printMenu();
                break;

            case 'I':
                cout << "Insert key: ";
                cin >> key;
                cout << endl << endl;
                // Insertion
                hashMap[key] = count;
                count++;
                break;

            case 'R':
                cout << "Removal key: ";
                cin >> key;
                cout << endl << endl;
                // Removal
                hashMap.erase(key);
                break;

            case 'F':
                cout << "Find: ";
                cin >> key;
                cout << endl << endl;
                // Search
                search(key, hashMap);
                break;

            case 'C':
                // Whole HashMap Erasure
                hashMap.clear();
                break;

            case 'E':
                // Checking if HashMap is Empty
                if(hashMap.empty()){
                    cout << "Empty" << endl << endl;
                }
                else{
                    cout << "Not Empty" << endl << endl;
                }
                break;

            case 'Q':
                // Quit
                return 0;

            default:
                // Default Case
                cout << "Invalid Command" << endl << endl;
        }
    }while(1);

    return 0;
}
