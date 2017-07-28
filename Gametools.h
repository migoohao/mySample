//
// Created by 钟志豪 on 2017/7/23.
//

#ifndef BLOKUS_GAMETOOLS_H
#define BLOKUS_GAMETOOLS_H

#include <vector>

#define PIECESIZE 5
#define PIECENUM 21
#define BOARDSIZE 20
#define TURNNUM 8
#define PLAYERMAX 4

using namespace std;

struct Position {
    int x;
    int y;

    Position(int u, int v);
};

struct PickedPiece {
    int id;
    vector<Position> places;
};

struct Piece {
    int piece[PIECESIZE][PIECESIZE];
};

class Gametools {
public:
    bool putable(int playerId, int x, int y, int pieceNum, int turnNum);

    bool putableFirst(Position &startPoint, int x, int y, int pieceNum, int turnNum);

    bool isTurnBan(int pieceNum, int turnNum);

    PickedPiece getOption(int x,int y,int pieceNum,int turnNum);

private:
    void turn(int turnNum, const Piece &ori, Piece &res);

    void initDiamond();

    void initDiamondPositions();

    void pushDiamondPosition(int pieceNum, int turnNum, Piece &onePiece);

    bool isInBoard(int u, int v);

    bool isEmpty(int u, int v);

    bool isNextToSelf(int playerId, int u, int v);

    bool isCornerToSelf(int playerId, int u, int v);

private:
    const Piece IRONS[PIECENUM] = {
            //No.0
            {
                    {1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.1
            {
                    {1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.2
            {
                    {1, 1, 1, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.3
            {
                    {1, 1, 1, 1, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.4
            {
                    {1, 1, 1, 1, 1,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.5
            {
                    {1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.6
            {
                    {1, 1, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.7
            {
                    {1, 1, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.8
            {
                    {1, 1, 0, 0, 0,
                            0, 1, 1, 0, 0,
                            0, 0, 1, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.9
            {
                    {1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.10
            {
                    {1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.11
            {
                    {1, 0, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.12
            {
                    {1, 0, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.13
            {
                    {1, 1, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.14
            {
                    {0, 1, 0, 0, 0,
                            1, 1, 1, 0, 0,
                            0, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.15
            {
                    {1, 0, 0, 0, 0,
                            1, 1, 1, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.16
            {
                    {1, 1, 1, 0, 0,
                            1, 0, 0, 0, 0,
                            1, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.17
            {
                    {0, 1, 1, 0, 0,
                            1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.18
            {
                    {0, 1, 1, 0, 0,
                            1, 1, 0, 0, 0,
                            0, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.19
            {
                    {0, 1, 1, 0, 0,
                            0, 1, 0, 0, 0,
                            1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            },
            //No.20
            {
                    {0, 1, 1, 1, 0,
                            1, 1, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0}
            }
    };
    const int TURNBAN[PIECENUM] = {
            0xfe,//0 1111 1110 fe
            0xfc,//1 1111 1100 fc
            0xfc,//2
            0xfc,//3
            0xfc,//4
            0xf0,//5
            0xfe,//6
            0x00,//7
            0xf0,//8
            0x00,//9
            0x00,//10
            0xf0,//11
            0x00,//12
            0xf0,//13
            0xfe,//14
            0xf0,//15
            0xf0,//16
            0xcc,//17
            0x00,//18
            0xcc,//19
            0x00 //20
    };
    int board[BOARDSIZE][BOARDSIZE] = {0};
    Piece diamond[PIECENUM][TURNNUM];
    vector<Position> diamondPositions[PIECENUM][TURNNUM];
    bool playerPieceUsed[PLAYERMAX][PIECENUM] = {false};
};


#endif //BLOKUS_GAMETOOLS_H
