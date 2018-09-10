/*演習2-5 符号無し整数xの全ビットを1と0とで表した文字列
* (例えばunsigned型が16ビットで値が43690であればナル文字を含めた17文字の文字列"1010101010101010"、
* またunsigned型が32ビットであればナル文字を含めた33文字の文字列)を作成し、その文字列の先頭文字を返却する関数を作成せよ。
* const char* bits_of(unsigned x);
* なお文字列の格納先は、静的記憶域期間を持つ配列とすること。
* さらに、この関数を利用するように、List2-1(p.51)を書き換えたプログラムを作成せよ。
*/

//numeric_limits関数を使用する
#include<limits>
#include<iostream>

using namespace std;

//最下位ビットのみが1の符号なし整数
const unsigned int leastBit = 1;

//unsigend int型のビット数
const int unsignedDigits = numeric_limits<unsigned int>::digits;

/**
* 符号無し整数を受け取り、その全ビットを1と0で表した文字列を作成し、先頭文字へのポインタを返却する
* @param integerValue ビット表示したい整数
* @return returnString ビット表示した文字列の先頭文字へのポインタ
* @author sawa
* @since 7/13
*/
const char* stringizeUnsignedInteger(unsigned integerValue)
{
	//全ビット+ナル文字を格納する配列を生成
	static char returnString[unsignedDigits + 1] = {0};

	//全ビットの並びを文字配列に変換するループ文
	for (int firstCounter = 0; firstCounter < unsignedDigits; ++firstCounter) {

		//符号無し整数をシフトしたビットの値が1だった場合
		if ((integerValue >> firstCounter) & leastBit) {

			//シフト回数と反対側の要素に'1'を代入
			returnString[unsignedDigits - 1 - firstCounter] = '1';
		}
		//符号無し整数をシフトしたビットの値が0だった場合
		else {

			//シフト回数と逆順の要素に'0'を代入
			returnString[unsignedDigits - 1 - firstCounter] = '0';
		}
	}
	//先頭文字へのポインタを返却
	return returnString;
}

//List2-1を書き換える
int main()
{
	//ビット表示したい符号無し整数a
	unsigned firstValue;

	//ビット表示したい符号無し整数b
	unsigned secondValue;

    //両整数の入力を促す
	cout << "非負の整数を二つ入力せよ。\n";

	//整数aの入力
	cin >> firstValue;

	//整数bの入力
	cin >> secondValue;

	cout << "a =     " << stringizeUnsignedInteger(firstValue) << '\n';    //整数a

	cout << "b =     " << stringizeUnsignedInteger(secondValue) << '\n';   //整数b

	cout << "a & b = " << stringizeUnsignedInteger(firstValue & secondValue) << '\n';   //論理積

	cout << "a | b = " << stringizeUnsignedInteger(firstValue | secondValue) << '\n';   //論理積

	cout << "a ^ b = " << stringizeUnsignedInteger(firstValue ^ secondValue) << '\n';   //論理差

	cout << "~a =    " << stringizeUnsignedInteger(~firstValue) << '\n';   //整数aにおける1の補数

	cout << "~b =    " << stringizeUnsignedInteger(~secondValue) << '\n';   //整数bにおける1の補数
}
