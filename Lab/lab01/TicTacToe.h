

#ifndef TICTACTOE_H_
#define TICTACTOE_H_ 

class TicTacToe{
    private:
        char currentPlayer;
        char board[3][3];

    public:
        TicTacToe();
        void print();
        char getCurrentPlayer();
        bool isDone();
        char getWinner();
        bool isValidMove(int row,int col);
        void makeMove(int row,int col);
};

#endif