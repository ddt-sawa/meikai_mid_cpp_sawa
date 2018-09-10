#ifndef ___SeniorMember
#define ___SeniorMember

#include<string>
#include "5-1_Member.h"

class SeniorMemberClass : public MemberClass {
public:

	/**
	* VipMemberClass型オブジェクトのコンストラクタ
	* @param inputName 名前, inputNumber 会員番号, inputWeight 体重, inputPrivilege 要介護度
	* @author Sawa
	* @since 7.31
	*/
	SeniorMemberClass(const std::string& inputName, int inputNumber, double inputWeight, int inputLevel = 0)
		: MemberClass(inputName, inputNumber, inputWeight)
	{
		//要介護度のセッタを呼び出す
		setCareLevel(inputLevel);
	}


	/**
	* 要介護度のセッタ
	* @param inputLevel 要介護度
	* @author Sawa
	* @since 8.1
	*/
	void setCareLevel(int inputLevel) 
	{
		//入力された要介護度が1-5の場合その値を、そうでない場合0をセット
		careLevel = (inputLevel >= 1 && inputLevel <= 5) ? inputLevel : 0;
	}

	/**
	* 要介護度のゲッタ
	* @return carelevel 介護度
	* @author Sawa
	* @since 8.1
	*/
	int getCareLevel() const { return careLevel; }


	/**
	* 会員情報を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printInformation() const { std::cout << "No." << getNumber() << ":" << getName() << "(" << getWeight()  << "kg) 要介護度 = " << getCareLevel(); }

	/**
	* 自己紹介を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printIntrodution() const { std::cout << "私は長寿会員です。\n"; }

//データメンバ
private:
	int careLevel; //要介護度

};

#endif