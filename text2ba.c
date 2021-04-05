#include<stdio.h>
#include<time.h>
#include<windows.h>
#define total_f 6569 //number of frames
#define CHUNK 3072 //processing 3KB at a time

void csrs(void);
void sub(int i);
int main()
{
    FILE *fp ;
    size_t nread; //number of elements
	int i = 1, tpf; //time per frame
	int time_sec, count_t, min = 0, sec;
	char file_path[19], buf[CHUNK];
	clock_t start_t, curr_t;

	system("CHCP 932");//set code page to shift-jis
	system("mode con: cols=90 lines=50"); //resizing console

	printf("\n  Bad Apple!! in Command Prompt\n\n");
	printf("  ASCII ART generated from Bad Apple!! PV\n\n\n");
	printf("  �y�����zBad Apple!!�@�o�u�y�e�G�z <sm8628149>\n          by ���ɂ� �l\n\n");
	printf("  Song: Bad Apple!! feat. nomico�^Alstroemeria Records\n");
	printf("  Origin: Bad Apple!!  �������z���@�` Lotus Land Story.\n");
	printf("          by ZUNSoft (��C�A���X���ْc)\n\n");
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

		    sub(i);
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
void sub(int i)
{

    if(i >=45 && i <=358)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�y���̑f�G�țޏ��v�@����얲\n");
    else if(i >=442 && i <=798)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u���m�̐��m���p�t�v�@���J������\n");
    else if(i >=853 && i <=1080)
        printf("\n�@�@�@�@�@�@�@�@�@�u�����Ȃ���}���فv�@�p�`�����[�E�m�[���b�W\n");
    else if(i >=1092 && i <=1217)
        printf("\n�@�@�@�@�@�@�@�@�@�u�i���ɍg���c�����v�@���~���A�E�X�J�[���b�g\n");
    else if(i >=1362 && i <=1478)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�u���S���n���ȃ��C�h�v�@�\\�Z����\n");
    else if(i >=1505 && i <=1710)
        printf("\n�@�@�@�@�@�@�@�@�@�@�u�����̖��v�@�t�����h�[���E�X�J�[���b�g\n");
    else if(i >=1750 && i <=1880)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u�������̒�t�v�@��鮗d��\n");
    else if(i >=1912 && i <=2100)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u����̖S��v�@���s���H�X�q\n");
    else if(i >=2188 && i <=2325)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�u�O�r�̐���ē��l�v�@����ˏ���\n");
    else if(i >=2360 && i <=2506)
        printf("\n�@�@�@�@�@�@�@�@�@�u�y���̍ō��ٔ����v�@�l�G�f�P�E���}�U�i�h�D\n");
    else if(i >=2540 && i <=2740)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u�H���̐l�̌`�v�@�������g\n");
    else if(i >=2780 && i <=2914)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�m���Ɨ��j�̔��b�v�@�㔒��d��\n");
    else if(i >=2975 && i <=3127)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u���̓��]�v�@���Ӊi��\n");
    else if(i >=3158 && i <=3300)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�u�i���Ɛ{�k�̍ߐl�v�@�H���R�P��\n");
    else if(i >=3361 && i <=3461)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@����O�o��\n");
    else if(i >=3462 && i <=3512)
        printf("\n�@�@�@�@�@�@�@�@�u���샔�@�C�I���j�X�g�v�@���i�T�E�v���Y�����o�[    \n");
    else if(i >=3513 && i <=3545)
        printf("\n�@�@�@�@�@�@�@�@�u����g�����؃b�^�[�v�@���������E�v���Y�����o�[    \n");
    else if(i >=3546 && i <=3586)
        printf("\n�@�@�@�@�@�@�@�@�u����L�[�{�[�f�B�X�g�v�@�����J�E�v���Y�����o�[    \n");
    else if(i >=3587 && i <=3614)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u�����̍��L�v�@��                 \n");
    else if(i >=3615 && i <=3643)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�����ܗd���̎��v�@���_��          \n");
    else if(i >=3644 && i <=3666)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�K�^�̑f�e�v�@�����Ă�           \n");
    else if(i >=3667 && i <=3748)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�u���C�̌��̓e�v�@���E�t�E�C�i�o       \n");
    else if(i >=3749 && i <=3789)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�����[�����V��v�@������         \n");
    else if(i >=3830 && i <=3932)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�u�J���镗�̐l�ԁv�@�����J���c       \n");
    else if(i >=3933 && i <=3997)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u��_�������v�@���R��           \n");
    else if(i >=3998 && i <=4067)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�u�R��ƌ΂̌����v�@����_�ގq       \n");
    else if(i >=4068 && i <=4168)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u�y���_�̒��_�v�@�k��z�K�q       \n");
    else if(i >=4258 && i <=4416)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u���E�̗d���v�@���_��           \n");
    else if(i >=4417 && i <=4566)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�u��z���z�V�̖��v�@��ߖ����V�q   \n");
    else if(i >=4669 && i <=4789)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�u�`���̌��z�u�����v�@�˖��ە�      \n");
    else if(i >=4836 && i <=5026)
        printf("\n�@�@�@�@�@�@�@�@�@�u�܂閲�A���A�����ĕS�S��s�v�@�ɐ��� \n");
    else if(i >=5088 && i <=5198)
        printf("\n�@�@�@�@�@�@�@�@�@�u���F�̐l�`�����v�@�A���X�E�}�[�K�g���C�h    \n");
    else if(i >=5232 && i <=5402)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�u���d���e���v�@�͏�ɂƂ�         \n");
    else if(i >=5482 && i <=5639)
        printf("\n�@�@�@�@�@�@�@�@�@�@�u�l�G�̃t�����[�}�X�^�[�v�@�����H��      \n");
    else if(i >=5661 && i <=5847)
        printf("\n�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�u�ق̖�ԁv�@�G���[            \n");
    else if(i >=5984 && i <=6098)
        printf("\n�@�@�@�@�@�@�@�@�@�@�u���Ɠ`����ێ炷��ޏ��v�@����얲    \n");
    else if(i >=6099 && i <=6171)
        printf("\n�@�@�@�@�@�@�@�@�@�@�u���@�ƍg������Ȃ鑶�݁v�@���J������   \n");
    else
        printf("\n                                                                 \n");
}
