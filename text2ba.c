#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>

void csrs(void);

int main()
{
    FILE *fp ;
    size_t nread; //number of elements
	int i = 1, tpf; //time per frame
	int time_sec, count_t, min = 0, sec;
	char file_path[19], c[2480];
	clock_t start_t, curr_t;

	printf("\n  Bad Apple!! in Command Prompt\n\n");
	printf("  Please enjoy!\n\n  <Press ENTER to continue>");
	getchar();
	PlaySound("res\\BA.wav", NULL, SND_ASYNC);
	system("cls");
	csrs();

	start_t = clock(); //starting the timer
	count_t = start_t;

	while (i <= 6569)
	{
	    curr_t = clock();
		time_sec = (curr_t - start_t) / CLOCKS_PER_SEC;
		min = time_sec/60;
		sec = time_sec%60; //acquiring elapsed time in mm:ss

		sprintf(file_path, "res\\BA%d.txt", i); //acquiring the .txt file path

		if (i % 30 == 0) //30 frames per second
			tpf = 43;
		else
			tpf = 33;

		if((curr_t - count_t) >= tpf)
		{
		    fp = fopen(file_path, "r");
		    while (fgets(c,2480,fp)!=NULL)
		    {
		        printf("%s", c);
		    }

            fclose(fp);

			printf("\n ------------------------\n");
			printf(" | Elapsed Time: %02d:%02d  |",min, sec);
			printf("\n ------------------------\n");
			csrs();

			i++;
			count_t += tpf;
		}
	}

	Sleep(1919);
	system("cls");
	printf("\n\n  Thank you for watching.\n");
	printf("  <Press ENTER to exit>");
	getchar();
	return 0;
}

void csrs(void) //resetting the cursor
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(h,pos);
}
