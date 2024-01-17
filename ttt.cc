#include <iostream>
#include <cstdlib>
using namespace std;

class ticTT {
    public:
    void clearBoard();
    void putMark(int i, int j);
    bool isWin(int mark);
    int getWinner();
    
    friend ostream &operator<<( ostream &output, const ticTT &obj);
    int getmpTY();
    int getX();
    
    private:
    static int const X = 1, O = -1, EMPTY = 0;
    int board[3][3];
    int currentPlayer;
};

void ticTT::clearBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
    currentPlayer = X;
}

void ticTT::putMark(int i, int j){
    board[i][j] = currentPlayer;
    currentPlayer = -currentPlayer;
}

bool ticTT::isWin(int mark){
    int win = 3*mark;
    return ((board[0][0] + board[0][1] + board[0][2] == win)
          ||(board[1][0] + board[1][1] + board[1][2] == win)
          ||(board[2][0] + board[2][1] + board[2][2] == win)
          ||(board[0][0] + board[1][0] + board[2][0] == win)
          ||(board[0][1] + board[1][1] + board[2][1] == win)
          ||(board[0][2] + board[0][2] + board[2][2] == win)
          ||(board[0][0] + board[1][1] + board[2][2] == win)
          ||(board[2][0] + board[1][1] + board[0][2] == win));
}

int ticTT::getWinner(){
    if (isWin(X)) return X;
    else if (isWin(O)) return O;
    else return EMPTY;
}

// overload operator
ostream &operator<<( ostream &output, const ticTT &obj){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            switch(obj.board[i][j]){
                case ticTT::X: output<<"X"; break;
                case ticTT::O: output<<"O"; break;
                case ticTT::EMPTY: output<<" "; break;
            }
            if (j < 2) output<<"|";
        }
        if (i < 2) output<<"\n-+-+-\n";
    }
    return output;
}

int ticTT::getmpTY(){
    return EMPTY;
}
int ticTT::getX(){
    return X;
}

int main(){
    ticTT  ttt;
    ttt.clearBoard();
    ttt.putMark(0,0);   cout << ttt << "\n"; 
    ttt.putMark(1,1);   cout << ttt << "\n\n";
    ttt.putMark(0,1);   cout << ttt << "\n\n";
    ttt.putMark(0,2);   cout << ttt << "\n\n";
    ttt.putMark(2,0);   cout << ttt << "\n\n";
    ttt.putMark(1,2);   cout << ttt << "\n\n";
    ttt.putMark(2,2);   cout << ttt << "\n\n";
    ttt.putMark(2,1);   cout << ttt << "\n\n";
    ttt.putMark(1,0);   cout<<ttt;
    int winner = ttt.getWinner();
    if (winner != ttt.getmpTY())
        cout<<"\n\n"<<(winner == ttt.getX() ? "X" : "O")   <<" wins "<<endl;
    else
        cout<<" Tie "<<endl;
        return EXIT_SUCCESS;
}