#include <iostream>
#include <cstdio>
#include "./headers/List/List.h"

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

   cin >> N;

    for (int i = 0; i < N; i++) {
        int shipId = 0;
        cin >> shipId;
        ships.insertOnFront(shipId);
    }

    int action;
    while (scanf("%d", &action) != EOF) {
        switch (action) {
            case SEND_SHIP_TO_WAR:
                cout << "nave " << ships.getFirst() << " em combate" << endl;
                war.insertOnFront(ships.getFirst());
                ships.popFirst();
                break;
            case REPAIRED_SHIP:
                cout << "nave " << broken.getFirst() << " consertada" << endl;
                ships.insertOnFront(broken.getFirst());
                broken.popFirst();
                break;
            case PRINT_WAITING_SHIPS:
                ships.showList();
                break;
            case PRINT_BROKEN_SHIPS:
                broken.showList();
                break;
            default:
                cout << "nave " << action << " avariada" << endl;
                broken.insertOnLast(action);
                war.removeByValue(action);
                break;
        }
    }
    return 0;
}
