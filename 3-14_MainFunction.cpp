#include<iostream>
//ユーザー定義ヘッダをインクルード
#include"3-14_PersonClass.h"
#include"3-14_SortFunctions.cpp"

using namespace std;

int main()
{
	//4人分の個人情報を格納
	PersonClass personArray[] = { {"Shibata", 170, 52 },
								  { "Takaoka", 180, 70},
								  { "Nangoh", 172, 63 },
								  {"Sugiyama", 165, 70}
	                                                    };

	//配列の要素(人数)を計算
	int personNumber = sizeof(personArray) / sizeof(personArray[0]);

	//ソート前の配列を表示することを告知
	cout << "ソート前の並び\n";

	//表示
	printPerson(personArray, personNumber); 

	//改行
	cout << '\n';

	//名前の昇順にソート
	doQuickSort(personArray, personNumber, sizeof(char), compareName);

	//ソート後の並びを表示
	printPerson(personArray, personNumber);

	//改行
	cout << '\n';

	//身長の昇順にソート
	doQuickSort(personArray, personNumber, sizeof(int), compareHeight);

	//ソート後の並びを表示
	printPerson(personArray, personNumber);

	//改行
	cout << '\n';

	//体重の昇順にソート
	doQuickSort(personArray, personNumber, sizeof(int), compareWeight);

	//ソート後の並びを表示
	printPerson(personArray, personNumber);
}

//ソートを確認
