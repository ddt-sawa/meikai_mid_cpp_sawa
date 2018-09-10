/*演習8-5 数値演算例外クラス群(第3版)の関数displayは、画面(標準出力ストリーム)への表示を行うため、
使い勝手が悪く利用できる局面に制限を受ける。エラーの内容を画面に表示するのではなく、
文字列を返却するように仕様変更した、以下の形式の関数を作成せよ。

virtual std::string what() const;

返却する文字列は、第3版のクラス群で表示している文字列と同じものとすること。*/


#include<iostream>
#include"8-5.h"

using namespace std;


/**
* 値が0より小さい、または99より大きい場合例外クラスを送出する
* @param inputValue 値
* @return inputValue 値
* @author Sawa
* @since 8.6
*/
int checkValue(int inputValue)
{
	//値が0より小さい場合
	if (inputValue < 0) {

		//アンダーフロークラスを送出
		throw UnderflowClass(inputValue);
	}
	//値が99より大きい場合
	if (inputValue > 99) {

		//オーバーフロークラスを送出
		throw OverflowClass(inputValue);

	}
	//値を返却
	return inputValue;
}

/**
* 2整数の足し算を行い、その値を一度checkValue関数に渡したのちに返却する
* @param firstInteger, secondInteger 整数
* @return sumValue 和
* @author Sawa
* @since 8.6
*/
int addOperands(int firstInteger, int secondInteger)
{
	//2引数の和を求める
	int sumValue = firstInteger + secondInteger;

	//和をcheckValue関数に渡した後に返却
	return checkValue(sumValue);
}

/**
* 2整数の引き算を行い、その値を一度checkValue関数に渡したのちに返却する
* @param firstInteger, secondInteger 整数
* @return subtractionValue 差
* @author Sawa
* @since 8.6
*/
int subtractOperands(int firstInteger, int secondInteger)
{
	//第一引数から第二引数を引いた値を計算する
	int subtractionValue = firstInteger - secondInteger;

	//差をcheckValue関数に渡した後に返却
	return checkValue(subtractionValue);
}


/**
* 2整数の乗算を行い、その値を一度checkValue関数に渡したのちに返却する
* @param firstInteger, secondInteger 整数
* @return multiplicationValue 積
* @author Sawa
* @since 8.6
*/
int multiplicateOperands(int firstInteger, int secondInteger)
{
	//2引数の積を求める
	int sumValue = firstInteger * secondInteger;

	//積をcheckValue関数に渡した後に返却
	return checkValue(sumValue);
}

/**
* 2整数の割り算を行い、その値を一度checkValue関数に渡したのちに返却する
* @param firstInteger, secondInteger 整数
* @return dividedValue 商
* @author Sawa
* @since 8.6
*/
int divideOperands(int firstInteger, int secondInteger)
{
	//第二引数が0だった場合
	if (secondInteger == 0) {

		//0による除算クラスを返却
		throw DividedByZero();
	}

	//第一引数から第二引数を割った値を計算する
	int subtractionValue = firstInteger / secondInteger;

	//商をcheckValue関数に渡した後に返却
	return checkValue(subtractionValue);
}

int main()
{
	//概要告知
	cout << "0から99までの値を扱う計算を行います。\n";

	//整数a
	int firstInteger = 0;

	//整数b
	int secondInteger = 0;

	//妥当な整数を入力させるためのループ
	do {
		//整数aの入力を促す
		cout << "整数aの値を入力してください。\n";

		//入力
		cin >> firstInteger;

		//整数bの入力を促す
		cout << "整数bの値を入力してください。\n";

		cin >> secondInteger;

		//入力された値が0より小さい、または99より大きい場合再試行
	} while (firstInteger < 0 || firstInteger > 99 || secondInteger < 0 || secondInteger > 99);

	//0から99までの値を扱う計算を行い、関数内で例外が捕捉された場合、例外ハンドラへ送出を行う
	try {
		cout << "a + b = " << addOperands(firstInteger, secondInteger) << '\n';           //加算

		cout << "a - b = " << subtractOperands(firstInteger, secondInteger) << '\n';      //減算

		cout << "a * b = " << multiplicateOperands(firstInteger, secondInteger) << '\n';  //乗算

		cout << "a / b = " << divideOperands(firstInteger, secondInteger) << '\n';        //除算
	}
	//MathExceptionとその下位クラス型の例外を補足するハンドラ
	catch (const MathException& inputClass) {

		//例外が発生したことを告知
		cout << "MathExceptionを補足。\n";

		//例外に応じたコメントが表示されることを確認
		cout << inputClass.printError() << '\n';

	}
}