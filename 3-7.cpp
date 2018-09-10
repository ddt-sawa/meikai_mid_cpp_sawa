/*演習3-7 qsort関数を用いて、以下の二つの配列を昇順にソートするプログラムを作成せよ。
char a[][7] = {"LISP", "C", "Ada", "Pascal"};
char* p[] = {"LISP", "C", "Ada", "Pascal"}
ソートを行う関数は、それぞれ独立した関数として実現すること。*/

//strcmp関数を使用するため、<cstring>ヘッダをインクルード
#include<cstring>
//qsort関数を使用するため、<cstdlib>ヘッダをインクルード
#include<cstdlib>
#include<iostream>

using namespace std;

//文字列数
const int arraySize = 4;

//文字列の要素数
const int stringLength = 7;

/**
* 第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する(二次元配列版)
* @param　firstArgument, secondArgument 文字列
* @return int型変数の値　
* @author Sawa
* @since 7.19
*/
int compareCharacter(const char* firstArgument, const char* secondArgument)
{
	//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
	return strcmp(firstArgument, secondArgument);
}

/**
* 第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する(ポインタ配列版)
* @param　firstArgument, secondArgument 文字列
* @return int型変数の値　
* @author Sawa
* @since 7.19
*/
int comparePointer(const char** firstArgument, const char** secondArgument)
{
	//第一引数と第二引数の値が等しければ0,第一引数のほうが大きければ正の整数値,第二引数のほうが大きければ負の整数値を返却する
	return strcmp(*firstArgument, *secondArgument);
}

/**
* 二次元配列文字列のソートを行い、表示する
* @param　inputString 二次元配列, arraySize 要素数
* @author Sawa
* @since 7.19
*/
void sortTwoDimensionArray(char inputString[][stringLength], int arraySize)
{
	//クイックソートを行う
	qsort(inputString, arraySize, sizeof(const char) * stringLength , reinterpret_cast<int(*)(const void*, const void*)>(compareCharacter));

	//ソートした二次元配列の行を参照するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//ソートした二次元配列の列を参照するループ
		for (int secondCounter = 0; inputString[firstCounter][secondCounter] != 0; ++secondCounter) {

			//参照文字を表示
			cout << inputString[firstCounter][secondCounter];
		}
		//参照行ごとに改行
		cout << '\n';
	}
}

/**
* 文字列へのポインタ配列のソートを行い、表示する
* @param　inputString 文字列へのポインタ配列, 配列の要素数 arraySize　
* @author Sawa
* @since 7.19
*/
void sortPointerArray(const char** inputString, int arraySize)
{
	//クイックソートを行う
	qsort(inputString, arraySize, sizeof(const char*), reinterpret_cast<int(*)(const void*, const void*)>(comparePointer));

	//ソートした二次元配列の行を参照するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//ソートした二次元配列の列を参照するループ
		for (int secondCounter = 0; inputString[firstCounter][secondCounter] != 0; ++secondCounter) {

			//参照文字を表示
			cout << inputString[firstCounter][secondCounter];
		}
		//参照行ごとに改行
		cout << '\n';
	}
}


int main()
{
	//二次元配列
	char firstString[arraySize][stringLength] = { "LISP", "C", "Ada", "Pascal" };

	//二次元配列のソートと表示を行う
	sortTwoDimensionArray(firstString, arraySize);

	//ポインタ配列版
	const char* secondString[arraySize] = { "LISP", "C", "Ada", "Pascal" };

	//ポインタ配列のソートと表示を行う
	sortPointerArray(secondString, arraySize);
}