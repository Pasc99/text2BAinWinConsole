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
	printf("  【東方】Bad Apple!!　ＰＶ【影絵】 <sm8628149>\n          by あにら 様\n\n");
	printf("  Song: Bad Apple!! feat. nomico／Alstroemeria Records\n");
	printf("  Origin: Bad Apple!!  東方幻想郷　～ Lotus Land Story.\n");
	printf("          by ZUNSoft (上海アリス幻樂団)\n\n");
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
        printf("\n　　　　　　　　　　　　　「楽園の素敵な巫女」　博麗霊夢\n");
    else if(i >=442 && i <=798)
        printf("\n　　　　　　　　　　　　　「東洋の西洋魔術師」　霧雨魔理沙\n");
    else if(i >=853 && i <=1080)
        printf("\n　　　　　　　　　「動かない大図書館」　パチュリー・ノーレッジ\n");
    else if(i >=1092 && i <=1217)
        printf("\n　　　　　　　　　「永遠に紅い幼き月」　レミリア・スカーレット\n");
    else if(i >=1362 && i <=1478)
        printf("\n　　　　　　　　　　　　「完全で瀟洒なメイド」　十\六夜咲夜\n");
    else if(i >=1505 && i <=1710)
        printf("\n　　　　　　　　　　「悪魔の妹」　フランドール・スカーレット\n");
    else if(i >=1750 && i <=1880)
        printf("\n　　　　　　　　　　　　　　「半分幻の庭師」　魂魄妖夢\n");
    else if(i >=1912 && i <=2100)
        printf("\n　　　　　　　　　　　　　「華胥の亡霊」　西行寺幽々子\n");
    else if(i >=2188 && i <=2325)
        printf("\n　　　　　　　　　　　　「三途の水先案内人」　小野塚小町\n");
    else if(i >=2360 && i <=2506)
        printf("\n　　　　　　　　　「楽園の最高裁判長」　四季映姫・ヤマザナドゥ\n");
    else if(i >=2540 && i <=2740)
        printf("\n　　　　　　　　　　　　　　「蓬莱の人の形」　藤原妹紅\n");
    else if(i >=2780 && i <=2914)
        printf("\n　　　　　　　　　　　　　「知識と歴史の半獣」　上白沢慧音\n");
    else if(i >=2975 && i <=3127)
        printf("\n　　　　　　　　　　　　　　「月の頭脳」　八意永琳\n");
    else if(i >=3158 && i <=3300)
        printf("\n　　　　　　　　　　　「永遠と須臾の罪人」　蓬莱山輝夜\n");
    else if(i >=3361 && i <=3461)
        printf("\n　　　　　　　　　　　　　　　　　　騒霊三姉妹\n");
    else if(i >=3462 && i <=3512)
        printf("\n　　　　　　　　「騒霊ヴァイオリニスト」　ルナサ・プリズムリバー    \n");
    else if(i >=3513 && i <=3545)
        printf("\n　　　　　　　　「騒霊トランぺッター」　メルラン・プリズムリバー    \n");
    else if(i >=3546 && i <=3586)
        printf("\n　　　　　　　　「騒霊キーボーディスト」　リリカ・プリズムリバー    \n");
    else if(i >=3587 && i <=3614)
        printf("\n　　　　　　　　　　　　　　　「凶兆の黒猫」　橙                 \n");
    else if(i >=3615 && i <=3643)
        printf("\n　　　　　　　　　　　　　「すきま妖怪の式」　八雲藍          \n");
    else if(i >=3644 && i <=3666)
        printf("\n　　　　　　　　　　　　　「幸運の素兎」　因幡てゐ           \n");
    else if(i >=3667 && i <=3748)
        printf("\n　　　　　　　　　　　「狂気の月の兎」　鈴仙・Ｕ・イナバ       \n");
    else if(i >=3749 && i <=3789)
        printf("\n　　　　　　　　　　　　　「下っ端哨戒天狗」　犬走椛         \n");
    else if(i >=3830 && i <=3932)
        printf("\n　　　　　　　　　　　「祀られる風の人間」　東風谷早苗       \n");
    else if(i >=3933 && i <=3997)
        printf("\n　　　　　　　　　　　　　　「秘神流し雛」　鍵山雛           \n");
    else if(i >=3998 && i <=4067)
        printf("\n　　　　　　　　　　　　「山坂と湖の権化」　八坂神奈子       \n");
    else if(i >=4068 && i <=4168)
        printf("\n　　　　　　　　　　　　　「土着神の頂点」　洩矢諏訪子       \n");
    else if(i >=4258 && i <=4416)
        printf("\n　　　　　　　　　　　　　　「境界の妖怪」　八雲紫           \n");
    else if(i >=4417 && i <=4566)
        printf("\n　　　　　　　　　　　「非想非非想天の娘」　比那名居天子   \n");
    else if(i >=4669 && i <=4789)
        printf("\n　　　　　　　　　　　　「伝統の幻想ブン屋」　射命丸文      \n");
    else if(i >=4836 && i <=5026)
        printf("\n　　　　　　　　　「萃まる夢、幻、そして百鬼夜行」　伊吹萃香 \n");
    else if(i >=5088 && i <=5198)
        printf("\n　　　　　　　　　「七色の人形遣い」　アリス・マーガトロイド    \n");
    else if(i >=5232 && i <=5402)
        printf("\n　　　　　　　　　　　　　「超妖怪弾頭」　河城にとり         \n");
    else if(i >=5482 && i <=5639)
        printf("\n　　　　　　　　　　「四季のフラワーマスター」　風見幽香      \n");
    else if(i >=5661 && i <=5847)
        printf("\n　　　　　　　　　　　　　　　「館の門番」　エリー            \n");
    else if(i >=5984 && i <=6098)
        printf("\n　　　　　　　　　　「夢と伝統を保守する巫女」　博麗霊夢    \n");
    else if(i >=6099 && i <=6171)
        printf("\n　　　　　　　　　　「魔法と紅夢からなる存在」　霧雨魔理沙   \n");
    else
        printf("\n                                                                 \n");
}
