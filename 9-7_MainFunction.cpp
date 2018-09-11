/*演習9-7 9-1節のクラステンプレートTwin<>をインクルードモデルで実現したプログラムを作成せよ。*/

#include<string>
#include<iostream>
#include"9-7_ClassDefinition.h"

using namespace std;

//動作検証用整数A
const int firstInteger = 15;
//動作検証用整数B
const int secondInteger = 20;

//動作検証用文字列A
string firstString = "ABC";
//動作検証用文字列B
string secondString = "XYZ";
int main()
{
	//int型に明示化を行ったTwinクラスオブジェクト
	const TwinClass<int> integerTwin(firstInteger, secondInteger);

	//演算子<<の動作を確認
	cout << "integerTwin = " << integerTwin << '\n';

	//string型に明示化を行ったTwinクラスオブジェクト
	TwinClass<string> stringTwin(firstString, secondString);

	//演算子<<の動作を確認
	cout << "stringTwin = " << stringTwin << '\n';

	//操作説明
	cout << "stringTwinの値を変更します。\n";

	//第1値の入力を促す
	cout << "第1値 : ";

	//第1値セッタの働きを確認
	cin >> (stringTwin.setFirstValue());

	//第2値の入力を促す
	cout << "第2値 : ";

	//第2値セッタの働きを確認
	cin >> stringTwin.setSecondValue();

	//第1値が第2値より大きい場合
	if (!stringTwin.compareValues()) {

		//操作説明
		cout << "第1値 < 第2値が成立しませんのでソートします。\n";

		//第1値と第2値を並び替え
		stringTwin.sortValues();

		//変更した値を表示
		cout << "stringTwinは" << stringTwin << "に変更されました。\n";
	}
}