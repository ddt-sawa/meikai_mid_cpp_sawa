/*演習9-6 Array<bool>型の配列に対して、対話的に処理を行うプログラムを作成せよ。
前問で作成したメンバ関数get_vsizeも利用すること。*/

#ifndef ___ArrayClass_Template
#define ___ArrayClass_Template

//配列クラステンプレート
template <class TypeName> class ArrayClass {
public:

   /**
   * 添字が配列クラスオブジェクトにおいて妥当であるかを判断する
   * @param inputIndex 添字
   * @return bool型の値
   * @author Sawa
   * @since 8.13
   */
	bool judgeIndex(int inputIndex) {

		//添字が0以上かつ要素数より小さければTrue,そうでなければFalseを返却
		return inputIndex >= 0 && inputIndex < arraySize;
	}

	//添字エラークラス
	class IndexError {
	public:

		/**
		*　添え字エラークラスのコンストラクタ
		* @param inputPointer, inputIndex
		* @return
		* @author Sawa
		* @since 8.13
		*/
		IndexError(const ArrayClass* inputPointer, int inputIndex)

			//エラーを起こしたオブジェクトへのポインタと、不正な添え字をデータメンバに代入
			: errorPointer(inputPointer), errorIndex(inputIndex) {}

		/**
		* 不正な添字のゲッタ
		* @return　errorIndex 不正な添字
		* @author Sawa
		* @since 8.13
		*/
		int getArrayIndex() const
		{
			//不正な添字を返却
			return errorIndex;
		}

	//データメンバ
	private:
		const ArrayClass* errorPointer; //エラーを起こしたオブジェクトへのポインタ
		int errorIndex;                 //不正な添字
	};

	/**
	* ArrayClass型の明示的コンストラクタ
	* @param inputArraySize 要素数, inputValue 初期化値
	* @return
	* @author Sawa
	* @since 8.13
	*/
	explicit ArrayClass(int inputArraySize, const TypeName& inputValue = TypeName()) : arraySize(inputArraySize)
	{
		//配列に使用するメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
		arrayPointer = new TypeName[arraySize];

		//配列の全要素に初期化値(デフォルトでは0)を代入するループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//配列の要素初期化値を代入
			arrayPointer[firstCounter] = inputValue;
		}
	}

	/**
	* ArrayClass型のコピーコンストラクタ
	* @param inputArray 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	ArrayClass(const ArrayClass<TypeName>& inputArray) {

		//初期化子が自身であれば
		if (&inputArray == this) {

			//要素数0
			arraySize = 0;

			//NULLポインタをデータメンバに持つオブジェクトを作成
			arrayPointer = NULL;
		}
		//そうでない場合
		else {

			//引数の要素数を代入
			arraySize = inputArray.arraySize;

			//要素数ぶんのメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
			arrayPointer = new TypeName[arraySize];

			//引数の値をコピーするループ
			for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

				//引数の値をコピー
				arrayPointer[firstCounter] = inputArray.arrayPointer[firstCounter];
			}
		}
	}

	/**
	* ArrayClass型のデストラクタ
	* @author Sawa
	* @since 8.13
	*/
	~ArrayClass() { delete[] arrayPointer; }

	/**
	* 要素数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 8.13
	*/
	int getArraySize() const
	{
		//要素数を返却
		return arraySize;
	}

	/**
	* ArrayClass型に代入演算子=を適用するための演算子関数
	* @param inputArray 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	ArrayClass& operator=(const ArrayClass<TypeName>& inputArray)
	{
		//代入するオブジェクトが自身でない場合
		if (&inputArray != this)
		{
			//要素数が異なる場合
			if (arraySize != inputArray.arraySize) {

				//オブジェクトを破棄
				delete[] arrayPointer;

				//引数の要素数を代入
				arraySize = inputArray.arraySize;

				//要素数ぶんのメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
				arrayPointer = new TypeName[arraySize];
			}
			//引数の値をコピーするループ
			for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

				//引数の値をコピー
				arrayPointer[firstCounter] = inputArray.arrayPointer[firstCounter];
			}
		}
		//自身への参照を返却
		return *this;
	}

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数
	* @param inputIndex 添字
	* @return ArrayClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	TypeName& operator[](int inputIndex)
	{
		//添字として妥当でない添字が検出された場合
		if (!judgeIndex(inputIndex)) {

			//添字エラーを送出
			throw IndexError(this, inputIndex);
		}
		//ArrayClass型オブジェクトに[]を適用した値への参照を返却
		return arrayPointer[inputIndex];
	}

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数 (const版)
	* @param inputIndex 添字
	* @return ArrayClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	const TypeName& operator[](int inputIndex) const
	{
		//添字として妥当でない添字が検出された場合
		if (!judgeIndex(inputIndex)) {

			//添字エラーを送出
			throw IndexError(this, inputIndex);
		}
		//ArrayClass型オブジェクトに[]を適用した値への参照を返却
		return arrayPointer[inputIndex];
	}

//データメンバ
private:
	int arraySize;          //配列の要素数
	TypeName* arrayPointer; //配列の先頭要素へのポインタ

};
#endif