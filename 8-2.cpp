/*演習8-2 左ページに示した『B』の構造を持つプログラムを実際に作成して、動作の検証を行え。*/

#include<iostream>

using namespace std;

//0が入力された場合の例外クラス
class ZeroError {};

int main()
{
	//整数値
	int inputNumber = 0;

	//整数値の入力
	cin >> inputNumber;

	//例外の捕捉
	try {
		//入力された整数値で場合分け
		switch (inputNumber) {

		//0が入力された場合
		case 0: 
		  //専用の例外クラスへのポインタを例外送出
		  throw ZeroError();

        //それ以外が入力された場合
		default: 
		  //const char* 型へのポインタを例外送出
		  throw "不自然な値";
		}
	}
	//0が入力された場合の例外ハンドラ
	catch (ZeroError&) {

		//メッセージ表示
		cout << "0が入力されました。\n";
	}
	//それ以外の型へのポインタを受け取った場合
	catch (...) {

		//メッセージ表示
		cout << "0以外の値が入力されました。\n";
	}
}