#include <iostream>
#include <cstdio>
#include "List/List.h"

using namespace std;

enum ACTIONS {
    SEND_SHIP_TO_WAR = 0,
    REPAIRED_SHIP = -1,
    PRINT_WAITING_SHIPS = -2,
    PRINT_BROKEN_SHIPS = -3
};


int main() {
    int N = 0;
    List<int> ships = *new List<int>();
    List<int> broken = *new List<int>();
    List<int> war = *new List<int>();

    cout << "Insert the number of ships:" << endl;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int shipId = 0;
        cout << "Insert the ship ID:" << endl;
        cin >> shipId;
        ships.insertOnFront(shipId);
    }

    int action;
    while (scanf("%d", &action) != EOF) {
        switch (action) {
            case SEND_SHIP_TO_WAR:
                cout << "Ship " << ships.getFirst() << " on war." << endl;
                war.insertOnFront(ships.getFirst());
                ships.popFirst();
                break;
            case REPAIRED_SHIP:
                ships.insertOnFront(broken.getFirst());
                broken.popFirst();
                break;
            case PRINT_WAITING_SHIPS:
                cout << "WAITING SHIPS:" << endl;
                ships.showList();
                break;
            case PRINT_BROKEN_SHIPS:
                cout << "BROKEN SHIPS:" << endl;
                broken.showList();
                break;
            default:
                //TODO: Implement the get item with value K on List and remove Item of the position;
                cout << "Ship " << action << " broken." << endl;
                break;
        }
    }

    cout << "WAITING SHIPS:" << endl;
    ships.showList();
    cout << "ON WAR:" << endl;
    war.showList();

    return 0;
}
