#include<iostream>

using namespace std;
const int SIZE = 3;
char board [SIZE][SIZE]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentPlayer = 'X';
void displayBoard(){
    cout<<"Current Board:"<<endl;
    for(int i= 0;i< SIZE;i++){
        for(int j=0;j<SIZE;j++){
           cout<< board[i][j]<<" "; 
           if(j< SIZE - 1)cout<<"| ";
        }
        cout<<endl;
        if(i<SIZE - 1)cout<<"--------"<<endl;
    }
}

bool checkWin(){
    // Check rows
    for (int i= 0;i<SIZE;i++)
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
       return true;

    // check columns
    for (int i=0;i<SIZE; i++)
     if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
          return true;

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
     if(board[0][2] == board[1][1] && board[1][1]== board[2][0])
        return true;

     return false;
}
bool checkDraw() {
    for(int i=0;i<SIZE;i++)
      for(int j= 0;j<SIZE;j++)
         if(board[i][j] != 'X' && board[i][j] !='O')
         return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer =='X') ? 'O' : 'X';
}

void makeMove() {
    int move;
    bool validMove = false;
    while (!validMove)
    {
        cout <<" Player"<< currentPlayer <<",enter your move(1-9): ";
        cin>>move;

        if (move < 1 || move > 9){
            cout<< "Invalid move! Please enter a number between 1 to 9."<<endl;
            continue;
        }

        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O'){
            cout<<"That spot is already taken! Try again."<< endl;
        } else {
            board[row][col] = currentPlayer;
            validMove = true ;
        }
    }
    
}

void resetBoard(){
    char resetVal = '1';
    for(int i= 0;i<SIZE;i++)
        for ( int j = 0;j<SIZE;j++)
             board[i][j] = resetVal++;
}

int main(){
    bool playAgain = true;
    char response;

    while (playAgain){
        resetBoard();
        currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;
         
         while(!gameWon && !gameDraw) {
            displayBoard();
            makeMove();

            gameWon = checkWin();
            if (gameWon){
                displayBoard();
                cout << "Player " << currentPlayer <<" wins!"<<endl;
            } else {
                gameDraw = checkDraw();
                if (gameDraw) {
                   displayBoard();
                   cout << "The game is a Draw!"<< endl; 
            
                } else {
                    switchPlayer();
                }
            }
         }

         cout<< "Do you want to play again? (y/n): ";
         cin>> response;
         playAgain = (response == 'y'|| response == 'Y');
    }


    return 0 ;
}