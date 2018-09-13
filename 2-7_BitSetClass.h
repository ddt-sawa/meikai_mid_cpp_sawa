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

#ifndef NEW2_7_H_
#define NEW2_7_H_

//unsigned long型におけるビット数及び最大値を調べるため、<limits>ヘッダをインクルード
#include<limits>
//stringクラステンプレートを使用するため、<string>ヘッダをインクルード
#include<string>
#include<iostream>

//最下位ビットのみが1であるunsigned long型の値
extern const unsigned long theLowestBit;

//全ビットが1であるunsiguned Long 型の値
extern const unsigned long unsignedLong_MaxValue;


//ビットベクトルによる集合クラス
class BitSet {
public:

	/**
	* BitSet型デフォルトコンストラクタ
	* @author Sawa
	* @since  7.13
	*/
	BitSet();

	/**
	* BitSet型コンストラクタ
	* @author Sawa
	* @since  7.13
	*/
	BitSet(const int intArray[], int elementNumber);

	/**
	* BitSetクラスで扱うことの出来る要素の最大値を返却する
	* @return maxValue 最大値
	* @author Sawa
	* @since  7.13
	*/
	static int getMaxElement();

	/**
	* BitSetクラスで扱うことの出来る要素の最小値を返却する
	* @return 0
	* @author Sawa
	* @since  7.13
	*/
	static int minimumElement();

	/**
	* 集合に特定の要素が含まれるかを確かめる
	* @param inputElement 要素
	* @return booleanValue 特定の値が含まれているかどうか
	* @author Sawa
	* @since  7.13
	*/
	bool checkContent(int inputElement) const;

	/**
	* 集合に要素を追加する
	* @param inputElement 要素
	* @author Sawa
	* @since  7.13
	*/
	void addElement(int inputElement);

	/**
	* 集合から要素を除外する
	* @param inputElement 要素
	* @author Sawa
	* @since  7.13
	*/
	void removeElement(int inputElement);

	/**
	* 集合が空集合かどうかを確認
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since  7.13
	*/
	bool checkEmpty() const;

	/**
	* 集合に含まれる要素数を求める
	* @return elementNumber 要素数
	* @author Sawa
	* @since  7.13
	*/
	int getSize() const;

	/**
	* 集合を他の集合との積集合に更新する
	* @param inputSet 他の集合
	* @return 自身への参照
	* @author Sawa
	* @since  7.13
	*/
	BitSet& operator&=(const BitSet& inputSet);

	/**
	* 集合を他の集合との和集合に更新する
	* @param inputSet 他の集合
	* @return 自身への参照
	* @author Sawa
	* @since  7.13
	*/
	BitSet& operator|=(const BitSet& inputSet);

	/**
	* 集合を他の集合との差集合に更新する(教材中の例文に誤植あり)
	* @param inputSet 他の集合
	* @return 自身への参照
	* @author Sawa
	* @since  7.13
	*/
	BitSet& operator^=(const BitSet& inputSet);

	/**
	* 集合が他の集合と等しいかどうかを調べる
	* @param inputSet 他の集合
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since  7.13
	*/
	bool operator==(const BitSet& inputSet);

	/**
	* 集合が他の集合と等しくないかどうかを調べる
	* @param inputSet 他の集合
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since  7.13
	*/
	bool operator!=(const BitSet& inputSet);

	//文字列表現を返却する
	std::string getString() const;

	//ビットベクトルの構成を返却する
	std::string getBitString() const;

	//以下追加のメンバ関数及び演算子関数

	/**
	* 集合の最小要素の値(空集合であれば-1)を返却する①
	* @return minimumValue 集合の最小値(-1)
	* @author Sawa
	* @since 7.17
	*/
	int getMinimumValue() const;

	/**
	* 集合の最大要素の値(空集合であれば-1)を返却する②
	* @return maxValue 集合の最大要素の値
	* @author Sawa
	* @since 7.17
	*/
	int getMaxValue() const;

	/**
	* 集合の全要素を削除して空集合化する③
	* @author Sawa
	* @since 7.17
	*/
	void clearSet();

	/**
	* 集合を他の集合と交換する(メンバ関数)④
	* @param anotherBitSet
	* @author Sawa
	* @since 7.17
	*/
	void swapBit(BitSet& anotherBitSet);

	/**
	* 集合Aを集合Bと交換する(非メンバ関数)⑤
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @author Sawa
	* @since 7.17
	*/
	friend void swapBit(BitSet& firstBitSet, BitSet& secondBitSet);

	/**
	* 集合Aと集合Bの対称差を求めて返却する⑥
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @return symmetricBitSet 対称差
	* @author Sawa
	* @since 7.17
	*/
	friend BitSet getSymmetricDifference(const BitSet& firstBitSet, const BitSet& secondBitSet);

	/**
	* 集合Aと集合Bの積集合を求めて返却する⑦
	* @param firstBitSet, secondBitSet
	* @return temporaryBitSet 積集合
	* @author Sawa
	* @since 7.17
	*/
	friend BitSet operator&(const BitSet& firstBitSet, const BitSet& secondBitSet);

	/**
	* 集合Aと集合Bの和集合を求めて返却する⑧
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @return temporaryBitSet 和集合
	* @author Sawa
	* @since 7.17
	*/
	friend BitSet operator|(const BitSet& firstBitSet, const BitSet& secondBitSet);

	/**
	* 集合Aと集合Bの差集合を求めて返却する⑨
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @return temporaryBitSet 差集合
	* @author Sawa
	* @since 9.6
	*/
	friend BitSet operator^(const BitSet& firstBitSet, const BitSet& secondBitSet);

	/**
	* 集合が他の集合の部分集合であるかを判定する⑩
	* @param anotherBitSet 他の集合
	* @return bool型の値
	* @author Sawa
	* @since 7.17
	*/
	bool checkSubSet(const BitSet& anotherBitSet);
	/**
	* 集合が他の集合の真部分集合であるかを判定する⑪
	* @param anotherBitSet 他の集合
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since 7.17
	*/
	bool checkProperSubSet(const BitSet& anotherBitSet);

private:
	//unsigned long型のビット数
	static const int LONGBIT = std::numeric_limits<unsigned long>::digits;

	//集合
	unsigned long bitVector;

	/**
	* 引数がBitSetの要素として妥当かを調べる
	* @param inputElement 要素として妥当か調べたい値
	* @return booleanValue 妥当性
	* @author Sawa
	* @since  7.13
	*/
	static bool checkValid(int inputElement);

	/**
	* 引数のビットのみが1であるビットベクトルを返却
	* @param inputElement 引数
	* @return returnVector 引数のビットのみが1であるビットベクトル
	* @author Sawa
	* @since  7.13
	*/
	static unsigned long setElement(int inputElement);

};

//挿入子<<を適用できるようにする演算子関数
std::ostream& operator<<(std::ostream& inputString, const BitSet& inputSet);

#endif
