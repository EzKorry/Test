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
	// 복사생성자

	Card(const int cardType, const int pee, const int ttee, const int animal,
			const int gwang);
	// 생성자

	const Card * getAddress();


	bool operator==(const Card &other);
	// 비교연산자

	const int getCardMonth() const;
	// 카드 월 리턴

	const std::string getDescription() const;
	// 카드 설명 리턴

	const int getCardType() const;
	// 카드 종류 리턴
	// 1부터 차례대로 피, 쌍피, 초단, 홍단, 청단, 비띠, 새, 동물, 광, 비광


};

#endif /* CARD_H_ */
