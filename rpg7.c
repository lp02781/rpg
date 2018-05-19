//inisialisasi preprocessor yang digunakan
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//inisialisasi variable
int select1, select2, stage, number_player;
int i = 0;
int j = 0;
int command;
int game_status=1;
char story1[]={"Pada jaman dahulu kala, di sebuah desa masyarakat hidup dengan damai. Air sungai mengalir dengan tenang, hasil pertanian dan berkah hutan melimpah. Namun semua berubah ketika para monster menyerang. Desa hancur berantakan, mayat-mayat bertumpukan. \n\nDisaat keputusasaan memuncak, datang dua pahlawan menyelamatkan desa. Pertarungan membasmi semua monster kecuali satu, monster itu terpaksa mundur ke gua. Para pahlawan berusaha memburu monster tersebut."};
char story2[]={"Monster terakhir telah terbunuh, dan kedamaian mendekati wilayah pendesaan. Para pahlawan balik keluar gua, tapi yang mereka temukan tidak pendesaan hijau yang mereka harapkan. Udara penuh asap dan langit terlihat merah, dari sisi kiri ke kanan hanya terlihat tanah yang hampa. \n\nDari jauh, terdengar suara monster mendekati...\n\n"};

//inisialisasi struct dari hero dan monster
struct hero {
   char	job[50];
   int id;
   int 	hp;
   int  mp;
   int 	def;
   int 	att;
};

struct monster {
   int 	hp;
   int 	deff;
   int  att;
};

//inisialisasi modular
void pause();//menunggu input keyboard untuk lanjut
void clear();//menghapus layar
void display_list_job();
void display_status_monster(struct monster mon, int number_mon);
void display_status_hero(struct hero player1, struct hero player2, int number1, int number2);
void display_status_game(struct hero player1, struct hero player2, struct monster mon, int number1, int number2, int number3);
void delay(float number_of_seconds);//memberikan jeda waktu 
void display_hero_skill();
void info_skill();
void display_request_command(int number);
void credit();
void hero1_attack();
void hero2_attack();
void mon_attack();
void idle();
void scene1();

//all magic happen here
int main( ) {
	//membuat karakter hero dan monster
	struct hero hero1;
	struct hero hero2;
	struct monster mon;
	
	printf("\n\n\t\tWELCOME TO LAST FIGHT DUGEON CRAWLER GAME\n\n");
	//menjalankan story1
	scene1();
	for(i=0;i<sizeof(story1);i++){
		printf("%c", story1[i]);
		delay(0.02);
	}

	printf("\n\n\n");
	pause();
	clear();
	
	//memilih job untuk hero 1
	display_list_job();
	printf("player 1 please select job:");
	scanf("%d", &select1);	
	if(select1 == 1){
		strcpy(hero1.job, "warrior");
		hero1.id 	=1;
		hero1.hp	=100;
		hero1.mp	=100;
		hero1.def	=10;
		hero1.att	=100;
	}
	else if(select1 == 2){
		strcpy(hero1.job, "wizard");
		hero1.id 	=2;
		hero1.hp	=60;
		hero1.mp	=150;
		hero1.def	=7;
		hero1.att	=130;
	}
	else if(select1 == 3){
		strcpy(hero1.job, "archer");
		hero1.id	=3;
		hero1.hp	=70;
		hero1.mp	=100;
		hero1.def	=8;
		hero1.att	=110;
	}
	else if(select1 == 4){
		strcpy(hero1.job, "priest");
		hero1.id	=4;
		hero1.hp	=80;
		hero1.mp	=130;
		hero1.def	=10;
		hero1.att	=80;
	}
	else{
		clear();
		printf("wrong input, go back to start game\n");
		pause();
		clear();
		main();
	}
   	clear();
   	
   	//memilih job hero 2
	display_list_job();
   	printf("player 2 please select job:");
   	scanf("%d", &select2);	
   	if(select2 == 1){
		strcpy(hero2.job, "warrior");
		hero2.id	=1;
		hero2.hp	=100;
		hero2.mp	=100;
		hero2.def	=10;
		hero2.att	=100;
	}
	else if(select2 == 2){
		strcpy(hero2.job, "wizard");
		hero2.id	=2;
		hero2.hp	=60;
		hero2.mp	=150;
		hero2.def	=7;
		hero2.att	=130;
	}
	else if(select2 == 3){
		strcpy(hero2.job, "archer");
		hero2.id	=3;
		hero2.hp	=70;
		hero2.mp	=100;
		hero2.def	=8;
		hero2.att	=110;
	}
	else if(select2 == 4){
		strcpy(hero2.job, "priest");
		hero2.id	=4;
		hero2.hp	=80;
		hero2.mp	=130;
		hero2.def	=10;
		hero2.att	=80;
	}
	else{
		clear();
		printf("wrong input, go back to start game\n");
		pause();
		clear();
		main();
	}
	clear();
   	
   	
   	//memulai stage 1
	stage = 1;
   	printf("\n\n\nstage %d start\n\n\n", stage);
   	hero1.att	=hero1.att*stage;
   	hero1.def	=hero1.def*stage;
   	hero1.hp	=hero1.hp*stage;
   	hero1.mp	=hero1.mp*stage;
   	hero2.att	=hero2.att*stage;
   	hero2.def	=hero2.def*stage;
   	hero2.hp	=hero2.hp*stage;
   	hero2.mp	=hero2.mp*stage;
   	mon.hp		=1000*stage;
   	mon.deff	=10*stage;
   	mon.att		=20*stage;
	display_status_monster(mon, 1);   	
	display_status_hero(hero1, hero2, 1, 2);
   	pause();
   	clear();
   	
   	//dalam game
   	while(game_status = 1) 
	{
		//giliran hero 1
   		if(hero1.hp>0){
   			clear();
   			idle();
   			display_status_game(hero1, hero2, mon, 1, 2, 1);
   			display_hero_skill();
   			display_request_command(1);
   			scanf("%d", &command);
   			if(command == 1){// hero 1 attack
				mon.hp=mon.hp+mon.deff-hero1.att;
			}	
			else if(command == 2){//hero 1 deffense
				hero1.def=hero1.def+30;
			}
			else if(command == 3){//hero 1 charge magic point
				hero1.mp=hero1.mp+50;
			}
			else if(command == 5){
				clear();
				printf("anda hanya cukup memasukkan input berdasarkan list dari command");
				pause();
				clear();
			}
			else if(command == 4){//ultimate skill tiap hero
				if(hero1.mp>=stage*100){
					if(hero1.id == 1){
						hero1.mp=hero1.mp-stage*100;
						mon.hp=mon.hp-hero1.att*4;
						hero1.def=hero1.def+stage*20;
						hero2.def=hero2.def+stage*20;
					}
					else if(hero1.id == 2){
						hero1.mp=hero1.mp-stage*100;
						mon.hp=mon.hp-hero1.att*2;
						hero1.mp=hero1.mp+stage*50;
						hero2.mp=hero2.mp+stage*50;
					}
					else if(hero1.id == 3){
						hero1.mp=hero1.mp-stage*100;
						mon.hp=mon.hp-hero1.att*3;
						hero1.def=hero1.def+stage*20;
						hero2.def=hero2.def+stage*20;
					}
					else if(hero1.id == 4){
						hero1.mp=hero1.mp-stage*100;
						mon.hp=mon.hp-hero1.att*2;
						hero1.hp=hero1.hp+stage*50;
						hero2.hp=hero2.hp+stage*50;
					}
				}
			}
			else{//salah command
				printf("wrong command, get pinalty one round");
				pause();
			}
				
			clear();
			hero1_attack();
			delay(1);

			//cek menang atau kalah
			clear();
			if(hero1.hp <= 0 || hero2.hp <= 0){//menang
				clear();
				printf("heroes lose\n\n!!");
				printf("\n\n\n");
				credit();
				pause();
				break;	
			}
			else if(mon.hp <=0){//kalah
				clear();
				
				for(j=0;j<sizeof(story2);j++){
					printf("%c", story2[j]);
					delay(0.05);
				}
				
				pause();
				clear();
				
				printf("\n\n\n");
				credit();
				
				pause();
				break;
			}
		}
		
		//giliran hero 2
	   	if(hero2.hp>0){
	   		clear();
	   		idle();
			display_status_game(hero1, hero2, mon, 1, 2, 1);
   			display_hero_skill();
			display_request_command(2);
   			scanf("%d", &command);
			if(command == 1){//hero 2 attack
				mon.hp=mon.hp+mon.deff-hero2.att;
			}	
			else if(command == 2){// hero 2 defense
				hero2.def=hero2.def+30;
			}
			else if(command == 3){//hero 2 charge magic point
				hero2.mp=hero2.mp+50;
			}
			else if(command == 5){
				clear();
				printf("anda hanya cukup memasukkan input berdasarkan list dari command");
				pause();
				clear();
			}
			else if(command == 4){//ultimate skill hero 2
				if(hero1.mp>=stage*100){
					if(hero2.id == 1){
						hero2.mp=hero2.mp-stage*100;
						mon.hp=mon.hp-hero2.att*4;
						hero2.def=hero2.def+stage*20;
						hero1.def=hero1.def+stage*20;
					}
					else if(hero2.id == 2){
						hero2.mp=hero2.mp-stage*100;
						mon.hp=mon.hp-hero2.att*2;
						hero2.mp=hero2.mp+stage*50;
						hero1.mp=hero1.mp+stage*50;
					}
					else if(hero2.id == 3){
						hero2.mp=hero2.mp-stage*100;
						mon.hp=mon.hp-hero2.att*3;
						hero2.def=hero2.def+stage*20;
						hero1.def=hero1.def+stage*20;
					}
					else if(hero2.id == 4){
						hero2.mp=hero2.mp-stage*100;
						mon.hp=mon.hp-hero1.att*2;
						hero2.hp=hero2.hp+stage*50;
						hero1.hp=hero1.hp+stage*50;
					}
				}
			}
			
			else{//salah command
				printf("wrong command, get pinalty one round");
				pause();
			}
			
			clear();
			hero2_attack();
			delay(1);
				
			clear();
			
			//cek menang atau kalah
			if(hero1.hp <= 0 || hero2.hp <= 0){//menang
				clear();
				printf("heroes lose\n\n!!");
				printf("\n\n\n");
				credit();
				pause();
				break;	
			}
			else if(mon.hp <=0){//kalah
				clear();
				
				for(j=0;j<sizeof(story2);j++){
					printf("%c", story2[j]);
					delay(0.05);
				}
				
				pause();
				clear();
				
				printf("\n\n\n");
				credit();
				
				pause();
				break;
			}
			
			mon_attack();
			delay(1);
			
			//giliran monster
			hero1.hp=hero1.hp-mon.att*stage+hero1.def;
			hero1.mp=hero1.mp-1/2*mon.att*stage+1/2*hero1.def;
			
			hero2.hp=hero2.hp-mon.att*stage+hero2.def;
			hero2.mp=hero2.mp-1/2*mon.att*stage+1/2*hero2.def;
			
			//cek menang atau kalah			
			if(hero1.hp <= 0 || hero2.hp <= 0){//menang
				clear();
				printf("Heroes lose\n\n!!");
				printf("\n\n\n");
				credit();
				pause();
				break;	
			}
			else if(mon.hp <=0){//kalah
				clear();
				
				for(j=0;j<sizeof(story2);j++){
					printf("%c", story2[j]);
					delay(0.05);
				}
				
				pause();
				clear();
				
				printf("\n\n\n");
				credit();
				
				pause();
				break;
			}
		}
   	} 
}

//GUI programs
void display_list_job(){
   	printf("Job List:\n");
   	printf("[1] Warrior\n");
   	printf("[2] Wizard\n");
   	printf("[3] Archer\n");
   	printf("[4] Priest\n");
}

void display_status_hero(struct hero player1, struct hero player2, int number1, int number2){
	printf("player %d Job \t: %s\t player %d Job \t: %s\n", number1, player1.job, number2, player2.job);
	printf("player %d HP \t: %d\t\t player %d HP \t: %d\n", number1, player1.hp, number2, player2.hp);
	printf("player %d MP \t: %d\t\t player %d MP \t: %d\t\n", number1, player1.mp, number2, player2.mp);
	printf("player %d Atk \t: %d\t\t player %d Atk \t: %d\t\n", number1, player1.att, number2, player2.att);
	printf("player %d Def \t: %d\t\t player %d Def \t: %d\t\n", number1, player1.def, number2, player2.def);
	printf("\n\n");
}

void display_status_game(struct hero player1, struct hero player2, struct monster mon, int number1, int number2, int number3){
	printf("p%d Job\t: %s\t p%d Job : %s\t\n", number1, player1.job, number2, player2.job);
	printf("p%d HP\t: %d\t\t p%d hp \t: %d\t\t m%d HP\t: %d\n", number1, player1.hp, number2, player2.hp, number3, mon.hp);
	printf("p%d MP\t: %d\t\t p%d mp \t: %d\t\t m%d MP : %d\n", number1, player1.mp, number2, player2.mp, number3, mon.deff);
	printf("p%d Atk\t: %d\t\t p%d att : %d\t\t m%d Atk\t: %d\n", number1, player1.att, number2, player2.att, number3, mon.att);
	printf("p%d Def\t: %d\t\t p%d Def : %d\t\t \n", number1, player1.def, number2, player2.def);
	printf("\n\n");
}

void display_status_monster(struct monster mon, int number_mon){
	printf("Monster %d HP \t: %d\n", number_mon, mon.hp);
	printf("Monster %d Def \t: %d\n", number_mon, mon.deff);
	printf("Monster %d Atk \t: %d\n", number_mon, mon.att);
	printf("\n\n");
}

void display_hero_skill(){
	printf("[1] Attack\n");
	printf("[2] Heal\n");
	printf("[3] Charge mana\n");
	printf("[4] Special skill\n");
	printf("[5] Info\n");
}
void display_request_command(int number){
	printf("Player %d select your command : ", number);
}

void credit(){
	printf("This game was made by:\n");
	printf("Fikih Muhamad\n");
	printf("Reza bhaskara\n");
	printf("source : asciiart.eu\n\n");
}

//Sprite karakter
void hero1_attack(){
	printf("\n\n\n");
	printf("     \\\n");
	printf("     /|\n");
	printf("    /  \\        |\n");
	printf("___/____|___    /\n");
	printf("   | o o|      ||\n");
	printf("   |____/     _||_\n");
	printf("  /  \\/  \\____/__|\n");
	printf(" /  \\     / //\n");
	printf(" |   \\   / ||\n");
	printf(" |    | /  ||\n");
	printf(" |    | |  //\n");
	printf(" |    | | //\n");
	printf(" |      |/_|\n");
	printf(" |          \\\n");
	printf(" |          |\n");
	printf(" |           \\\n");
	printf(" |____________\\\n");
	
	delay(0.5);
	clear();
	printf("\n");
	printf("                                                  \\\n");
	printf("                                                  /|\n");
	printf("                                                 /  \\        |\n");
	printf("                                             ___/____|___    /\n");
	printf("                                                | o o|      ||\n");
	printf("                                                |____/     _||_\n");
	printf("                                               /  \\/  \\____/__|\n");
	printf("                                              /  \\     / //\n");
	printf("                                              |   \\   / ||\n");
	printf("                                              |    | /  ||\n");
	printf("                                              |    | |  //\n");
	printf("                                              |    | | //\n");
	printf("                                              |      |/_|\n");
	printf("                                              |          \\\n");
	printf("                                              |          |\n");
	printf("                                              |           \\\n");
	printf("                                              |____________\\\n");
	
	delay(0.2);
	clear();
	printf("\n\n\n");
	printf("     \\\n");
	printf("     /|\n");
	printf("    /  \\        |\n");
	printf("___/____|___    /\n");
	printf("   | o o|      ||\n");
	printf("   |____/     _||_\n");
	printf("  /  \\/  \\____/__|\n");
	printf(" /  \\     / //\n");
	printf(" |   \\   / ||\n");
	printf(" |    | /  ||\n");
	printf(" |    | |  //\n");
	printf(" |    | | //\n");
	printf(" |      |/_|\n");
	printf(" |          \\\n");
	printf(" |          |\n");
	printf(" |           \\\n");
	printf(" |____________\\\n");
	
}
void hero2_attack(){
	printf("\n\n\n");
	printf("                          /   ______   \\\n");
	printf("                         \\\\__| \\  / |__//\n");
	printf("                           --| o  o |--\n");
	printf("                           __|______|__\n");
	printf("                          /   /\\    ___\\_____\n");
	printf("                         |  | ||    |_______|\n");
	printf("                         |  \\ ||    | |   | |\n");
	printf("                           \\ \\||    | |   | |\n");
	printf("                            \\_||_   | \\___/ |\n");
	printf("                             \\^^/____\\_____/\n");
	printf("                             /||      \\\n");
	printf("                            /    /\\    |\n");
	printf("                            |   |  |   |\n");
	printf("                            |  /    \\  |\n");
	printf("                            |  |    |  |\n");
	printf("                            |  |    |  |\n");
	printf("                           /____|   |___\\\n");
	
	delay(0.5);
	clear();
	printf("\n");
	printf("                                               /   ______   \\\n");
	printf("                                              \\\\__| \\  / |__//\n");
	printf("                                                --| o  o |--\n");
	printf("                                                __|______|__\n");
	printf("                                               /   /\\    ___\\_____\n");
	printf("                                              |  | ||    |_______|\n");
	printf("                                              | \\ ||    | |   | |\n");
	printf("                                                \\ \\||    | |   | |\n");
	printf("                                                 \\_||_   | \\___/ |\n");
	printf("                                                  \\^^/____\\_____/\n");
	printf("                                                  /||      \\\n");
	printf("                                                 /    /\\    |\n");
	printf("                                                 |   |  |   |\n");
	printf("                                                 |  /    \\  |\n");
	printf("                                                 |  |    |  |\n");
	printf("                                                 |  |    |  |\n");
	printf("                                                /____|   |___\\\n");
	
	delay(0.2);
	clear();
	printf("\n\n\n");
	printf("                          /   ______   \\\n");
	printf("                         \\\\__| \\  / |__//\n");
	printf("                           --| o  o |--\n");
	printf("                           __|______|__\n");
	printf("                          /   /\\    ___\\_____\n");
	printf("                         |  | ||    |_______|\n");
	printf("                         |  \\ ||    | |   | |\n");
	printf("                           \\ \\||    | |   | |\n");
	printf("                            \\_||_   | \\___/ |\n");
	printf("                             \\^^/____\\_____/\n");
	printf("                             /||      \\\n");
	printf("                            /    /\\    |\n");
	printf("                            |   |  |   |\n");
	printf("                            |  /    \\  |\n");
	printf("                            |  |    |  |\n");
	printf("                            |  |    |  |\n");
	printf("                           /____|   |___\\\n");	
}
void mon_attack(){
	printf("\n\n\n");
	printf("                                                             ___\n");
	printf("                                                            /   \\\\\n");
	printf("                                                           |.  . \\\\\n");
	printf("                                                       //\\\\|     ||\n");
	printf("                                                     //// \\\\ ___//\\_\n");
	printf("                                                   ////    \\\\        \\\n");
	printf("                                                  ///       \\\\        |\n");
	printf("                                                  //        |\\\\   \\    \\\n");
	printf("                                                  /         | \\\\   \\    \\\n");
	printf("                                                            |  \\\\  /    /\n");
	printf("                                                            |   \\\\/    /\n");
	printf("                                                            |    \\\\ / |\n");
	printf("                                                            |     \\\\  |\n");
	printf("                                                            |      \\\\ |\n");
	printf("                                                            |       \\\\|\n");
	printf("                                                            |         |\n");
	printf("                                                            |__________\\\n");
	
	delay(0.5);
	clear();;
	printf("\n");
	printf("                                        ___\n");
	printf("                                       /   \\\\\n");
	printf("                                      |.  . \\\\\n");
	printf("                                  //\\\\|     ||\n");
	printf("                               //// \\\\ ___//\\_\n");
	printf("                             ////    \\\\        \\\n");
	printf("                            ///       \\\\        |\n");
	printf("                            //        |\\\\   \\    \\\n");
	printf("                            /         | \\\\   \\    \\\n");
	printf("                                      |  \\\\  /    /\n");
	printf("                                      |   \\\\/    /\n");
	printf("                                      |    \\\\ / |\n");
	printf("                                      |     \\\\  |\n");
	printf("                                      |      \\\\ |\n");
	printf("                                      |       \\\\|\n");
	printf("                                      |         |\n");
	printf("                                      |__________\\\n");
	
	delay(0.2);
	clear();	
	printf("\n\n\n");
	printf("                                                            ___\n");
	printf("                                                           /   \\\\\n");
	printf("                                                          |.  . \\\\\n");
	printf("                                                      //\\\\|     ||\n");
	printf("                                                     //// \\\\ ___//\\_\n");
	printf("                                                   ////    \\\\        \\\n");
	printf("                                                  ///       \\\\        |\n");
	printf("                                                  //        |\\\\   \\    \\\n");
	printf("                                                  /         | \\\\   \\    \\\n");
	printf("                                                            |  \\\\  /    /\n");
	printf("                                                            |   \\\\/    /\n");
	printf("                                                            |    \\\\ / |\n");
	printf("                                                            |     \\\\  |\n");
	printf("                                                            |      \\\\ |\n");
	printf("                                                            |       \\\\|\n");
	printf("                                                            |         |\n");
	printf("                                                            |__________\\\n");
	
	delay(0.5);
	clear();;
	printf("\n");
	printf("                         ___\n");
	printf("                        /   \\\\\n");
	printf("                       |.  . \\\\\n");
	printf("                   //\\\\|     ||\n");
	printf("                 //// \\\\ ___//\\_\n");
	printf("               ////    \\\\        \\\n");
	printf("              ///       \\\\        |\n");
	printf("              //        |\\\\   \\    \\\n");
	printf("              /         | \\\\   \\    \\\n");
	printf("                        |  \\\\  /    /\n");
	printf("                        |   \\\\/    /\n");
	printf("                        |    \\\\ / |\n");
	printf("                        |     \\\\  |\n");
	printf("                        |      \\\\ |\n");
	printf("                        |       \\\\|\n");
	printf("                        |         |\n");
	printf("                        |__________\\\n");
	
	delay(0.2);
	clear();	
	printf("\n\n\n");
	printf("                                                            ___\n");
	printf("                                                           /   \\\\\n");
	printf("                                                          |.  . \\\\\n");
	printf("                                                      //\\\\|     ||\n");
	printf("                                                     //// \\\\ ___//\\_\n");
	printf("                                                   ////    \\\\        \\\n");
	printf("                                                  ///       \\\\        |\n");
	printf("                                                  //        |\\\\   \\    \\\n");
	printf("                                                  /         | \\\\   \\    \\\n");
	printf("                                                            |  \\\\  /    /\n");
	printf("                                                            |   \\\\/    /\n");
	printf("                                                            |    \\\\ / |\n");
	printf("                                                            |     \\\\  |\n");
	printf("                                                            |      \\\\ |\n");
	printf("                                                            |       \\\\|\n");
	printf("                                                            |         |\n");
	printf("                                                            |__________\\\n");
}
void idle(){
	printf("\n\n\n");
	printf("     \\                  /   ______   \\                     ___\n");
	printf("     /|                \\\\__| \\  / |__//      	          /   \\\\\n");
	printf("    /  \\        |        --| o  o |--        	         |.  . \\\\\n");
	printf("___/____|___    /        __|______|__        	     //\\\\|     ||\n");
	printf("   | o o|      ||       /   /\\    ___\\_____  	   //// \\\\ ___//\\_\n");
	printf("   |____/     _||_     |  | ||    |_______|  	 ////    \\\\        \\\n");
	printf("  /  \\/  \\____/__|     |  \\ ||    | |   | |  	///       \\\\        |\n");
	printf(" /  \\     / //          \\  \\||    | |   | |  	//        |\\\\   \\    \\\n");
	printf(" |   \\   / ||             \\_||_   | \\___/ |  	/         | \\\\   \\    \\\n");
	printf(" |    | /  ||              \\^^/____\\_____/   	          |  \\\\  /    /\n");
	printf(" |    | |  //              /||      \\        	          |   \\\\/    /\n");
	printf(" |    | | //              /    /\\    |       	          |    \\\\ / |\n");
	printf(" |      |/_|              |   |  |   |       	          |     \\\\  |\n");
	printf(" |          \\             |  /    \\  |       	          |      \\\\ |\n");
	printf(" |          |             |  |    |  |       	          |       \\\\|\n");
	printf(" |           \\            |  |    |  |       	          |         |\n");
	printf(" |____________\\          /____|   |___\\      	          |__________\\\n");
	
}

//Scene Art
void scene1(){
	printf("\n\n\n\n");
	printf("                                           |\n");
	printf("                                   ` \\  * |    /'\n");
	printf("                                      \\ ._|_* /   .\n");
	printf("                         ____       . * .'   `.  *                    _________\n");
	printf("        ___          ___________  ~~~~~~|     |~~~~~~      ____________________\n");
	printf("      _______      ____________________________________.-._____________________\n");
	printf("______________..__________________........________/=\\_\\| |_____________________\n");
	printf("________________.._____________................___|_|_||_|_____________________\n");
	printf("_________________.._________....____________.........__________________________\n");
	printf("__________________.....____..../_/+\\___/=\\_\\____........_______________________\n");
	printf("____________________.........__|_|_|___|_|_|_______.........___________________\n");
	printf("________________________________________________________.........._____________\n");
	printf("______________________/_/=\\_______________________________..........___________\n");
	printf("______________________|_|_|_________________________________.........._________\n");
	printf("________________________________________________________________...........____\n");
	printf("___________________________________________________________________........____\n");
}

//system command
void delay(float number_of_seconds){
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void pause(){system("pause");}
void clear(){system("cls");}

/*
refensi
https://www.tutorialspoint.com/cprogramming/index.htm
https://www.geeksforgeeks.org/time-delay-c/
https://www.programmingsimplified.com/c/dos.h/delay
asciiart.eu
*/
