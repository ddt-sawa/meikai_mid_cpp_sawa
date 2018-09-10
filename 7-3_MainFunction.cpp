/*演習7-3 左上直角の二等辺三角形RectEquilTriangleLUと、右下直角の二等辺三角形RectEquilTriangleRBを作成せよ。*/

#include<iostream>
#include "7-3_ShapeClass.h"
#include "7-3_RectangleClass.h"
#include "7-3_PointClass.h"
#include "7-3_LineClass.h"
#include "7-3_TriangleClass.h"

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

		//参照するオブジェクトが二次元図形だった場合(キャストが成功した場合)
		if (TwoDimensionClass* temporaryPointer = dynamic_cast<TwoDimensionClass*>(shapeArray[firstCounter])) {

			//図形の面積を表示
			cout << "面積は" << temporaryPointer->getArea() << "です。\n";
		}
		//改行
		cout << '\n';
	}

	//作成した配列を削除するループ
	for (int firstCounter = 0; firstCounter < sizeof(shapeArray) / sizeof(shapeArray[0]); ++firstCounter) {

		//図形を削除
		delete shapeArray[firstCounter];
	}
}