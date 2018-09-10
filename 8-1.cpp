/*演習8-1 左ページに示した、set_terminate関数によってexception_errorを登録する【a】を実際に含む
プログラムを作成して、動作の検証を行え。*/

#include<iostream>
//set_terminate関数を使用
#include<exception>
#include<cstdlib>

using namespace std;


/**
* terminate関数の挙動を変更する
* @author Sawa
* @since 8.3
*/
void exceptionError()
{
	//エラーの発生を告知
	cout << "例外関連のエラーが発生しました。\n";

	//強制終了
	abort();
}

int main()
{
	//適当な整数の値
	int integerValue = 0;

	//送出すべき例外が存在しない場合の挙動を変更する
	set_terminate(exceptionError);

	//送出すべき例外が存在しない例外を起こす
	throw integerValue;
}