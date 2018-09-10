/*演習3-6 bsearch関数を用いて、文字列の配列からの探索を行うプログラムを作成せよ。
2次元配列で実現された文字列の配列からの探索を行うプログラムと、文字列の先頭文字への
ポインタの配列で実現された文字列の配列からの探索を行うプログラムの二つを作ること。

b.文字列の先頭文字へのポインタの配列
*/


//strcmp関数を使用するため、<cstring>ヘッダをインクルード
#include<cstring>
//bsearch関数を使用するため、<cstdlib>ヘッダをインクルード
#include<cstdlib>
#include<iostream>

using namespace std;

/**
*　//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
* @param　firstArgument, secondArgument 文字列
* @return int型変数の値　
* @author Sawa
* @since 7.18
*/
int compareCharacter(const char* firstArgument, const char** secondArgument)
{
	//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
	return strcmp(firstArgument, *secondArgument);
}

//ポインタ配列の要素数
const int arraySize = 3;

//ポインタが指す文字列の、ナル文字を含めた要素数
const int stringSize = 4;


int main()
{
	//二次元配列に文字列を格納
	const char* inputString[stringSize] = { "AAA", "BBB", "CCC" };

	//一次元配列に文字列を格納
	const char* searchString = "CCC";

		//bsearch関数を用いて、ポインタ配列中の文字列と、探索する文字列を比較し、先頭要素へのポインタを受け取る
		char** searchPointer = (reinterpret_cast<char**>(bsearch(searchString, inputString, sizeof(inputString) / sizeof(inputString[0]), sizeof(char*),
			reinterpret_cast<int(*)(const void*, const void*)>(compareCharacter))));

		//文字列が見つかった場合
		if (searchPointer != NULL) {

			//文字列が格納されている二次元配列の先頭要素の添字を表示
			cout << "inputStirng[" << searchPointer - inputString << "]が一致します。";
		}
	}