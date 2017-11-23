#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void printBoard(char board[3][3]);
bool gameOver(char board[3][3], int totalTurn);
const char playerX='X';
const char playerO='O';

int main()
{
	string input;
	char board[3][3];
	int row, column;
	bool gameOverMain;
	bool turn=0;
	int totalTurn=1;
	bool checkMove=true;
	int placeCol;
	int placeRow;

	for (row=0; row<3; row++)
	{
		for (column=0; column<3; column++)
		{
			board[row][column]=' ';
		}
	}
	while(true)
	{
		system("cls");
		printBoard(board);
		if (turn==0)
		{
			cout << "Player X" << endl;
			turn=1;
		}
		else
		{
			cout << "Player O" << endl;
			turn=0;
		}
		while (checkMove==true)
		{
			cout << "Enter column" << endl;
			while (true)
			{
				getline(cin, input);
				stringstream myStream(input);
				if (myStream >> placeCol && placeCol <=3 && placeCol >= 1)
				{
					break;
				}
				cout << "Enter Column #" << endl;
			}
			cout << "Enter Row" << endl;
			while (true)
			{
				getline(cin, input);
				stringstream myStream(input);
				if (myStream >> placeRow && placeRow <=3 && placeRow >=1)
				{
					break;
				}
				cout << "Enter Row #" << endl;
			}
			if (board[placeRow-1][placeCol-1] == ' ')
			{
				checkMove=false;
			}
			else
			{
				cout << "Invalid Move" << endl;
			}
		}
		checkMove=true;
		if (turn==1)
		{
			board[placeRow-1][placeCol-1] = 'X';
		}
		else
		{
			board[placeRow-1][placeCol-1] = 'O';
		}
		gameOverMain = gameOver(board, totalTurn);
		if(gameOverMain==true)
		{
			return 0;
		}
		totalTurn++;
	}
}

void printBoard(char board[3][3])
{
	cout << "-------" << endl;
	cout << "|" << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << endl;
	cout << "|-|-|-|" << endl;
	cout << "|" << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << endl;
	cout << "|-|-|-|" << endl;
	cout << "|" << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << endl;
	cout << "-------" << endl;
}

bool gameOver(char board[3][3], int totalTurn)
{
	int winner=0;
	if (board[0][0]==playerX && board[0][1]==playerX && board[0][2]==playerX)
	{
		winner=1;
	}
	if (board[1][0]==playerX && board[1][1]==playerX && board[1][2]==playerX)
	{
		winner=1;
	}
	if (board[2][0]==playerX && board[2][1]==playerX && board[2][2]==playerX)
	{
		winner=1;
	}
	if (board[0][0]==playerX && board[1][0]==playerX && board[2][0]==playerX)
	{
		winner=1;
	}
	if (board[0][1]==playerX && board[1][1]==playerX && board[2][1]==playerX)
	{
		winner=1;
	}
	if (board[0][2]==playerX && board[1][2]==playerX && board[2][2]==playerX)
	{
		winner=1;
	}
	if (board[0][0]==playerX && board[1][1]==playerX && board[2][2]==playerX)
	{
		winner=1;
	}
	if (board[2][0]==playerX && board[1][1]==playerX && board[0][2]==playerX)
	{
		winner=1;
	}
	
	if (board[0][0]==playerO && board[0][1]==playerO && board[0][2]==playerO)
	{
		winner=2;
	}
	if (board[1][0]==playerO && board[1][1]==playerO && board[1][2]==playerO)
	{
		winner=2;
	}
	if (board[2][0]==playerO && board[2][1]==playerO && board[2][2]==playerO)
	{
		winner=2;
	}
	if (board[0][0]==playerO && board[1][0]==playerO && board[2][0]==playerO)
	{
		winner=2;
	}
	if (board[0][1]==playerO && board[1][1]==playerO && board[2][1]==playerO)
	{
		winner=2;
	}
	if (board[0][2]==playerO && board[1][2]==playerO && board[2][2]==playerO)
	{
		winner=2;
	}
	if (board[0][0]==playerO && board[1][1]==playerO && board[2][2]==playerO)
	{
		winner=2;
	}
	if (board[2][0]==playerO && board[1][1]==playerO && board[0][2]==playerO)
	{
		winner=2;
	}
	else if (totalTurn==9)
	{
		winner=3;
	}
	switch (winner)
	{
		case 1:
			cout << "X Wins" << endl;
			return true;
		case 2:
			cout << "O Wins" << endl;
			return true;
		case 3:
			cout << "The game is a draw" << endl;
			return true;
		default:
			return false;
	}
}