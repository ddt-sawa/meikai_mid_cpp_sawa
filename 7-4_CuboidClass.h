/*演習7-4 3次元クラスThreeDimensionを抽象基底クラスとして定義せよ。さらに、ThreeDimensionを継承するクラスを自由に作成せよ。*/

#ifndef ___Cuboid
#define ___Cuboid

#include <string>
#include<sstream>
#include<iostream>
#include "7-4_ShapeClass.h"
#include "7-4_ThreeDimensionClass.h"

//直方体クラス
class CuboidClass : public ShapeClass, public ThreeDimension {
public:

	/**
	* 直方体型オブジェクトのコンストラクタ
	* @param inputVertiCalLength 縦, inputHorizontalLength 横, inputHeightLength 高さ
	* @author Sawa
	* @since 8.1
	*/
	CuboidClass(int inputVerticalLength, int inputHorizontalLength, int inputHeightLength) : verticalLength(inputHeightLength), horizontalLength(inputHorizontalLength), heightLength(inputHeightLength) {}


	/**
	* 直方体を複製する
	* @return 直方体型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual CuboidClass* makeClone() const {
		return new CuboidClass(verticalLength, horizontalLength, heightLength);
	}

	/**
	* 直方体を表示できないので、警告文を発する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		std::cout << "直方体の図示は行いません。\n";
	}

	/**
	* 直方体の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "CuboidClass(verticalLength:" << verticalLength << ", horizontalLength:" << horizontalLength << ", heightLength:" << heightLength << ')';

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
		std::cout << "CuboidClass(verticalLength:" << verticalLength << ", horizontalLength:" << horizontalLength << ", heightLength:" << heightLength << '\n';
	}

	/**
	* 直方体の体積を返却する
	* @return cuboidVolume 直方体の体積
	* @author Sawa
	* @since 8.1
	*/
	double getVolume() const
	{
		//直方体の体積を計算
		double cuboidVolume = verticalLength * horizontalLength * heightLength;

		//直方体の体積を返却
		return  cuboidVolume;
	}

//データメンバ
private:
	int verticalLength;     //縦
	int horizontalLength;   //横
	int heightLength;       //高さ

};

#endif
