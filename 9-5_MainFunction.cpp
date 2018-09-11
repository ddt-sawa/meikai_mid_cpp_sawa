/*演習9-5 クラスArray<bool>型に対して、velemのゲッタの働きを持つメンバ関数
int Array<bool>::get_vsize() const;  を追加せよ。*/

#include<iostream>
#include "9-5_ArrayClass.h"
#include "9-5_BoolArray.h"

using namespace std;

int main()
{
	//オブジェクトの要素数
	const int arraySize = 20;

	//ゲッタの働きを調べるためのオブジェクトを初期化
	ArrayClass<bool> testArray(arraySize);

	//ゲッタの働きを確認 (20ビットを格納できるbool型の要素数は3)
	cout << testArray.getByteArraySize();
}