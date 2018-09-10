#ifndef ___Computer
#define ___Computer

#include<iostream>
#include<ctime>
#include<cstdlib>
#include "6-3_PlayerClass.h"

//コンピュータクラス
class ComputerClass : public PlayerClass {

public:

	/**
	* HumanClass型オブジェクトのコンストラクタ(セッタを呼び出す)
	* @author Sawa
	* @since 8.1
	*/
	ComputerClass() { setHand(); }

	/**
	* ComputerClass型セッタ
	* @author Sawa
	* @since 8.1
	*/
	void setHand()
	{
		//乱数テーブルを用意
		srand(time(NULL));

		//0-2までの乱数
		int inputHand = rand() % 3;

		//乱数をデータメンバに代入
		PlayerClass::setHand(inputHand);
	}

	/**
	* コンピュータの手を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printHand() const
	{
		std::cout << "コンピュータの手は" << integertoString(getHand()) << "です。";
	}
};

#endif