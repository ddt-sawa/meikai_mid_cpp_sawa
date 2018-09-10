#ifndef ___VipMember
#define ___VipMember

#include<string>
#include "5-1_Member.h"

//優待会員クラス
class VipMemberClass : public MemberClass{
public:

	/**
	* VipMemberClass型オブジェクトのコンストラクタ
	* @param inputName 名前, inputNumber 会員番号, inputWeight 体重, inputPrivilege 特典
	* @author Sawa
	* @since 7.31
	*/
	VipMemberClass(const std::string& inputName, int inputNumber, double inputWeight, const std::string& inputPrivilege)
		: MemberClass(inputName, inputNumber, inputWeight)
	{
		//特典のセッタを呼び出す
		setPrivilege(inputPrivilege);
	}


	/**
	* 特典のセッタ
	* @inputPrivilege 特典
	* @author Sawa
	* @since 8.1
	*/
	void setPrivilege(const std::string& inputPrivilege) 
	{
		//特典の入力が空白なら未登録を、そうでなければ特典を表示
		userPrivilege = (inputPrivilege != "") ? inputPrivilege : "未登録";
	}

	/**
	* 会員情報を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printInformation() const { std::cout << "No." << getNumber() << ":" << getName() << "(" << getWeight() << "kg)\n"; }

	/**
	* 自己紹介を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printIntrodution() const { std::cout << "私は優待会員です。\n"; }

//データメンバ
private:
	std::string userPrivilege; //特典

};

#endif