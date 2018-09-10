#ifndef ___ResigningMember
#define ___ResigningMember

#include<iostream>
#include<string>
#include"4-4_Member.h"

//退会済み会員クラス
class ResigningMember : private MemberClass {

public:

	/**
	* ResigningMember型オブジェクトのコンストラクタ
	* @param inputName 名前, inputNumber 会員番号, inputWeight 体重
	* @author Sawa
	* @since 7.31
	*/
	ResigningMember(const std::string& inputName, int inputNumber, double inputWeight)
		: MemberClass(inputName, inputNumber, inputWeight) {}

	/**
	* MemberClass型体重ゲッタを隠蔽する、ResigningMember型メンバ関数
	* @return 0
	* @author Sawa
	* @since 7.31
	*/
	double getWeight() {

		//説明文表示
		std::cout << "退会した会員の体重の取得はできません。\n";

		//0を返却
		return 0;
	}
	//会員番号のゲッタに対するアクセスをpublicに変更
	using MemberClass::getNumber;
};

#endif