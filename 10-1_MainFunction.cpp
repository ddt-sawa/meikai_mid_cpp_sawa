/*演習10-1 第1章で作成した日付クラスDateのベクトルを作成するプログラムを作成せよ。*/

#include<iostream>
#include<vector>
#include"10-1_DateClass.h"
#include"10-1_MemberDefinition.cpp"

using namespace std;

//ベクトルAの容量を仮に5とする
const int dateVectorCapacity = 5;

//ベクトルBの変更後の要素数を仮に3とする
const int copyVectorSize = 3;


int main()
{
	DateClass firstDate(2005, 12, 24);   //日付A
	DateClass secondDate(1956, 2, 9);    //日付B

	//日付を格納するベクトルAを宣言
	vector<DateClass> dateVector;

	//ベクトルAに日付Aを追加
	dateVector.push_back(firstDate);

	//ベクトルAの要素数と容量を表示(1,1)
	cout << dateVector.size() << ',' << dateVector.capacity() << '\n';

	//ベクトルBに日付Bを追加
	dateVector.push_back(secondDate);

	//ベクトルAの容量を確保
	dateVector.reserve(dateVectorCapacity);

	//ベクトルAの要素数と容量を表示(2,5)
	cout << dateVector.size() << ',' << dateVector.capacity() << '\n';

	//ベクトルBにベクトルAをコピー
	vector<DateClass> copyVector(dateVector);

	//ベクトルBの要素数を変更
	copyVector.resize(copyVectorSize);

	//ベクトルにBに保存した日付を表示するループ
	for (vector<DateClass>::size_type firstCounter = 0; firstCounter < copyVector.size(); ++firstCounter) {

		//日付を表示
		cout << "[" << firstCounter << "] = " << copyVector[firstCounter] << "\n";
	}
	/*
	[0] = 2005年12月24日
	[1] = 1956年2月9日
	[2] = 2018年9月7日(デフォルトコンストラクタ) 
	*/	
}