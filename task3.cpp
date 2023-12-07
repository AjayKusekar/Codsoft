//Tic Tac Toe Game in C++

#include <iostream>
#include <stdlib.h>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the gaming board

void display_board(){

    cout<<"\n\t\t\t    PLAYER [X]\t PLAYER [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";

    cout<<"Kindly Enter the number where you want to place your X or O" <<endl;
}

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer [O] turn : ";
    }
    cin>> choice;

    //switch case for row and colums updated

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //same for O
        board[row][column] = 'O';
        turn = 'X';
    }else {
        cout<<"Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }
    display_board();
}

bool gameover(){
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations ! Player '0' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations ! Player 'X' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!\n\n";
} 