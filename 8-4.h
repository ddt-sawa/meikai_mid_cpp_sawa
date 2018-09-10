#ifndef ___Error
#define ___Error

#include<iostream>

//数値演算による例外
class MathException {
public:

	/**
	* 例外が発生したことを表示する
	* @author Sawa
	* @since 8.7
	*/
	virtual void printError() const { std::cout << "数値演算例外。\n"; }
};

//0による除算を行った例外
class DividedByZero : public MathException {
public:

	/**
	* 0による除算が発生したことを表示する
	* @author Sawa
	* @since 8.7
	*/
	void printError() const { std::cout << "0による除算。\n"; }
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
	* オーバーフローが発生したことと、その値を表示する
	* @author Sawa
	* @since 8.7
	*/
	void printError() const { std::cout << "オーバーフロー(値は" << integerValue << ")。\n"; }


//データメンバ
public:
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
	* アンダーフローが発生したことと、その値を表示する
	* @author Sawa
	* @since 8.7
	*/
	void printError() const { std::cout << "アンダーフロー(値は" << integerValue << ")。\n"; }

//データメンバ
private:
	int integerValue; //アンダーフローした値
};

#endif