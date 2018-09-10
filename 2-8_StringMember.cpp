
//stringクラステンプレートを使用する
#include<string>
//出力ストリームへの操作を行う
#include<sstream>
#include<iostream>
#include"2-8_BitSetClass.h"

using namespace std;

/**
* BitSetクラスの要素を｛｝で囲んだ文字列表現で返却する
* @return string型文字列
* @author Sawa
* @since  7.13
*/
string getString(const BitSet inputSet)
{
	//文字列出力ストリームを宣言
	ostringstream inputString;

	//集合に含まれる要素
	 int* vectorElements = new int[inputSet.getUpperLimit() - inputSet.getLowerLimit() + 1];

	//要素数を初期化
	int elementNumber = 0;

	//集合配列の全要素を参照するループ
	for (int firstCounter = 0; firstCounter < inputSet.getArraySize(); ++firstCounter) {

		//各集合配列の要素を走査し、含まれる要素と要素数を調べるループ
		for (int secondCounter = 0; secondCounter < LONGBIT; ++secondCounter) {

			//ある要素が含まれていた場合
			if ((inputSet.getBitPointer()[firstCounter] >> secondCounter) & theLowestBit) {

				//その要素の値を配列に保存し、要素数カウンタを一つ増やす
				vectorElements[elementNumber++] = LONGBIT * firstCounter + secondCounter + inputSet.getLowerLimit();
			}
		}
	}

	//要素を囲む'｛'を表示
	inputString << "{";

	//要素数が0ではなかった場合
	if (elementNumber != 0) {

		//要素を{}内に表示するループ
		for (int firstCounter = 0; firstCounter < elementNumber - 1; ++firstCounter) {

			//検出した要素を出力ストリームに挿入し、,を打つ
			inputString << vectorElements[firstCounter] << ", ";
		}
		//最後尾の要素は,なしで表示
		inputString << vectorElements[elementNumber - 1];
	}
	//要素を囲む'}'を表示
	inputString << "}";

	//動的確保した配列を開放
	delete[] vectorElements;

	//出力ストリーム内を文字表現にしたデータを返却
	return inputString.str();
}

/**
* BitSetクラスに挿入子<<を適用できるようにする演算子関数
* @param inputString 出力ストリーム, inputSet BitSetクラス
* @return string型文字列
* @author Sawa
* @since  7.13
*/
ostream& operator<<(std::ostream& inputString, const BitSet& inputSet)
{
	//BitSetクラスの集合の全要素を{}付きの文字列にしたものを返却
	return inputString << getString(inputSet);
}
