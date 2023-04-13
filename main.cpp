#include <iostream>
#include <string>

using namespace std;

class TikTacToe {
  char spot{'_'};
  char gameBoard[3][3] = {
      {spot, spot, spot}, {spot, spot, spot}, {spot, spot, spot}};

 public:
  void setMove(int a, int b, char ch) { gameBoard[a][b] = ch; }

  void showBoard(void) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << "|"
             << "_" << gameBoard[i][j] << "_"
             << "|";
      }
      cout << endl;
    }
  }

  bool CheckH(void) {
    // cout << "Horizontal checked" << endl;
    for (int i = 0; i < 3; i++) {
      int j = 0;
      if (gameBoard[i][j] == gameBoard[i][j + 1] &&
          gameBoard[i][j + 1] == gameBoard[i][j + 2] &&
          gameBoard[i][j] != '_') {
        return true;
      }
      // cout << gameBoard[i][j] << gameBoard[i][j + 1] << gameBoard[i][j + 2]
      //      << endl;
      // cout << (gameBoard[i][j] == gameBoard[i][j + 1] &&
      //          gameBoard[i][j + 1] == gameBoard[i][j + 2] &&
      //          gameBoard[i][j] != '_')
      //      << endl;
    }
    return false;
  }

  bool CheckV(void) {
    // cout << "Vertical checked" << endl;
    for (int j = 0; j < 3; j++) {
      int i = 0;
      if (gameBoard[i][j] == gameBoard[i + 1][j] &&
          gameBoard[i + 1][j] == gameBoard[i + 2][j] &&
          gameBoard[i][j] != '_') {
        return true;
      }
      // cout << gameBoard[i][j] << endl
      //      << gameBoard[i + 1][j] << endl
      //      << gameBoard[i + 2][j] << endl;
      // cout << (gameBoard[i][j] == gameBoard[i + 1][j] &&
      //          gameBoard[i + 1][j] == gameBoard[i + 2][j] &&
      //          gameBoard[i][j] != '_')
      //      << endl;
    }
    return false;
  }
  bool checkD(void) {
    if ((gameBoard[0][0] == gameBoard[1][1] &&
         gameBoard[1][1] == gameBoard[2][2] && gameBoard[1][1] != '_') ||
        (gameBoard[2][0] == gameBoard[1][1] &&
         gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] != '_')) {
      return true;
    }
    return false;
  }
};

int main() {
  bool again = false;
  do {
    char againChar = 'Y';
    bool Fbool;
    string player1Name = "X";
    string player2Name = "O";
    int count = 1;
    TikTacToe newGame;
    int a, b;
    char c;
    newGame.showBoard();
    cout << "Enter 1st Player's Name: ";
    cin >> player1Name;
    cout << "Enter 2nd Player's Name: ";
    cin >> player2Name;
    while (!Fbool && count != 9) {
      if (count % 2 != 0) {
        cout << "It's " << player1Name << "'s turn...";
      } else {
        cout << "It's " << player2Name << "'s turn...";
      }
      cout << "Enter your position: " << endl;
      cin >> a >> b;
      cout << "Enter your sign" << endl;
      cin >> c;
      newGame.setMove(a, b, c);

      Fbool = newGame.CheckV() || newGame.CheckH();
      cout << Fbool << endl;
      newGame.showBoard();
      count++;
    }
    if (count % 2 != 0) {
      cout << player1Name << " wins" << endl;

    } else {
      cout << player2Name << " wins" << endl;
    }
    count = 1;
    cout << "Do you Want to play again(Y/N)";
    cin >> againChar;
    if (againChar == 'Y') {
      again = true;
    } else {
      again = false;
    }
  } while (again);
}
