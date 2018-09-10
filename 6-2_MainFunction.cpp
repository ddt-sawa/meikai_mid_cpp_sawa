#include<iostream>
#include "6-2_ShapeClass.h"
#include "6-2_RectangleClass.h"
#include "6-2_PointClass.h"
#include "6-2_LineClass.h"
#include "6-2_TriangleClass.h"

using namespace std;

int main()
{
	//水平直線の長さ
	int horizontalLineLength = 0;

	//値の入力を促す
	cout << "水平直線の長さ : ";

	//入力
	cin >> horizontalLineLength;

	//垂直直線の長さ
	int verticalLineLength = 0;

	//値の入力を促す
	cout << "垂直直線の長さ : ";

	//入力
	cin >> verticalLineLength;

	//長方形の幅
	int rectWidth = 0;

	//値の入力を促す
	cout << "長方形の幅 : ";

	//入力
	cin >> rectWidth;

	//長方形の高さ
	int rectHeight = 0;

	//値の入力を促す
	cout << "長方形の高さ : ";

	//入力
	cin >> rectHeight;

	//直角二等辺三角形の等辺の長さ
	int sidesLength = 0;

	//値の入力を促す
	cout << "直角二等辺三角形の等辺の長さ : ";

	//入力
	cin >> sidesLength;

	//図形クラスを作成
	PointClass pointObject;                                     //点
	HorizontalLineClass horizontalObject(horizontalLineLength); //水平直線
	VerticalLineClass verticalObject(verticalLineLength);       //垂直直線
	RectangleClass rectangleObject(rectWidth, rectHeight);      //長方形
	LowerLeftClass lowerLeftObject(sidesLength);                //左下直角二等辺三角形
	UpperLeftClass upperLeftObject(sidesLength);                //左上直角二等辺三角形
	LowerRightClass lowerRightObject(sidesLength);              //右下直角二等辺三角形
	UpperRightClass upperRightObject(sidesLength);              //右上直角二等辺三角形

	//6-1で確かめていなかったmakeClone関数が機能しているかを検討する
	ShapeClass* shapeArray[] = {
		pointObject.makeClone(),               //点,
		horizontalObject.makeClone(),          //水平直線
		verticalObject.makeClone(),            //垂直直線
		rectangleObject.makeClone(),           //長方形
		lowerLeftObject.makeClone(),           //左下直角二等辺三角形
		upperLeftObject.makeClone(),           //左上直角二等辺三角形
		lowerRightObject.makeClone(),          //右下直角二等辺三角形
		upperRightObject.makeClone(),          //右上直角二等辺三角形
										
	};

	//配列を参照するループ
	for (int firstCounter = 0; firstCounter < sizeof(shapeArray) / sizeof(shapeArray[0]); ++firstCounter) {

		//配列名と添字を表示する
		cout << "shapeArray[" << firstCounter << "]\n";

		//図形の情報を表示
		shapeArray[firstCounter]->printInformation();

		//図形のデバック情報を表示
		shapeArray[firstCounter]->printDebug();

		//改行
		cout << '\n';
	}

	//作成した配列を削除するループ
	for (int firstCounter = 0; firstCounter < sizeof(shapeArray) / sizeof(shapeArray[0]); ++firstCounter) {

		//図形を削除
		delete shapeArray[firstCounter];
	}
}

//動作を確認