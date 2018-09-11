/*演習9-2 1-2節で作成したDate型のTwin<>と、Date型のTwin<>のTwin<>を作るプログラムを作成せよ。*/

#ifndef ___Twin
#define ___Twin

#include<iostream>
#include<string>
//swap関数を使用するため、下記二つのヘッダをインクルード
#include<utility>
#include<algorithm>
//DateClass型の定義をインクルード
#include "9-2_DateClass.h"
#include "9-2_DateClassDefinition.h"

//2値クラステンプレート
template <class TypeName> class TwinClass {
public:

	/**
	* TwinClass型オブジェクトのデフォルトコンストラクタ
	* @param　firstArgument 第1引数, secondArgument 第2引数
	* @author Sawa
	* @since 8.13
	*/
	TwinClass(const TypeName& firstArgument = TypeName(), const TypeName& secondArgument = TypeName())

		//第1引数を第1値に、第2引数を第2値に代入
		: firstValue(firstArgument), secondValue(secondArgument) {}

	/**
	* TwinClass型オブジェクトのコピーコンストラクタ
	* @param　argumentTwinClass TwinClass型オブジェクト
	* @author Sawa
	* @since 8.13
	*/
	TwinClass(const TwinClass<TypeName>& argumentTwinClass)

		//引数となるTwinClass型オブジェクトの第1値、第2値をコピー
		: firstValue(argumentTwinClass.getFirstValue()), secondValue(argumentTwinClass.getSecondValue()) {}

	/**
	* 第1値のゲッタ
	* @return firstValue 第1値
	* @author Sawa
	* @since 8.13
	*/
	TypeName getFirstValue() const
	{
		//第1値を返却
		return firstValue;
	}

	/**
	* 第1値のゲッタ及びセッタ
	* @return firstValue 第1値
	* @author Sawa
	* @since 8.13
	*/
	TypeName& setFirstValue()
	{
		//第1値の参照を返却
		return firstValue;
	}

	/**
	* 第2値のゲッタ
	* @return secondValue 第2値
	* @author Sawa
	* @since 8.13
	*/
	TypeName getSecondValue() const
	{
		//第2値を返却
		return secondValue;
	}

	/**
	* 第2値のゲッタ及びセッタ
	* @return secondValue 第2値
	* @author Sawa
	* @since 8.13
	*/
	TypeName& setSecondValue()
	{
		//第2値の参照を返却
		return secondValue;
	}

	/**
	* 第1値,第2値のセッタ
	* @param firstArgument 第1引数, secondArgument 第2引数
	* @author Sawa
	* @since 8.13
	*/
	void setTwinValue(const TypeName& firstArgument, const TypeName& secondArgument)
	{
		firstValue = firstArgument;    //第1値をセット
		secondValue = secondArgument;  //第2値をセット
	}

	/**
	* 第1値と第2値の最小値を返却する
	* @return minimumValue 最小値
	* @author Sawa
	* @since 8.13
	*/
	TypeName& returnMinimumValue()
	{

		//最小値
		TypeName minimumValue = (firstValue < secondValue ? firstValue : secondValue);

		//最小値を返却
		return minimumValue;
	}


	/**
	* 第1値が第2値より小さい場合はTrueを、そうでない場合はFalseを返却する
	* @return bool型の値
	* @author Sawa
	* @since 8.13
	*/
	bool compareValues() const
	{
		//第1値が第2値より小さい場合はTrueを、そうでない場合はFalseを返却する
		return firstValue < secondValue;
	}

	/**
	* 第1値と第2値を昇順にソートする
	* @author Sawa
	* @since 8.13
	*/
	void sortValues()
	{
		//第1値が第2値より小さい場合 
		if (!(firstValue < secondValue)) {

			//両値を入れ替える
			std::swap(firstValue, secondValue);
		}
	}

//データメンバ
private:
	TypeName firstValue;  //第1値
	TypeName secondValue; //第2値

};
/**
* TwinClass型に比較演算子<を適用できるようにする演算子関数
* @param firstTwinClass TwinClass型オブジェクトA, secondTwinClass TwinClass型オブジェクトB
* @return bool型の値
* @author Sawa
* @since 8.13
*/
template <class TypeName> inline bool operator<(const TwinClass<TypeName>& firstTwinClass, const TwinClass<TypeName>& secondTwinClass)
{
	//Aの第1値が、Bの第1値より小さい場合
	if (firstTwinClass.getFirstValue() < secondTwinClass.getFirstValue()) {

		//tureを返却
		return true;
	}

	//そうでなく、Bの第1値がAの第1値より小さくない(Bの第1値=Aの第1値)かつAの第2値が、Bの第2値より小さい場合
	else if (!(secondTwinClass.firstValue() < firstTwinClass.getFirstValue()) && firstTwinClass.getSecondValue() < secondTwinClass.getSecondValue()) {

		//trueを返却
		return true;
	}

	//上記いずれの条件にも当てはまらなかった場合、falseを返却
	return false;
}

/**
* TwinClass型に挿入子<<を適用できるようにする演算子関数
* @author Sawa
* @since 8.13
*/
template <class TypeName> inline std::ostream& operator<<(std::ostream& userOstream, const TwinClass<TypeName>& argumentTwinClass)
{
	//出力ストリームに[第1値,第2値]の形で文字列表現を挿入
	return userOstream << "[" << argumentTwinClass.getFirstValue() << "," << argumentTwinClass.getSecondValue() << "]";
}

/**
* char型に特殊化されたTwinClass型に挿入子<<を適用できるようにする演算子関数
* @author Sawa
* @since 8.13
*/
template <> inline std::ostream& operator<<(std::ostream& userOstream, const TwinClass<std::string>& argumentTwinClass)
{
	//出力ストリームに[第1値,第2値]の形で文字列表現を挿入
	return userOstream << "[\'" << argumentTwinClass.getFirstValue() << "\',\'" << argumentTwinClass.getSecondValue() << "\']";
}

/**
* DateClass型に特殊化されたTwinClass型に挿入子<<を適用できるようにする演算子関数
* @author Sawa
* @since 8.13
*/
template <> inline std::ostream& operator<<(std::ostream& userOstream, const TwinClass<DateClass>& argumentTwinClass)
{
	//出力ストリームに[第1値,第2値]の形で文字列表現を挿入
	return userOstream << "[" << argumentTwinClass.getFirstValue() << "," << argumentTwinClass.getSecondValue()<< "]";
}
#endif

