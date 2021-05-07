#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "TicTacToe.h"

using namespace std;


int main() {
    while(1) {
        //whether continue the game or not
        printf("If you want to continue this game, please input 1.\n");
        printf("If you want to end this game, please input 0.\n");
        int ifContinue ;
        scanf("%d",&ifContinue);
        if(!ifContinue) {
            printf("The game is ended.");
            return 0;
        }
        
        //reset the board 
        TicTacToe Tictactoe;

        //print the board
        Tictactoe.print();


        //play the game 
        while(!Tictactoe.isDone()) {

            //input the row,col
            printf("It turns %c\n",Tictactoe.getCurrentPlayer());
            printf("Please input a valid move(the row and the col)\n");
            int row,col;
            while(scanf("%d%d",&row,&col)) {
                if(Tictactoe.isValidMove(row,col)) break;
                printf("Your input is't a valid move, please input again.\n");
            }

            //make move
            Tictactoe.makeMove(row,col);
            Tictactoe.print();

            //find winner
            if(Tictactoe.getWinner()!='-') {
                printf("The winner is %c\n",Tictactoe.getWinner());
                break;
            } 
        }
        
        printf("The game is end.\n");
    }
    return  0;
}