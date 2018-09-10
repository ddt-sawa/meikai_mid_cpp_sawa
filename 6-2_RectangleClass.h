#ifndef ___Rectangle
#define ___Rectangle

#include <string>
#include<sstream>
#include<iostream>
#include "6-2_ShapeClass.h"


//長方形クラス
class RectangleClass : public ShapeClass {
public:

	/**
	* RectAngleClass型オブジェクトのコンストラクタ
	* @param inputWidth 幅, inputHeight 高さ
	* @author Sawa
	* @since 8.1
	*/
	RectangleClass(int inputWidth, int inputHeight) : rectWidth(inputWidth), rectHeight(inputHeight) {}

	/**
	* 長方形を複製する
	* @return 長方形オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual RectangleClass * makeClone() const {
		return new RectangleClass(rectWidth, rectHeight);
	}

	/**
	* 長方形を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//高さを参照するループ
		for (int firstCounter = 1; firstCounter <= rectHeight; ++firstCounter) {

			//幅を参照するループ
			for (int secondCounter = 1; secondCounter <= rectWidth; ++secondCounter) {

				//記号を表示
				std::cout << '*';
			}
			//改行
			std::cout << '\n';
		}
	}

	/**
	* 長方形の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "RectangleClass(rectWidth:" << rectWidth << ", rectHeight:" << rectHeight << ")";

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
		//幅を表示
		std::cout << "rectWidth : " << rectWidth << '\n';
		//高さを表示
		std::cout << "rectHeight : " << rectHeight << '\n';
	}

//データメンバ
private:
	int rectWidth;    //幅
	int rectHeight;   //高さ
};

#endif