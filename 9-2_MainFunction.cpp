/*演習9-2 1-2節で作成したDate型のTwin<>と、Date型のTwin<>のTwin<>を作るプログラムを作成せよ。*/

#include<iostream>
#include<string>
#include"9-2_DateClass.h"
#include"9-2_DateClassDefinition.h"
#include"9-2_TwinClass.h"

int main()
{
	//日付A
	DateClass firstDate(2018, 8, 13);

	//日付B
	DateClass secondDate(1993, 7, 1);

	//DateClass型で特殊化を行ったTwinClass型オブジェクトAを作成
    TwinClass<DateClass> firstTwin(firstDate, secondDate);

	//TwinClass型オブジェクトAを表示
	cout << firstTwin << '\n';

	//日付C
	DateClass thirdDate(2001, 1, 1);

	//日付D 
	DateClass forthDate(1985, 2, 27);

	//DateClass型で特殊化を行ったTwinClass型オブジェクトBを作成
	TwinClass<DateClass> secondTwin(thirdDate, forthDate);

	//TwinClass型で特殊化を行ったTwinClass型オブジェクトAを作成
	TwinClass<TwinClass<DateClass>> testTwinTwin(firstTwin, secondTwin);

	//TwinClass型オブジェクトAを表示
	cout << testTwinTwin;
}
