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
	//ī�� ������ �迭


	int totalScore;

	CardList(const CardList &);
	CardList& operator=(const CardList &); //����, ������ ������� ����

public:

	CardList();
	// ������

	void cardPush(const Card& card);
	void cardPush(Card& card);
	void cardPush(Card* card);
	//�迭�� ī�� ����

	Card * cardPop();
	//�迭�� ���� ������ĭ�� �ִ� �� ����

	Card * cardPopFirst();
	//�迭�� ���� ��ĭ�� �ִ� �� ����

	Card * cardDeleteSame(const Card& card);
	Card * cardDeleteSame(const Card* card);
	//���� ������ ī�� ����

	Card * cardDelete(const Card& card);
	Card * cardDelete(const Card* card);
	//�迭�� Ư�� ī�� ��

	void printList();
	//ī�� ��� ����Ʈ

	Card * selectCard();
	//ī�� ����� �ϳ� �����ϱ�

	Card * autoSelectCard(CardList& List);

	int getScore();
	//�� ī�帮��Ʈ�� ���� ���ϱ�

	int getIndex() const;
	//�� ī�帮��Ʈ�� �� ���� ���ϱ�

	int getNumOfSameCard(const Card& card) ;
	int getNumOfSameCard(const Card* card) ;
	//���� ������ ī�� ���� ���ϱ�

	void sortByMonth();
	// ���� ����

	void sortByType();
	// ������ ����

	void shuffle();
	// ����
};

#endif /* CARDLIST_H_ */
