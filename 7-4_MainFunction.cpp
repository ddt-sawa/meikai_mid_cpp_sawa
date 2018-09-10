/*演習7-4 3次元クラスThreeDimensionを抽象基底クラスとして定義せよ。さらに、ThreeDimensionを継承するクラスを自由に作成せよ。*/

#include<iostream>
#include "7-4_ShapeClass.h"
#include "7-4_ThreeDimensionClass.h"
#include "7-4_CuboidClass.h"
#include "7-4_SphereClass.h"

using namespace std;

int main()
{
	//三次元図形へのポインタを、図形クラスのポインタ配列に格納
	ShapeClass* testObject[] = {
		new SphereClass(4),      //球体
		new CuboidClass(3,4,5),  //直方体
	};

	//三次元図形の情報を表示するループ
	for (int firstCounter = 0; firstCounter < (sizeof(testObject) / sizeof(testObject[0])); ++firstCounter) {

		//情報を表示する配列要素の添字
		cout << "testObject[" << firstCounter << "]\n";

		//図形情報を表示
		testObject[firstCounter]->printInformation();

		//配列に格納されているポインタが指すオブジェクトが三次元図形だった場合(今回は全要素が当てはまる)
		if (ThreeDimension* temporaryPointer = dynamic_cast<ThreeDimension*>(testObject[firstCounter])) {

			//体積を表示
			cout << "体積は" << temporaryPointer->getVolume() << "です。\n";
		}

		//改行
		cout << '\n';
	}
}