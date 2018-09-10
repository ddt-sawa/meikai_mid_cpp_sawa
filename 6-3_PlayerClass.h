#ifndef ___Player
#define ___Player

#include<iostream>
#include<string>

//プレーヤクラス(抽象クラス)
class PlayerClass {
public:

	//純粋仮想デストラクタ
	virtual ~PlayerClass() = 0;

	//HumanClass、ComputerClassおける手のセッタ
	virtual void setHand() = 0;

	//PlayerClassにおける手のセッタ
	void setHand(int);

	//手のゲッタ
	int getHand() const { return playerHand; }

	//手を表示
	virtual void printHand() const = 0;

//データメンバ
private:
	int playerHand; //じゃんけんの手

};


//派生クラスのデストラクタ
inline PlayerClass::~PlayerClass() {}

/**
* じゃんけんの手のセッタ
* @param inputHand
* @author Sawa
* @since 8.1
*/
inline void PlayerClass::setHand(int inputHand) { playerHand = inputHand; }

/**
* じゃんけんの手を整数から文字列に変換する
* @param inputInteger 整数
: @return string型文字列 (0 = グー, 1 = パー, 2 = チョキ) 
* @author Sawa
* @since 8.1
*/
inline std::string integertoString(int inputInteger)
{
	switch (inputInteger) {
	case 0:               //0の場合 
		return "グー";    //"グー"を返却

	case 1:               //1の場合
		return "パー";    //"パー"を返却

	case 2:               //2の場合
		return "チョキ";  //チョキを返却

	default:              //それ以外の場合
		return  "";       //空白を返却
	}
}
#endif