/*
 * Process.h
 *
 *  Created on: 2014. 2. 25.
 *      Author: EzKorry
 */

#ifndef PROCESS_H_
#define PROCESS_H_

class CardList;
void PlayerTurn(CardList &PlayerPae, CardList &PlayerDan, CardList &strewed,
		CardList &deck);
// �÷��̾� �� �ൿ

void PrintPan(CardList &PlayerPae, CardList& otherPlayerPae,
		CardList &PlayerDan, CardList &otherPlayerDan, CardList &strewed);
// �� ����Ʈ

void ComputerTurn(CardList &PlayerPae, CardList &PlayerDan, CardList &strewed,
		CardList &deck);
// ��ǻ�� ��

#endif /* PROCESS_H_ */
