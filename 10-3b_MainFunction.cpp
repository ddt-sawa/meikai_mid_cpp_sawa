/*演習10-3 第1章で作成した日付クラスDateや、前章で作成したTwin<>などの2次元配列を作成するプログラムを作成せよ。
List10-10に相当するものと、List10-11に相当するものの両方を作ること。
b List10-11に相当するもの*/

#include<iostream>
#include<vector>
#include"10-3b_TwinClass.h"

using namespace std;

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

	//Twin型二次元ベクトルの宣言
	vector<vector<TwinClass<int>>> twinVector;

	//二次元ベクトルの行を参照するループ
	for (int firstCounter = 0; firstCounter < matrixRow; ++firstCounter) {

		//列数入力を促す
		cout << "二次元配列" << firstCounter << "行目の列数 : ";

		//列数入力
		cin >> matrixColumn;

		//入力した列数分の配列を追加
		twinVector.push_back(vector<TwinClass<int>>(matrixColumn));
	}
	//要素を走査表示するために、二次元ベクトルの行を参照するループ
	for (int firstCounter = 0; firstCounter < matrixRow; ++firstCounter) {

		//二次元ベクトルの列を参照するループ
		for (int secondCounter = 0; secondCounter < twinVector[firstCounter].size(); ++secondCounter) {

			//参照要素を表示
			cout << "[" << firstCounter << "][" << secondCounter << "] = " << twinVector[firstCounter][secondCounter] << '\n';
		}
	}
}
//凸凹二次元配列になっていることを確認