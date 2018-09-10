/*演習3-2 指定された条件を満たす要素を配列から線形探索する関数search_ifを作成せよ。
int search_if(const int a[], int n, bool cond(int n ));
第一引数aは探索対称の配列であり、第二引数nは要素数である。第三引数condには、
条件を満たすかどうかの判定を行うための関数へのポインタを受け取る。
条件を満たす要素のうち、最も先頭側の要素の添字を返却すること。ただし、探索に失敗した
場合には-1を返却するものとする。
※この関数は、例えば『15以上30以下の要素の探索』『5で割り切れる要素の探索』といった、
任意の条件での探索を可能とする*/

#include<iostream>

using namespace std;

//配列の要素数
const int arraySize = 5;

/**
* 指定された条件を満たす要素を配列から線形探索する
* @param intArray[] 配列, arraySize 要素数, activeFunction 条件を指定する関数へのポインタ
* @return int型の値 条件を満たす要素のうち、最も先頭にある要素の添字
* @author Sawa
* @since 7.17
*/
int searchElement(const int intArray[], const int arraySize, bool activeFunction(int))
{
	//返却する値
	int firstIndex = 1;

	//配列内に条件を満たす要素があるかどうかを走査するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//条件を満たす要素を確認した場合
		if (activeFunction(intArray[firstCounter])) {

			//添字を返却値に代入
			 firstIndex = firstCounter;

			//ループを抜ける
			break;
		}
	}
	//返却
	return firstIndex;
}

/**
* 引数が30以上か調べる
* @param inputInteger 整数
* @return booleanValue 命題の真理値
* @author Sawa
* @since 7.17
*/
bool searchOver30(const int inputInteger)
{
	//命題の真理値
	bool booleanValue;

	//引数が30以上の場合
	if (inputInteger >= 30) {

		//命題は真
		booleanValue = true;
	}
	//30より小さい場合
	else {

		//命題は偽
		booleanValue = false;
	}
	//命題の真理値を返却
	return booleanValue;
}

/**
* 引数が5で割り切れるかどうか調べる
* @param inputInteger 整数
* @return booleanValue 命題の真理値
* @author Sawa
* @since 7.17
*/
bool searchDivisorof5(const int inputInteger)
{
	//引数が5で割り切れるかどうか
	bool booleanValue;

	//引数が5で割り切れる場合
	if (inputInteger % 5 == 0) {

		//命題は真
		booleanValue = true;
	}
	//割り切れない場合
	else {

		//命題は偽
		booleanValue = false;
	}
	//命題の真理値を返却
	return booleanValue;
}

int main()
{
	//配列の要素に値を代入
	int intArray[arraySize] = { 20, 70, 0, 100, 4 };

	//表示する値の説明
	cout << "配列内で30以上の値を持つ、最も先頭の要素の添字は" << searchElement(intArray, arraySize, searchOver30) << "です。\n";

	//表示する値の説明
	cout << "配列内で5で割り切れる、最も先頭の要素の添字は" << searchElement(intArray, arraySize, searchDivisorof5) << "です。\n";
}
