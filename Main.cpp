#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
private:
    char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string p1;
    string p2;
    char token = 'X';
    bool tie = false;

public:
    void printBoard() {
        cout << "  |    |  \n";
        cout << " " << space[0][0] << "| " << space[0][1] << "  |" << space[0][2] << " \n";
        cout << "__|____|__\n";
        cout << "  |    |  \n";
        cout << " " << space[1][0] << "| " << space[1][1] << "  |" << space[1][2] << " \n";
        cout << "__|____|__\n";
        cout << "  |    |  \n";
        cout << " " << space[2][0] << "| " << space[2][1] << "  |" << space[2][2] << " \n";
        cout << "  |    |  \n";
    }

    void getPlayerMove() {
        int digit;
        cout << (token == 'X' ?  p1 :  p2) << " enter your move: ";
        cin >> digit;


        if (digit < 1 || digit > 9 || space[(digit - 1) / 3][(digit - 1) % 3] == 'X' || space[(digit - 1) / 3][(digit - 1) % 3] == 'O') {
            cout << "Invalid move! Please try again." << endl;
            getPlayerMove();
            return;
        }

        space[(digit - 1) / 3][(digit - 1) % 3] = token;
        token = (token == 'X') ? 'O' : 'X';
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (space[i][0] == space[i][1] && space[i][0] == space[i][2])
                return true;
            if (space[0][i] == space[1][i] && space[0][i] == space[2][i])
                return true;
        }
        if (space[0][0] == space[1][1] && space[0][0] == space[2][2])
            return true;
        if (space[0][2] == space[1][1] && space[0][2] == space[2][0])
            return true;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (space[i][j] != 'X' && space[i][j] != 'O')
                    return false;
            }
        }
        tie = true;
        return false;
    }

    void playGame() {
        cout << "Enter player 1 name: ";
        cin.ignore();
        getline(cin, p1);
        cout << "Enter player 2 name: ";
        getline(cin, p2);

        while (!checkWin() && !tie) {
            printBoard();
            getPlayerMove();
        }

        printBoard();

        if (checkWin() && !tie)
            cout << ((token == 'X') ? p2 : p1) << " wins!" << endl;
        else
            cout << "It's a tie!" << endl;
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
