/*演習2-3 符号なし整数xの第posビットを、1にした値を返す関数set、0にした値を返す関数set、反転した値を返す関数inverseを作成せよ。
unsigned set(unsigned x, int pos);
unsigned reset(unsigned x, int pos);
unsigned inverse(unsigned x, int pos);
*/

#include<iostream>

using namespace std;

//最下位ビットのみが1の符号なし整数
const unsigned int leastBit = 1;

//2進数における基数
const int binaryNumber = 2;

//unsigend int型のビット数
const int unsignedDigits = numeric_limits<unsigned int>::digits;

/**
* 値のビット配列を表示する
* @param integerValue 値
* @author Sawa
* @since 7.27
*/
void printBit(unsigned int integerValue)
{
	//ビット配列を表示するループ
	for (int firstCounter = unsignedDigits - 1; firstCounter >= 0; --firstCounter) {

		//カウンタ変数ぶん右シフトした値が1だった場合'1'を、0だった場合'0'を表示する
		cout << ((integerValue >> firstCounter) & leastBit ? '1' : '0');
	}
	//改行
	cout << '\n';
}

/**
* 第nビットのみが1である値を返却する
* @param bitPosition nの値
* @return　oneBit 第nビットのみが1である値
* @author Sawa
* @since 7.27
*/
unsigned getOneBit(int bitPosition) {

	//第nビットのみが1である値
	unsigned int oneBit = 1;

	//nの値が適切な場合
	if (bitPosition >= 0 && bitPosition <= unsignedDigits - 1) {

		//最下位ビットが第nビットに移動するまで値に進数の基数を乗算するループ
		for (int firstCounter = 0; firstCounter < bitPosition; ++firstCounter) {

			//基数を乗算(2)
			oneBit *= binaryNumber;
		}
	}
	//nの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//第nビットのみが1である値を返却
	return oneBit;
}

/**
* 値の第nビットを1にして返却
* @param integerValue 値, bitPosition nの値
* @return　integerValue 第nビットを1にした値
* @author Sawa
* @since 7.27
*/
unsigned int setBit(unsigned int integerValue, int bitPosition)
{
	//nの値が適切な場合
	if (bitPosition >= 0 && bitPosition <= unsignedDigits - 1) {

		//引数に第nビットのみが1である整数を論理和代入
		integerValue |= getOneBit(bitPosition);
	}
	//nの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//第nビットを1にした値を返却
	return integerValue;
}

/**
* 値の第nビットを0にして返却
* @param integerValue 値, bitPosition nの値
* @return integerValue 第nビットを0にした値
* @author Sawa
* @since 7.27
*/
unsigned resetBit(unsigned integerValue, int bitPosition)
{
	//nの値が適切な場合
	if (bitPosition >= 0 && bitPosition <= unsignedDigits - 1) {

		//第nビットが1の場合
		if (integerValue >> (bitPosition) & leastBit) {

			//第nビットを0にする
			integerValue -= getOneBit(bitPosition);
		}
	}
	//nの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//値を返却
	return integerValue;
}

/**
* 値の第nビットを反転して返却
* @param integerValue 値, bitPosition nの値
* @return　integerValue 第nビットを反転した値
* @author Sawa
* @since 7.27
*/
unsigned inverseBit(unsigned integerValue, int bitPosition)
{
	//nの値が適切な場合
	if (bitPosition >= 0 && bitPosition <= unsignedDigits - 1) {

		//第nビットが1の場合
		if (integerValue >> (bitPosition) & leastBit) {

			//第nビットのみが1である値を減算代入
			integerValue -= getOneBit(bitPosition);
		}
		//第nビットが0の場合
		else {

			//第nビットのみが1である値を加算代入
			integerValue += getOneBit(bitPosition);
		}
	}
	//nの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//第nビットを反転した値を返却
	return integerValue;
}

int main()
{
	//表示する値の概要を告知
	cout << "入力した符号無し整数値の第nビットを変化させた値を表示します。";

	//ビット回転したい整数
	unsigned integerValue = 0;

	//符号無し整数値の入力告知
	cout << "符号無し整数値 : ";

	//入力
	cin >> integerValue;

	//入力値のビット配列表示を告知
	cout << "その値のビット配列は : ";

	//ビット配列を表示
	printBit(integerValue);

	//何ビット目を変化させるかを表す整数
	int bitPosition = 0;

	//入力を促す
	cout << "n : ";

	//適切なビット数を参照するためのループ
	do {

		//入力
		cin >> bitPosition;

		//入力値が0より小さいまたはunsigend int型のビット数 - 1より大きい場合再入力
	} while (!(bitPosition >= 0 && bitPosition <= unsignedDigits - 1));

	//値の表示
	cout << "第nビットを1にした値は" << setBit(integerValue, bitPosition) << "です。\n";
	cout << "第nビットを0にした値は" << resetBit(integerValue, bitPosition) << "です。\n";
	cout << "第nビットを反転した値は" << inverseBit(integerValue, bitPosition) << "です。\n";

	//確認のためビット構成の表示
	printBit(setBit(integerValue, bitPosition));    //第nビットを1にしたビット構成
	printBit(resetBit(integerValue, bitPosition));  //第nビットを0にしたビット構成
	printBit(inverseBit(integerValue, bitPosition));//第nビットを反転したビット構成
}

