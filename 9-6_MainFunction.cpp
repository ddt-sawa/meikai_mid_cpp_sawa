/*演習9-6 Array<bool>型の配列に対して、対話的に処理を行うプログラムを作成せよ。
前問で作成したメンバ関数get_vsizeも利用すること。*/

#include<iostream>
#include "9-6_ArrayClass.h"
#include "9-6_BoolArray.h"

using namespace std;

//bool型trueに値するint型変数を定義
const int trueValue = 1;

//bool型falseに値するint型変数を定義
const int falseValue = 0;

int main()
{
	//概要説明
	cout << "bool型の値をビットベクトルとして格納したバイトの配列testArrayを作成します。\n";

	//bool型要素数
	int boolNumber;

	//bool型要素数の入力を促す
	cout << "bool型オブジェクトの個数を入力してください。 : ";

	//入力
	cin >> boolNumber;

	//オブジェクトの作成
	ArrayClass<bool> testArray(boolNumber);

	//作成したオブジェクトの詳細説明
	cout << "bool型オブジェクトの個数は" << boolNumber << "、それを格納するバイト配列testArrayの要素数は" << testArray.getByteArraySize() << "です。\n";

	//要素に代入する値の入力を促す
	cout << "bool型オブジェクトに値を代入してください。 ([0] = \"False\" [1] = \"True\")\n";

	//配列の全要素に入力値を代入するループ
	for (int firstCounter = 0; firstCounter < boolNumber; ++firstCounter) {

		//入力値宣言
		int inputValue;

		//妥当な値が入力されるまでループ
		do {
			//入力を促す
			cout << "testArray[" << firstCounter << "] = ";

			//入力
			cin >> inputValue;

			//0か1が入力されるまでループ
		} while (inputValue != falseValue && inputValue != trueValue);

		//入力値を代入
		testArray[firstCounter] = inputValue;
	}
	//配列の全要素をbool型で走査表示するループ
	for (int firstCounter = 0; firstCounter < boolNumber; ++firstCounter) {

		//要素を表示
		cout << "testArray[" << firstCounter << "] = " << boolalpha << static_cast<bool>(testArray[firstCounter]) << "\n"; 
	}
}