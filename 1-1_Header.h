/*
* new1-1.h
*
*  Created on: 2018/07/12
*      Author: ddt
*/

/*演習1-1 クラスHumanのコンストラクタを本ページに示したように書き換えたプログラムを作成し、
初期化が期待通りに行われることを確認せよ。*/


#ifndef ___NEW1_1_H_
#define ___NEW1_1_H_

#include<string>

//人間クラスHumanClass
class HumanClass {
public:

	//コンストラクタ
	HumanClass(const std::string& inputName, int inputHeight, int inputWeight);

	//名前のゲッタ
	std::string getName() const;

	//身長のゲッタ
	int getHeight() const;

	//体重のゲッタ
	int getWeight() const;

	//体重を増やす
	void increaseWeight(int plusHeight);

	//体重を減らす
	void decreaseWeight(int minusHeight);

private:
	std::string fullName;  //名前
	int userHeight;        //身長
	int userWeight;        //体重

};

#endif
