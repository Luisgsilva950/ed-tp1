#include <iostream>
#include <cstdio>
#include "headers/BasicList.h"
#include "headers/Stack.h"
#include "headers/Queue.h"

using namespace std;

enum ACTIONS {
    SEND_SHIP_TO_WAR = 0,
    REPAIRED_SHIP = -1,
    PRINT_WAITING_SHIPS = -2,
    PRINT_BROKEN_SHIPS = -3
};

Stack<int> getShipIds(int numberOfships){
    Stack<int> ships = *new Stack<int>();
    for (int i = 0; i < numberOfships; i++) {
        int shipId = 0;
        cin >> shipId;
        ships.insert(shipId);
    }
    return ships;
}

void executeWar(Stack<int> ships){
    Queue<int> broken = *new Queue<int>();
    BasicList<int> war = *new BasicList<int>();
    int action;
    while (scanf("%d", &action) != EOF) {
        switch (action) {
            case SEND_SHIP_TO_WAR:
                cout << "nave " << ships.get() << " em combate" << endl;
                war.insertOnFront(ships.get());
                ships.pop();
                break;
            case REPAIRED_SHIP:
                cout << "nave " << broken.get() << " consertada" << endl;
                ships.insert(broken.get());
                broken.pop();
                break;
            case PRINT_WAITING_SHIPS:
                ships.showList();
                break;
            case PRINT_BROKEN_SHIPS:
                broken.showList();
                break;
            default:
                cout << "nave " << action << " avariada" << endl;
                broken.insert(action);
                war.removeByValue(action);
                break;
        }
    }
}

int main() {
    int N = 0;
    cin >> N;
    Stack<int> ships = getShipIds(N);
    executeWar(ships);
    return 0;
}