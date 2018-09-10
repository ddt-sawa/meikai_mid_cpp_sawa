/*演習2-8 以下の特徴を持つビットベクトルによる集合を実現するVecBitSet型を作成せよ。
・要素数はunsigned long型のビット数に制限されない。
・集合の下限値と上限値を任意の値に設定できる。
例えば、VecBitSet型の集合s1を10以上99以下の整数を表せる集合とするのであれば、
以下に示す方法で初期化できるように実現すること。
VecBitSet b1(10, 99);
もしもunsigned long型が32ビットであれば、呼び出されたコンストラクタは、10から99までの90種類を格納可能とするために、
要素数が3であるunsigned long型の配列setを動的に確保する。
そうすると、set[0]の各ビットは10～41までを、set[1]の各ビットは42～73までを、set[5](恐らくset[2]の誤植)のビットは74～99までを格納できる。
基本的な演算を行うための演算子関数を含め、メンバ関数を設計・作成すること。
*/

#include<iostream>
#include"2-8_BitSetClass.h"
#include"2-8_StringMember.cpp"

using namespace std;

int main()
{
	//検証用ビットベクトルAに代入する要素
	int firstArray[] = { 1, 20, 40, 70};

	//ビットベクトルAの下限値と上限値
	int firstLower = 3, firstUpper = 80;

	//検証用ビットベクトルAの作成
	BitSet firstVector(firstArray, sizeof(firstArray) / sizeof(firstArray[0]),firstLower, firstUpper); //{20,40,70}

	//検証用ビットベクトルBに代入する要素
	int secondArray[] = { 1, 40, 50, 90 };

	//ビットベクトルBの下限値を上限値
	int secondLower = 1, secondUpper = 100;

	//検証用ビットベクトルBの作成
	BitSet secondVector(secondArray, sizeof(secondArray) / sizeof(secondArray[0]), secondLower, secondUpper);//{1,40,50,90}

	//検証用ビットベクトルAのコピー
	BitSet temporaryVector = firstVector;


	//追加した①～⑪の関数における動作確認を行う(内は表示値)

	//①(40)
	cout << firstVector.getMinimumValue() << '\n';

	//②(70)
	cout << firstVector.getMaxValue() << '\n';

	//③({})
	temporaryVector.clearSet(); cout << temporaryVector << '\n';

	//④({1,40,50,90})
	firstVector.swapBit(secondVector); cout << firstVector << '\n';

	//⑤({20,40,70})
	swapBit(firstVector, secondVector); cout << firstVector << '\n';

	//⑥({1,20,50,70,90})
	cout << getSymmetricDifference(firstVector, secondVector) << '\n';

	//⑦({40})
	cout << (firstVector & secondVector) << '\n';

	//⑧({1,20,40,50,70,90})
	cout << (firstVector | secondVector) << '\n';

	//⑨({20})
	cout << (firstVector ^ secondVector) << '\n';

	//⑩(0)
	cout << firstVector.checkSubSet(secondVector) << '\n';

	//⑪(0)
	cout << firstVector.checkProperSubSet(secondVector) << '\n';

	//全関数の動作を確認
}