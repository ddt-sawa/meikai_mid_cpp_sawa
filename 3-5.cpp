/*演習3-4 以下に示す形式の関数f(x)を、台形公式によって積分した値を返却する関数daikeiを作成せよ。
double f(double x);
図Aの網部分の面積を求める積分を、図Bに示すように、台形の集まりと考えることによって近似的に積分する
（すなわち、台形の面積の合計を積分値とする）のが台形公式である。

関数daikeiは以下の形式とする。
double daikei(double x1, double x2, int n, double fp(double));
引数x1とx2は積分区間の下限値と上限値であり、引数nは積分区間の分割数(図Bの例であれば7)
である。最後の引数fpは、積分の対象となる関数へのポインタである。
*/

#include<iostream>

using namespace std;


/**
* 計算元の関数として、3x^2 + 2x + 5に変数を代入した値を返却する
* @param doubleValue 変数
* @return double型の値
* @author Sawa
* @since 7.17
*/
double quadraticFunction(double doubleValue)
{
	//二次関数に変数を代入した値を返却
	return 3 * doubleValue * doubleValue + 2 * doubleValue + 5;
}

/**
* 台形公式により求めた積分面積の値を返却する
* @param lowerLimit 積分区間の下限値, upperLimit 積分区間の上限値, divisionNumber 積分区間の分割数, functionalPointer 関数へのポインタ
* @return integraArea 積分面積
* @author Sawa
* @since 7.17
*/
double getTrapezoid(double lowerLimit, double upperLimit, int divisionNumber, double functionalPointer(double))
{
	//積分区間の一区間幅((上限値 - 下限値)　/ 区関数)
	double divisionLength = (upperLimit - lowerLimit) / divisionNumber;

	//積分面積を0で初期化
	double integralArea = 0;

	//台形公式により積分面積を求める
	for (int firstCounter = 1; firstCounter < divisionNumber; ++firstCounter) {

		//台形公式によって求めた一区間分の面積を積分面積に加算代入
		integralArea += (divisionLength / 2 * (functionalPointer(lowerLimit + (firstCounter - 1) * divisionLength) + functionalPointer(lowerLimit + firstCounter * divisionLength)));
	}

	//積分面積を返却
	return integralArea;
}
int main()
{
	//表示する値の説明
	cout << "台形公式により、3x^2 + 2x + 5を積分した面積を表示します。\n";

	//積分区間の下限値
	double lowerLimit;

	//入力を促す
	cout << "積分下限値 : ";

	//入力
	cin >> lowerLimit;

	//積分区間の上限値
	double upperLimit;

	//入力を促す
	cout << "積分上限値 : ";

	//入力
	cin >> upperLimit;

	//積分区間の分割数
	int divisionNumber;

	//入力を促す
	cout << "積分区間の分割数 ";

	//入力
	cin >> divisionNumber;

	//積分面積を表示
	cout << getTrapezoid(lowerLimit, upperLimit, divisionNumber, quadraticFunction);
}