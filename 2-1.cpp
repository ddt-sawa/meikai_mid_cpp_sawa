/*演習2-1 符号なし整数を左右にシフトした値が、（オーバーフローしない限り）
* 2のべき乗での乗算や除算の演算結果と一致することを確認するプログラムを作成せよ。
*/

#include<iostream>

using namespace std;

/**
* 2のべき乗値を返却する。
* @param inputIndex 指数
* @return exponentialValue べき乗値
* @author Sawa
* @since 8.23
*/
double exponetateBinaryNumber(int inputIndex) {

	//べき乗を行う値(2)
	int binaryNumber = 2;

	//べき乗値
	unsigned exponentialValue = 1;

	//指数が0以上の場合
	if (inputIndex >= 0) {

		//値に指数ぶんべき乗を行うループ
		for (; inputIndex > 0; --inputIndex) {

			//べき乗値を計算する
			exponentialValue *= binaryNumber;
		}
	}
	else {

		//値に指数ぶんべき乗を行うループ
		for (; inputIndex < 0; ++inputIndex) {

			//べき乗値を計算する
			exponentialValue /= binaryNumber;
		}
	}
	//べき乗値を返却する
	return exponentialValue;
}

int main() {

	//計算元となる値
	unsigned int unsignedInteger = 0;

	//値の入力を促す
	cout << "計算元となる値 : ";

	//値の入力
	cin >> unsignedInteger;

	//指数(シフト数)
	int indexValue = 0;

	//指数の入力を促す
	cout << "【値をシフトする回数】および【2のべき乗値の指数】 : ";

	//指数に正の値を入力させるループ
	do {
		//指数の入力
		cin >> indexValue;

		//指数が負の場合再入力
	} while (indexValue < 0);

	//オーバーフローを起こさない場合
	if ((unsignedInteger * exponetateBinaryNumber(indexValue)) > unsignedInteger * exponetateBinaryNumber(indexValue - 1)) {

		//左シフトおよび乗算をした値の表示
		cout << "計算元となる値を" << indexValue << "回左シフトした値は" << (unsignedInteger << indexValue) << "で、2の" << indexValue << "乗を乗算した値は" << (unsignedInteger * exponetateBinaryNumber(indexValue)) << "です。\n";

	}
	//アンダーフローを起こさない場合
	if ((unsignedInteger >> indexValue) != 0) {

		//右シフトおよび除算をした値の表示
		cout << "計算元となる値を" << indexValue << "回右シフトした値は" << (unsignedInteger >> indexValue) << "で、2の" << indexValue << "乗を除算した値は" << (unsignedInteger / exponetateBinaryNumber(indexValue)) << "です。\n";

	}
}
