#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

void play_game() {
    int enemy_win=0;		/*獲勝條件*/
	int player_win=0;
	
	int status=0,enemy_status=1, player_status = 1;
	int poker1[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};/*抽6張牌的撲克(0沒用)*/ 
	int poker2[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	int poker3[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	int poker4[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	int poker5[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	int poker6[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	
	int enemy[8]={};/*敵方手牌初始狀態*/
	int player[8]={};/*玩家手牌初始狀態*/

	while(enemy_win <2 && player_win <2){
		
			/*確認初始手牌*/
			enemy[1]=poker1[rand()%13+1];
			enemy[2]=poker2[rand()%13+1];
			enemy[3]=poker3[rand()%13+1];
			enemy[4]=poker4[rand()%13+1];
			enemy[5]=poker5[rand()%13+1];
			while(enemy[5] == enemy[1])enemy[5]=poker1[rand()%13+2];	/*去掉重複牌*/
			enemy[6]=poker6[rand()%13+1];
			while(enemy[6] == enemy[2] or enemy[6] == enemy[1])enemy[6]=poker2[rand()%13+2];	/*去掉重複牌*/
			
			player[1]=poker1[rand()%13+1];
			player[2]=poker2[rand()%13+1];
			player[3]=poker3[rand()%13+1];
			player[4]=poker4[rand()%13+1];
			player[5]=poker5[rand()%13+1];
			while(player[5]==player[1])player[5]=poker1[rand()%13+2];	/*去掉重複牌*/ 
			player[6]=poker6[rand()%13+1];
			while(player[6]==player[2] or player[6]==player[1])player[6]=poker2[rand()%13+2];	/*去掉重複牌*/
			/*確認初始手牌*/
			
			while(enemy_win<2 && player_win<2){
					int player_t[8]={};	/*預防會有重複的牌打出*/
					int enemy_total=0;
					int player_total=0;
				int status=0;/*狀態(選擇動作*/
				cout<<"敵方出牌"<<endl;
				for(int i=1; i<=6; i++){						/*以敵方為主,最多只會有6個動作*/
					if(enemy_total+enemy[i]<=21){
						enemy_status=1;							/*檢測敵方狀態(1出牌,0棄權)*/
						cout<<enemy[i]<<endl;
						enemy_total=enemy_total+enemy[i];
						cout<<"敵方打出了 "<< enemy[i]<<endl; 
						cout<<"目前敵方總共點數:"<<enemy_total<<endl; 
						cout<<"你的回合"<<endl; 
						cout<<"你的選擇是:"<<endl<<endl<<endl<<endl;
						cout<<"1. "<<player[1]<<" 2."<<player[2]<<" 3."<<player[3]<<" 4."<<player[4]<<" 5."<<player[5]<<" 6."<<player[6]<<" 8.棄權"<<endl;
						cin>>status;						/*檢測玩家狀態*/
						
						if(status==8){
							player_status=0;
							break;
						}
						while(status==7 || (status==1 && status<=6 && player[status]==player_t[status])){
							cout<<"你已經打出過"<<endl;
							cin>> status;
						}
						cout<<"你選擇打出了: "<< player[status]<<endl; 
						player_t[status]=player[status];
						player_total=player_total+player[status];
						cout<<"目前我方點數:"<< player_total<<endl;
						}
					else {
					 	cout<<"對方選擇棄權"<<endl;
					 	enemy_status=0;
					 	cout<<"目前敵方總共點數:"<<enemy_total<<endl; 
						cout<<"你的回合"<<endl; 
						cout<<"你的選擇是:"<<endl<<endl<<endl<<endl;
						cout<<"1. "<<player[1]<<" 2."<<player[2]<<" 3."<<player[3]<<" 4."<<player[4]<<" 5."<<player[5]<<" 6."<<player[6]<<"8.棄權"<<endl;
						cin>>status;						/*檢測玩家狀態*/
						
						if(status==8){
							player_status=0;
							break;
						}
						while (status==7 || (status==1 && status<=6 && player[status]==player_t[status])){
							cout<<"你已經打出過"<<endl;
							cin>> status;
						}
						cout<<"你選擇打出了: "<< player[status]<<endl; 
						player_t[status]=player[status];
						player_total=player_total+player[status];
						cout<<"目前我方點數:"<< player_total<<endl;
					}
				}
			cout<<"結果:"<<endl;
			cout<<"敵方總共:"<<enemy_total<<endl; 
			cout<<"我方總共:"<<player_total<<endl;
			if(21-enemy_total>21-player_total){
				enemy_win=enemy_win+1;
				cout<<"敵方獲勝"<<endl<<"目前敵方勝場: "<< enemy_win<<endl;
			}
			else if(21-enemy_total<21-player_total){
				player_win=player_win+1;
				cout<<"我方獲勝"<<endl<<"目前敵方勝場: "<< player_win<<endl;
				}
			else cout<<"平局,再一次"<<endl; 
		}
		if (enemy_win==2) cout<<"你輸了"<<endl;
		else cout<<"你贏了"<<endl; 
}
