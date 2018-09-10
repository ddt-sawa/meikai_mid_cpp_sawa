/*演習7-4 3次元クラスThreeDimensionを抽象基底クラスとして定義せよ。さらに、ThreeDimensionを継承するクラスを自由に作成せよ。*/

#ifndef ___ThreeDimension
#define ___ThreeDimension

#include<iostream>
#include<string>
#include<sstream>

//三次元クラス(抽象基底クラス)
class ThreeDimension {
public:

	//純粋仮想デストラクタ
	virtual ~ThreeDimension() = 0;

	//体積を求める仮想関数
	virtual double getVolume() const = 0;
};

//純粋仮想デストラクタ
inline ThreeDimension::~ThreeDimension() {}

#endif