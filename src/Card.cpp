/*
 * Card.cpp
 *
 *  Created on: 2014. 2. 25.
 *      Author: EzKorry
 */

#include <iostream>
#include <sstream>
#include "Card.h"

using namespace std;

template<typename T>
string NumberToString(T Number) {
	ostringstream ss;
	ss << Number;
	return ss.str();
}

Card::Card(int acardType, int apee, int attee, int aanimal, int agwang) :
		cardMonth(acardType), isPee(apee), isTtee(attee), isAnimal(aanimal), isGwang(
				agwang) {

}
/*Card::Card(const Card &other) {
 cardType = other.cardType;
 isPee = other.isPee;
 isTtee = other.isTtee;
 isAnimal = other.isAnimal;
 isGwang = other.isGwang;
 }*/

const Card * Card::getAddress() {
	return this;
}
bool Card::operator==(const Card& other) {
	return (this->cardMonth == other.cardMonth) && (this->isPee == other.isPee)
			&& (this->isTtee == other.isTtee)
			&& (this->isAnimal == other.isAnimal)
			&& (this->isGwang == other.isGwang);

}

const int Card::getCardMonth() const {
	return cardMonth;
}

const string Card::getDescription() const{
	string temp = "[";
	int type = 0;
	temp.append(NumberToString(cardMonth));
	temp.append("-");
	/*if (isPee == 1)
	 temp.append("ÇÇ");
	 else if (isPee == 2)
	 temp.append("½ÖÇÇ");
	 else if (isTtee == 1)
	 temp.append("ÃÊ´Ü");
	 else if (isTtee == 2)
	 temp.append("È«´Ü");
	 else if (isTtee == 3)
	 temp.append("Ã»´Ü");
	 else if (isTtee == 4)
	 temp.append("ºñ¶ì");
	 else if (isAnimal == 1)
	 temp.append("»õ");
	 else if (isAnimal == 2)
	 temp.append("µ¿¹°");
	 else if (isGwang == 1)
	 temp.append("±¤");
	 else if (isGwang == 2)
	 temp.append("ºñ±¤");
	 else
	 cout << "¿¡·¯¾î¾î¾î" << endl;*/

	type = getCardType();
	switch (type) {
	case 1:
		temp.append("ÇÇ");
		break;
	case 2:
		temp.append("½ÖÇÇ");
		break;
	case 3:
		temp.append("ÃÊ´Ü");
		break;
	case 4:
		temp.append("È«´Ü");
		break;
	case 5:
		temp.append("Ã»´Ü");
		break;
	case 6:
		temp.append("ºñ¶ì");
		break;
	case 7:
		temp.append("»õ");
		break;
	case 8:
		temp.append("µ¿¹°");
		break;
	case 9:
		temp.append("±¤");
		break;
	case 10:
		temp.append("ºñ±¤");
		break;
	default:
		temp.append("¿¡·¯");
		break;
	}

	temp.append("]");

	return temp;

}

const int Card::getCardType() const {
	if (isPee == 1)
		return 1;
	else if (isPee == 2)
		return 2;
	else if (isTtee == 1)
		return 3;
	else if (isTtee == 2)
		return 4;
	else if (isTtee == 3)
		return 5;
	else if (isTtee == 4)
		return 6;
	else if (isAnimal == 1)
		return 7;
	else if (isAnimal == 2)
		return 8;
	else if (isGwang == 1)
		return 9;
	else if (isGwang == 2)
		return 10;
	else
		return -1;

}
