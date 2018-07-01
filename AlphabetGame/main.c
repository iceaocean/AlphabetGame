#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

void EntrySpace(int num)
{
	int i = 0;
	for (; i < num; i++)
	{
		printf(" ");
	}
}

void EntryLine(int num)
{
	int i = 0;
	for (; i < num; i++)
	{
		printf("\r\n");
	}
}

void PrepareGame()
{
	EntryLine(15);
	EntrySpace(40);
	printf("press anykey to start\r\n");
	getchar();
}

void GameInit(int levelId, int scores)
{
	system("cls");
	EntrySpace(25);

	printf("levels:%d\t", levelId);
	printf("score:%d\r\n", scores);
	EntrySpace(25);

	printf("1---Pause\t");
	printf("0---Exit\r\n");
	for (int i = 0; i < 80; i++)
	{
		printf("-");
	}
	EntryLine(1);
}

void GameOver()
{
	system("cls");
	EntryLine(15);
	EntrySpace(40);
	printf("Game Over!\r\n");
	getchar();
	exit(0);
}

int main()
{
	int levelId = 0, scores = 0;
	PrepareGame();
	
	while (true)
	{
		int lines = 0, num = 0, col = 0;
		GameInit(levelId, scores);
		num = rand() % 26;
		col = rand() % 80;
		while (true)
		{
			lines++;

			if (lines > 20)
			{
				lines = 0;
				scores -= 20;
				if (scores < -60)
				{
					GameOver();
				}
				break;
			}
			EntrySpace(col);
			printf("%c",'a' + num);
			Sleep(1000);
			printf("\b \r\n");

			if (kbhit())
			{
				char inputKey = getch();
				if (inputKey == 'a' + num)
				{
					scores += 10;
					break;
				}
				
			}
		}
	}
	return 0;
}