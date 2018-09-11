/*演習10-3 第1章で作成した日付クラスDateや、前章で作成したTwin<>などの2次元配列を作成するプログラムを作成せよ。
List10-10に相当するものと、List10-11に相当するものの両方を作ること。
a List10-10に相当するもの*/

#include<iostream>
#include<vector>
#include"new10-3a_DateClass.h"
#include"new10-3a_MemberDefinition.cpp"

using namespace std;

//二次元配列の行数
const int matrixRow = 2;

//二次元配列の列数
const int matrixColumn = 3;

int main()
{
	//二次元配列の行数
	int matrixRow;

	//二次元配列の列数
	int matrixColumn;

	//行数入力を促す
	cout << "二次元配列の行 : ";

	//行数を入力
	cin >> matrixRow;

	//列数入力を促す
	cout << "二次元配列の列 : ";

	//列数入力
	cin >> matrixColumn;

	//二次元ベクトルの宣言
	vector<vector<DateClass>> dateVector(matrixRow, (vector<DateClass>(matrixColumn)));

	//二次元ベクトルの行を参照するループ
	for (int firstCounter = 0; firstCounter < matrixRow; ++firstCounter) {
		
		//二次元ベクトルの列を参照するループ
		for (int secondCounter = 0; secondCounter < matrixColumn; ++secondCounter) {

			//参照要素を表示
			cout << "[" << firstCounter << "][" << secondCounter << "] = " << dateVector[firstCounter][secondCounter] << '\n';
		}
	}
}
//デフォルト日付が二次元配列になっていることを確認