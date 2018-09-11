/*演習10-4 List10-17は、int型の配列とベクトルの表示を行っている。List10-16のように、
double型やstring型などの表示を行うように書き換えよ。*/

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

	//double型配列
	double doubleArray[arraySize] = { 1.1, 2.2, 3.3 };

	//配列をベクトルに代入
	vector<double> doubleVector(doubleArray, doubleArray + sizeof(doubleArray) / sizeof(doubleArray[0]));

	//string型配列
	string stringArray[arraySize] = { "AA", "BB", "CC" };

	//配列をベクトルに代入
	vector<string> stringVector(stringArray, stringArray + sizeof(stringArray) / sizeof(stringArray[0]));

	//int型ベクトル表示
	printContena(intVector.begin(), intVector.end());

	//改行
	cout << "\n";

	//double型ベクトル表示
	printContena(doubleVector.begin(), doubleVector.end());

	//改行
	cout << "\n";

	//string型ベクトル表示
	printContena(stringVector.begin(), stringVector.end());

	//改行
	cout << "\n";

}