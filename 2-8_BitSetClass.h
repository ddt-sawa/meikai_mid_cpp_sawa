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
const unsigned long theLowestBit = 1UL;

//全ビットが1であるunsiguned Long 型の値
const unsigned long unsignedLong_MaxValue = ULONG_MAX;

//unsigned long型のビット数
static const int LONGBIT = std::numeric_limits<unsigned long>::digits;

//ビットベクトルによる集合クラス
class BitSet {

	//集合配列へのポインタ
	unsigned long* bitPointer;

	//集合配列の要素数
	int arraySize;

	//下限値
	int lowerLimit;

	//上限値
	int upperLimit;

public:


	/**
	* BitSet型コンストラクタ
	* param inputLimit 下限値, inputUpper 上限値
	* @author Sawa
	* @since  7.13
	*/
	BitSet(int inputLower, int inputUpper) : lowerLimit(inputLower), upperLimit(inputUpper)
	{
		//下限値から上限値までの整数を格納するために必要なunsigned long型配列の要素数を割り出す
		arraySize = (upperLimit - lowerLimit + 1) / LONGBIT + 1;

		//unsigned long型配列を動的確保
		bitPointer = new unsigned long[arraySize]();
	}

	/**
	* BitSet型コンストラクタ
	* @param intArray 配列, elementNumber 配列に含まれる要素の数, lowerLimit 下限値, upperLimit 上限値
	* @author Sawa
	* @since  7.13
	*/
	BitSet(const int intArray[], int elementNumber, int inputLower, int inputUpper) : lowerLimit(inputLower), upperLimit(inputUpper)
	{
		//下限値から上限値までの整数を格納するために必要なunsigned long型配列の要素数を割り出す
		arraySize = (upperLimit - lowerLimit + 1) / LONGBIT + 1;

		//unsigned long型配列を動的確保
		bitPointer = new unsigned long[arraySize]();

		//int型配列から集合を生成するループ文
		for (int firstCounter = 0; firstCounter < elementNumber; ++firstCounter) {

			//集合に、配列に含まれている要素を追加する
			addElement(intArray[firstCounter]);
		}
	}

	/**
	* BitSet型コピーコンストラクタ
	* @param inputSet BitSet型オブジェクト
	* @author Sawa
	* @since  7.13
	*/
	BitSet(const BitSet& inputSet)
	{
		//配列の要素数をコピー
		arraySize = inputSet.arraySize;

		//unsigned long型配列を動的確保
		bitPointer = new unsigned long[arraySize]();

		//配列の要素をコピーするループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//配列の要素をコピー
			bitPointer[firstCounter] = inputSet.bitPointer[firstCounter];
		}

		//下限値をコピー
		lowerLimit = inputSet.lowerLimit;

		//上限値をコピー
		upperLimit = inputSet.upperLimit;

	}

	/**
	* 集合配列のポインタのゲッタ
	* @return bitPointer ポインタ
	* @author Sawa
	* @since 9.5
	*/
	unsigned long* getBitPointer() const { return bitPointer; }

	/**
	* 配列の要素数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 9.5
	*/
	int getArraySize() const { return arraySize; }

	/**
	* 下限値のゲッタ
	* @return lowerLimit 下限値
	* @author Sawa
	* @since 9.5
	*/
	int getLowerLimit() const { return lowerLimit; }

	/**
	* 上限値のゲッタ
	* @return upperLimit 上限値
	* @author Sawa
	* @since 9.5
	*/
	int getUpperLimit() const { return upperLimit; }


	/**
	* 引数がBitSetの要素として妥当かを調べる
	* @param inputElement 要素として妥当か調べたい値
	* @return booleanValue 妥当性
	* @author Sawa
	* @since  7.13
	*/
	bool checkValid(int inputElement) const
	{
		//引数の妥当性
		bool booleanValue = false;

		//値が下限値以上かつ上限値以下で、参照している添字が要素数より小さい場合
		if (inputElement >= lowerLimit && inputElement <= upperLimit &&  getArrayIndex(inputElement) < arraySize) {

			//妥当
			booleanValue = true;
		}
		//妥当性を返却
		return booleanValue;
	}


	/**
	* 引数に対応する配列要素の対応ビットのみが1であるビットベクトルを返却
	* @param inputElement 引数
	* @return returnVector 引数に対応する配列要素の対応ビットのみが1であるビットベクトル
	* @author Sawa
	* @since  7.13
	*/
	unsigned long setElement(int inputElement) const
	{
		//返却する値
		unsigned long returnVector;

		//引数を左シフトするべき回数
		int shiftNumber;

		//下限値から、1を何回左シフトすれば引数に対応する配列要素の対応ビットになるかを割り出す
		shiftNumber = (inputElement - lowerLimit) % LONGBIT;

		//返却する値に1を引数ぶん左シフトした値を代入
		returnVector = theLowestBit << shiftNumber;

		//ビットベクトルを返却
		return returnVector;
	}

	/**
	* 特定の値が含まれている配列要素の添字を返却する
	* @param inputElement 値
	* @return arrayIndex 添字
	* @author Sawa
	* @since  7.13
	*/
	int getArrayIndex(int inputElement) const
	{
		//添字
		int arrayIndex;

		//特定の値が含まれている配列要素の添字を計算
		arrayIndex = (inputElement - lowerLimit) / LONGBIT;

		//添字を返却
		return arrayIndex;
	}

	/**
	* 集合に特定の要素が含まれるかを確かめる
	* @param inputElement 要素
	* @return booleanValue 特定の値が含まれているかどうか
	* @author Sawa
	* @since  7.13
	*/
	bool checkContent(int inputElement) const
	{
		//集合に特定の値が含まれているかどうか
		bool booleanValue = false;

		//特定の要素が含まれており、下限、上限値の範囲を逸脱していない場合
		if ((bitPointer[getArrayIndex(inputElement)] & setElement(inputElement)) && checkValid(inputElement)) {

		//返却値を真とする
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
	void addElement(int inputElement)
	{
		//引数が要素として妥当な場合
		if (checkValid(inputElement)) {

			//対応ビット値を1に値に更新
			bitPointer[getArrayIndex(inputElement)] |= setElement(inputElement);
		}
	}

	/**
	* 集合から要素を除外する
	* @param inputElement 要素
	* @author Sawa
	* @since  7.13
	*/
	void removeElement(int inputElement)
	{
		//引数が要素として妥当な場合
		if (checkValid(inputElement)) {

			//対応ビット値を0に更新
			bitPointer[getArrayIndex(inputElement)] &= ~setElement(inputElement);
		}
	}

	/**
	* 集合が空集合かどうかを確認
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since  7.13
	*/
	bool checkEmpty() const
	{
		//空集合かどうか
		bool booleanValue = true;

		//集合配列の全ビット値を走査するループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//0ではない配列要素を見つけた場合
			if (bitPointer[firstCounter] != 0) {

				//空集合ではない
				booleanValue = false;

				//ループを抜ける
				break;
			}
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
	int getSize() const
	{
		//集合配列に含まれる要素数
		int elementNumber = 0;

		//計算用に集合配列を複製
		unsigned long* temporaryPointer = new unsigned long[arraySize];

		//複製した集合配列に値をコピーするループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//集合配列の値をコピー
			temporaryPointer[firstCounter] = bitPointer[firstCounter];
		}

		//集合配列の全要素に対して走査処理を行うループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//各集合配列要素の値が0になるまで、要素数のカウントを行うループ
			for (; temporaryPointer[firstCounter] > 0;) {

				//最も下位にあるビット値を0に更新(ビットカウント手法)
				temporaryPointer[firstCounter] &= temporaryPointer[firstCounter] - 1;

				//要素数をインクリメント
				++elementNumber;
			}
		}
		//計算用配列を破棄
		delete temporaryPointer;

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
	BitSet& operator&=(const BitSet& inputSet)
	{
		//自身が格納可能な値を、他の集合が持っているかを調べるループ
		for (int firstCounter = lowerLimit; (firstCounter >= lowerLimit && firstCounter <= upperLimit); ++firstCounter) {

			//他の集合がサーチ中の値を持っていた場合
			if (inputSet.checkContent(firstCounter)) {

				//該当要素の該当ビットを、サーチ中の値との積集合に更新する
				bitPointer[getArrayIndex(firstCounter)] &= setElement(firstCounter);
			}
		}
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
	BitSet& operator|=(const BitSet& inputSet)
	{
		//自身が格納可能な値を、他の集合が持っているかを調べるループ
		for (int firstCounter = lowerLimit; (firstCounter >= lowerLimit && firstCounter <= upperLimit); ++firstCounter) {

			//他の集合がサーチ中の値を持っていた場合
			if (inputSet.checkContent(firstCounter)) {

				//該当要素の該当ビットを、サーチ中の値との和集合に更新する
				bitPointer[getArrayIndex(firstCounter)] |= setElement(firstCounter);
			}
		}
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
	BitSet& operator^=(const BitSet& inputSet)
	{
		//自身が格納可能な値を、他の集合が持っているかを調べるループ
		for (int firstCounter = lowerLimit; (firstCounter >= lowerLimit && firstCounter <= upperLimit); ++firstCounter) {

			//自身と他の集合がサーチ中の値を持っていた場合
			if (checkContent(firstCounter) && inputSet.checkContent(firstCounter)) {

				//その値を自身の要素から除外する
				removeElement(firstCounter);
			}
		}
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
	bool operator==(const BitSet& inputSet)
	{
		//集合が他の集合と等しいかどうか
		bool booleanValue = true;

		//両集合のどちらかが持ちうる値の下限値
		int entireLower;

		//どちらかが持ちうる下限値を計算
		entireLower = lowerLimit < inputSet.lowerLimit ? lowerLimit : inputSet.lowerLimit;

		//両集合のどちらかが持ちうる値の上限値
		int entireUpper;

		//どちらかが持ちうる上限値を計算
		entireUpper = upperLimit > inputSet.upperLimit ? upperLimit : inputSet.upperLimit;

		//両集合が同じ値を持っているかを調べるループ
		for (int firstCounter = entireLower; (firstCounter >= entireLower && firstCounter <= entireUpper); ++firstCounter) {

			//どちらかがサーチ中の値を持っており、他方がその値を持っていない場合
			if ((checkContent(firstCounter) && !inputSet.checkContent(firstCounter)) || (!checkContent(firstCounter) && inputSet.checkContent(firstCounter))) {

				//両集合は等しくない
				booleanValue = false;

				//ループを抜ける
				break;
			}
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
	bool operator!=(const BitSet& inputSet)
	{
		//集合が他の集合と等しくないかどうか
		bool booleanValue;

		//等価演算子を適用し、反転させた値を返却値とする
		booleanValue = !(*this == inputSet);

		//命題の真理値を返却
		return booleanValue;


	}

	//以下追加のメンバ関数及び演算子関数

	/**
	* 集合の最小値(空集合であれば-1)を返却する①
	* @return minimumValue 集合の最小値(-1)
	* @author Sawa
	* @since 7.17
	*/
	int getMinimumValue() const
	{
		//集合の最小値(空集合の場合-1)
		int minimumValue = -1;

		//集合が空集合ではない場合
		if (!checkEmpty()) {

			//集合配列の全要素を上位要素から参照するループ
			for (int firstCounter = arraySize - 1; firstCounter >= 0; --firstCounter) {

				//要素を最上位ビットから走査していくループ
				for (int secondCounter = LONGBIT - 1; secondCounter >= 0; --secondCounter) {

					//ビット値1が確認された場合
					if (bitPointer[firstCounter] == (theLowestBit << secondCounter)) {

						//そのビット位を元に最小値を計算する
						minimumValue = LONGBIT * firstCounter +  secondCounter + lowerLimit ;
					}
				}
			}
			//最小値を返却
			return minimumValue;
		}
	}

	/**
	* 集合の最大値(空集合であれば-1)を返却する②
	* @return maxValue 集合の最大要素の値
	* @author Sawa
	* @since 7.17
	*/
	int getMaxValue() const
	{
		//集合の最大値(空集合の場合-1)
		int maxValue = -1;

		//集合が空集合ではない場合
		if (!checkEmpty()) {

			//集合配列の全要素を下位要素から参照するループ
			for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

				//要素を最下位ビットから走査していくループ
				for (int secondCounter = 0; secondCounter < LONGBIT; ++secondCounter) {

					//ビット値1が確認された場合
					if ((bitPointer[firstCounter]  >> secondCounter) == theLowestBit) {

						//そのビット位を元に最大値を計算する
						maxValue = LONGBIT * firstCounter  + secondCounter + lowerLimit;

					}
				}
			}
			//最大値を返却
			return maxValue;
		}
	}

	/**
	* 集合の全要素を削除して空集合化する③
	* @author Sawa
	* @since 7.17
	*/
	void clearSet()
	{
		//集合配列の全要素を参照するループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//集合配列要素の全ビットを0にする
			bitPointer[firstCounter] &= 0;
		}
	}

	/**
	* 集合を他の集合と交換する(メンバ関数)④
	* @param anotherBitSet
	* @author Sawa
	* @since 7.17
	*/
	void swapBit(BitSet& anotherBitSet)
	{
		//集合の要素を一時保存する
		BitSet temporaryBitSet = *this;

		//他の集合の要素を集合に代入する
		*this = anotherBitSet;

		//一時保存しておいた集合を他の集合に代入する
		anotherBitSet = temporaryBitSet;

	}

	/**
	* 集合Aを集合Bと交換する(非メンバ関数)⑤
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @author Sawa
	* @since 7.17
	*/
	friend void swapBit(BitSet& firstBitSet, BitSet& secondBitSet)
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
	friend BitSet getSymmetricDifference(const BitSet& firstBitSet, const BitSet& secondBitSet)
	{
		//両集合のどちらかが持ちうる値の下限値
		int entireLower;

		//どちらかが持ちうる下限値を計算
		entireLower = firstBitSet.lowerLimit < secondBitSet.lowerLimit ? firstBitSet.lowerLimit : secondBitSet.lowerLimit;

		//両集合のどちらかが持ちうる値の上限値
		int entireUpper;

		//どちらかが持ちうる上限値を計算
		entireUpper = firstBitSet.upperLimit > secondBitSet.upperLimit ? firstBitSet.upperLimit : secondBitSet.upperLimit;

		//対称差
		BitSet symmetricDifference(entireLower, entireUpper);

		//両集合について特定の値を持っているかどうかを調べるループ
		for (int firstCounter = entireLower; (firstCounter >= entireLower && firstCounter <= entireUpper); ++firstCounter) {

			//どちらかがサーチ中の値を持っており、他方がその値を持っていない場合
			if ((firstBitSet.checkContent(firstCounter) && !secondBitSet.checkContent(firstCounter)) || (!firstBitSet.checkContent(firstCounter) && secondBitSet.checkContent(firstCounter))) {

				//その値を対称差に保存
				symmetricDifference.bitPointer[symmetricDifference.getArrayIndex(firstCounter)] |= symmetricDifference.setElement(firstCounter);

			}
		}
		//対称差を返却
		return symmetricDifference;
	}

	/**
	* 集合Aと集合Bの積集合を求めて返却する⑦
	* @param firstBitSet 集合A, secondBitSet 集合B
	* @return temporaryBitSet 積集合
	* @author Sawa
	* @since 7.17
	*/
	friend BitSet operator&(const BitSet& firstBitSet, const BitSet& secondBitSet)
	{
		//両集合のどちらかが持ちうる値の下限値
		int entireLower;

		//どちらかが持ちうる下限値を計算
		entireLower = firstBitSet.lowerLimit < secondBitSet.lowerLimit ? firstBitSet.lowerLimit : secondBitSet.lowerLimit;

		//両集合のどちらかが持ちうる値の上限値
		int entireUpper;

		//どちらかが持ちうる上限値を計算
		entireUpper = firstBitSet.upperLimit > secondBitSet.upperLimit ? firstBitSet.upperLimit : secondBitSet.upperLimit;

		//積集合
		BitSet temporaryBitSet(entireLower, entireUpper);

		//両集合について特定の値を持っているかどうかを調べるループ
		for (int firstCounter = entireLower; (firstCounter >= entireLower && firstCounter <= entireUpper); ++firstCounter) {

			//両集合がサーチ中の値を持っている場合
			if (firstBitSet.checkContent(firstCounter) && secondBitSet.checkContent(firstCounter)) {

				//その値を積集合に保存
				temporaryBitSet.bitPointer[temporaryBitSet.getArrayIndex(firstCounter)] |= temporaryBitSet.setElement(firstCounter);

			}
		}
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
	friend BitSet operator|(const BitSet& firstBitSet, const BitSet& secondBitSet)
	{
		//両集合のどちらかが持ちうる値の下限値
		int entireLower;

		//どちらかが持ちうる下限値を計算
		entireLower = firstBitSet.lowerLimit < secondBitSet.lowerLimit ? firstBitSet.lowerLimit : secondBitSet.lowerLimit;

		//両集合のどちらかが持ちうる値の上限値
		int entireUpper;

		//どちらかが持ちうる上限値を計算
		entireUpper = firstBitSet.upperLimit > secondBitSet.upperLimit ? firstBitSet.upperLimit : secondBitSet.upperLimit;

		//和集合
		BitSet temporaryBitSet(entireLower, entireUpper);

		//両集合について特定の値を持っているかどうかを調べるループ
		for (int firstCounter = entireLower; (firstCounter >= entireLower && firstCounter <= entireUpper); ++firstCounter) {

			//どちらかがサーチ中の値を持っている場合
			if (firstBitSet.checkContent(firstCounter) || secondBitSet.checkContent(firstCounter)) {

				//その値を和集合に保存
				temporaryBitSet.bitPointer[temporaryBitSet.getArrayIndex(firstCounter)] |= temporaryBitSet.setElement(firstCounter);

			}
		}
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
	friend BitSet operator^(const BitSet& firstBitSet, const BitSet& secondBitSet)
	{
		//差集合
		BitSet temporaryBitSet(firstBitSet.lowerLimit, firstBitSet.upperLimit);

		//集合Aが格納可能な値を、集合Bが持っているかを調べるループ
		for (int firstCounter = firstBitSet.lowerLimit; (firstCounter >= firstBitSet.lowerLimit && firstCounter <= firstBitSet.upperLimit); ++firstCounter) {

			//集合Aがサーチ中の値を持っており、集合Bが持っていない場合
			if (firstBitSet.checkContent(firstCounter) && !secondBitSet.checkContent(firstCounter)) {

				//その値を差集合に保存
				temporaryBitSet.bitPointer[temporaryBitSet.getArrayIndex(firstCounter)] |= temporaryBitSet.setElement(firstCounter);
			}
		}
		//差集合を返却
		return temporaryBitSet;
	}

	/**
	* 集合が他の集合の部分集合であるかを判定する⑩
	* @param anotherBitSet 他の集合
	* @return booleanValue 命題の真理値
	* @author Sawa
	* @since 7.17
	*/
	bool checkSubSet(const BitSet& anotherBitSet)
	{
		//集合が他の集合の部分集合であるかどうか
		bool booleanValue = true;

		//自身が格納可能な値を、他の集合が持っているかを調べるループ
		for (int firstCounter = lowerLimit; (firstCounter >= lowerLimit && firstCounter <= upperLimit); ++firstCounter) {

			//自身がサーチ中の値を持っており、他の集合がサーチ中の値を持っていない場合
			if (checkContent(firstCounter) && !anotherBitSet.checkContent(firstCounter)) {

				//部分集合ではない
				booleanValue = false;

				//ループを抜ける
				break;
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
	bool checkProperSubSet(const BitSet& anotherBitSet)
	{
		//集合が他の集合の真部分集合であるか否か
		bool booleanValue = true;

		//集合と他の集合が等しい場合
		if (*this == anotherBitSet) {

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

};

std::string getString(const BitSet);

//挿入子<<を適用できるようにする演算子関数
std::ostream& operator<<(std::ostream& inputString, const BitSet& inputSet);

#endif
