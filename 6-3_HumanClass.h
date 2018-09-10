#ifndef ___Human
#define ___Human

#include<iostream>
#include "6-3_PlayerClass.h"

//人間クラス
class HumanClass : public PlayerClass {

public:

	/**
	* HumanClass型オブジェクトのコンストラクタ(セッタを呼び出す)
	* @author Sawa
	* @since 8.1
	*/
	HumanClass(){ setHand();}
	
	/**
	* HumanClass型オブジェクトのコンストラクタ(セッタを呼び出す)
	* @author Sawa
	* @since 8.1
	*/
	void setHand()
	{
		//入力値
		int inputHand;

		//人間の手を入力するループ
		do {
			//メニューを表示
			std::cout << "手を入力してください。 ([0] = グー　[1] = パー  [2] = チョキ) ";

			//手を入力
			std::cin >> inputHand;

			//適切な値が入力されるまでループ
		} while (inputHand < 0 && inputHand > 2);

		//適切な値が入力された場合、値をデータメンバに代入
		PlayerClass::setHand(inputHand);
	}

	/**
	* 人間の手を表示
	* @author Sawa
	* @since 8.1
	*/
	void printHand() const
	{
		std::cout << "あなたの手は" << integertoString(getHand()) << "です。";
	}
};

#endif