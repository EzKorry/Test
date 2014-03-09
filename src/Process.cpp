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

	cout << "�� ��: ";
	selectCard = PlayerPae.selectCard();
	deckCard = deck.cardPop();

	tempint = strewed.getNumOfSameCard(selectCard);

	if (tempint == 3) //ī�� 3���� ���ִٸ�?
			{
		PlayerDan.cardPush(selectCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

	}

	else if (tempint == 2) { // ī�� 2���� ���ִٸ�?

		tempList.cardPush(strewed.cardDeleteSame(selectCard));
		tempList.cardPush(strewed.cardDeleteSame(selectCard));

		PlayerDan.cardPush(tempList.selectCard());
		PlayerDan.cardPush(selectCard);
		strewed.cardPush(tempList.cardPop());

	}

	else if (tempint == 1) { // ī�尡 �����̶��?
		if (deckCard->getCardMonth() == selectCard->getCardMonth()) { // ���࿡ �մٸ�?
			strewed.cardPush(deckCard);
			strewed.cardPush(selectCard);

		}
		else {

			PlayerDan.cardPush(selectCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

		}
	}

	else if (tempint == 0) { //ī�尡 �� �嵵 ���ٸ�?
		strewed.cardPush(selectCard);

	}

	tempint = strewed.getNumOfSameCard(deckCard);

	if (tempint == 3) { // �� �а� ī��3�� ���ִ� �Ŷ� ���ٸ�?
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

	//�� ����

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

	if (tempint == 3) //ī�� 3���� ���ִٸ�?
			{
		PlayerDan.cardPush(selectCard);
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));
		PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

	}

	else if (tempint == 2) { // ī�� 2���� ���ִٸ�?

		tempList.cardPush(strewed.cardDeleteSame(selectCard));
		tempList.cardPush(strewed.cardDeleteSame(selectCard));

		PlayerDan.cardPush(tempList.autoSelectCard(strewed));
		PlayerDan.cardPush(selectCard);
		strewed.cardPush(tempList.cardPop());

	}

	else if (tempint == 1) { // ī�尡 �����̶��?
		if (deckCard->getCardMonth() == selectCard->getCardMonth()) { // ���࿡ �մٸ�?
			strewed.cardPush(deckCard);
			strewed.cardPush(selectCard);
			isSsat = true;

		}
		else {

			PlayerDan.cardPush(selectCard);
			PlayerDan.cardPush(strewed.cardDeleteSame(selectCard));

		}
	}

	else if (tempint == 0) { //ī�尡 �� �嵵 ���ٸ�?
		strewed.cardPush(selectCard);

	}

	if (isSsat != 1) {
		tempint = strewed.getNumOfSameCard(deckCard);

		if (tempint == 3) { // �� �а� ī��3�� ���ִ� �Ŷ� ���ٸ�?
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

	//�� ����

}

void PrintPan(CardList &PlayerPae, CardList& otherPlayerPae,
		CardList &PlayerDan, CardList &otherPlayerDan, CardList &strewed) {

	cout
			<< "------------------------------------------------------------------\n------------------------------------------------------------------\n\n\n�� ��: ";
	for (int i = 0; i < otherPlayerPae.getIndex(); i++) {
		cout << "[//] ";
	}
	cout << "\n���� ���� ī��: ";
	otherPlayerDan.sortByType();
	otherPlayerDan.printList();

	cout << "\n��ѷ��� �ִ� ī��: ";
	strewed.printList();

	cout << "\n���� ���� ī��:";
	PlayerDan.sortByType();

	PlayerDan.printList();
	cout << "\n";

}

// �� ����Ʈ

