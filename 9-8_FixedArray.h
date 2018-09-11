#ifndef ___FixedArray
#define ___FixedArray

//固定長配列クラステンプレート
template<class ClassType, int arraySize> class FixedArray {
public:

	//添字範囲エラークラス
	class IndexError {

	public:

		/**
		* 添字エラーコンストラクタ
		* @param inputPointer エラーを起こした固定長配列, inputNumber エラーを起こした添字
		* @return
		* @author Sawa
		* @since 9.10
		*/
		IndexError(const FixedArray* inputPointer, int inputNumber);

		/**
		* エラーを起こした添字を返却する
		* @return 添字 indexNumber
		* @author Sawa
		* @since 9.10
		*/
		int getIndex() const;

	private:
		//エラーを起こした配列
		const FixedArray* errorArray;

		//エラーを起こした添字
		int indexNumber;
	};

	/**
	* 固定長配列クラスコンストラクタ
	* @param inputNumber 値
	* @return
	* @author Sawa
	* @since 9.10
	*/
	explicit FixedArray(const ClassType& inputNumber = ClassType());

	/**
	* 固定長配列クラスコピーコンストラクタ
	* @param inputArray 固定長配列
	* @author Sawa
	* @since 9.10
	*/
	FixedArray(const FixedArray& inputArray);

	/**
	* 固定長配列要素数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 9.10
	*/
	int getSize() const;

	/**
	* 固定長配列の代入演算子=
	* @return inputArray 固定長配列
	* @author Sawa
	* @since 9.10
	*/
	FixedArray& operator=(const FixedArray& inputArray);

	/**
	* 固定長配列の添字演算子[]
	* @return inputIndex 添字
	* @author Sawa
	* @since 9.10
	*/
	ClassType& operator[](const int inputIndex);

	/**
	* 固定長配列の添字演算子[](const版)
	* @return inputIndex 添字
	* @author Sawa
	* @since 9.10
	*/
	const ClassType& operator[](const int inputIndex) const;

private:
	//固定長配列
	ClassType dataArray[arraySize];
};

#include"9-8_FixedArrayDefinition.h"
#endif