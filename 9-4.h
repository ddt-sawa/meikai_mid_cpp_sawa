/*演習9-4 Array<>は要素を一つの添字でアクセスする1次元配列に相当する。
二つの添字を持つ2次元配列クラステンプレートをMatrix<>として実現せよ。*/

#include<iostream>

template <class TypeName> class MatrixClass {
public:

	/**
	* 入力された値が添字として適切かどうかを判断する
	* @param inputRow 
	* @return bool型の値
	* @author Sawa
	* @since 9.10
	*/
	bool judgeIndex(int inputRowNumber) {

		//添字が0以上かつデータメンバにおける行数より小さい場合、行列の添字として妥当とみなす
		return	inputRowNumber >= 0 && inputRowNumber < rowNumber;

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
		IndexError(const MatrixClass* inputPointer, int inputRowNumber)

			//エラーを起こしたオブジェクトへのポインタと、不正な行、列をデータメンバに代入
			: errorPointer(inputPointer), errorRow(inputRowNumber) {}

		/**
		* 不正な行のゲッタ
		* @return　errorRow 不正な行
		* @author Sawa
		* @since 8.13
		*/
		int getErrorRow() const
		{
			//不正な添字を返却
			return errorRow;
		}

	//データメンバ
	private:
		const MatrixClass* errorPointer; //エラーを起こしたオブジェクトへのポインタ
		int errorRow;                     //不正な行
	};

	/**
	* MatrixClass型の明示的コンストラクタ
	* @param inputRow 行数, inputColumn 列数, inputValue 初期化値
	* @return
	* @author Sawa
	* @since 8.13
	*/
	explicit MatrixClass(int inputRow, int inputColumn, const TypeName& inputValue = TypeName())

		//行数、列数をデータメンバに代入
		: rowNumber(inputRow), columnNumber(inputColumn)
	{
		//行に値するメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
		matrixPointer = new TypeName*[rowNumber]();

		//行に値するメモリ領域に、列の先頭要素へのポインタを格納するループ
		for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

			//列に値するメモリ領域を確保し、先頭要素へのポインタを行に値するメモリ領域に代入
			matrixPointer[firstCounter] = new TypeName[columnNumber]();
		}
	}

	/**
	* MatrixClass型のコピーコンストラクタ
	* @param inputMatrix 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	MatrixClass(const MatrixClass<TypeName>& inputMatrix) {

		//初期化子が自身の場合
		if (&inputMatrix == this) {

			//行数0
			rowNumber = 0;

			//列数0
			columnNumber = 0;

			//NULLポインタをデータメンバに持つオブジェクトを作成
			arrayPointer = NULL;
		}
		//そうでない場合
		else {

			//行数をコピー
			rowNumber = inputMatrix.rowNumber;

			//列数をコピー
			columnNumber = inputMatrix.columnNumber;

			//要素数ぶんのメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
			matrixPointer = new TypeName*[rowNumber];

			//行に値するメモリ領域に、列の先頭要素へのポインタを格納するループ
			for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

				//列に値するメモリ領域を確保し、先頭要素へのポインタを行に値するメモリ領域に代入
				matrixPointer[firstCounter] = new TypeName[ColumnNumber];
			}

			//引数の値をコピーするため、行を参照するループ
			for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

				//列を参照するループ
				for (int secondCounter = 0; secondCounter < columnNumber; ++secondCounter) {

					//指定行列における要素の値をコピー
					matrixPointer[firstCounter][secondCounter] = inputMatrix.matrixPointer[firstCounter][seconCounter];
				}
			}
		}
	}

	/**
	* MatrixClass型のデストラクタ
	* @author Sawa
	* @since 8.13
	*/
	~MatrixClass()
	{
		//行毎に列の要素を破棄するためのループ
		for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

			//列の要素を破棄
			delete[] matrixPointer[firstCounter];
		}
		//行の要素(列の先頭要素へのポインタ)を破棄
		delete[] matrixPointer;
	}

	/**
	* 行数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 8.13
	*/
	int getRowNumber() const
	{
		//行数を返却
		return rowNumber;
	}

	/**
	* 列数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 8.13
	*/
	int getColumnNumber() const
	{
		//列数を返却
		return columnNumber;
	}


	/**
	* MatrixClass型に代入演算子=を適用するための演算子関数
	* @param inputMatrix 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	MatrixClass& operator=(const MatrixClass<TypeName>& inputMatrix)
	{
		//代入するオブジェクトが自身でない場合
		if (&inputMatrix != this)
		{
			//行数または列数が異なる場合
			if (rowNumber != inputMatrix.rowNumber || columnNumber != inputMatrix.columnNumber) {

				//行ごとに確保していた列用メモリ領域を破棄するループ
				for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

					//列を破棄
					delete[] matrixPointer[firstCounter];
				}
				//行を破棄
				delete[] matrixPointer;

				//行数を代入
				rowNumber = inputMatrix.rowNumber;

				//列数を代入
				columnNumber = inputMatrix.columnNumber;

				//行に値するメモリ領域を確保し、先頭要素へのポインタをデータメンバに代入
				matrixPointer = new TypeName*[rowNumber];

				//行に値するメモリ領域に、列の先頭要素へのポインタを格納するループ
				for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

					//列に値するメモリ領域を確保し、先頭要素へのポインタを行に値するメモリ領域に代入
					matrixPointer[firstCounter] = new TypeName[ColumnNumber];
				}
			}
			//引数の値をコピーするため、行を参照するループ
			for (int firstCounter = 0; firstCounter < rowNumber; ++firstCounter) {

				//列を参照するループ
				for (int secondCounter = 0; secondCounter < columnNumber; ++secondCounter)

					//指定行列における要素の値をコピー
					matrixPointer[firstCounter][secondCounter] = inputMatrix.matrixPointer[firstCounter][seconCounter];
			}
		}
		//自身への参照を返却
		return *this;
	}

	/**
	* MatrixClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数
	* @param inputRow 行
	* @return MatrixClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	TypeName* operator[](int inputRowNumber)
	{
		//添字として妥当でない添字が検出された場合
		if (!judgeIndex(inputRowNumber)) {

			//添字エラーを送出
			throw IndexError(this, inputRowNumber);
		}
		//MatrixClass型オブジェクトに[]を適用した値への参照を返却
		return matrixPointer[inputRowNumber];
	}

	/**
	* MatrixClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数 (const版)
	* @param inputRow 行, inputColumn 列
	* @return MatrixClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	const TypeName* operator[](int inputRowNumber) const
	{
		//添字として妥当でない添字が検出された場合
		if (!judgeIndex()) {

			//添字エラーを送出
			throw IndexError(this, inputRowNumber);
		}
		//MatrixClass型オブジェクトに[]を適用した値への参照を返却
		return matrixPointer[inputRowNumber];
	}

//データメンバ
private:
	int rowNumber;            //行数
	int columnNumber;         //列数
	TypeName** matrixPointer; //行列の先頭要素へのポインタ

};
