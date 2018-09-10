#ifndef ___Line
#define ___Line

#include <string>
#include<sstream>
#include<iostream>
#include "6-2_ShapeClass.h"

//直線クラス(抽象クラス)
class LineClass : public ShapeClass {
public:

	/**
	* lineClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	LineClass(int inputLength) : lineLength(inputLength) {}

	/**
	* 長さのゲッタ
	* @return lineLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	int getLength() const { return lineLength; }

	/**
	* 長さのセッタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	void getLength(int inputLength) { lineLength = inputLength; }

	/**
	* デバッグ情報を表示
	* @author Sawa
	* @since 8.1
	*/
	void printDebug() const
	{
		//基本デバッグ情報を表示
		ShapeClass::printDebug();
		//長さを表示
		std::cout << "lineLength : " << lineLength << '\n';
	}

//データメンバ
protected:
	int lineLength; //長さ
};

//水平直線クラス
class HorizontalLineClass : public LineClass {

public:

	/**
	* HorizontalLineClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	HorizontalLineClass(int inputLength) : LineClass(inputLength) {}

	/**
	* 水平直線を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual HorizontalLineClass* makeClone() const {
		return new HorizontalLineClass(lineLength);
	}

	/**
	* 水平直線を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//直線の長さぶん記号を表示するループ
		for (int firstCounter = 1; firstCounter <= lineLength; ++firstCounter) {

			//記号を表示
			std::cout << '-';
		}
		//改行
		std::cout << '\n';
	}

	/**
	* 水平直線の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "HorizontalLineClass(lineLenght:" << lineLength << ")";

		//文字列を返却
		return userStream.str();
	}
};

//垂直直線クラス
class VerticalLineClass : public LineClass {

public:

	/**
	* VerticalLineClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	VerticalLineClass(int inputLength) : LineClass(inputLength) {}

	/**
	* 垂直直線を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual VerticalLineClass* makeClone() const {
		return new VerticalLineClass(lineLength);
	}

	/**
	* 垂直直線を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//直線の長さぶん記号を表示するループ
		for (int firstCounter = 1; firstCounter <= lineLength; ++firstCounter) {

			//記号を表示
			std::cout << '|';

			//改行
			std::cout << '\n';
		}
	}

	/**
	* 垂直直線の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "VerticalLineClass(lineLength:" << lineLength << ")";

		//文字列を返却
		return userStream.str();
	}
};

#endif