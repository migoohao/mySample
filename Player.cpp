//
// Created by 钟志豪 on 2017/7/23.
//
//#include <cstdlib>
#include <ctime>
#include <random>
#include "Player.h"

using namespace std;

Player::Player(int id, Gametools *game, Position &startPoint) : id(id), game(game), startPoint(startPoint) {}

bool Player::findAllOptions() {
    options.clear();
    for (int x = -PIECESIZE + 1; x < BOARDSIZE; ++x) {
        for (int y = -PIECESIZE + 1; y < BOARDSIZE; ++y) { ;
        }
    }
    firstPutStatus = false;
    return !options.empty();
}

PickedPiece &Player::randomStep() {
    int index;
    mt19937 rd((unsigned) time(nullptr));
    index = (int) (rd() % options.size());
    return options[index];
}

void Player::addPutableOption(int x, int y) {
    for (int i = 0; i < PIECENUM; ++i) {
        for (int t = 0; t < TURNNUM; ++t) {
            if (game->isTurnBan(i, t)) {
                continue;
            }
            bool canPutStatus;
            if (firstPutStatus) {
                canPutStatus = game->putableFirst(startPoint, x, y, i, t);
            } else {
                canPutStatus = game->putable(id, x, y, i, t);
            }
            if (canPutStatus) {
                options.emplace_back(game->getOption(x, y, i, t));
            }
        }
    }
}
