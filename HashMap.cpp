// Hash Map
// Group Project #4
// Drew Clark, Thomas Bendall, Christelle Mbemba
// 11/7/2023

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printMenu(){
    cout << "H: prints this menu" << endl;
    cout << "I: insert key-value pair" << endl;
    cout << "R: remove key-value pair" << endl;
    cout << "F: find value from key" << endl;
    cout << "C: clear hashMap" << endl;
    cout << "E: Is hashMap empty" << endl;
    cout << "Q: Quit" << endl << endl;
}

void search(string pin, const unordered_map<string, int> hM){
    auto itr = hM.find(pin);
    if(itr != hM.end()){
        cout << "Found!" << endl << endl;
    }
    else{
        cout << "Not Found!" << endl << endl;
    }
}

int main(){
    unordered_map<string, int> hashMap;

    string key;
    int count = 0;
    printMenu();

    do{
        for(const auto& pair : hashMap){
            cout << pair.first << ": " << pair.second << endl;
        }

        char cmd;
        cout << "command: ";
        cin >> cmd;
        cout << endl;


        switch(cmd){
            case 'H':
                printMenu();
                break;

            case 'I':
                cout << "Insert key: ";
                cin >> key;
                cout << endl << endl;
                hashMap[key] = count;
                count++;
                break;

            case 'R':
                cout << "Removal key: ";
                cin >> key;
                cout << endl << endl;
                hashMap.erase(key);
                break;

            case 'F':
                cout << "Find: ";
                cin >> key;
                cout << endl << endl;
                search(key, hashMap);
                break;

            case 'C':
                hashMap.clear();
                break;

            case 'E':
                if(hashMap.empty()){
                    cout << "Empty" << endl << endl;
                }
                else{
                    cout << "Not Empty" << endl << endl;
                }
                break;

            case 'Q':
                return 0;

            default:
                cout << "Invalid Command" << endl << endl;
        }
    }while(1);

    return 0;
}
