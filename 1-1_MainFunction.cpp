/*
* new1-1test.cpp
*
*  Created on: 2018/07/12
*      Author: ddt
*/

#include<iostream>
#include<string>
#include"1-1_Header.h"

using namespace std;

int main()
{
	//中野
	HumanClass TaroNakano("中野太郎", 173, 65);
	//森田
	const HumanClass KoujiMorita("森田孝司", 168, 71);

	//コンストラクタ初期化子によって初期化ができているかを確認
	cout << "TaroNakano = " << TaroNakano.getName() << "  " << TaroNakano.getHeight() << "cm  " << TaroNakano.getWeight() << "kg\n";

	//同上
	cout << "KoujiMorita = " << KoujiMorita.getName() << "  " << KoujiMorita.getHeight() << "cm  " << KoujiMorita.getWeight() << "kg\n";
}

//初期化を確認
