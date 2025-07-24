// task3_tictactoe.cpp

#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else return false;
}

int winner() {
    for(int i = 0; i < 3; i++) {
        // check rows and columns
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
           (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return current_player;
    }

    // check diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return current_player;

    return 0;
}

void swapPlayer() {
    if(current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    cout << "?? Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> current_marker;

    current_player = 1;

    drawBoard();

    for(int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << current_player << ", enter your move (1-9): ";
        cin >> slot;

        if(!placeMarker(slot)) {
            cout << "? Invalid move. Try again.\n";
            i--; continue;
        }

        drawBoard();

        int win = winner();
        if(win == 1 || win == 2) {
            cout << "?? Player " << win << " wins the game!\n";
            break;
        }

        swapPlayer();
    }

    if(winner() == 0) {
        cout << "?? It's a draw!\n";
    }

    return 0;
}
