//
// Created by 钟志豪 on 2017/7/23.
//

#include "Gametools.h"

bool Gametools::isTurnBan(int pieceNum, int turnNum) {
    return (bool) (TURNBAN[pieceNum] & (1 << turnNum));
}

void Gametools::turn(int turnNum, const Piece &ori, Piece &res) {
    for (int u = 0; u < PIECESIZE; ++u) {
        for (int v = 0; v < PIECESIZE; ++v) {
            switch (turnNum) {
                case 0:
                    res.piece[u][v] = ori.piece[u][v];
                    break;
                case 1:
                    res.piece[u][v] = ori.piece[PIECESIZE - v - 1][u];
                    break;
                case 2:
                    res.piece[u][v] = ori.piece[PIECESIZE - u - 1][PIECESIZE - v - 1];
                    break;
                case 3:
                    res.piece[u][v] = ori.piece[v][PIECESIZE - u - 1];
                    break;
                case 4:
                    res.piece[u][v] = ori.piece[u][PIECESIZE - v - 1];
                    break;
                case 5:
                    res.piece[u][v] = ori.piece[PIECESIZE - v - 1][PIECESIZE - u - 1];
                    break;
                case 6:
                    res.piece[u][v] = ori.piece[PIECESIZE - u - 1][v];
                    break;
                case 7:
                    res.piece[u][v] = ori.piece[v][u];
                    break;
                default:
                    break;
            }
        }
    }
}

void Gametools::initDiamond() {
    for (int i = 0; i < PIECENUM; ++i) {
        for (int t = 0; t < TURNNUM; ++t) {
            turn(t, IRONS[i], diamond[i][t]);
        }
    }
}

void Gametools::initDiamondPositions() {
    for (int i = 0; i < PIECENUM; ++i) {
        for (int t = 0; t < TURNNUM; ++t) {
            pushDiamondPosition(i, t, diamond[i][t]);
        }
    }
}

void Gametools::pushDiamondPosition(int pieceNum, int turnNum, Piece &onePiece) {
    for (int u = 0; u < PIECESIZE; ++u) {
        for (int v = 0; v < PIECESIZE; ++v) {
            if (0 == onePiece.piece[u][v]) {
                continue;
            }
            diamondPositions[pieceNum][turnNum].emplace_back(Position(u, v));
        }
    }
}

bool Gametools::putable(int playerId, int x, int y, int pieceNum, int turnNum) {
    vector<Position> &diamondPositon = diamondPositions[pieceNum][turnNum];
    bool cornerToSelf = false;
    if (playerPieceUsed[playerId][pieceNum]) {
        return false;
    }
    for (Position &pos:diamondPositon) {
        int u = x + pos.x;
        int v = y + pos.y;
        if (!isInBoard(u, v) || !isEmpty(u, v) || isNextToSelf(playerId, u, v)) {
            return false;
        }
        if (isCornerToSelf(playerId, u, v)) {
            cornerToSelf = true;
        }
    }
    return cornerToSelf;
}

bool Gametools::putableFirst(Position &startPoint, int x, int y, int pieceNum, int turnNum) {
    vector<Position> &diamondPositon = diamondPositions[pieceNum][turnNum];
    bool putStatus = false;
    for (Position &pos:diamondPositon) {
        int u = x + pos.x;
        int v = y + pos.y;
        if (!isInBoard(u, v)) {
            return false;
        }
        if (startPoint.x == u && startPoint.y == v) {
            putStatus = true;
        }
    }
    return putStatus;
}

inline bool Gametools::isInBoard(int u, int v) {
    return u >= 0 && u < BOARDSIZE && v >= 0 && v < BOARDSIZE;
}

inline bool Gametools::isEmpty(int u, int v) {
    return 0 == board[u][v];
}

inline bool Gametools::isNextToSelf(int playerId, int u, int v) {
    return (isInBoard(u - 1, v) && playerId == board[u - 1][v]) ||
           (isInBoard(u + 1, v) && playerId == board[u + 1][v]) ||
           (isInBoard(u, v - 1) && playerId == board[u][v - 1]) ||
           (isInBoard(u, v + 1) && playerId == board[u][v + 1]);
}

inline bool Gametools::isCornerToSelf(int playerId, int u, int v) {
    return (isInBoard(u - 1, v - 1) && playerId == board[u - 1][v - 1]) ||
           (isInBoard(u + 1, v - 1) && playerId == board[u + 1][v - 1]) ||
           (isInBoard(u - 1, v + 1) && playerId == board[u - 1][v + 1]) ||
           (isInBoard(u + 1, v + 1) && playerId == board[u + 1][v + 1]);
}

PickedPiece Gametools::getOption(int x, int y, int pieceNum, int turnNum) {
    vector<Position> diamondPosition = diamondPositions[pieceNum][turnNum];
    PickedPiece option;
    option.id = pieceNum;
    for (Position &pos:diamondPosition) {
        option.places.emplace_back(Position(x + pos.x, y + pos.y));
    }
    return option;
}

Position::Position(int u, int v) : x(u), y(v) {}

