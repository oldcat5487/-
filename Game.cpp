#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "Card.h"
using namespace std;


void play_game() {
	int enemy_win = 0;
	int player_win = 0;

	int status = 0, enemy_status = 1, player_status = 1;

	int enemy[8] = {};
	int player[8] = {};

	while (enemy_win < 2 && player_win < 2) {

		/*初始手牌*/
		enemy[1] = drawCard();
		enemy[2] = drawCard();
		enemy[3] = drawCard();
		enemy[4] = drawCard();
		enemy[5] = drawCard();

		while (enemy[5] == enemy[1])
			enemy[5] = drawCard();

		enemy[6] = drawCard();

		while (enemy[6] == enemy[2] || enemy[6] == enemy[1])
			enemy[6] = drawCard();

		player[1] = drawCard();
		player[2] = drawCard();
		player[3] = drawCard();
		player[4] = drawCard();
		player[5] = drawCard();

		while (player[5] == player[1])
			player[5] = drawCard();

		player[6] = drawCard();
		
		while (player[6] == player[2] || player[6] == player[1])
			player[6] = drawCard();
		/*確認初始手牌*/

		while (enemy_win < 2 && player_win < 2) {
			int player_t[8] = {};	//預防會有重複的牌打出
			int enemy_total = 0;
			int player_total = 0;
			int status = 0;			//狀態(選擇動作
			cout << "Opponent plays a card" << endl;
			for (int i = 1; i <= 6; i++) {						//以敵方為主,最多只會有6個動作
				if (enemy_total + enemy[i] <= 21) {
					enemy_status = 1;							//檢測敵方狀態(1出牌,0棄權)
					cout << enemy[i] << endl;
					enemy_total = enemy_total + enemy[i];
					cout << "The enemy played :" << enemy[i] << endl;
					cout << "Current total points of the enemy:" << enemy_total << endl;
					cout << "Your trun" << endl;
					cout << "Your choice is:" << endl << endl << endl << endl;
					cout << "1. " << player[1] << " 2." << player[2] << " 3." << player[3] << " 4." << player[4] << " 5." << player[5] << " 6." << player[6] << " 8.Give up" << endl;
					cin >> status;						//檢測玩家狀態

					if (status == 8) {
						player_status = 0;
						break;
					}
					while (status == 7 || (status == 1 && status <= 6 && player[status] == player_t[status])) {
						cout << "You've already typed it" << endl;		//你已經出過
						cin >> status;
					}
					cout << "You chose to play: " << player[status] << endl;
					player_t[status] = player[status];
					player_total = player_total + player[status];
					cout << "Our current points:" << player_total << endl;
				}
				else {
					cout << "The other party chose to forfeit" << endl;
					enemy_status = 0;
					cout << "Current total points of the enemy:" << enemy_total << endl;
					cout << "Your trun" << endl;
					cout << "Your choice is:" << endl << endl << endl << endl;
					cout << "1. " << player[1] << " 2." << player[2] << " 3." << player[3] << " 4." << player[4] << " 5." << player[5] << " 6." << player[6] << "8.Forfeit" << endl;
					cin >> status;						//檢測玩家狀態

					if (status == 8) {
						player_status = 0;
						break;
					}
					while (status == 7 || (status == 1 && status <= 6 && player[status] == player_t[status])) {
						cout << "You've already played it" << endl;
						cin >> status;
					}
					cout << "You chose to play: " << player[status] << endl;
					player_t[status] = player[status];
					player_total = player_total + player[status];
					cout << "Our current points:" << player_total << endl;
				}
			}
			cout << "Result:" << endl;
			cout << "Total enemies:" << enemy_total << endl;
			cout << "Our total:" << player_total << endl;
			if (21 - enemy_total > 21 - player_total) {
				enemy_win = enemy_win + 1;
				cout << "The enemy wins" << endl << "Current enemy wins: " << enemy_win << endl;
			}
			else if (21 - enemy_total < 21 - player_total) {
				player_win = player_win + 1;
				cout << "We won" << endl << "Current enemy wins: " << player_win << endl;
			}
			else cout << "Draw, once again" << endl;
		}
		if (enemy_win == 2) cout << "You Lose" << endl;
		else cout << "You Win" << endl;
	}
	cout << "Game Over" << endl;	//結束
}
