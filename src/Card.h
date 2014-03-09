/*
 * Card.h
 *
 *  Created on: 2014. 2. 23.
 *      Author: EzKorry
 */

#ifndef CARD_H_
#define CARD_H_

class Card {

private:

	const int cardMonth;
	//cardType: 0~11

	const int isPee;
	//pee 0:not, 1:pee, 2:ssangPee

	const int isTtee;
	//ttee 0:not, 1:chodan, 2:hongdan, 3:cheongdan, 4:beeTtee

	const int isAnimal;
	//animal 0:not, 1:bird, 2:animal

	const int isGwang;
	//gwang 0:not, 1:gwang, 2:beeGwang





	Card& operator= (const Card &);

public:



	Card(const Card &other);
	// ���������

	Card(const int cardType, const int pee, const int ttee, const int animal,
			const int gwang);
	// ������

	const Card * getAddress();


	bool operator==(const Card &other);
	// �񱳿�����

	const int getCardMonth() const;
	// ī�� �� ����

	const std::string getDescription() const;
	// ī�� ���� ����

	const int getCardType() const;
	// ī�� ���� ����
	// 1���� ���ʴ�� ��, ����, �ʴ�, ȫ��, û��, ���, ��, ����, ��, ��


};

#endif /* CARD_H_ */
