/*演習7-3 左上直角の二等辺三角形RectEquilTriangleLUと、右下直角の二等辺三角形RectEquilTriangleRBを作成せよ。*/

#include <string>
#include<sstream>
#include<iostream>
#include "7-3_ShapeClass.h"
#include "7-3_TwoDimensionClass.h"

//直角二等辺三角形クラス(抽象クラス)
class TriangleClass : public ShapeClass, public  TwoDimensionClass{
public:

	/**
	* TriangleClass型オブジェクトのコンストラクタ
	* @param sidesLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	TriangleClass(int inputLength) : sidesLength(inputLength) {}


	/**
	* 長さのゲッタ
	* @return sidesLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	int getLength() const { return sidesLength; }

	/**
	* 長さのセッタ
	* @param sidesLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	void getLength(int inputLength) { sidesLength = inputLength; }

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
		std::cout << "sidesLength : " << sidesLength << '\n';
	}

	/**
	* 図形の面積を計算して返却する
	* @return double型の値 三角形の面積
	* @author Sawa
	* @since 8.2
	*/
	double getArea() const {

		//三角形の面積
		return sidesLength * sidesLength / 2.0;
	}


//データメンバ
protected:
	int sidesLength; //等辺の長さ

};

//左下直角クラス
class LowerLeftClass : public TriangleClass {

public:

	/**
	* LowerRightClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	LowerLeftClass(int inputLength) : TriangleClass(inputLength) {}

	/**
	* 三角形を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual LowerLeftClass* makeClone() const {
		return new LowerLeftClass(sidesLength);
	}

	/**
	* 左下直角二等辺三角形を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//左下直角二等辺三角形を表示するループ(段目を参照)
		for (int firstCounter = 1; firstCounter <= sidesLength; ++firstCounter) {

			//段目ぶん記号を置くループ
			for (int secondCounter = 0; secondCounter < firstCounter; ++secondCounter) {

				//記号を表示
				std::cout << '*';
			}
			//段数-段目ぶん空白文字を置くループ
			for (int secondCounter = 0; secondCounter < sidesLength - firstCounter; ++secondCounter) {

				//空白文字を表示
				std::cout << ' ';
			}
			//改行
			std::cout << '\n';
		}
	}

	/**
	* 三角形の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "LowerleftCass(sidesLenght:" << sidesLength << ")";

		//文字列を返却
		return userStream.str();
	}
};

//左上直角クラス
class UpperLeftClass : public TriangleClass {

public:

	/**
	* LowerRightClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	UpperLeftClass(int inputLength) : TriangleClass(inputLength) {}

	/**
	* 三角形を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual UpperLeftClass* makeClone() const {
		return new UpperLeftClass(sidesLength);
	}

	/**
	* 左上直角二等辺三角形を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//左上直角二等辺三角形を表示するループ(段目を参照)
		for (int firstCounter = 1; firstCounter <= sidesLength; ++firstCounter) {

			//段数 - 段目 + 1ぶん記号を置くループ
			for (int secondCounter = 0; secondCounter < sidesLength - firstCounter + 1; ++secondCounter) {

				//記号を表示
				std::cout << '*';
			}
			//段目 - 1ぶん空白文字を置くループ
			for (int secondCounter = 0; secondCounter < firstCounter - 1; ++secondCounter) {

				//空白文字を表示
				std::cout << ' ';
			}
			//改行
			std::cout << '\n';
		}
	}

	/**
	* 三角形の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "UpperLeftClass(sidesLenght:" << sidesLength << ")";

		//文字列を返却
		return userStream.str();
	}
};

//右下直角クラス
class LowerRightClass : public TriangleClass {

public:

	/**
	* LowerRightClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	LowerRightClass(int inputLength) : TriangleClass(inputLength) {}

	/**
	* 三角形を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual LowerRightClass* makeClone() const {
		return new LowerRightClass(sidesLength);
	}

	/**
	* 右下直角二等辺三角形を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//右下直角二等辺三角形を表示するループ(段目を参照)
		for (int firstCounter = 1; firstCounter <= sidesLength; ++firstCounter) {

			//段数-段目ぶん空白文字を置くループ
			for (int secondCounter = 0; secondCounter < sidesLength - firstCounter; ++secondCounter) {

				//空白文字を表示
				std::cout << ' ';
			}
			//段目ぶん記号を置くループ
			for (int secondCounter = 0; secondCounter < firstCounter; ++secondCounter) {

				//記号を表示
				std::cout << '*';
			}
			//改行
			std::cout << '\n';
		}
	}

	/**
	* 三角形の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "LowerRightClass(sidesLenght:" << sidesLength << ")";

		//文字列を返却
		return userStream.str();
	}
};

//右上直角クラス
class UpperRightClass : public TriangleClass {

public:

	/**
	* UooerRightClass型オブジェクトのコンストラクタ
	* @param inputLength 長さ
	* @author Sawa
	* @since 8.1
	*/
	UpperRightClass(int inputLength) : TriangleClass(inputLength) {}

	/**
	* 三角形を複製する
	* @return 水平直線型オブジェクトへの参照
	* @author Sawa
	* @since 8.1
	*/
	virtual UpperRightClass* makeClone() const {
		return new UpperRightClass(sidesLength);
	}

	/**
	* 右上直角二等辺三角形を表示する
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{

		//右上直角二等辺三角形を表示するループ(段目を参照)
		for (int firstCounter = 1; firstCounter <= sidesLength; ++firstCounter) {

			//段数-1ぶん空白文字を置くループ
			for (int secondCounter = 0; secondCounter < firstCounter - 1; ++secondCounter) {

				//空白文字を表示
				std::cout << ' ';
			}
			//段数-段目+1ぶん記号を置くループ
			for (int secondCounter = 0; secondCounter < sidesLength - firstCounter + 1; ++secondCounter) {

				//記号を表示
				std::cout << '*';
			}
			//改行
			std::cout << '\n';
		}
	}

	/**
	* 三角形の情報を文字列にして返却する
	* @return 文字列表現
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//出力ストリーム
		std::ostringstream userStream;

		//出力ストリームに図形の情報を挿入
		userStream << "UpperRightClass(sidesLenght:" << sidesLength << ")";

		//文字列を返却
		return userStream.str();
	}
};
