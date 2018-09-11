/*演習9-4 Array<>は要素を一つの添字でアクセスする1次元配列に相当する。二つの添字を持つ2次元配列クラステンプレート
をMatrix<>として実現せよ。*/

#include<iostream>
#include"9-4.h"

using namespace std;

//行列の行数
const int rowNumber = 3;

//行列の列数
const int columnNumber = 2;

int main()
{
	//int型に明示化を行った行列クラス
	MatrixClass<int> sampleMatrix(rowNumber, columnNumber);

	//行列に値を入力するため、行列の行数を参照するループ
	for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

		//行列の列数を参照するループ
		for (int secondCounter = 0; secondCounter < columnNumber; ++secondCounter) {

			//値
			int inputValue = 0;

			//値の入力を促す
			cout << "[" << firstCounter << "][" << secondCounter << "] : ";

			//値を入力
			cin >> inputValue;

			//入力値を行列に代入
			sampleMatrix[firstCounter][secondCounter] = inputValue;
		}
	}
	//行列の値を走査出力するため、行列の行数を参照するループ
	for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

		//行列の列数を参照するループ
		for (int secondCounter = 0; secondCounter < columnNumber; ++secondCounter) {

			//値を表示
			cout << "[" << firstCounter << "][" << secondCounter << "] = " << sampleMatrix[firstCounter][secondCounter] << '\n';
		}
	}
}