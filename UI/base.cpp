#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;


void printInventory(vector<string> inventory) {
    cout << "Inventory:" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i] << endl;
    }
}

void inventory(string item) {
    vector<string> inventory;
    bool quit = false;

    do {
        // Prompt the user to enter a command or an item
        cout << "Enter a command or an item: ";
        cin >> item;

        // Check if the user wants to quit
        if (item == "q") {
            quit = true;
        }

            // Check if the user wants to display the inventory
        else if (item == "e") {
            printInventory(inventory);
        }

            // Add the item to the inventory
        else {
            inventory.push_back(item);
            cout << "Added " << item << " to the inventory." << endl;
        }

    } while (!quit);

}


string support;
string tpe;
string quiting, input;
void mainMenu() {
    if(support == "Help" || support == "help") {

        cout << "-------------------------------------------" << endl;
        cout << "                MAIN MENU                  " << endl;
        cout << "To quite the game, type 'quit'. " << endl;
        cout << "To continue, type 'continue'. " << endl;
        cout << "To open the inventory, type 'e'. " << endl;
        cin >> tpe;
    }
    if(tpe == "quit" || tpe == "Quit") {
        cout << "Are You Sure You Want to Quit?" << endl;
        cout << "Please Type: Y / N" << endl;
        cin >> quiting;
        if(quiting == "Y" || quiting == "y") {
            cout << "Thank you for enjoying our game!" << endl;
            exit(0);
        }
    }
    if(tpe == "e") {
        input = 'e';
        inventory(input);
    }
}

void gameID() {
    string ID;
    cout << "What is your name?" << endl; //might take this out for later plot twist
    cin >> ID;
    cout << "Hello " << ID << ", Good luck on your journey" << endl;
    cin >> support;
}

void starting() {
    string userStart;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Hello, welcome to the \"Haunted Memories: The School Tragedy\"." << endl << " " << endl;
    cout << "If you need help during the game, type 'help' to go to the main menu." << endl << " " << endl;
    cout << "Type 'start' to start your adventure!" << endl;
    cin >> support;
    if (support == "Start" || support == "start") {

        gameID();
    }
}

void puzzle3() {
    cout << "\033[1;91m##     ##     ########     ##          #########\n";
    cout << "##     ##           ##     ##          ##     ##\n";
    cout << "##     ##           ##     ##          ##     ##\n";
    cout << "#########     ########     ##          #########\033[0m\n";
    cout << "\033[31m##\033[0m     \033[1;91m##           ##     ##\033[0m          \033[31m##\033[0m\n";
    cout << "\033[31m##\033[0m     \033[1;91m##           ##     ##\033[0m          \033[31m##\033[0m\n";
    cout << "\033[31m##\033[0m     \033[1;91m##     ########     ##\033[0m\033[31m######    ##\033[0m\n";
}

int main() {

    starting();
    mainMenu();
    puzzle3();
}