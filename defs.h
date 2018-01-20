#ifndef DEFS_H
#define DEFS_H

#include "stdlib.h"

#define DEBUG //comment this out to disable debug mode.

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - failed ", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf("At Line %d\n " ,__LINE__); \
exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "cChess 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK }; // Describes pieces
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { 
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { WHITE, BLACK, BOTH };

enum { FALSE, TRUE };

// 0 0 0 0 <- bits representing castling rights.
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

typedef struct {
    int move;
    int castlePermission;
    int enPas;
    int fiftyMove;
    U64 posKey;
} S_UNDO;

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; // 00000000

    int KingSquare[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePermission;

    U64 posKey;

    int pieceNumber[13];
    int bigPieces[3];
    int majorPieces[3];
    int minorPieces[3];

    S_UNDO history[MAXGAMEMOVES];

    // piece list
    int pieceList[13][10];
    // pieceList[wN] [0] = E1;
} S_BOARD;

/* MACROS */

#define FR2SQ(f,r) ( (21 + (f)) + ((r) * 10))
#define SQ64(sq120) Square120ToSquare64[sq120]
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)

/* GLOBALS */

extern int Square120ToSquare64[BRD_SQ_NUM];
extern int Square64ToSquare120[64];

/* FUNCTIONS */

// init.c
extern void AllInit();

// bitboards.c
extern void PrintBitBoard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);
#endif