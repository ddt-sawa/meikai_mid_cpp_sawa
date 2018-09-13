/*演習2-8 以下の特徴を持つビットベクトルによる集合を実現するVecBitSet型を作成せよ。
・要素数はunsigned long型のビット数に制限されない。
・集合の下限値と上限値を任意の値に設定できる。
例えば、VecBitSet型の集合s1を10以上99以下の整数を表せる集合とするのであれば、
以下に示す方法で初期化できるように実現すること。
VecBitSet b1(10, 99);
もしもunsigned long型が32ビットであれば、呼び出されたコンストラクタは、10から99までの90種類を格納可能とするために、
要素数が3であるunsigned long型の配列setを動的に確保する。
そうすると、set[0]の各ビットは10～41までを、set[1]の各ビットは42～73までを、set[5](恐らくset[2]の誤植)のビットは74～99までを格納できる。
基本的な演算を行うための演算子関数を含め、メンバ関数を設計・作成すること。
*/

#ifndef NEW2_8_H_
#define NEW2_8_H_

//unsigned long型におけるビット数及び最大値を調べるため、<limits>ヘッダをインクルード
#include<limits>
//stringクラステンプレートを使用するため、<string>ヘッダをインクルード
#include<string>
#include<iostream>

//最下位ビットのみが1であるunsigned long型の値
extern const unsigned long theLowestBit;

//全ビットが1であるunsiguned Long 型の値
extern const unsigned long unsignedLong_MaxValue;

//unsigned long型のビット数
extern const int LONGBIT;

//ビットベクトルによる集合クラス
class BitSet {
public:

	/**
	* BitSet型コンストラクタ
	* param inputLimit 下限値, inputUpper 上限値
	* @author Sawa
	* @since  7.13
	*/
	BitSet(int inputLower, int inputUpper);

	/**
	* BitSet型コンストラクタ
	* @param intArray 配列, elementNumber 配列に含まれる要素の数, lowerLimit 下限値, upperLimit 上限値
	* @author Sawa
	* @since  7.13
	*/
	BitSet(const int intArray[], int elementNumber, int inputLower, int inputUpper);

	/**
	* BitSet型コピーコンストラクタ
	* @param inputSet BitSet型オブジェクト
	* @author Sawa
	* @since  7.13
	*/
	BitSet(const BitSet& inputSet);

	/**
	* 集合配列のポインタのゲッタ
	* @return bitPointer ポインタ
	* @author Sawa
	* @since 9.5
	*/
	unsigned long* getBitPointer() const;

	/**
	* 配列の要素数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 9.5
	*/
	int getArraySize() const;

	/**
	* 下限値のゲッタ
	* @return lowerLimit 下限値
	* @author Sawa
	* @since 9.5
	*/
	int getLowerLimit() const;

	/**
	* 上限値のゲッタ
	* @return upperLimit 上限値
	* @author Sawa
	* @since 9.5
	*/
	int getUpperLimit() const;


	/**
	* 引数がBitSetの要素として妥当かを調べる
	* @param inputElement 要素として妥当か調べたい値
	* @return booleanValue 妥当性
	* @author Sawa
	* @since  7.13
	*/
	bool checkValid(int inputElement) const;


	/**
	* 引数に対応する配列要素の対応ビットのみが1であるビットベクトルを返却
	* @param inputElement 引数
	* @return returnVector 引数に対応する配列要素の対応ビットのみが1であるビットベクトル
	* @author Sawa
	* @since  7.13
	*/
	unsigned long setElement(int inputElement) const;

	/**
	* 特定の値が含まれている配列要素の添字を返却する
	* @param inputElement 値
	* @return arrayIndex 添字
	* @author Sawa
	* @since  7.13
	*/
	int getArrayIndex(int inputElement) const;

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

	//以下追加のメンバ関数及び演算子関数

	/**
	* 集合の最小値(空集合であれば-1)を返却する①
	* @return minimumValue 集合の最小値(-1)
	* @author Sawa
	* @since 7.17
	*/
	int getMinimumValue() const;

	/**
	* 集合の最大値(空集合であれば-1)を返却する②
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
	* @param firstBitSet 集合A, secondBitSet 集合B
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
	* @return booleanValue 命題の真理値
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
	//集合配列へのポインタ
	unsigned long* bitPointer;

	//集合配列の要素数
	int arraySize;

	//下限値
	int lowerLimit;

	//上限値
	int upperLimit;
};

std::string getString(const BitSet);

//挿入子<<を適用できるようにする演算子関数
std::ostream& operator<<(std::ostream& inputString, const BitSet& inputSet);

#endif
