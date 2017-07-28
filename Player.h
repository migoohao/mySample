//
// Created by 钟志豪 on 2017/7/23.
//

#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include <vector>
#include "Gametools.h"

using namespace std;

class Player {
public:
    Player(int id, Gametools *game,Position &startPoint);

    bool findAllOptions();

    PickedPiece &randomStep();

    void addPutableOption(int x,int y);

private:
    int id;
    Position startPoint = {-1, -1};

private:
    Gametools *game;
    vector<PickedPiece> options;
    bool firstPutStatus = true;
};


#endif //BLOKUS_PLAYER_H
