#include<iostream>
#include "4-3.h"

using namespace std;

int main()
{
	//基底クラス型オブジェクト
	BaseClass myBaseClass(0, 1);

	//派生クラス型オブジェクト
	DerivedClass myDerivedClass(0, 1, 2);

	//アップキャストを実行
	BaseClass* baseClassPointer = &myDerivedClass;

	//アップキャストしたポインタを使って基底クラスのデータメンバを取得
	baseClassPointer->printBaseInteger();

	//アップキャストしたポインタを使って派生クラスのデータメンバを取得(コンパイルエラー)
	//baseClassPointer->printDerivedInteger();

	//ダウンキャストを実行(コンパイルエラー)
	//DerivedClass* derivedClassPointer = &myBaseClass;

}

