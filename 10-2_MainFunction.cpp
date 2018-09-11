/*演習10-2 List10-9の関数テンプレートprint_vectorを以下のように書き換えよ。
・各要素の区切りをコンマと1個のスペース文字とする。
・各先頭の{の直後と、末尾の}の直前にはスペースを出力しない。
すなわち、{1, 2, 3, 4, 5}という形式で表示すること。*/

#include<vector>
#include<string>
#include<iostream>

using namespace std;

//各ベクトルの要素数を3とする
const int arraySize = 3;

/**
* vectorの要素を走査表示するための関数テンプレート
* @param inputVector ベクトル
* @author Sawa
* @since 9.6
*/
template <class ClassType, class ClassAllocator> void printVector(const vector<ClassType, ClassAllocator>& inputVector)
{
	//前括弧を表示
	cout << '{';

	//ベクトルの最後以外の要素を走査表示するループ
	for (typename vector<ClassType, ClassAllocator>::size_type firstCounter = 0; firstCounter < inputVector.size() - 1; ++firstCounter) {

		//要素表示のあと,コンマとスペース文字を表示
		cout << inputVector.at(firstCounter) << ", ";
	}
	//末尾要素を表示
	cout << inputVector.back();

	//後ろ括弧を表示
	cout << '}';
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
	printVector(intVector);

	//改行
	cout << "\n";

	//double型ベクトル表示
	printVector(doubleVector);

	//改行
	cout << "\n";

	//string型ベクトル表示
	printVector(stringVector);

	//改行
	cout << "\n";
}