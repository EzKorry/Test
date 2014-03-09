/*
 * Process.cpp
 *
 *  Created on: 2014. 2. 25.
 *      Author: EzKorry
 */

#include <iostream>
#include "Process.h"
#include "Card.h"
#include "CardList.h"
using namespace std;

void PlayerTurn(CardList &PlayerPae, CardList &PlayerDan, CardList &strewed,
		CardList &deck) {
	Card *selectCard = NULL;
	Card *deckCard = NULL;
	CardList tempList;
	int tempint = 0;

	cout << "내 패: ";
	selectCard = PlayerPae.selectCard();
	deckCard = deck.cardPop();

	tempint = strewed.getNumOfSameCard(selectCard);

	if (tempint == 3) //카드 3장이 모여있다면?
			{
		PlayerDan.cardPush(selectCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

	}

	else if (tempint == 2) { // 카드 2장이 모여있다면?

		tempList.cardPush(strewed.cardDeleteSame(selectCard));
		tempList.cardPush(strewed.cardDeleteSame(selectCard));

		PlayerDan.cardPush(tempList.selectCard());
		PlayerDan.cardPush(selectCard);
		strewed.cardPush(tempList.cardPop());

	}

	else if (tempint == 1) { // 카드가 한장이라면?
		if (deckCard->getCardMonth() == selectCard->getCardMonth()) { // 만약에 쌌다면?
			strewed.cardPush(deckCard);
			strewed.cardPush(selectCard);

		}
		else {

			PlayerDan.cardPush(selectCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

		}
	}

	else if (tempint == 0) { //카드가 한 장도 없다면?
		strewed.cardPush(selectCard);

	}

	tempint = strewed.getNumOfSameCard(deckCard);

	if (tempint == 3) { // 깐 패가 카드3장 모여있는 거랑 같다면?
		PlayerDan.cardPush(deckCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
	}

	else if (tempint == 2) {
		tempList.cardPush(strewed.cardDeleteSame(deckCard));
		tempList.cardPush(strewed.cardDeleteSame(deckCard));

		PlayerDan.cardPush(tempList.selectCard());
		PlayerDan.cardPush(deckCard);
		strewed.cardPush(tempList.cardPop());

	}

	else if (tempint == 1) {

		PlayerDan.cardPush(deckCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));

	}

	else if (tempint == 0) {
		strewed.cardPush(deckCard);
	}

	//패 선택

}

void ComputerTurn(CardList &PlayerPae, CardList &PlayerDan, CardList &strewed,
		CardList &deck) {
	Card *selectCard = NULL;
	Card *deckCard = NULL;
	CardList tempList;
	bool isSsat = 0;
	int tempint = 0;

	selectCard = PlayerPae.autoSelectCard(strewed);
	deckCard = deck.cardPop();

	tempint = strewed.getNumOfSameCard(selectCard);

	if (tempint == 3) //카드 3장이 모여있다면?
			{
		PlayerDan.cardPush(selectCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

	}

	else if (tempint == 2) { // 카드 2장이 모여있다면?

		tempList.cardPush(strewed.cardDeleteSame(selectCard));
		tempList.cardPush(strewed.cardDeleteSame(selectCard));

		PlayerDan.cardPush(tempList.autoSelectCard(strewed));
		PlayerDan.cardPush(selectCard);
		strewed.cardPush(tempList.cardPop());

	}

	else if (tempint == 1) { // 카드가 한장이라면?
		if (deckCard->getCardMonth() == selectCard->getCardMonth()) { // 만약에 쌌다면?
			strewed.cardPush(deckCard);
			strewed.cardPush(selectCard);
			isSsat = true;

		}
		else {

			PlayerDan.cardPush(selectCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

		}
	}

	else if (tempint == 0) { //카드가 한 장도 없다면?
		strewed.cardPush(selectCard);

	}

	if (isSsat != 1) {
		tempint = strewed.getNumOfSameCard(deckCard);

		if (tempint == 3) { // 깐 패가 카드3장 모여있는 거랑 같다면?
			PlayerDan.cardPush(deckCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
			PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
			PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));
		}

		else if (tempint == 2) {
			tempList.cardPush(strewed.cardDeleteSame(deckCard));
			tempList.cardPush(strewed.cardDeleteSame(deckCard));

			PlayerDan.cardPush(tempList.autoSelectCard(strewed));
			PlayerDan.cardPush(deckCard);
			strewed.cardPush(tempList.cardPop());

		}

		else if (tempint == 1) {
			PlayerDan.cardPush(deckCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(deckCard));

		}

		else if (tempint == 0) {
			strewed.cardPush(deckCard);
		}

	}

	//패 선택

}

void PrintPan(CardList &PlayerPae, CardList& otherPlayerPae,
		CardList &PlayerDan, CardList &otherPlayerDan, CardList &strewed) {

	cout
			<< "------------------------------------------------------------------\n------------------------------------------------------------------\n\n\n적 패: ";
	for (int i = 0; i < otherPlayerPae.getIndex(); i++) {
		cout << "[//] ";
	}
	cout << "\n적이 얻은 카드: ";
	otherPlayerDan.sortByType();
	otherPlayerDan.printList();

	cout << "\n흩뿌려져 있는 카드: ";
	strewed.printList();

	cout << "\n내가 얻은 카드:";
	PlayerDan.sortByType();

	PlayerDan.printList();
	cout << "\n";

}

// 판 프린트

