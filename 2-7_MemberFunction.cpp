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
)*/



#ifndef ___MemberFunction
#define ___MemberFunction

//unsigned long型におけるビット数及び最大値を調べるため、<limits>ヘッダをインクルード
#include<limits>
//stringクラステンプレートを使用するため、<string>ヘッダをインクルード
#include<string>
#include "2-7_BitSetClass.h"
#include<iostream>

//最下位ビットのみが1であるunsigned long型の値
const unsigned long theLowestBit = 1UL;

//全ビットが1であるunsiguned Long 型の値
const unsigned long unsignedLong_MaxValue = ULONG_MAX;


/**
* 引数がBitSetの要素として妥当かを調べる
* @param inputElement 要素として妥当か調べたい値
* @return booleanValue 妥当性
* @author Sawa
* @since  7.13
*/
bool BitSet::checkValid(int inputElement)
{
	//引数の妥当性
	bool booleanValue = false;

	//値が0以上かつunsigned long型ビット数より小さい場合
	if (inputElement >= 0 && inputElement < LONGBIT) {

		//妥当
		booleanValue = true;
	}
	//妥当性を返却
	return booleanValue;
}

/**
* 引数のビットのみが1であるビットベクトルを返却
* @param inputElement 引数
* @return returnVector 引数のビットのみが1であるビットベクトル
* @author Sawa
* @since  7.13
*/
unsigned long BitSet::setElement(int inputElement)
{
	//返却する値
	unsigned long returnVector;

	//返却する値に1を引数ぶん左シフトした値を代入
	returnVector = theLowestBit << inputElement;

	//ビットベクトルを返却
	return returnVector;
}

/**
* BitSet型デフォルトコンストラクタ
* @author Sawa
* @since  7.13
*/
BitSet::BitSet() : bitVector(0UL) {}

/**
* BitSet型コンストラクタ
* @author Sawa
* @since  7.13
*/
BitSet::BitSet(const int intArray[], int elementNumber) : bitVector(0UL)
{
	//int型配列から集合を生成するループ文
	for (int firstCounter = 0; firstCounter < elementNumber; ++firstCounter) {

		//集合に、配列に含まれている要素を追加する
		addElement(intArray[firstCounter]);
	}
}

/**
* BitSetクラスで扱うことの出来る要素の最大値を返却する
* @return maxValue 最大値
* @author Sawa
* @since  7.13
*/
int BitSet::getMaxElement()
{
	//最大値
	int maxElement;

	//unsigned long型のビット数から1引いた値を最大値とする(0～)
	maxElement = LONGBIT - 1;

	//最大値を返却
	return maxElement;
}

/**
* BitSetクラスで扱うことの出来る要素の最小値を返却する
* @return 0
* @author Sawa
* @since  7.13
*/
int BitSet::minimumElement()
{
	//0を返却
	return 0;
}

/**
* 集合に特定の要素が含まれるかを確かめる
* @param inputElement 要素
* @return booleanValue 特定の値が含まれているかどうか
* @author Sawa
* @since  7.13
*/
bool BitSet::checkContent(int inputElement) const
{
	//集合に特定の値が含まれているかどうか
	bool booleanValue = false;

	//要素として妥当かつ特定の要素が含まれている場合
	if (checkValid(inputElement) && (bitVector & setElement(inputElement))) {

		//含まれている
		booleanValue = true;
	}
	//真理値を返却
	return booleanValue;
}

/**
* 集合に要素を追加する
* @param inputElement 要素
* @author Sawa
* @since  7.13
*/
void BitSet::addElement(int inputElement)
{
	//引数が要素として妥当な場合
	if (checkValid(inputElement)) {

		//対応ビット値を1に値に更新
		bitVector |= setElement(inputElement);
	}
}

/**
* 集合から要素を除外する
* @param inputElement 要素
* @author Sawa
* @since  7.13
*/
void BitSet::removeElement(int inputElement)
{
	//引数が要素として妥当な場合
	if (checkValid(inputElement)) {

		//対応ビット値を0に更新
		bitVector &= ~setElement(inputElement);
	}
}

/**
* 集合が空集合かどうかを確認
* @return booleanValue 命題の真理値
* @author Sawa
* @since  7.13
*/
bool BitSet::checkEmpty() const
{
	//空集合かどうか
	bool booleanValue = false;

	//全ビット値が0の場合
	if (bitVector == 0) {

		//空集合
		booleanValue = true;
	}
	//真理値を返却
	return booleanValue;
}

/**
* 集合に含まれる要素数を求める
* @return elementNumber 要素数
* @author Sawa
* @since  7.13
*/
int BitSet::getSize() const
{
	//集合に含まれる要素数
	int elementNumber = 0;

	//集合の値を計算用に保存
	unsigned long temporaryVector = bitVector;

	//集合の値が0になるまで、要素数のカウントを行うループ
	for (; temporaryVector > 0;) {

		//最も下位にあるビット値を0に更新(ビットカウント手法)
		temporaryVector &= temporaryVector - 1;

		//要素数をインクリメント
		++elementNumber;
	}
	//要素数を返却
	return elementNumber;
}

/**
* 集合を他の集合との積集合に更新する
* @param inputSet 他の集合
* @return 自身への参照
* @author Sawa
* @since  7.13
*/
BitSet& BitSet::operator&=(const BitSet& inputSet)
{
	//他の集合との積集合に更新
	bitVector &= inputSet.bitVector;

	//自身への参照を返却
	return *this;
}

/**
* 集合を他の集合との和集合に更新する
* @param inputSet 他の集合
* @return 自身への参照
* @author Sawa
* @since  7.13
*/
BitSet& BitSet::operator|=(const BitSet& inputSet)
{
	//他の集合との差集合に更新
	bitVector |= inputSet.bitVector;

	//自身への参照を返却
	return *this;
}

/**
* 集合を他の集合との差集合に更新する(教材中の例文に誤植あり)
* @param inputSet 他の集合
* @return 自身への参照
* @author Sawa
* @since  7.13
*/
BitSet& BitSet::operator^=(const BitSet& inputSet)
{
	//集合と他の集合との積集合 
	unsigned long temporaryIntersection;

	//積集合を計算
	temporaryIntersection = (bitVector & inputSet.bitVector);

	//集合の値から積集合の値を引くことで、他の集合と被っているビット値を0にする(差集合)
	bitVector -= temporaryIntersection;

	//自身への参照を返却
	return *this;
}

/**
* 集合が他の集合と等しいかどうかを調べる
* @param inputSet 他の集合
* @return booleanValue 命題の真理値
* @author Sawa
* @since  7.13
*/
bool BitSet::operator==(const BitSet& inputSet)
{
	//集合が他の集合と等しいかどうか
	bool booleanValue = false;

	//集合の値と積集合の値が等しい場合
	if (bitVector == inputSet.bitVector) {

		//集合と他の集合は等しい
		booleanValue = true;
	}
	//命題の真理値を返却
	return booleanValue;
}

/**
* 集合が他の集合と等しくないかどうかを調べる
* @param inputSet 他の集合
* @return booleanValue 命題の真理値
* @author Sawa
* @since  7.13
*/
bool BitSet::operator!=(const BitSet& inputSet)
{
	//集合が他の集合と等しくないかどうか
	bool booleanValue = false;

	//集合の値と積集合の値が等しくない場合
	if (bitVector != inputSet.bitVector) {

		//集合と他の集合は等しくない
		booleanValue = true;
	}
	//命題の真理値を返却
	return booleanValue;
}

//以下追加のメンバ関数及び演算子関数

/**
* 集合の最小要素の値(空集合であれば-1)を返却する①
* @return minimumValue 集合の最小値(-1)
* @author Sawa
* @since 7.17
*/
int BitSet::getMinimumValue() const
{
	//集合の最小要素の値(空集合の場合-1)
	int minimumValue = -1;

	//集合が空集合ではない場合
	if (!checkEmpty()) {

		//集合の要素を最下位ビットから走査していくループ
		for (int firstCounter = 0; firstCounter < LONGBIT; ++firstCounter) {

			//集合に要素が確認された場合
			if (checkContent(firstCounter)) {

				//その要素の値を最小要素の値とする
				minimumValue = firstCounter;

				//ループを抜ける
				break;
			}
		}
	}
	//最小要素の値を返却
	return minimumValue;
}

/**
* 集合の最大要素の値(空集合であれば-1)を返却する②
* @return maxValue 集合の最大要素の値
* @author Sawa
* @since 7.17
*/
int BitSet::getMaxValue() const
{
	//集合の最大要素の値(空集合の場合-1)
	int maxValue = -1;

	//集合が空集合ではない場合
	if (!checkEmpty()) {

		//集合の要素を最上位ビットから走査していくループ
		for (int firstCounter = LONGBIT - 1; firstCounter >= 0; --firstCounter) {

			//集合に要素が確認された場合
			if (checkContent(firstCounter)) {

				//その要素を最大要素の値とする
				maxValue = firstCounter;

				//ループを抜ける
				break;
			}
		}
	}
	//最大要素の値を返却
	return maxValue;
}

/**
* 集合の全要素を削除して空集合化する③
* @author Sawa
* @since 7.17
*/
void BitSet::clearSet()
{
	//集合の全ビットを0にする
	bitVector &= 0;
}

/**
* 集合を他の集合と交換する(メンバ関数)④
* @param anotherBitSet
* @author Sawa
* @since 7.17
*/
void BitSet::swapBit(BitSet& anotherBitSet)
{
	//集合の要素を一時保存する
	BitSet temporaryBitSet = *this;

	//他の集合の要素を集合に代入する
	*this = anotherBitSet;

	//一時保存しておいた集合の要素を他の集合に代入する
	anotherBitSet = temporaryBitSet;

}

/**
* 集合Aを集合Bと交換する(非メンバ関数)⑤
* @param firstBitSet 集合A, secondBitSet 集合B
* @author Sawa
* @since 7.17
*/
void swapBit(BitSet& firstBitSet, BitSet& secondBitSet)
{
	//集合Aの要素を一時保存する
	BitSet temporaryBitSet = firstBitSet;

	//集合Bの要素を集合Aに代入する
	firstBitSet = secondBitSet;

	//一時保存しておいた集合Aの要素を集合Bに代入する
	secondBitSet = temporaryBitSet;

}

/**
* 集合Aと集合Bの対称差を求めて返却する⑥
* @param firstBitSet 集合A, secondBitSet 集合B
* @return symmetricBitSet 対称差
* @author Sawa
* @since 7.17
*/
BitSet getSymmetricDifference(const BitSet& firstBitSet, const BitSet& secondBitSet)
{
	//対称差
	BitSet symmetricDifference;

	//対称差=排他的論理和なので、集合Aと集合Bの排他的論理和を対称差とする
	symmetricDifference.bitVector = (firstBitSet.bitVector ^ secondBitSet.bitVector);

	//対称差を返却
	return symmetricDifference;
}

/**
* 集合Aと集合Bの積集合を求めて返却する⑦
* @param firstBitSet, secondBitSet
* @return temporaryBitSet 積集合
* @author Sawa
* @since 7.17
*/
BitSet operator&(const BitSet& firstBitSet, const BitSet& secondBitSet)
{
	//積集合
	BitSet temporaryBitSet;

	//積集合を計算
	temporaryBitSet.bitVector = (firstBitSet.bitVector & secondBitSet.bitVector);

	//積集合を返却
	return temporaryBitSet;
}

/**
* 集合Aと集合Bの和集合を求めて返却する⑧
* @param firstBitSet 集合A, secondBitSet 集合B
* @return temporaryBitSet 和集合
* @author Sawa
* @since 7.17
*/
BitSet operator|(const BitSet& firstBitSet, const BitSet& secondBitSet)
{
	//和集合
	BitSet temporaryBitSet;

	//和集合を計算
	temporaryBitSet.bitVector = (firstBitSet.bitVector | secondBitSet.bitVector);

	//和集合を返却
	return temporaryBitSet;
}

/**
* 集合Aと集合Bの差集合を求めて返却する⑨
* @param firstBitSet 集合A, secondBitSet 集合B
* @return temporaryBitSet 差集合
* @author Sawa
* @since 9.6
*/
BitSet operator^(const BitSet& firstBitSet, const BitSet& secondBitSet)
{
	//差集合
	BitSet temporaryBitSet;

	//集合Aと集合Bとの積集合 
	unsigned long temporaryIntersection;

	//積集合を計算
	temporaryIntersection = (firstBitSet.bitVector & secondBitSet.bitVector);

	//集合Aの値から積集合の値を引くことで、集合Bと被っているビット値を0にする(差集合)
	temporaryBitSet.bitVector = firstBitSet.bitVector - temporaryIntersection;

	//差集合を返却
	return temporaryBitSet;

}

/**
* 集合が他の集合の部分集合であるかを判定する⑩
* @param anotherBitSet 他の集合
* @return bool型の値
* @author Sawa
* @since 7.17
*/
bool BitSet::checkSubSet(const BitSet& anotherBitSet)
{
	//集合が他の集合の部分集合であるかどうか
	bool booleanValue = true;

	//集合の全ての要素が他の集合の要素として含まれているかを走査するループ
	for (int firstCounter = 0; firstCounter < LONGBIT; ++firstCounter) {

		//集合の要素を見つけた場合
		if (checkContent(firstCounter)) {

			//その要素が他の集合の要素として含まれていなかった場合
			if (!(anotherBitSet.checkContent(firstCounter))) {

				//部分集合ではない
				booleanValue = false;

				//ループを抜ける
				break;
			}
		}
	}
	//命題の真理値を返却
	return booleanValue;
}

/**
* 集合が他の集合の真部分集合であるかを判定する⑪
* @param anotherBitSet 他の集合
* @return booleanValue 命題の真理値
* @author Sawa
* @since 7.17
*/
bool BitSet::checkProperSubSet(const BitSet& anotherBitSet)
{
	//集合が他の集合の真部分集合であるか否か
	bool booleanValue = true;

	//集合と他の集合の全要素が等しい場合
	if (bitVector == anotherBitSet.bitVector) {

		//真部分集合ではない
		booleanValue = false;
	}
	//集合と他の集合の全要素が等しくない場合
	else {

		//部分集合かどうかの真理値を返却値に代入
		booleanValue = checkSubSet(anotherBitSet);
	}
	//命題の真理値を返却
	return booleanValue;
}

//挿入子<<を適用できるようにする演算子関数
std::ostream& operator<<(std::ostream& inputString, const BitSet& inputSet);

#endif
