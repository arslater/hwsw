#include<stdio.h>
#include"game.h"

int main()
{	
	int spaces_left;
	initBoard();
	for(spaces_left = 0; spaces_left<9;spaces_left++)
	{	
		humanMove();	
		displayBoard();
		spaces_left++;

		machineMove();
		displayBoard();
	}
	return 0;
}

