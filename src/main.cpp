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
	}; //ī�� ����. �� �ڸ��� 9�� ���� �ǳ��� �����ϱ� ����.


	int i = 0;
	CardList Deck, Strewed, APae, BPae, ADan, BDan; //��, ��ѷ����ִ� ��,

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
		// A��, B��, ��Ƴ��� �� �� ����


	//

	APae.sortByMonth();
	BPae.sortByMonth();


//	Deck.printList();
//	APae.printList();
//	BPae.printList();
//	Strewed.printList();

	cout << "������ ���۵Ǿ����ϴ�. �°�." << endl;

	for (i = 0; i < 10; i++) {

		PrintPan(APae, BPae, ADan, BDan, Strewed);
		PlayerTurn(APae, ADan, Strewed, Deck);




		ComputerTurn(BPae, BDan, Strewed, Deck);



	}

	PrintPan(APae, BPae, ADan, BDan, Strewed);

	cout << "A�� " << ADan.getScore() << "��" << endl;
	cout << "B�� " << BDan.getScore() << "��" << endl;

	cout << "��" << endl;
//	cin >> i;*/
	return 0;
}
