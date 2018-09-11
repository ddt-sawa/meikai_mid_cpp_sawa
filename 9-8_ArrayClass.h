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
	bool judgeIndex(int inputIndex);

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
		IndexError(const ArrayClass* inputPointer, int inputIndex);

		/**
		* 不正な添字のゲッタ
		* @return　errorIndex 不正な添字
		* @author Sawa
		* @since 8.13
		*/
		int getArrayIndex() const;

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
	explicit ArrayClass(int inputArraySize, const TypeName& inputValue = TypeName());

	/**
	* ArrayClass型のコピーコンストラクタ
	* @param inputArray 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	ArrayClass(const ArrayClass<TypeName>& inputArray);

	/**
	* ArrayClass型のデストラクタ
	* @author Sawa
	* @since 8.13
	*/
	~ArrayClass();

	/**
	* 要素数のゲッタ
	* @return arraySize 要素数
	* @author Sawa
	* @since 8.13
	*/
	int getArraySize() const;

	/**
	* ArrayClass型に代入演算子=を適用するための演算子関数
	* @param inputArray 同型のオブジェクト
	* @return
	* @author Sawa
	* @since 8.13
	*/
	ArrayClass& operator=(const ArrayClass<TypeName>& inputArray);

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数
	* @param inputIndex 添字
	* @return ArrayClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	TypeName& operator[](int inputIndex);

	/**
	* ArrayClass型オブジェクトに添字演算子[]を適用できるようにする演算子関数 (const版)
	* @param inputIndex 添字
	* @return ArrayClass型オブジェクトに[]を適用した値への参照
	* @author Sawa
	* @since 8.13
	*/
	const TypeName& operator[](int inputIndex) const;

	//データメンバ
private:
	int arraySize;          //配列の要素数
	TypeName* arrayPointer; //配列の先頭要素へのポインタ
};

//インクルードモデルを使用してArray<bool>型に明示化したクラステンプレートを読み込む
#include"9-8_ArrayClassDefinition.cpp"
#endif
