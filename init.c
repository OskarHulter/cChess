// init.c

#include "defs.h"

int Square120ToSquare64[BRD_SQ_NUM];
int Square64ToSquare120[64];


void InitSquare120To64() {
    int index = 0;
    int file = FILE_A;
    int rank = RANK_1;
    int sq = A1;
    int sq64 = 0;
    for(index = 0; index < BRD_SQ_NUM; ++index) {
        Square120ToSquare64[index] = 65;
    }

    for(index = 0; index < 64; ++index) {
        Square64ToSquare120[index] = 120;
    }

    for(rank = RANK_1; rank <= RANK_8; ++rank) {
        for(file = FILE_A; file <= FILE_H; ++file) {
            sq = FR2SQ(file, rank);
            Square64ToSquare120[sq64] = sq;
            Square120ToSquare64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit() {
    InitSquare120To64();
}