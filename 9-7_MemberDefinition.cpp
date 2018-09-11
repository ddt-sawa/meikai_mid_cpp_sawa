#ifndef ___MemberDefinition
#define ___MemberDefinition

#include<iostream>
#include<string>
//swap関数を使用するため、下記二つのヘッダをインクルード
#include<utility>
#include<algorithm>

/**
* TwinClass型オブジェクトのデフォルトコンストラクタ
* @param　firstArgument 第1引数, secondArgument 第2引数
* @author Sawa
* @since 8.13
*/
template <class TypeName> TwinClass<TypeName>::TwinClass(const TypeName& firstArgument, const TypeName& secondArgument)

//第1引数を第1値に、第2引数を第2値に代入
	: firstValue(firstArgument), secondValue(secondArgument) {}

/**
* TwinClass型オブジェクトのコピーコンストラクタ
* @param　argumentTwinClass TwinClass型オブジェクト
* @author Sawa
* @since 8.13
*/
template <class TypeName> TwinClass<TypeName>::TwinClass(const TwinClass<TypeName>& argumentTwinClass)

//引数となるTwinClass型オブジェクトの第1値、第2値をコピー
	: firstValue(argumentTwinClass.getFirstValue()), secondValue(argumentTwinClass.secondValue()) {}

/**
* 第1値のゲッタ
* @return firstValue 第1値
* @author Sawa
* @since 8.13
*/
template <class TypeName> TypeName TwinClass<TypeName>::getFirstValue() const
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
template <class TypeName> TypeName& TwinClass<TypeName>::setFirstValue()
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
template <class TypeName> TypeName TwinClass<TypeName>::getSecondValue() const
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
template <class TypeName> TypeName& TwinClass<TypeName>::setSecondValue()
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
template <class TypeName> void TwinClass<TypeName>::setTwinValue(const TypeName& firstArgument, const TypeName& secondArgument)
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
template <class TypeName> TypeName& TwinClass<TypeName>::returnMinimumValue()
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
template <class TypeName> bool TwinClass<TypeName>::compareValues() const
{
	//第1値が第2値より小さい場合はTrueを、そうでない場合はFalseを返却する
	return firstValue < secondValue;
}

/**
* 第1値と第2値を昇順にソートする
* @author Sawa
* @since 8.13
*/
template <class TypeName> void TwinClass<TypeName>::sortValues()
{
	//第1値が第2値より小さい場合 
	if (!(firstValue < secondValue)) {

		//両値を入れ替える
		std::swap(firstValue, secondValue);
	}
}

/**
* TwinClass型に比較演算子<を適用できるようにする演算子関数
* @param firstTwinClass TwinClass型オブジェクトA, secondTwinClass TwinClass型オブジェクトB
* @return boolValue bool型の値
* @author Sawa
* @since 8.13
*/
template <class TypeName> inline bool operator<(const TwinClass<TypeName>& firstTwinClass, const TwinClass<TypeName>& secondTwinClass)
{
	//オブジェクトの大小関係
	bool boolValue;

	//Aの第1値が、Bの第1値より小さい場合
	if (firstTwinClass.getFirstValue() < secondTwinClass.getFirstValue()) {

		//Aの方が小さい
		boolValue = true;
	}
	//そうでなく、Bの第1値がAの第1値より小さくない(Bの第1値=Aの第1値)かつAの第2値が、Bの第2値より小さい場合
	else if (!(secondTwinClass.firstValue() < firstTwinClass.getFirstValue()) && firstTwinClass.getSecondValue() < secondTwinClass.getSecondValue()) {

		//Aの方が小さい
		boolValue = true;
	}
	//上記いずれの条件にも当てはまらない場合
	else {

		//Bの方が小さい
		boolValue = false;
	}
	//大小関係を返却
	return boolValue;
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

#endif