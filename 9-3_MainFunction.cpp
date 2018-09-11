/*演習9-3 Twin<Twin<Date>, Twin<Date>>を要素として持つArray<>クラステンプレートオブジェクトを作成して利用するプログラムを作成せよ。*/

#include<iostream>
#include"9-3_ArrayClass.h"
#include"9-3_DateClass.h"
#include"9-3_DateClassDefinition.h"
#include"9-3_TwinClass.h"

//配列クラスの要素数を2とする
const int arraySize = 2;

int main()
{
	DateClass firstDate(2003, 9, 20);  //日付A
	DateClass secondDate(1993, 8, 20); //日付B
	DateClass thirdDate(1904, 4, 30);  //日付C
	DateClass forthDate(2007, 3, 1);   //日付D

	TwinClass<DateClass> firstTwin(firstDate, secondDate); //TwinA
	TwinClass<DateClass> secondTwin(thirdDate, forthDate); //TwinB

	TwinClass<TwinClass<DateClass>> firstTwinTwin(firstTwin, secondTwin);  //TwinTwinA
	TwinClass<TwinClass<DateClass>> secondTwinTwin(secondTwin, firstTwin); //TwinTwinB

	ArrayClass<TwinClass <TwinClass<DateClass>>> firstArray(arraySize); //Twin<Twin<Date>,Twin<Date>>を要素として持つ配列クラスオブジェクトを初期化


	firstArray[0] = firstTwinTwin;  //配列クラスオブジェクトの先頭要素にTwinTwinAを代入
	firstArray[1] = secondTwinTwin; //配列クラスオブジェクトの第2要素にTwinTwinBを代入

		//配列クラスの要素を走査表示するためのループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//要素を表示
		cout << firstArray[firstCounter] << '\n';
	}
	//敢えて添字エラーの動作確認をするためのtry文 
	try {
		//不正な添字を参照
		cout << firstArray[arraySize];
	}
	//不正な添え字を検出した場合
	catch (const ArrayClass<TwinClass<TwinClass<DateClass>>>::IndexError& inputError) {

		//その旨を告知(動作を確認)
		cout << "不正な添字を検出しました。\n";
	}
}