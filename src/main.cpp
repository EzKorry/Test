/*
 * main.cpp
 *
 *  Created on: 2014. 2. 23.
 *      Author: EzKorry
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "Card.h"
#include "CardList.h"
#include "Well.h"
#include "Process.h"
using namespace std;

int main() {

	Card cards[48] = {
			Card(1,0, 0, 0, 1),Card(1,0, 2, 0, 0),Card(1,1, 0, 0, 0),Card(1,1, 0, 0, 9),
			Card(2,0, 0, 1, 0),Card(2,0, 2, 0, 0),Card(2,1, 0, 0, 0),Card(2,1, 0, 0, 9),
			Card(3,0, 0, 0, 1),Card(3,0, 2, 0, 0),Card(3,1, 0, 0, 0),Card(3,1, 0, 0, 9),
			Card(4,0, 0, 1, 0),Card(4,0, 1, 0, 0),Card(4,1, 0, 0, 0),Card(4,1, 0, 0, 9),
			Card(5,0, 0, 2, 0),Card(5,0, 1, 0, 0),Card(5,1, 0, 0, 0),Card(5,1, 0, 0, 9),
			Card(6,0, 0, 2, 0),Card(6,0, 3, 0, 0),Card(6,1, 0, 0, 0),Card(6,1, 0, 0, 9),
			Card(7,0, 0, 2, 0),Card(7,0, 1, 0, 0),Card(7,1, 0, 0, 0),Card(7,1, 0, 0, 9),
			Card(8,0, 0, 0, 1),Card(8,0, 0, 1, 0),Card(8,1, 0, 0, 0),Card(8,1, 0, 0, 9),
			Card(9,2, 0, 0, 0),Card(9,0, 3, 0, 0),Card(9,1, 0, 0, 0),Card(9,1, 0, 0, 9),
			Card(10,0, 0, 2, 0),Card(10,0, 3, 0, 0),Card(10,1, 0, 0, 0),Card(10,1, 0, 0, 9),
			Card(11,0, 0, 0, 1),Card(11,2, 0, 0, 0),Card(11,1, 0, 0, 0),Card(11,1, 0, 0, 9),
			Card(12,0, 0, 0, 2),Card(12,0, 0, 2, 0),Card(12,0, 4, 0, 0),Card(12,2, 0, 0, 0)
	}; //카드 지정. 광 자리에 9는 같은 피끼리 구분하기 위해.


	int i = 0;
	CardList Deck, Strewed, APae, BPae, ADan, BDan; //덱, 흩뿌려져있는 것,

	for(i=0;i<48;i++){
		Deck.cardPush(cards[i]);
	}

	std::srand ( unsigned ( std::time(0) ) );

	Deck.shuffle();




	for(i=0;i<10;i++){
		APae.cardPush(Deck.cardPop());
		BPae.cardPush(Deck.cardPop());
	}
	for(i=0;i<8;i++){
		Strewed.cardPush(Deck.cardPop());
	}
		// A패, B패, 깔아놓는 것 다 설정


	//

	APae.sortByMonth();
	BPae.sortByMonth();


//	Deck.printList();
//	APae.printList();
//	BPae.printList();
//	Strewed.printList();

	cout << "게임이 시작되었습니다. 맞고." << endl;

	for (i = 0; i < 10; i++) {

		PrintPan(APae, BPae, ADan, BDan, Strewed);
		PlayerTurn(APae, ADan, Strewed, Deck);




		ComputerTurn(BPae, BDan, Strewed, Deck);



	}

	PrintPan(APae, BPae, ADan, BDan, Strewed);

	cout << "A는 " << ADan.getScore() << "점" << endl;
	cout << "B는 " << BDan.getScore() << "점" << endl;

	cout << "끝" << endl;
//	cin >> i;*/
	return 0;
}
