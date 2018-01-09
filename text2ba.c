#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#define total_f 6569 //number of frames
#define CHUNK 3072 //processing 3KB at a time

void csrs(void);

int main()
{
    FILE *fp ;
    size_t nread; //number of elements
	int i = 1, tpf; //time per frame
	int time_sec, count_t, min = 0, sec;
	char file_path[19], buf[CHUNK];
	clock_t start_t, curr_t;

	system("mode con: cols=90 lines=50"); //resizing console

	printf("\n  Bad Apple!! in Command Prompt\n\n");
	printf("  ASCII ART generated from Bad Apple!! PV\n\n\n");
	printf("  Åyìåï˚ÅzBad Apple!!Å@ÇoÇuÅyâeäGÅz <sm8628149>\n          by Ç†Ç…ÇÁ ól\n\n");
	printf("  Song: Bad Apple!! feat. nomicoÅ^Alstroemeria Records\n");
	printf("  Origin: Bad Apple!!  ìåï˚å∂ëzãΩÅ@Å` Lotus Land Story.\n");
	printf("          by ZUNSoft (è„äCÉAÉäÉXå∂ûŸíc)\n\n");
	printf("  Please enjoy!\n  <Press ENTER to continue>");
	getchar();

	system("cls");
	printf("\n  Loading...");
	PlaySound("res\\BA.wav", NULL, SND_ASYNC);
	Sleep(514);
	PlaySound(NULL, 0, 0); //Pre-load

	PlaySound("res\\BA.wav", NULL, SND_ASYNC);

	system("cls");
	csrs();

	start_t = clock(); //starting the timer
	count_t = start_t;

	while (i <= total_f)
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

		    while((nread = fread(buf, 1, sizeof buf, fp)) > 0)//reads data into the array pointed to
                fwrite(buf, 1, nread, stdout);// writes data to standard output(console)

		    fclose(fp);

			printf("\n ------------------------\n");
			printf(" | Elapsed Time: %02d:%02d  |\n | Frame.NO: %04d       |",min, sec, i);
			printf("\n ------------------------\n");
			csrs();

			i++;
			count_t += tpf;
		}
	}

	Sleep(1919);
	system("cls");
	printf("\n\n  Coded by InnoVeda\n\n");
	printf("  Thank you for watching.\n");
	printf("  <Press ENTER to exit>");
	getchar();
	return 0;
}

void csrs(void) //resetting the cursor
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 1 };
	SetConsoleCursorPosition(h,pos);
}
