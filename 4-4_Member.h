#ifndef ___Member
#define ___Member

//string型を使用
#include<string>

//スポーツジムの一般会員クラス
class MemberClass {

public:
	/**
	* MemberClass型オブジェクトのコンストラクタ
	* @param inputName 名前, inputNumber 会員番号, inputWeight 体重
	* @author Sawa
	* @since 7.31
	*/
	MemberClass(const std::string& inputName, int inputNumber, double inputWeight) {}

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
	* 会員番号のゲッタ
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
	void setWeight(double inputWeight) { userWeight = (inputWeight > 0) ?  inputWeight : 0; }

//データメンバ
private:
	std::string userName;  //名前
	int userNumber;        //会員番号
	double userWeight;     //体重
};

#endif 