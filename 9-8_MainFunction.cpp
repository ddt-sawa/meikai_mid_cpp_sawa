/*演習9-8 9-2節のクラステンプレートArray<>, Array<bool>, FixedArray<>をインクルードモデルで実現したプログラムを作成せよ。
(9/11 Array<bool>のように特殊化されたクラステンプレートは、現在使用中のVisualStudioCommunityでは宣言と定義を分割できない可能性があります。
他の環境にて分割コンパイルを調査中です。)*/

#include"9-8_ArrayClass.h"
#include"9-8_FixedArray.h"
#include<iostream>

using namespace std;


//配列の要素数
const int arraySize = 7;

int main()
{
	//配列クラスインスタンス
	ArrayClass<int> normalArray(arraySize);

	//固定長配列インスタンス
	FixedArray<int, 7> fixedArray;

	//両配列の要素が初期化されていることを確認するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//配列の要素を表示
		cout << "normalArray[" << firstCounter << "] = " << normalArray[firstCounter] << '\n';

		//固定長配列の要素を表示
		cout << "fixedArray[" << firstCounter << "] = " << fixedArray[firstCounter] << '\n';
	}
}