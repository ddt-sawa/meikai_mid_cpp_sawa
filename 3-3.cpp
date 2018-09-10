/*演習3-3 指定された条件を満たす全要素を配列から線形探索する関数search_if_allを作成せよ。
int search_if(const int a[], int n, bool cond(int n), int** idx);
先頭側の三つの引数は前問と同様である。
指定された条件を満たす全要素の添字を格納するための配列を生成し、その配列の
先頭要素へのポインタを、第4引数idxの指すポインタに格納すること。なお、
関数が返却するのは、格納した要素数（条件を満たした要素数）である（例えば、
配列{1, 3, 6, 7, 8}から偶数である要素を探索した場合は、6と8の添字である{2,4}を格納する配列
を生成して2を返却する）。なお、条件を満たす要素が存在しない場合は、idxの指すポインタにNULLを
代入するとともに、0を返却すること。
*/

#include<iostream>

using namespace std;

/**
* 指定された条件を満たす全要素を配列から線形探索する
* @param intArray[] 配列, arraySize 要素数, activeFunction 条件を指定する関数へのポインタ, storePointer 条件を満たす要素を格納した配列の先頭要素へのポインタへのポインタ
* @return temporaryNumber 条件を満たす要素数
* @author Sawa
* @since 7.17
*/
int searchElement(const int intArray[], const int arraySize, bool activeFunction(int), int** storePointer)
{
	//条件を満たす要素を格納する配列bを宣言
	static int temporaryArray[100];

	//条件を満たす要素数を0で初期化
	int temporaryNumber = 0;

	//配列中の条件を満たす要素を配列bに格納するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//配列中に条件を満たす要素を確認した場合
		if (activeFunction(intArray[firstCounter])) {

			//配列bに格納し、条件を満たす要素数をインクリメントする
			temporaryArray[temporaryNumber++] = intArray[firstCounter];
		}

	}

	//条件を満たす要素が存在しない場合
	if (temporaryNumber == 0) {

		//引数として受け取ったポインタにNULLを代入
		*storePointer = NULL;
	}
	//条件を満たす要素が存在した場合
	else {
		//引数として受け取ったポインタに、配列bの先頭要素へのポインタを代入
		*storePointer = temporaryArray;
	}

	//要素数を返却
	return temporaryNumber;

}

/**
* 引数が30以上か調べる
* @param inputInteger 整数
* @return bool型の値
* @author Sawa
* @since 7.17
*/
bool searchOver30(const int inputInteger)
{
	//引数が30以上の場合
	if (inputInteger >= 30) {

		//trueを返却
		return true;
	}

	//30より小さい場合
	else {

		//falseを返却
		return false;
	}
}

/**
* 引数が5で割り切れるか調べる
* @param inputInteger 整数
* @return bool型の値
* @author Sawa
* @since 7.17
*/
bool searchDivisorof5(const int inputInteger)
{
	//引数が5で割り切れる場合
	if (inputInteger % 5 == 0) {

		//trueを返却
		return true;
	}
	//割り切れない場合
	else {

		//falseを返却
		return false;
	}
}

int main()
{
	//配列の要素数
	const int arraySize = 5;

	//配列の要素に値を代入
	int intArray[arraySize] = { 20, 70, 0, 100, 4 };

	//条件を満たす要素群を格納した配列を指すポインタ
	int* storePointer;

	//条件を満たす要素群を格納した配列の要素数
	int storeSize = searchElement(intArray, arraySize, searchOver30, &storePointer);

	//表示する値の説明
	cout << "配列内で30以上の値を持つ要素数は" << storeSize << "です。\n";

	//格納した要素を走査表示するループ
	for (int firstCounter = 0; firstCounter < storeSize; ++firstCounter) {

		//要素を表示
		cout << storePointer[firstCounter] << "\n";
	}
}