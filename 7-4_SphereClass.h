/*演習7-4 3次元クラスThreeDimensionを抽象基底クラスとして定義せよ。さらに、ThreeDimensionを継承するクラスを自由に作成せよ。*/

#ifndef ___Sphere
#define ___Sphere

#include <string>
#include<sstream>
#include<iostream>
#include "7-4_ShapeClass.h"
#include "7-4_ThreeDimensionClass.h"

//円周率
const double PI = 3.14;

//球体クラス
class SphereClass : public ShapeClass, public ThreeDimension{
public:

	/**
	* 球体型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	SphereClass(int inputLength) : radiusLength(inputLength) {}
	

	/**
	* 球体を複製する
	* @return 球体型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual SphereClass* makeClone() const {
		return new SphereClass(radiusLength);
	}

	/**
	* 球体を表示できないので、警告文を発する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		std::cout << "球体の図示は行いません。\n";
	}

	/**
	* 球体の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "SphereClass(lineLength:" << radiusLength << ")";

		//文字列を返却
		return userStream.str();
	}

	/**
	* デバッグ情報を表示
	* @author Sawa
	* @since 8.1
	*/
	void printDebug() const
	{
		//基本デバッグ情報を表示
		ShapeClass::printDebug();
		//半径を表示
		std::cout << "radiusLength : " << radiusLength << '\n';
	}

	/**
	* 球体の体積を返却する
	* @return sphereVolume 球体の体積
	* @author Sawa
	* @since 8.1
	*/
	double getVolume() const
	{
		//球体の体積を計算する
		double sphereVolume = 4 * PI * radiusLength * radiusLength * radiusLength / 3;

		//球体の体積を返却
		return sphereVolume;
	}

//データメンバ
private:
	int radiusLength; //半径の長さ
};

#endif
