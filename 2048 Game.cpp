#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4;

class Game2048 {
public:
    void play() {
        initBoard();
        printBoard();

        while (!isGameOver()) {
            char move;
            cout << "Enter move (W/A/S/D): ";
            cin >> move;

            if (makeMove(move)) {
                addTile();
                printBoard();
            }
        }

        cout << "Game over!" << endl;
    }

private:
    int board[SIZE][SIZE];

    void initBoard() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board[i][j] = 0;
            }
        }

        addTile();
        addTile();
    }

    void printBoard() {
        cout << "Score: " << calculateScore() << endl;

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void addTile() {
        vector<pair<int, int>> emptyCells;

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    emptyCells.push_back(make_pair(i, j));
                }
            }
        }

        if (emptyCells.empty()) {
            return;
        }

        srand(time(0));
        int randomIndex = rand() % emptyCells.size();
        int newValue = (rand() % 2 + 1) * 2;
        board[emptyCells[randomIndex].first][emptyCells[randomIndex].second] = newValue;
    }

    bool isGameOver() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == 0) {
                    return false;
                }
                if (i < SIZE - 1 && board[i][j] == board[i + 1][j]) {
                    return false;
                }
                if (j < SIZE - 1 && board[i][j] == board[i][j + 1]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool makeMove(char move) {
        bool moved = false;

        for (int i = 0; i < SIZE; ++i) {
            vector<int> line;

            for (int j = 0; j < SIZE; ++j) {
                if (move == 'W' || move == 'w') {
                    line.push_back(board[j][i]);
                } else if (move == 'A' || move == 'a') {
                    line.push_back(board[i][j]);
                } else if (move == 'S' || move == 's') {
                    line.push_back(board[SIZE - 1 - j][i]);
                } else if (move == 'D' || move == 'd') {
                    line.push_back(board[i][SIZE - 1 - j]);
                }
            }

            mergeLine(line);
            
            for (int j = 0; j < SIZE; ++j) {
                if (move == 'W' || move == 'w') {
                    moved |= (board[j][i] != line[j]);
                    board[j][i] = line[j];
                } else if (move == 'A' || move == 'a') {
                    moved |= (board[i][j] != line[j]);
                    board[i][j] = line[j];
                } else if (move == 'S' || move == 's') {
                    moved |= (board[SIZE - 1 - j][i] != line[j]);
                    board[SIZE - 1 - j][i] = line[j];
                } else if (move == 'D' || move == 'd') {
                    moved |= (board[i][SIZE - 1 - j] != line[j]);
                    board[i][SIZE - 1 - j] = line[j];
                }
            }
        }

        return moved;
    }

    void mergeLine(vector<int>& line) {
        for (int i = 0; i < SIZE - 1; ++i) {
            if (line[i] == line[i + 1] && line[i] != 0) {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        vector<int> temp;
        for (int i = 0; i < SIZE; ++i) {
            if (line[i] != 0) {
                temp.push_back(line[i]);
            }
        }

        while (temp.size() < SIZE) {
            temp.push_back(0);
        }

        line = temp;
    }

    int calculateScore() {
        int score = 0;

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                score += board[i][j];
            }
        }

        return score;
    }
};

int main() {
    Game2048 game;
    game.play();

    return 0;
}
