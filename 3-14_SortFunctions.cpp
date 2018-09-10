#ifndef ___SortFunctions
#define ___SortFunctions

#include<iostream>
//sring関数を使用する
#include<cstring>
//データ型size_tを使用する
#include<cstdlib>
//操作子setwを使用する
#include<iomanip>
#include"3-14_PersonClass.h"

/**
* 名前の大きさを比較する比較関数
* @param firstPerson 人物A, secondPerson 人物B
* @return differenceName 人物Aの名前の大きさ - 人物Bの名前の大きさ
* @author Sawa
* @since 7.30
*/
int compareName(PersonClass firstPerson, PersonClass secondPerson)
{
	//人物Aの名前の大きさ - 人物Bの名前の大きさ
	int differenceName;

	//人物Aの名前の大きさ - 人物Bの名前の大きさを計算
	differenceName = strcmp(firstPerson.getName(), secondPerson.getName());

	//人物Aの名前の大きさ - 人物Bの名前の大きさ
	return differenceName;
}

/**
* 身長の大きさを比較する比較関数
* @param firstPerson 人物A, secondPerson 人物B
* @return differnceHeight 人物Aの身長 - 人物Bの身長
* @author Sawa
* @since 7.30
*/
int compareHeight(PersonClass firstPerson, PersonClass secondPerson)
{
	//人物Aの身長から人物Bの身長を引いた値
	int differenceHeight;

	//人物Aの身長から人物Bの身長を引いた値を計算
	differenceHeight = firstPerson.getHeight() - secondPerson.getHeight();

	//人物Aの身長から人物Bの身長を引いた値を返却
	return differenceHeight;
}

/**
* 体重の大きさを比較する比較関数
* @param firstPerson 人物A, secondPerson 人物B 
* @return differnceWeight 人物Aの体重 - 人物Bの体重
* @author Sawa
* @since 7.30
*/
int compareWeight(PersonClass firstPerson, PersonClass secondPerson)
{
	//人物Aの体重から人物Bの体重を引いた値
	int differenceWeight;

	//人物Aの体重から人物Bの体重を引いた値を計算
	differenceWeight = firstPerson.getWeight() - secondPerson.getWeight();

	//人物Aの体重から人物Bの体重を引いた値を返却
	return differenceWeight;
}

/**
* 人数分のデータを表示する
* @param PersonClass[] クラス型オブジェクトの配列, personNumber 人数
* @author Sawa
* @since 7.31
*/
void printPerson(const PersonClass personArray[], const int personNumber)
{
	//人数分のデータを表示するループ
	for (int firstCounter = 0; firstCounter < personNumber; ++firstCounter) {

		//確認のデータメンバを単位付きで表示
		std::cout << std::setw(10) << std::left << personArray[firstCounter].getName() << " " << personArray[firstCounter].getHeight() << "cm" << personArray[firstCounter].getWeight() << "kg\n";
	}
}

/**
* 名前、身長、体重のうち指定した要素でのクイックソートを行う
* @param personArray 人間クラス　personNumber 人数, objectSize データ型のバイト数, compareFunction 比較関数
* @author Sawa
* @since 7.31
*/
void doQuickSort(PersonClass personArray[], size_t personNumber, size_t objectSize, int(*compareFunction) (PersonClass, PersonClass))
{
	//検討中の人数が一人以上の場合
	if (personNumber > 0) {

		//左から配列走査を行い、検討中要素の添字を値として持つカーソル
		int leftCursor = 0;

		//右から配列走査を行い、検討中要素の添字を値として持つカーソル
		size_t rightCursor = personNumber - 1;

		//配列の要素を比較する基準となる中心カーソル
		size_t pivotCursor = (leftCursor + rightCursor) / 2;

		//配列の要素を左右に振り分けるループ
		do {
			//左カーソルの指す要素が中心カーソルの指す要素よりも小さい場合
			while (compareFunction(personArray[leftCursor], personArray[pivotCursor]) < 0) {

				//左カーソルを一つ進める
				++leftCursor;
			}

			//右カーソルの指す要素が中心カーソルの指す要素よりも大きい場合
			while (compareFunction(personArray[rightCursor], personArray[pivotCursor]) > 0) {

				//右カーソルを一つ進める
				--rightCursor;
			}

			//右クリック
			if (leftCursor <= rightCursor) {

				//左カーソルが指す要素と右カーソルが指す要素の交換を行う
				PersonClass temporaryPerson = personArray[leftCursor];

				//右カーソルの要素を左カーソルに代入
				personArray[leftCursor] = personArray[rightCursor];

				//左カーソルの要素を右カーソルに代入
				personArray[rightCursor] = temporaryPerson;

				//左カーソルを1進める
				++leftCursor;

				//右カーソルが0の場合カーソルを進めると配列外のオブジェクトを参照してしまうため、右カーソルが0でない場合のみ
				if (rightCursor != 0) {

					//右カーソルを進める
					--rightCursor;
				}
			}
			//カーソルが交差するまでループ
		} while (leftCursor <= rightCursor);

		//分離した前列要素がまだ2つ以上ある場合(右カーソルが0以下を指していない場合)
		if (rightCursor > 0) {

			//前列要素に関して再帰的クイックソート
			doQuickSort(personArray, rightCursor + 1, objectSize, compareFunction);
		}

		//分離した後列要素がまだ2つ以上ある場合(左カーソルが末尾の添字を指していない場合)
		if (leftCursor < personNumber - 1) {

			//後列要素に関して再帰的クイックソート
			doQuickSort(&personArray[leftCursor], personNumber - leftCursor, objectSize, compareFunction);
		}
	}
}

#endif