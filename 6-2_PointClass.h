#ifndef ___Point
#define ___Point

#include <string>
#include<sstream>
#include<iostream>
#include "6-2_ShapeClass.h"


//点クラス
class PointClass : public ShapeClass {

public:

	/**
	* 点を複製する
	* @return 長方形オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual PointClass* makeClone() const {
		return new PointClass;
	}

	/**
	* 点を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//記号を表示
		std::cout << '*';

		//改行
		std::cout << '\n';
	}

	/**
	* 点の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "PointClass";

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
	}
};

#endif