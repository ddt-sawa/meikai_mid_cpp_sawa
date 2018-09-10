/*演習2-4 符号無し整数xの第posビットから第pos + n - 1ビットまでのn個のビットを、
* 1にした値を返す関数set_n、0にした値を返す関数reset_n、反転した値を返す関数
* inverse_nを作成せよ。
*/

//numeric_limits関数を使用する
#include<limits>
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
* @param integerValue
* @author Sawa
* @since 7.27
*/
void printBit(unsigned integerValue)
{
	//ビット配列を表示するループ
	for (int firstCounter = unsignedDigits - 1; firstCounter >= 0; --firstCounter) {

		//第nビットの値を表示する
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
		for (int firstCounter = 0; firstCounter <= bitPosition - 1 ; ++firstCounter) {

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
* 値の第nビットから上位方向にm個のビットを1にして返却
* @param integerValue 値, bitPosition nの値, changeNumber mの値
* @return　integerValue 第nビットから上位方向にm個のビットを1にした値
* @author Sawa
* @since 7.27
*/
unsigned setBit(unsigned integerValue, int bitPosition, int changeNumber)
{
	//n,mの値が適切な場合
	if ((bitPosition > 0 && bitPosition <= unsignedDigits - 1) && (changeNumber > 0 && changeNumber <= bitPosition)) {

		//値におけるm個のビットを修正するためのループ
		for (int firstCounter = 0; firstCounter < changeNumber; ++firstCounter) {

			//チェック中ビットの値が0だった場合
			if (!(integerValue >> (bitPosition + firstCounter)) & leastBit) {

				//値にチェック中ビットのみが1である値を加算代入
				integerValue += getOneBit(bitPosition + firstCounter);
			}
		}
	}
	//n,mの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//値を返却
	return integerValue;
}

/**
* 値の第nビットから上位方向にm個のビットを0にして返却
* @param integerValue 値, bitPosition nの値, changeNumber mの値
* @return　第nビットから上位方向にm個のビットを0にした値
* @author Sawa
* @since 7.27
*/
unsigned resetBit(unsigned integerValue, int bitPosition, int changeNumber)
{
	//n,mの値が適切な場合
	if ((bitPosition >= 0 && bitPosition <= unsignedDigits - 1) || (changeNumber > 0 && changeNumber <= bitPosition)) {

		//値におけるm個のビットを修正するためのループ
		for (int firstCounter = 0; firstCounter < changeNumber; ++firstCounter) {

			//チェック中ビットの値が1だった場合
			if (integerValue >> (bitPosition + firstCounter) & leastBit) {

				//値にチェック中ビットのみが1である値を減算代入
				integerValue -= getOneBit(bitPosition + firstCounter);
			}
		}
	}
	//n,mの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//値を返却
	return integerValue;
}

/**
* 値の第nビットから上位方向にm個のビットを反転して返却
* @param integerValue 値, bitPosition nの値, changeNumber mの値
* @return　第nビットから上位方向にm個のビットを反転した値
* @author Sawa
* @since 7.27
*/
unsigned inverseBit(unsigned integerValue, int bitPosition, int changeNumber)
{
	//n,mの値が適切な場合
	if ((bitPosition >= 0 && bitPosition <= unsignedDigits - 1) || (changeNumber > 0 && changeNumber <= bitPosition)) {

		//値におけるm個のビットを修正するためのループ
		for (int firstCounter = 0; firstCounter < changeNumber; ++firstCounter) {

			//チェック中ビットの値が1だった場合
			if (integerValue >> (bitPosition + firstCounter - 1) & leastBit) {

				//値にチェック中ビットのみが1である値を減算代入
				integerValue -= getOneBit(bitPosition + firstCounter);
			}
			//チェック中ビットの値が0だった場合
			else {

				//値にチェック中ビットのみが1である値を加算代入
				integerValue += getOneBit(bitPosition + firstCounter);
			}
		}
	}
	//n,mの値が不適切な場合
	else {

		//例外処理を告知
		cout << "変更ビットの参照が不適切です。入力値をそのまま返却します。\n";
	}
	//値を返却
	return integerValue;
}

int main()
{
	//表示する値の概要を告知
	cout << "入力した符号無し整数値の第nビットから、上位方向にm個のビットを変化させた値を表示します。\n";

	//ビット回転したい整数
	unsigned integerValue = 0;

	//符号無し整数値の入力告知
	cout << "符号無し整数値 : ";

	//入力
	cin >> integerValue;

	//何ビット目を基準にするかを表す整数
	int bitPosition = 0;

	//入力を促す
	cout << "n : ";

	//適切なビットを基準とするためのループ
	do {
		//入力
		cin >> bitPosition;

		//入力値が0より小さいまたはunsigend int型のビット数より大きい場合再入力
	} while (!(bitPosition >= 0 && bitPosition <= unsignedDigits - 1));

	//何個ビットを変化させるかを表す整数
	int changeNumber = 0;

	//入力を促す
	cout << "m : ";

	//適切なビット個数を変化させるためのループ
	do {
		//入力
		cin >> changeNumber;

		//入力値が0以下または基準値より大きい場合再入力
	} while (!(changeNumber > 0 && changeNumber <= bitPosition));

	//ビット構成の表示
	printBit(integerValue);

	//値の表示
	cout << "参照ビットを1にした値は" << setBit(integerValue, bitPosition, changeNumber) << "です。\n";
	cout << "参照ビットを0にした値は" << resetBit(integerValue, bitPosition, changeNumber) << "です。\n";
	cout << "参照ビットを反転した値は" << inverseBit(integerValue, bitPosition, changeNumber) << "です。\n";

	//ビット構成の表示
	printBit(setBit(integerValue, bitPosition, changeNumber));    //ビットを1にしたビット構成
	printBit(resetBit(integerValue, bitPosition, changeNumber));  //ビットを0にしたビット構成
	printBit(inverseBit(integerValue, bitPosition, changeNumber));//反転したビット構成
}