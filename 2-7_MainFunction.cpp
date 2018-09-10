/*演習2-7 ビットベクトルによる集合クラスBitsetに対して、以下のメンバ関数を追加せよ。
集合の最小要素の値(空集合であれば-1)を返却する関数min①
int min() const;
集合の最大要素の値(空集合であれば-1)を返却する関数max②
int max() const;
集合の全要素を削除して空集合化する関数clear③
void clear();
集合を集合rと交換する(全要素を交換する)関数swap④
void swap(BitSet& r);
集合s1とs2を交換する非メンバ関数swap⑤
void swap(BitSet& s1, BitSet& s2);
集合s1とs2の対称差を求めて返却kする関数symmetric_difference⑥
※集合A,Bに対する対称差(symmetricdifference)とは、A-B ∩ B-Aのことである
BitSet symmetric_difference(const BitSet& s1, const BitSet& s2);
集合s1とs2の積集合を求めて返却する演算子関数&⑦
BitSet operator&(const BitSet& s1, const BitSet& s2);
集合s1とs2の和集合を求めて返却する演算子関数|⑧
BitSet operator|(const BitSet& s1, const BitSet& s2);
集合s1とs2の差集合を求めて返却する演算子関数^⑨
BitSet operator^(const BitSet& s1, const BitSet& s2);
集合がsの部分集合であるかどうかを判定する関数is_subset_of⑩
bool is_subset_of(const BitSet& s);
集合がsの真部分集合であるかどうかを判定する関数is_proper_subset_of⑪
bool is_proper_subset_of(const BitSet& s);
*/

#include<iostream>
#include"2-7_BitSetClass.h"
#include"2-7_StringFunction.cpp"

using namespace std;

int main()
{
	//検証用ビットベクトルAに代入する要素
	int firstArray[] = { 1, 15 };

	//検証用ビットベクトルAの作成
	BitSet firstVector(firstArray, sizeof(firstArray) / sizeof(firstArray[0]));

	//検証用ビットベクトルBに代入する要素
	int secondArray[] = { 1, 15, 30 };

	//検証用ビットベクトルBの作成
	BitSet secondVector(secondArray, sizeof(secondArray) / sizeof(secondArray[0]));

	//検証用ビットベクトルAのコピー
	BitSet temporaryVector = firstVector;


	//追加した①～⑪の関数における動作確認を行う(内は表示値)

	//①(1)
	cout << firstVector.getMinimumValue();

	//②(15)
	cout << firstVector.getMaxValue();

	//③({})
	temporaryVector.clearSet(); cout << temporaryVector;

	//④({1, 15, 30})
	firstVector.swapBit(secondVector); cout << firstVector;

	//⑤({1, 15})
	swapBit(firstVector, secondVector); cout << firstVector;

	//⑥({30})
	cout << getSymmetricDifference(firstVector, secondVector);

	//⑦({1, 15})
	cout << (firstVector & secondVector);

	//⑧({1, 15, 30})
	cout << (firstVector | secondVector);

	//⑨({})
	cout << (firstVector ^ secondVector);

	//⑩(1)
	cout << firstVector.checkSubSet(secondVector);

	//⑪(1)
	cout << firstVector.checkProperSubSet(secondVector);

	//全関数の動作を確認
}