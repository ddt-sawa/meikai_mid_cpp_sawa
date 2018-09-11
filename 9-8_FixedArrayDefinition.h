#ifndef ___FixedArrayDefinition
#define ___FixedArrayDefinition

/**
* 添字エラーコンストラクタ
* @param inputPointer エラーを起こした固定長配列, inputNumber エラーを起こした添字
* @return
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> FixedArray<ClassType, arraySize>::IndexError::IndexError(const FixedArray* inputPointer, int inputNumber) : errorArray(inputPointer), indexNumber(inputNumber) {}

/**
* エラーを起こした添字を返却する
* @return 添字 indexNumber
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> int FixedArray<ClassType, arraySize>::IndexError::getIndex() const { return indexNumber; }


/**
* 固定長配列クラスコンストラクタ
* @param inputNumber 値
* @return
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> FixedArray<ClassType, arraySize>::FixedArray(const ClassType& inputNumber) {

	//引数の値を固定長配列に代入するループ
	for (int firstCounter = 0; firstCounter < arraySize; firstCounter++) {

		//値を代入
		dataArray[firstCounter] = inputNumber;
	}
}

/**
* 固定長配列クラスコピーコンストラクタ
* @param inputArray 固定長配列
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> FixedArray<ClassType, arraySize>::FixedArray(const FixedArray& inputArray) {

	//自己初期化でない場合
	if (&inputArray != this) {

		//固定長配列をコピーするループ
		for (int firstCounter = 0; firstCountre < arraySize; firstCounter++) {

			//値をコピー
			dataArray[firstCounter] = inputArray.dataArray[firstCounter];
		}
	}
}

/**
* 固定長配列要素数のゲッタ
* @return arraySize 要素数
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> int FixedArray<ClassType, arraySize>::getSize() const { return arraySize; }

/**
* 固定長配列の代入演算子=
* @return inputArray 固定長配列
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> FixedArray<ClassType, arraySize>& FixedArray<ClassType, arraySize>::operator=(const FixedArray<ClassType, arraySize>& inputArray) {


	//固定長配列の値をコピーするループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//値をコピー
		dataArray[firstCounter] = inputArray.dataArray[firstCounter];
	}
	//自身への参照を返却
	return *this;
}

/**
* 固定長配列の添字演算子[]
* @return inputIndex 添字
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> ClassType& FixedArray<ClassType, arraySize>::operator[](const int inputIndex) {

	//添字が不正な場合
	if (inputIndex < 0 || inputIndex >= arraySize) {

		//添字範囲エラーを送出
		throw IndexError(this, inputIndex);
	}
	//添字演算子を適用した値を返却
	return dataArray[inputNumber];
}

/**
* 固定長配列の添字演算子[](const版)
* @return inputIndex 添字
* @author Sawa
* @since 9.10
*/
template<class ClassType, int arraySize> const ClassType& FixedArray<ClassType, arraySize>::operator[](const int inputIndex) const {

	//添字が不正な場合
	if (inputIndex < 0 || inputIndex >= arraySize) {

		//添字範囲エラーを送出
		throw IndexError(this, inputIndex);
	}
	//添字演算子を適用した値を返却
	return dataArray[inputNumber];
}

#endif