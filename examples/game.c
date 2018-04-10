#include<stdio.h>
#include<stdlib.h>
#include"game.h"

char boars [3][3]; // making this global IN THIS FILE!!!

void humanMove()
{
	
	int row;
	int col;

	printf("Enter a row #(between 0 and 2): ");	
	scanf("%d", &row);
	printf("Great! Now enter a column (between 0 & 2): ");
	scanf("%d", &col);
	
	// make a move
	if( board[row][col] == ' ')
		board[row][col] = 'X';
}
void displayBoard()
{
	int x = 0;
	int y = 0;	

	for (x=0; x<3;x++)
	{
		for(y=0;y<3;y++)
			printf("%c |",board[x][y]);	
		printf("\n");
	}
	printf("********************************\n");
}
void initBoard()
{
	int x = 0;
	int y = 0;	

	// initialize the board ( yo )
	for (x=0; x<3;x++)
	{
		for(y=0;y<3;y++)
			board[x][y] = ' ';	
	}
}
void machineMove()
{
	int row = 4;
	int col = 4;

	while(1)
	{
		row = rand() % 3;
		col = rand() % 3;
		if(board[row][col] == ' ')
			break; 
	}
	board[row][col] = 'O';
}

