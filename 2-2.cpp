/*演習2-2 符号無し整数xの全ビットを右にnビット回転した値を返す関数rrotateと、
* 左にnビット回転した値を返す関数lrotateを作成せよ。
* unsigned rrotate(unsigned x, int n);
* unsigned lrotate(unsigned x, int n);
*
* 回転とは、最下位ビットと最上位ビットが繋がっているとみなしてシフトをすることである。
* 例えば、右に5ビット回転した場合は、シフトによって弾き出されることになる下位5ビットを上位にもってこなければならない。
*/

#include<climits>
#include<iostream>

using namespace std;

//最下位ビットのみが1であるunsigned int型定数
unsigned int leastSignificantBit = 1;

/**
* 使用処理系における最上位ビットのみが1であるunsigned型の値を返却
* @return unsignde型の値　最上位ビットのみ1
* @author Sawa
* @since 7.27
*/
unsigned getBIT_MAX() {

	//返却する値を1で初期化
	unsigned int mostSignificantBit = leastSignificantBit;

	//最下位ビットの値が最上位ビットになるまで値に2を掛けるループ
	for (int firstCounter = 0; firstCounter < numeric_limits<unsigned int>::digits - 1; ++firstCounter) {

		//値に2を掛ける
		mostSignificantBit *= 2;
	}

	//最上位ビットのみが1である値を返却
	return mostSignificantBit;
}

/**
* 整数値を右にnビット回転した値を返却
* @param integerValue 整数値 rotationNumber nの値
* @return 回転後の値
* @author Sawa
* @since 7.27
*/
unsigned rotateRight(unsigned integerValue, int rotationNumber)
{
	//ビット回転を行うループ
	for (int firstCounter = 0; firstCounter < rotationNumber; ++firstCounter) {

		//最下位ビットが1の場合
		if (integerValue & 1U) {

			//右にシフトを行う
			integerValue >>= 1;

			//最上位ビットの値を1にする
			integerValue += getBIT_MAX();
		}

		//最下位ビットが0の場合
		else {

			//右にシフトを行う
			integerValue >>= 1;
		}
	}
	//回転後の値を返却
	return integerValue;
}

/**
* 整数値を左にnビット回転した値を返却
* @param integerValue 整数値 rotationNumber nの値
* @return 回転後の値
* @author Sawa
* @since 7.27
*/
unsigned rotateLeft(unsigned integerValue, int rotationNumber)
{
	//ビット回転を行うループ
	for (int firstCounter = 0; firstCounter < rotationNumber; ++firstCounter) {

		//最上位ビットが1の場合
		if (integerValue & getBIT_MAX()) {

			//左にシフトを行う
			integerValue <<= 1;

			//最下位ビットを1にする
			integerValue += 1U;
		}

		//最上位ビットが0の場合
		else {

			//左にシフトを行う
			integerValue <<= 1;
		}
	}
	//回転後の値を返却
	return integerValue;
}

int main()
{
	//表示する値の概要を告知
	cout << "入力した符号無し整数値を右にnビット回転した値を表示します。";

	//ビット回転したい整数
	unsigned integerValue;

	//符号無し整数値の入力告知
	cout << "符号無し整数値 : ";

	//入力
	cin >> integerValue;

	//何ビット右に回転させるかを示す整数
	int firstNumber;

	//入力を促す
	cout << "n : ";

	//入力
	cin >> firstNumber;

	//符号無し整数値を右にnビット回転した値を表示
	cout << "回転した値は" << rotateRight(integerValue, firstNumber) << "です。\n";

	//表示する値の概要を告知
	cout << "元の整数値を左にmビット回転した値を表示します。\n";

	//何ビット左に回転させるかを示す整数
	int secondNumber;

	//入力を促す
	cout << "m : ";

	//入力
	cin >> secondNumber;

	//符号無し整数値を左にnビット回転した値を表示
	cout << "回転した値は" << rotateLeft(integerValue, secondNumber) << "です。";
}
