#ifndef ___Member
#define ___Member

//string型を使用
#include<string>

#include<iostream>

//スポーツジムの一般会員クラス
class MemberClass {
public:
	/**
	* MemberClass型オブジェクトのコンストラクタ
	* @param inputName 名前, inputNumber 会員番号, inputWeight 体重
	* @author Sawa
	* @since 7.31
	*/
	MemberClass(const std::string& inputName, int inputNumber, double inputWeight)
		: userName(inputName), userNumber(inputNumber), userWeight(inputWeight) {}

	/**
	* 名前のゲッタ
	* @return userName 名前
	* @author Sawa
	* @since 7.31
	*/
	std::string getName() const { return userName; }

	/**
	* 会員番号のゲッタ
	* @return userNumber 会員番号
	* @author Sawa
	* @since 7.31
	*/
	int getNumber() const { return userNumber; }

	/**
	* 体重のゲッタ
	* @return userWeight 体重
	* @author Sawa
	* @since 7.31
	*/
	double getWeight() const { return userWeight; }

	/**
	* 体重のセッタ
	* @param inputWeight 体重
	* @author Sawa
	* @since 7.31
	*/
	void setWeight(double inputWeight) { userWeight = (inputWeight > 0) ? inputWeight : 0; }

	/**
	* 会員情報を表示する
	* @author Sawa
	* @since 8.1
	*/
	virtual void printInformation() const{ std::cout << "No." << userNumber << ":" << userName << "(" << userWeight << "kg)\n"; }

	/**
	* 自己紹介を表示する
	* @author Sawa
	* @since 8.1
	*/
	virtual void printIntrodution() const { std::cout << "私は一般会員です。\n"; }

//データメンバ
private:
	std::string userName;  //名前
	int userNumber;        //会員番号
	double userWeight;     //体重

};

#endif 