#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define UP 72
#define DOWN 80
#define ENTER 13
#define BACKSPACE 8
#define HASH 9999 
#include "models.cpp"
#include "pantry.cpp"

void clear(void)
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#endif
}

void sleep()
{
	for(int i = 0;i <= 1e7;i++){};
}

void profileScreen()
{
	clear();
	char txt[255];
	FILE *fp = fopen("spicy.txt", "r");
	while(fscanf(fp, "%[^\n]%*c", txt) != EOF)
	{
		printf("%s\n", txt);
	}
	fclose(fp);
	puts("\nPress enter to continue...");
	getchar();
}

void mainLogo()
{
	clear();
	FILE *fp = fopen("main_screen.txt", "r");
	char txt[255];
	while(fscanf(fp, "%[^\n]%*c", txt) != EOF)
	{
		printf("\t%s\n", txt);
	}
}

void loadingMenu()
{
	clear();
	FILE *fp = fopen("loading.txt", "r");
	char txt[255];
	int i = 0;
	puts("");
	while(i != 180 && fscanf(fp, "%[^\n]%*c", txt) != EOF)
	{
		printf("\t\t\t%s\n", txt);
		i++;
		if(i % 15 == 0)
		{
			sleep();
			clear();
			puts("");
		}
	}
	fclose(fp);
}

void arrowPosition(int realPost, int position)
{
	if(realPost == position)
	{
		printf("\t#   -->  ");
	}
	else
	{
		printf("\t#        ");
	}
}

void realTime()
{
  time_t rtime;
  struct tm *timeInfo;

  time(&rtime);
  timeInfo = localtime(&rtime);
  printf("\t %s", asctime(timeInfo));
}

int arrowFunc(int key, int position, int max, int min)
{
	if(key == DOWN && position != max)
	{
		return position + 1;
	}
	else if(key == DOWN && position == max)
	{
		return min;
	}
	else if(key == UP && position != min)
	{
		return position - 1;
	}
	else if(key == UP && position == min)
	{
		return max;
	}
	else
	{
		return position;
	}
}


void mainScreen()
{
	bool online = true;
	while(online)
	{
	int position = 1, key = 0;
    while(key != ENTER)
	{
		mainLogo();
		puts("\n\t\tMain menu");
        puts("\t==========================");
		arrowPosition(1, position); puts("Home            #");
		arrowPosition(2, position); puts("Cookbook        #");
		arrowPosition(3, position); puts("Kitchen         #");
		arrowPosition(4, position); puts("Pantry          #");
		arrowPosition(5, position); puts("About us        #");
		arrowPosition(6, position); puts("Exit            #");
		puts("\t==========================");
		realTime();
		key = getch();
		position = arrowFunc(key, position, 6, 1);
	}
	switch(position)
	{
		case 1:
		loadingMenu();
		break;
		case 2:
		loadingMenu();
		break;
		case 3:
		loadingMenu();
		break;
		case 4:
		loadingMenu();
		pantryScreen();
		break;
		case 5:
		profileScreen();
		break;
		case 6:
		online = false;	
	}
  }
}

int main()
{
    mainScreen();
	return 0;
}
