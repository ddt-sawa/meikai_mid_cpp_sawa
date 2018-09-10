/*演習3-14　List3-13(p.116)に示したクラスPerson型の配列をクイックソートアルゴリズムによってソートするプログラムを作成せよ。
qsort関数を利用することなく実現すること。*/

#ifndef ___QuickSort
#define ___QuickSort

#include<iostream>

//個人情報を格納するPersonClassクラスを定義
class PersonClass {

public:

	/**
	* PersonClass型オブジェクトを初期化するコンストラクタ
	* @param inputName 名前, inputHeight 身長, inputWeight 体重
	* @return
	* @author Sawa
	* @since 7.30
	*/
	PersonClass(const char* inputName, int inputHeight, int inputWeight) : personClassName(inputName), personClassHeight(inputHeight), personClassWeight(inputWeight) {}

	/**
	* PersonClass型オブジェクトの名前を取得するゲッタ
	* @return personClassName 名前
	* @author Sawa
	* @since 7.30
	*/
	const char* getName() const { return personClassName; }

	/**
	* PersonClass型オブジェクトの身長を取得するゲッタ
	* @return personClassHeight 身長
	* @author Sawa
	* @since 7.30
	*/
	int getHeight() const { return personClassHeight; }

	/**
	* PersonClass型オブジェクトの体重を取得するゲッタ
	* @return personClassWeight 体重
	* @author Sawa
	* @since 7.30
	*/
	int getWeight() const { return personClassWeight; }

private:

	const char* personClassName;   //名前
	int personClassHeight;         //身長
	int personClassWeight;         //体重
};

#endif