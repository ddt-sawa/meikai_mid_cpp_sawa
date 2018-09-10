/*演習課題8-7 List8-13のプログラムの二つの例外ハンドラを、const exception&型を受け取るもの一つのみに改変したプログラムを作成せよ。*/

#include<iostream>
//例外処理基底クラスexceptionを呼び出す
#include<exception>

using namespace std;


/**
* 0-99までの整数値を受け取り、0-99までの合計値を返却する。それ以外の値に関しては例外を送出する
* @param firstInteger 整数a, secondInteger 整数b
* @return sumValue 合計値
* @author Sawa
* @since 8.9
*/
int addOperands(int firstInteger, int secondInteger)
{
	//整数aの値が不正の場合
	if (firstInteger < 0 || firstInteger > 99) {

		//その旨を記した文字列を持つ、例外クラスを送出
		throw out_of_range("整数aの値が不正。");
	}

	//整数bの値が不正の場合
	if (secondInteger < 0 || secondInteger > 99) {

		//その旨を記した文字列を持つ、例外クラスを送出
		throw out_of_range("整数bの値が不正。");
	}
	//整数aと整数bの合計値
	int sumValue = firstInteger + secondInteger;

	//合計値が不正の場合
	if (sumValue < 0 || sumValue > 99) {

		//その旨を記した文字列を持つ、例外クラスを送出
		throw overflow_error("オーバーフロー。");
	}
	//合計値を返却
	return sumValue;
}

int main()
{
	//整数a
	int firstInteger;

	//入力してほしい値を表示
	cout << "aの値(0～99) : ";

	//整数aの値を入力
	cin >> firstInteger;

	//整数b
	int secondInteger;

	//入力してほしい値を表示
	cout << "bの値(0～99) : ";

	//整数bの値を入力
	cin >> secondInteger;

	//0-99以外の値が入力された場合、合計値が0-99以外だった場合に例外を送出
	try {
		//加算した値を返却
		cout << "加算した値は" << addOperands(firstInteger, secondInteger) << "です。\n";
	}
	//例外を捕捉した場合
	catch (const exception& errorClass) {

		//論理エラーの内容によって表示されるコメントが異なることを確認
		cerr << "論理エラー発生 : " << errorClass.what() << '\n';
	}
}