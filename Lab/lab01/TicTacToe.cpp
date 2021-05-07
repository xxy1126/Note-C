#include <cstdio>
#include <cstdlib>

#include "TicTacToe.h"


TicTacToe::TicTacToe() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            board[i][j]='-';
        }
    }
    currentPlayer='X';
}

void TicTacToe::print() {
    printf(" ");
    for(int i=1;i<=3;i++) {
        printf("%d ",i);
    }
    printf("\n");
    for(int i=1;i<=3;i++) {
        printf("%d ",i);
        for(int j=1;j<=3;j++) {
            printf("%c ",board[i-1][j-1]);
        }
        printf("\n");
    }
}

char TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}

bool TicTacToe::isDone() {
    int sum=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(isValidMove(i+1,j+1)) sum++;
        }
    }
    if(getWinner()!='-' || sum==0) {
        return 1;
    } else {
        return 0;
    }
}

char TicTacToe::getWinner() {
    for(int i=0;i<3;i++) {
        if(board[i][0]=='-') continue ;
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            return board[i][0];
        }
    }
    for(int i=0;i<3;i++) {
        if(board[0][i]=='-') continue ;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
            return board[0][i];
        }
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!='-') return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!='-') return board[0][2];

    return '-';
}

bool TicTacToe::isValidMove(int row,int col) {
    if(row>3 || col>3 || row<1 || col<1) return 0;
    if(board[row-1][col-1]!='-') return 0;
    return 1; 
}

void TicTacToe::makeMove(int row,int col) {
    if(isValidMove(row,col)) {
        board[row-1][col-1]=currentPlayer;
        if(currentPlayer=='X') currentPlayer='O';
        else currentPlayer='X';
    }
}