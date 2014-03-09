/*
 * CardList.cpp
 *
 *  Created on: 2014. 2. 25.
 *      Author: EzKorry
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include "CardList.h"
#include "Card.h"
using namespace std;

class isSameMonthOfCard {
public:

	isSameMonthOfCard(const Card* a) :
			cc(a) {

	}

	bool operator()(const Card* a) {
		return a->getCardMonth() == cc->getCardMonth();
	}

private:
	const Card* cc;
};

class ByMonth {
public:
	bool operator()(const Card* rhs, const Card* lhs) {
		return rhs->getCardMonth() < lhs->getCardMonth() ;

	}
};


class ByType {
public:
	// 1부터 차례대로 피, 쌍피, 초단, 홍단, 청단, 비띠, 새, 동물, 광, 비광
	bool operator()(const Card* rhs, const Card* lhs) {
		if(rhs->getCardType() == 9 || rhs->getCardType() == 10) {
			return true;
		}
		else if(rhs->getCardType() == 1 || rhs->getCardType() == 2) {
			return false;
		}

		else if(lhs->getCardType() == 9 || lhs->getCardType() == 10) {
					return false;
				}
				else if(lhs->getCardType() == 1 || lhs->getCardType() == 2) {
					return true;
				}

		return rhs->getCardType() < lhs->getCardType();

	}


};
CardList::CardList() :
		 totalScore(0) {

}
void CardList::cardPush(Card& card) {
	cardlist.push_back(&card);

}
void CardList::cardPush(Card* card) {
	cardlist.push_back(card);
}

Card * CardList::cardPop() {
	Card * temp = NULL;
	temp = cardlist.back();
	cardlist.pop_back();
	return temp;

}

Card * CardList::cardPopFirst() {
	Card * temp = NULL;
	temp = cardlist.front();
	cardlist.pop_front();
	return temp;

}

Card * CardList::cardDeleteSame(const Card &card) {
	std::list<Card *>::iterator i;
	Card *temp = NULL;
	isSameMonthOfCard K(&card);

	i = std::find_if(cardlist.begin(), cardlist.end(), K);
	temp = *i;
	cardlist.remove(temp);
	return temp;
}

Card * CardList::cardDeleteSame(const Card *card) {
	std::list<Card *>::iterator i;
	Card *temp = NULL;
	isSameMonthOfCard K(card);

	i = std::find_if(cardlist.begin(), cardlist.end(), K);
	temp = *i;
	cardlist.remove(temp);
	return temp;
}

Card * CardList::cardDelete(const Card &card) {
	std::list<Card *>::iterator i;
		Card *temp = NULL;


		i = std::find(cardlist.begin(), cardlist.end(), &card);
		temp = *i;
		cardlist.erase(i);


		return temp;

}

Card * CardList::cardDelete(const Card *card) {
	std::list<Card *>::iterator i;
			Card *temp = NULL;


			i = std::find(cardlist.begin(), cardlist.end(), card);
			temp = *i;
			cardlist.erase(i);


			return temp;

}

void CardList::printList() {

	for (std::list<Card *>::iterator i = cardlist.begin(); i != cardlist.end(); i++) {
		cout << (*i)->getDescription() << " ";
	}
	cout << endl;

}

Card * CardList::selectCard() {
	std::size_t i=0;
	std::list<Card *>::iterator it = cardlist.begin();
	printList();



	cout << "카드를 선택하세요(1~" << cardlist.size() << "): ";
	while (1) {
		cin >> i;
		if (i >= 1 && i <= cardlist.size()) break;
		else
			cout << "카드를 다시 선택하세요(1~" << cardlist.size() << "): ";
	}

	i--;

	while(i>0) {
		it++;
		i--;
	}
	return cardDelete(*it);

}

Card * CardList::autoSelectCard(CardList& List) {

	std::list<Card *>::iterator i;
	for (i = cardlist.begin(); i != cardlist.end(); i++) {
		if(List.getNumOfSameCard(*i)) {
			return cardDelete(*i);
		}

	}
	return cardDelete(cardlist.front());
}

int CardList::getScore() {
	int gwang = 0, chodan = 0, hongdan = 0, cheongdan = 0, dan = 0,
			beegwang = 0, godori = 0, dongmul = 0, pee = 0;
	for (std::list<Card *>::iterator i = cardlist.begin(); i != cardlist.end(); i++) {
		int type = (*i)->getCardType();
		switch (type) {
			case 1:
				pee++;
				break;
			case 2:
				pee += 2;
				break;
			case 3:
				dan++;
				chodan++;
				break;
			case 4:
				hongdan++;
				dan++;
				break;
			case 5:
				cheongdan++;
				dan++;
				break;
			case 6:
				dan++;
				break;
			case 7:
				godori++;
				dongmul++;
				break;
			case 8:
				dongmul++;
				break;
			case 9:
				gwang++;
				break;
			case 10:
				gwang++;
				beegwang++;
				break;
			default:

				break;
		}

	}

	if (chodan == 3) totalScore += 3;
	if (hongdan == 3) totalScore += 3;
	if (cheongdan == 3) totalScore += 3;
	if (dan >= 5) totalScore += dan - 4;
	if (godori == 3) totalScore += 5;
	if (dongmul >= 5) totalScore += dongmul - 4;
	if (pee >= 10) totalScore += pee - 9;

	if (gwang >= 4) totalScore += gwang;
	else if (gwang == 3 && beegwang == 1) totalScore += 2;
	else if (gwang == 3 && beegwang == 0) totalScore += 3;

	return totalScore;
}

int CardList::getIndex() const {
	return cardlist.size();
}

int CardList::getNumOfSameCard(const Card& card)  {

	int temp = 0;
	for (std::list<Card *>::iterator i = cardlist.begin(); i != cardlist.end(); i++) {
		if ((*i)->getCardMonth() == card.getCardMonth()) {
			temp++;
		}
	}
	return temp;

}

int CardList::getNumOfSameCard(const Card* card)  {

	int temp = 0;
		for (std::list<Card *>::iterator i = cardlist.begin(); i != cardlist.end(); i++) {
			if ((*i)->getCardMonth() == card->getCardMonth()) {
				temp++;
			}
		}
		return temp;


}

void CardList::sortByMonth() {

	cardlist.sort(ByMonth());
}

void CardList::sortByType() {
	// 1부터 차례대로 피, 쌍피, 초단, 홍단, 청단, 비띠, 새, 동물, 광, 비광

	cardlist.sort(ByType());

}

void CardList::shuffle() {
	std::vector<Card *> tempVector;

	tempVector.assign(cardlist.begin(),cardlist.end());
	std::random_shuffle(tempVector.begin(), tempVector.end());
	cardlist.assign(tempVector.begin(), tempVector.end());

}
