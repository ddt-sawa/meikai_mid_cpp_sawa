/*演習9-7 9-1節のクラステンプレートTwin<>をインクルードモデルで実現したプログラムを作成せよ。*/

#ifndef ___Twin
#define ___Twin

#include<iostream>
#include<string>
//swap関数を使用するため、下記二つのヘッダをインクルード
#include<utility>
#include<algorithm>

//2値クラステンプレート
template <class TypeName> class TwinClass {
public:

	//TwinClass型オブジェクトのデフォルトコンストラクタ
	TwinClass(const TypeName& firstArgument = TypeName(), const TypeName& secondArgument = TypeName());
	
	// TwinClass型オブジェクトのコピーコンストラクタ
	TwinClass(const TwinClass<TypeName>& argumentTwinClass);
	
	//第1値のゲッタ
	TypeName getFirstValue() const;

	//第1値のゲッタ及びセッタ
	TypeName& setFirstValue();

    //第2値のゲッタ
	TypeName getSecondValue() const;

	//第2値のゲッタ及びセッタ
	TypeName& setSecondValue();

	//第1値,第2値のセッタ
	void setTwinValue(const TypeName& firstArgument, const TypeName& secondArgument);

	//第1値と第2値の最小値を返却する
	TypeName& returnMinimumValue();


	//第1値が第2値より小さい場合はTrueを、そうでない場合はFalseを返却する
	bool compareValues() const;

	//第1値と第2値を昇順にソートする
	void sortValues();

//データメンバ
private:
	TypeName firstValue;  //第1値
	TypeName secondValue; //第2値
};

//TwinClass型に比較演算子<を適用できるようにする演算子関数
template <class TypeName> inline bool operator<(const TwinClass<TypeName>& firstTwinClass, const TwinClass<TypeName>& secondTwinClass);

//TwinClass型に挿入子<<を適用できるようにする演算子関数
template <class TypeName> inline std::ostream& operator<<(std::ostream& userOstream, const TwinClass<TypeName>& argumentTwinClass);

//char型に特殊化されたTwinClass型に挿入子<<を適用できるようにする演算子関数
template <> inline std::ostream& operator<<(std::ostream& userOstream, const TwinClass<char>& argumentTwinClass);

//インクルードモデルを使用
#include "9-7_MemberDefinition.cpp"
#endif