#include<iostream>
#include "6-1_ShapeClass.h"
#include "6-1_RectangleClass.h"
#include "6-1_PointClass.h"
#include "6-1_LineClass.h"
#include "6-1_TriangleClass.h"

using namespace std;

int main()
{
	//図形のポインタを配列に格納する
	ShapeClass* shapeArray[] = {
		new PointClass(),              //点
		new HorizontalLineClass(9),    //水平直線
		new VerticalLineClass(6),      //垂直直線
		new RectangleClass(7,3),       //長方形
		new LowerLeftClass(5),         //左下直角二等辺三角形
		new UpperLeftClass(3),         //左上直角二等辺三角形
		new LowerRightClass(6),        //右下直角二等辺三角形
		new UpperRightClass(5),        //右上直角二等辺三角形
	};

	//配列を参照するループ
	for (int firstCounter = 0; firstCounter < sizeof(shapeArray) / sizeof(shapeArray[0]); ++firstCounter) {

		//配列名と添字を表示する
		cout << "shapeArray[" << firstCounter << "]\n";

		//図形の情報を表示
		shapeArray[firstCounter]->printInformation();

		//図形のデバック情報を表示
		shapeArray[firstCounter]->printDebug();

		cout << '\n';
	}
	
	//作成した配列を削除するループ
	for (int firstCounter = 0; firstCounter < sizeof(shapeArray) / sizeof(shapeArray[0]); ++firstCounter) {

		//図形のポインタを削除
		delete shapeArray[firstCounter];
	}
}