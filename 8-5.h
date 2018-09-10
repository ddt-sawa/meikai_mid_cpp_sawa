#ifndef ___Error
#define ___Error

/*演習8-5 数値演算例外クラス群(第3版)の関数displayは、画面(標準出力ストリーム)への表示を行うため、
使い勝手が悪く利用できる局面に制限を受ける。エラーの内容を画面に表示するのではなく、
文字列を返却するように仕様変更した、以下の形式の関数を作成せよ。

virtual std::string what() const;

返却する文字列は、第3版のクラス群で表示している文字列と同じものとすること。*/

#include<iostream>
#include<sstream>

//数値演算による例外
class MathException {

public:

	/**
	* 例外が発生したことを表示する
	* @author Sawa
	* @since 8.7
	*/
	virtual std::string printError() const { return "数値演算例外。"; }
};

//0による除算を行った例外
class DividedByZero : public MathException {

public:

	/**
	* 0による除算が発生したことを表示する
	* @author Sawa
	* @since 8.7
	*/
	std::string printError() const { return "0による除算。"; }
};

//オーバーフローによる例外
class OverflowClass : public MathException {
public:

	/**
	* オーバーフローした場合の例外クラスコンストラクタ
	* @param inputValue オーバーフローした値
	* @author Sawa
	* @since 8.6
	*/
	OverflowClass(int inputValue) : integerValue(inputValue) {}

	/**
	* オーバーフローした値のゲッタ
	* @return integerValue オーバーフローした値
	* @author Sawa
	* @since 8.6
	*/
	int getValue() const { return integerValue; }

	/**
	* オーバーフローが発生したことと、その値を文字列にして返却する
    * @return returnString 文字列
	* @author Sawa
	* @since 8.7
	*/
	std::string printError() const {

		//出力ストリーム
		std::ostringstream userStream;

		//返却する文字列
		std::string returnString;

		//出力ストリームにコメントとオーバーフローした値を挿入
		userStream << "オーバーフロー(値は" << integerValue << ")";

		//返却する文字列に、出力ストリーム内の文字列表現を代入
		returnString = userStream.str();

		//文字列を返却
		return returnString;
	}

//データメンバ
private:
	int integerValue; //オーバーフローした値
};

//アンダーフローによる例外
class UnderflowClass : public MathException {
public:

	/**
	* アンダーフローした場合の例外クラスコンストラクタ
	* @param inputValue アンダーフローした値
	* @author Sawa
	* @since 8.6
	*/
	UnderflowClass(int inputValue) : integerValue(inputValue) {}


	/**
	* アンダーフローした値のゲッタ
	* @return integerValue アンダーフローした値
	* @author Sawa
	* @since 8.6
	*/
	int getValue() const { return integerValue; }

	/**
	* アンダーフローが発生したことと、その値を文字列にして返却する
	* @return returnString 文字列
	* @author Sawa
	* @since 8.7
	*/
	std::string printError() const {

		//出力ストリーム
		std::ostringstream userStream;

		//返却する文字列
		std::string returnString;

		//出力ストリームにコメントとアンダーフローした値を挿入
		userStream << "アンダーフロー(値は" << integerValue << ")";

		//返却する文字列に、出力ストリーム内の文字列表現を代入
		returnString = userStream.str();

		//文字列を返却
		return returnString;
	}

//データメンバ
private:
	int integerValue; //アンダーフローした値

};

#endif