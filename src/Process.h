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
// 플레이어 턴 행동

void PrintPan(CardList &PlayerPae, CardList& otherPlayerPae,
		CardList &PlayerDan, CardList &otherPlayerDan, CardList &strewed);
// 판 프린트

void ComputerTurn(CardList &PlayerPae, CardList &PlayerDan, CardList &strewed,
		CardList &deck);
// 컴퓨터 턴

#endif /* PROCESS_H_ */
