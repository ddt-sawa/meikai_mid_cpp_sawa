/*演習10-5 List1017に、関数呼び出しprint(x.rebegin(), x.rend())を追加するとどうなるかを検証せよ。*/

#include<vector>
#include<string>
#include<iostream>

using namespace std;

//コンテナの要素数
const int arraySize = 3;

/**
* コンテナの要素を表示する関数テンプレート
* @param firstIterator 先頭要素のポインタ, lastIterator 末尾要素の一つ後ろのポインタ
* @return
* @author Sawa
* @since 9.7
*/
template<class InputIterator> void printContena(InputIterator firstIterator, InputIterator lastIterator)
{
	//前括弧を表示
	cout << "{ ";

	//コンテナの要素を走査表示するためのループ
	for (InputIterator firstCounter = firstIterator; firstCounter != lastIterator; firstCounter++) {

		//要素を表示
		cout << *firstCounter << " ";
	}
	//後括弧を表示
	cout << "}";
}

int main()
{
	//int型配列
	int intArray[arraySize] = { 1,2,3 };

	//配列をベクトルに代入
	vector<int> intVector(intArray, intArray + sizeof(intArray) / sizeof(intArray[0]));

	//int型ベクトル表示
	printContena(intVector.begin(), intVector.end());

	//課題に従い、関数呼び出しを行う
	printContena(intVector.rbegin(), intVector.rend());

	//逆順に表示されることを確認
}