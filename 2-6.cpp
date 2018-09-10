/*演習問題 2-6 ここで学習した三つの型変換（同一ビットへの型変換・より長いビットへの型変換・より短いビットへの型変換)
* を確認できるプログラムを作成せよ。変換前後の値とビット構成を表示すること。
*
* a.同一ビットへの型変換
*/

#include<iostream>
//numeric_limitsテンプレートを使用
#include<limits>

using namespace std;

//unsigned int型のビット数
const int unsignedIntegerBits = numeric_limits<unsigned int>::digits;

//unsigned intの最下位ビットのみが1の値
const unsigned int leastBit = 1;

int main()
{
	//同一ビットへの型変換(int型→unsigned int 型)を試すため、負のint型変数を適当に定義
	int integerValue = -500;

	//キャスト前の値を表示
	cout << "値は" << integerValue << '\n';

	//ビット構成を表示することを告知
	cout << "ビット構成は";

	//キャスト前のビット構成を表示するためのループ文
	for (int firstCounter = (unsignedIntegerBits - 1); firstCounter >= 0; --firstCounter) {

		//カウンタ変数分シフトを行い、該当ビットの値を表示
		cout << ((integerValue >> firstCounter) & leastBit ? '1' : '0');
	}
	//改行
	cout << '\n';

	//キャストして値を表示
	cout << "値は" << static_cast<unsigned int>(integerValue) << '\n';

	//キャスト後のビット構成を表示する告知
	cout << "ビット構成は";

	//キャスト後のビット構成を表示するためのループ文
	for (int firstCounter = (unsignedIntegerBits - 1); firstCounter >= 0; --firstCounter) {

		//カウンタ変数分シフトを行い、該当ビットの値を表示
		cout << ((static_cast<unsigned int>(integerValue) >> firstCounter) & leastBit ? '1' : '0');
	}
}

/*
キャスト前の値は-500
ビット配列は    11111111111111111111111000001100
キャスト後の値は4294966796
ビット配列は    11111111111111111111111000001100

ビットは変化しない
*/
