/*演習9-6 Array<bool>型の配列に対して、対話的に処理を行うプログラムを作成せよ。
前問で作成したメンバ関数get_vsizeも利用すること。*/

#ifndef ___BoolArray
#define ___BoolArray

//1バイトのビット数を調べるべくnumeric_limits関数を使用するため、<limits>ヘッダをインクルード
#include <limits>
#include "9-6_ArrayClass.h"

//1バイトを確保するデータ型
typedef unsigned char ONE_BYTE;

//配列クラスをbool型用に明示的特殊化したクラステンプレート
template <> class ArrayClass<bool> {
public:
	/**
	* 指定された個数のbool型オブジェクトを格納するのに必要なONE_BYTE型配列の要素数を返却
	* @param inputNumber bool型オブジェクトの個数
	* @return neededByteArraySize 必要となるONE_BYTE型配列の要素数
	* @author Sawa
	* @since 8.20
	*/
	static int returnByteArraySize(int inputNumber)
	{
		//必要となるONE_BYTE型配列の要素数を計算
		int neededByteArraySize = (inputNumber + CHARACTER_BITS - 1) / CHARACTER_BITS;

		//要素数を返却
		return neededByteArraySize;
	}

	//特定バイト中の特定ビットへの参照を表すためのクラス
	class BitVector {
	public:

		/**
		* BitVector型オブジェクトのコンストラクタ
		* @param inputByteArrayNumber 参照したいONE_BYTE型配列, inputBitIndex 特定ビットのビット番号
		* @author Sawa
		* @since 8.20
		*/
		BitVector(ONE_BYTE& inputByteArrayPointer, int inputBitIndex) : byteArrayPointer(inputByteArrayPointer), bitIndex(inputBitIndex) {}

		/**
		* BitVector型をbool型に変換する
		* @author Sawa
		* @since 8.20
		*/
		operator bool() const
		{
			//特定ビットが1ならばTrue、0ならばFalseを返却する
			return (byteArrayPointer >> bitIndex) & 1U;
		}

		/**
		* 特定ビットの値を更新する演算子関数=
		* @param inputBool bool型の値
		* @author Sawa
		* @since 8.20
		*/
		BitVector& operator=(bool inputBool)
		{
			//引数がTrueの場合
			if (inputBool) {

				//特定ビットの値を1に更新する
				byteArrayPointer |= 1U << bitIndex;
			}
			//引数がFalseの場合
			else {

				//特定ビットの値を0に更新する
				byteArrayPointer &= ~(1U << bitIndex);
			}
			//自身への参照を返却する
			return *this;
		}

	//データメンバ
	private:
			
		//参照先ONE_BYTE型配列
		ONE_BYTE& byteArrayPointer;

		//参照先ONE_BYTE型配列における、特定ビットのビット番号
		int bitIndex;

	};
	//添字エラークラス
	class IndexError {
	public:

		/**
		* 添え字エラークラスのコンストラクタ
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
	* bool型に明示的特殊化を行ったArrayClass型オブジェクトの明示的コンストラクタ
	* @param inputNumber bool型の要素数, inputBool 入力bool値
	* @author Sawa
	* @since 8.20
	*/
	explicit ArrayClass(int inputNumber, bool inputBool = bool()) : boolNumber(inputNumber), byteArraySize(returnByteArraySize(inputNumber))
	{
		//ONE_BYTE型配列のメモリ領域を確保し、先頭要素へのポインタをデータメンバに設定
		byteArrayPointer = new ONE_BYTE[byteArraySize];

		//全要素を入力bool値で初期化するためのループ
		for (int firstCounter = 0; firstCounter < byteArraySize; ++firstCounter) {

			//要素を入力bool値で初期化
			byteArrayPointer[firstCounter] = inputBool;
		}
	}

	ArrayClass(const ArrayClass& inputArray)
	{

		//自己初期化の場合
		if (&inputArray == this) {

			//要素数0
			boolNumber = 0;

			//NULLポインタをデータメンバに持つオブジェクトを生成
			byteArrayPointer = nullptr;
		}
		//自己初期化ではない場合
		else {
			//bool型要素数をコピー
			boolNumber = inputArray.boolNumber;

			//ONE_BYTE型要素数をコピー
			byteArraySize = inputArray.byteArraySize;

			//ONE_BYTE型配列のメモリ領域を確保し、先頭要素へのポインタをデータメンバに設定
			byteArrayPointer = new ONE_BYTE[byteArraySize];

			//全要素をコピーするためのループ
			for (int firstCounter = 0; firstCounter < byteArraySize; ++firstCounter) {

				//要素をコピー
				byteArrayPointer[firstCounter] = inputArray.byteArrayPointer[firstCounter];
			}
		}
	}

	~ArrayClass() { delete[] byteArrayPointer; }

	/**
	* bool型要素数のゲッタ
	* @return boolNumber bool型要素数
	* @author Sawa
	* @since 8.20
	*/
	int getBoolNumber() const
	{
		//bool型要素数を返却
		return boolNumber;
	}

	/**
	* ArrayClass型オブジェクトに代入演算子=を適用できるようにする演算子関数
	* @param inputArray 同型オブジェクト
	* @return 自身への参照
	* @author Sawa
	* @since 8.20
	*/
	ArrayClass& operator=(const ArrayClass& inputArray)
	{
		//自己代入でない場合
		if (&inputArray != this) {

			//ONE_BYTE型要素数が異なる場合
			if (byteArraySize != inputArray.byteArraySize) {

				//確保していた領域を開放
				delete[] byteArrayPointer;

				//要素数をコピー
				byteArraySize = inputArray.byteArraySize;

				//ONE_BYTE型配列のメモリ領域を確保し、先頭要素へのポインタをデータメンバに設定
				byteArrayPointer = new ONE_BYTE[byteArraySize];
			}
			//bool型要素数をコピー
			boolNumber = inputArray.boolNumber;

			//全要素をコピーするためのループ
			for (int firstCounter = 0; firstCounter < byteArraySize; ++firstCounter) {

				//要素をコピー
				byteArrayPointer[firstCounter] = inputArray.byteArrayPointer[firstCounter];
			}
		}
		//自身への参照を返却
		return *this;
	}

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数
	* @param inputIndex 添字
	* @return 特定ONE_BYTE型配列における、特定ビットを表すオブジェクトを返却
	* @author Sawa
	* @since 8.20
	*/
	BitVector operator[](int inputIndex)
	{
		//添字が不正な場合
		if (inputIndex < 0 || inputIndex >= boolNumber) {

			//自身のポインタと不正な添字で初期化した例外クラスオブジェクトを送出
			throw IndexError(this, inputIndex);
		}

		//特定ONE_BYTE型配列における、特定ビットを表すオブジェクトを返却
		return BitVector(byteArrayPointer[inputIndex / CHARACTER_BITS], (inputIndex % CHARACTER_BITS));
	}

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数　(const版)
	* @param inputIndex 添字
	* @return 特定ONE_BYTE型配列における、特定ビットを表すオブジェクトを返却
	* @author Sawa
	* @since 8.20
	*/
	bool operator[](int inputIndex) const
	{
		//添字が不正な場合
		if (inputIndex < 0 || inputIndex >= boolNumber) {

			//自身のポインタと不正な添字で初期化した例外クラスオブジェクトを送出
			throw IndexError(this, inputIndex);
		}
		//特定ONE_BYTE型配列における、特定ビットの値を返却
		return (byteArrayPointer[inputIndex / CHARACTER_BITS] >> (inputIndex & (CHARACTER_BITS - 1)) & 1U) == 1;
	}
	//演習課題の要件を満たすメンバ関数を宣言
	int getByteArraySize() const;

	//データメンバ
private:

	//1バイトのビット数を表す静的データメンバ
	static const int CHARACTER_BITS = std::numeric_limits<unsigned char>::digits;

	//bool型の要素数
	int boolNumber;

	//bool型配列を格納するONE_BYTE型配列の要素数
	int byteArraySize;

	//ONE_BYTE型配列の先頭要素へのポインタ
	ONE_BYTE* byteArrayPointer;
};

/**
* ONE_BYTE型要素数のゲッタ
* @return byteArraySize ONE_BYTE型要素数
* @author Sawa
* @since 8.20
*/
int ArrayClass<bool>::getByteArraySize() const
{
	//ONE_BYTE型要素数を返却
	return byteArraySize;
}

#endif