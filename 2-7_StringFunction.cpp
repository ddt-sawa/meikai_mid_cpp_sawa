/*
* new2-7.cpp
*
*  Created on: 2018/07/13
*      Author: ddt
*/

/*演習2-7 ビットベクトルによる集合クラスBitSetに対して、以下のメンバ関数を追加せよ。
* ・集合の最小要素の値(空集合であれば-1)を返却する関数min
* int min() const;
* ・集合の最大要素の値(空集合であれば-1)を返却する関数max
* int max() const;
* ・集合の全要素を削除して空集合化する関数clear
* void clear();
* ・集合を集合rと交換する(全要素を交換する)関数swap
* void swap(BitSet& r);
* ・集合s1とs2を交換する非メンバ関数swap
* void swap(BitSet& s1, BitSet& s2);
* 集合siとs2の対称差を求めて返却する関数symmetric_difference
* ※集合A,Bに対する対称差とは、A-B∩B-Aのことである。
* BitSet symmetric_difference(const BitSet& s1, const BitSet& s2);
* 集合s1とs2の積集合を求めて返却する演算子関数&
* BitSet Operator&(const BitSet& s1, const BitSet& s2);
* 集合s1とs2の和集合を求めて返却する演算子関数|
* BitSet Operator|(const BitSet& s1, const BitSet& s2);
* 集合s1とs2の和集合を求めて返却する演算子関数^
* BitSet Operator^(const BitSet& s1, const BitSet& s2);
* 集合がsの部分集合であるかどうかを判定する関数is_subset_of
* bool is_subset_of(const BitSet& s);
* 集合がsの真部分集合であるかどうかを判定する関数is_proper_subset_of
* bool is_proper_subset_of(const BitSet& s);
*/

//stringクラステンプレートを使用する
#include<string>
//出力ストリームへの操作を行う
#include<sstream>
#include<iostream>
#include"2-7_BitSetClass.h"

using namespace std;

/**
* BitSetクラスの要素を｛｝で囲んだ文字列表現で返却する
* @return string型文字列
* @author Sawa
* @since  7.13
*/
string BitSet::getString() const
{
	//文字列出力ストリームを宣言
	ostringstream inputString;

	//集合に含まれる要素
	int vectorElements[LONGBIT];

	//要素数を初期化
	int elementNumber = 0;

	//ビットベクトルを走査し、含まれる要素と要素数を調べるループ
	for (int firstCounter = 0; firstCounter < LONGBIT; ++firstCounter) {

		//ある要素が含まれていた場合
		if (bitVector & setElement(firstCounter)) {

			//その要素の値を配列に保存し、要素数カウンタを一つ増やす
			vectorElements[elementNumber++] = firstCounter;
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

	//出力ストリーム内を文字表現にしたデータを返却
	return inputString.str();
}

/**
* BitSetクラスの要素をビット構成の文字列で返却する
* @return string型文字列
* @author Sawa
* @since  7.13
*/
string BitSet::getBitString() const
{
	//ビット構成の文字列
	char printBit[LONGBIT + 1];

	//ビットベクトルの値をビット構成に変換するループ
	for (int firstCounter = 0; firstCounter < LONGBIT; ++firstCounter) {

		//走査中ビットの値が1だった場合'1'を、0だった場合'0'を配列に逆順代入する
		printBit[LONGBIT - firstCounter - 1] = (bitVector & setElement(firstCounter) ? '1' : '0');
	}
	//最下位ビットの次の値にナル文字を代入
	printBit[LONGBIT] = '\0';

	//ビット構成の文字列を返却
	return string(printBit);
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
	return inputString << inputSet.getString();
}
