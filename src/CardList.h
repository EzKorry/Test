/*
 * CardList.h
 *
 *  Created on: 2014. 2. 25.
 *      Author: EzKorry
 */

#ifndef CARDLIST_H_
#define CARDLIST_H_


//const int Null = 0;
#include <list>

class vector;
class Card;
class CardList {
private:

	std::list<Card *> cardlist;
	//카드 보관할 배열


	int totalScore;

	CardList(const CardList &);
	CardList& operator=(const CardList &); //복사, 대입을 허용하지 않음

public:

	CardList();
	// 생성자

	void cardPush(const Card& card);
	void cardPush(Card& card);
	void cardPush(Card* card);
	//배열에 카드 넣음

	Card * cardPop();
	//배열의 제일 마지막칸에 있는 것 빼기

	Card * cardPopFirst();
	//배열의 제일 앞칸에 있는 것 빼기

	Card * cardDeleteSame(const Card& card);
	Card * cardDeleteSame(const Card* card);
	//같은 종류의 카드 빼기

	Card * cardDelete(const Card& card);
	Card * cardDelete(const Card* card);
	//배열에 특정 카드 뺌

	void printList();
	//카드 목록 프린트

	Card * selectCard();
	//카드 목록중 하나 선택하기

	Card * autoSelectCard(CardList& List);

	int getScore();
	//이 카드리스트의 점수 구하기

	int getIndex() const;
	//이 카드리스트의 총 갯수 구하기

	int getNumOfSameCard(const Card& card) ;
	int getNumOfSameCard(const Card* card) ;
	//같은 종류의 카드 갯수 구하기

	void sortByMonth();
	// 월로 정렬

	void sortByType();
	// 종류로 정렬

	void shuffle();
	// 섞기
};

#endif /* CARDLIST_H_ */
