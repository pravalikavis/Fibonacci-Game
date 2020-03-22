#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <time.h>

int display_menu()
{
	//clrscr();
	printf("\n welcome to the 2048:FIBONACCI game:\n\n\n");
	printf("\n select 1 to start a new game :\n select 2 to start previously saved game:\n select 3 to see the leaderboard:\n\n");
	int i;
	scanf_s("%d", &i);
	return i;



}
int random_number(int min_num, int max_num)
{
	int result = 0, low_num = 0, hi_num = 0;

	if (min_num < max_num)
	{
		low_num = min_num;
		hi_num = max_num + 1; 
	}
	else {
		low_num = max_num + 1; 
		hi_num = min_num;
	}

	srand(time(NULL));
	result = (rand() % (hi_num - low_num)) + low_num;
	return result;
}
int ** create_matrix(int n)
{
	int **a = (int **)calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int *)calloc(n, sizeof(int ));
	}
	int i = random_number(0, n -1);
	int j = random_number(0, n - 1);
	a[i][j] = 1;
	printf("\n \n");
	
	return a;
}
void display_matrix(int **a, int n)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%*d", 4, a[i][j]);
		}
		printf("\n");
	}
}

int fib(int i, int j)
{
	int a[32] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269 };
	int s = 0;
	int s1 = 31;
	int x = (i + j) ;
	do
	{
		int m = (s + s1) / 2;
		
		
		 if (x < a[m])
		{
			s1 = m - 1;
		}
		 else if (x>a[m])
		{
			s = m+1;
		}
		 else if (x == a[m])
			 return 1;
		 else
			 break;
	} while (s1 >= s);
	return 0;
}
void mark(int **a,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j]==0)
			{
				a[i][j] = 1;
				return;
			}
		}
	}
	return;
}
void make_move(int **a, int n, char m)
{
	if (m == 'w' || m == 'W')
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = n; k>0;k--)
				for (int j = 0; j < n - 1; j++)
				{
					if (a[j][i] == 0)
					{
						a[j][i] = a[j + 1][i];
						a[j + 1][i] = 0;
					}
				}
			
			for (int j = 0; j < n-1; j++)
			{
				
					int k = fib(a[j][i], a[j + 1][i]);
					if (k == 1)
					{
						a[j][i] = a[j][i] + a[j + 1][i];
						a[j + 1][i] = 0;
					}
				
			}
		}
	}
	if (m == 's' || m == 'S')
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = n; k>0; k--)
				for (int j = n-1; j >0; j--)
				{
					if (a[j][i] == 0)
					{
						a[j][i] = a[j -1][i];
						a[j - 1][i] = 0;
					}
				}
			
			for (int j = n-1; j >0; j--)
			{
				
					int k = fib(a[j][i], a[j -1][i]);
					if (k == 1)
					{
						a[j][i] = a[j][i] + a[j - 1][i];
						a[j - 1][i] = 0;
					}
				
			}
		}
	}
	if (m == 'a' || m == 'A')
	{
		for (int i = 0; i < n; i++)
		{
			for (int k = n; k>0; k--)
				for (int j = 0; j < n - 1; j++)
				{
					if (a[i][j] == 0)
					{
						a[i][j] = a[i][j+1];
						a[i][j+1] = 0;
					}
				
			}
			for (int j = 0; j < n - 1; j++)
			{
				
					int k = fib(a[i][j], a[i][j+1]);
					if (k == 1)
					{
						a[i][j] = a[i][j] + a[i][j+1];
						a[i][j+1] = 0;
					}
				
			}
		}
	}
	if (m == 'd' || m == 'D')
	{

		for (int i = 0; i < n; i++)
		{
			for (int k = n; k>0; k--)
				for (int j = n-1; j >0; j--)
				{
					if (a[i][j] == 0)
					{
						a[i][j] = a[i][j - 1];
						a[i][j -1] = 0;
					}
				}
			
			for (int j = n - 1; j >0; j--)
			{
				
					int k = fib(a[i][j], a[i][j-1]);
					if (k == 1)
					{
						a[i][j] = a[i][j] + a[i][j-1];
						a[i][j-1] = 0;
					}
				
			}
		}
	}
	mark(a, n);
}
int check_win(int **a, int n)
{
	int b[32] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269 };
	int s =b[ 2 * n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (a[i][j] == s)
				return 1;
	}
	return 0;

}
int calculate_score(int **a, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t += a[i][j];
		}
	}
	return t;
}
void addToScoreboard(int numberOfGuesses)
{
	time_t t = time(NULL);
	struct tm tm;
	localtime_s(&tm,&t);
	FILE *scoreboardFile;
	fopen_s(&scoreboardFile, "scoreboard.txt", "a");
	char name[20];
	


	printf("\n\nGive name: ");
	scanf_s("%s", name,19);
	

	fprintf(scoreboardFile, "Name: %s \nPoints: %d\n", name, numberOfGuesses);
	fprintf(scoreboardFile,"date : %d-%d-%d time: %d:%d:%d\n\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	fclose(scoreboardFile);

}
void store_state(int **a, int n)
{
	FILE *p ;
	fopen_s(&p, "state.txt", "w");
	fprintf(p,"%d", n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(p,"%s"," ");
			fprintf(p,"%d",a[i][j]);
			
		}
		
	}
	fclose(p);
}
int check_dead(int **a, int n)
{
	return 0;
}
int main()
{
	do{
		int d = display_menu();
		int w = 0;
		int s;
		int **a = (int **)calloc(5, sizeof(int *));
		for (int i = 0; i < 6; i++)
		{
			a[i] = (int *)calloc(6, sizeof(int));
		}
		if (d == 1)
		{
			printf("\n enter 2 for 2X2 matrix 4 for 4X4 matrix: ");

			scanf_s("%d", &s);

			a = create_matrix(s);
		step1:;
			char m = 'a';
			display_matrix(a, s);
			do
			{
				w = check_win(a, s);
				if (w == 1)
				{
					printf("\n\n you have won the game\n");
					break;
				}
				int w1 = check_dead(a, s);
				if (w1 == 1)
				{
				printf("\n\n sorry no moves to play !! you have lost\n");
				break;
				}
				fflush(stdin);

				printf("\n enter w for up s for down a for left d for right z to exit:");

				scanf_s("%c", &m);

				make_move(a, s, m);
				display_matrix(a, s);

			} while (m != 'z'&&m != 'Z');
			int t = calculate_score(a, s);
			printf("\n\n your total score is %d", t);
			addToScoreboard(t);
			if (w == 0)
			{
				store_state(a, s);
			}
			getchar();
			getchar();
		}
		else if (d == 3)
		{
			FILE *p; fopen_s(&p, "scoreboard.txt", "r");
			char buff[200];
			int x = 1;
			
			
			printf("\n\n LEADERBOARD:\n");
			while (fgets(buff, 199, p)>=1)
			{
				fflush(stdin);
				fflush(stdout);
				printf("\n\n%d %s", x,buff);
				fgets(buff, 199, p);
				fflush(stdout);
				printf("%s", buff);
				fgets(buff, 199, p);
				fflush(stdin);
				fflush(stdout);
				printf("%s", buff);
				
				x++;
			} 
			getchar();
			getchar();
		}
		else
		{
			FILE *p; fopen_s(&p, "state.txt", "r");
			char buff[10];

			fscanf_s(p, "%d", &s);
			int b;

			for (int i = 0; i < s; i++)
			{
				for (int j = 0; j < s; j++)

				{
					fscanf_s(p, "%d", &b);
					a[i][j] = b;
				}
			}
			goto step1;

		}
	} while (1);
}
