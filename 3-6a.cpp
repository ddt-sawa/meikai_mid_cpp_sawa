/*演習3-6 bsearch関数を用いて、文字列の配列からの探索を行うプログラムを作成せよ。
2次元配列で実現された文字列の配列からの探索を行うプログラムと、文字列の先頭文字への
ポインタの配列で実現された文字列の配列からの探索を行うプログラムの二つを作ること。

a.2次元配列での文字列配列
*/


//strcmp関数を使用するため、<cstring>ヘッダをインクルード
#include<cstring>
#include<iostream>

using namespace std;

/**
*　//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
* @param　firstArgument, secondArgument 文字列
* @return int型変数の値　
* @author Sawa
* @since 7.18
*/
int compareCharacter(const char* firstArgument, const char* secondArgument)
{
	//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
	return strcmp(firstArgument, secondArgument);
}

int main()
{
	//二次元配列に文字列を格納
	char inputString[][4] = { "AAA", "BBB", "CCC" };

	//一次元配列に文字列を格納
	char searchString[] = "CCC";

	//bsearch関数を用いて、二次元配列中の一次元配列を探索し、先頭要素へのポインタを受け取る
	char* searchPointer = reinterpret_cast<char*>(bsearch(searchString, inputString,sizeof(inputString)/ sizeof(inputString[0]), sizeof(inputString[0])/sizeof(inputString[0][0]),
		reinterpret_cast<int(*)(const void*, const void*)>(compareCharacter)));

	//文字列が見つかった場合
	if (searchPointer != NULL) {
		//文字列が格納されている二次元配列の先頭要素の添字を表示
		cout << "inputStirng[" << (searchPointer - inputString[0]) / sizeof(inputString[0]) / sizeof(inputString[0][0]) << "]が一致します。";
	}
	//文字列が見つからなかった場合
	else {
		//見つからなかったことを告知
		cout << "見つかりませんでした。";
	}
}