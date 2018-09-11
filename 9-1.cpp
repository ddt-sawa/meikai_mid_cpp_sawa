/*演習9-1 char型に特殊化した挿入子を作成せよ。表示する文字を単一引用符'で囲んで表示する(例えば、['A','C'と表示する])こと。*/

#include<iostream>
#include<string>
#include"9-1_twin.h"

using namespace std;

int main()
{
	//テンプレート実引数をchar型に指定したTwinClass型オブジェクトを定義
	TwinClass<char> testTwinObject('A', 'Z');

	//char型に特殊化した挿入子を用いてオブジェクト表示を確認
	cout << testTwinObject;
}