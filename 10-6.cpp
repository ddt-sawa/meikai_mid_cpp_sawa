/*演習10-6 <functional>で提供される算術演算のファンクタとtransformアルゴリズムを組み合わせたプログラムを作成せよ。*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//ベクトルの要素数
const int vectorSize = 5;

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
	//ベクトルA
	vector<int> firstVector;

	//ベクトルAの要素に値を代入するためのループ
	for (int firstCounter = 0; firstCounter < vectorSize; ++firstCounter) {

		//添字と同じ値を代入
		firstVector.push_back(firstCounter);
	}
	//ベクトルA表示
	printContena(firstVector.begin(), firstVector.end());   //  {0 1 2 3 4}

	//ベクトルB
	vector<int> secondVector(vectorSize);

	//ベクトルBに、ファンクタを適用し、ベクトルAの符号を反転した値を代入
	transform(firstVector.begin(), firstVector.end(), secondVector.begin(), negate<int>());

	//ベクトルB表示
	printContena(secondVector.begin(), secondVector.end()); //  -A   {0 -1 -2 -3 -4}

	//AとBに加算ファンクタを適用した値を保存するベクトル
	vector<int> plusVector(vectorSize);

	//加算ファンクタを適用
	transform(firstVector.begin(), firstVector.end(), secondVector.begin(), plusVector.begin(), plus<int>());

	//適用後のベクトルを表示
	printContena(plusVector.begin(), plusVector.end());     //  A + B   {0 0 0 0 0}

	//AとBに乗算ファンクタを適用した値を保存するベクトル
	vector<int> multipliesVector(vectorSize);

	//乗算ファンクタを適用
	transform(firstVector.begin(), firstVector.end(), secondVector.begin(), multipliesVector.begin(), multiplies<int>());

	//適用後のベクトルを表示
	printContena(multipliesVector.begin(), multipliesVector.end());     //  A * B    {0 -1 -4 -9 -16}
}