/*演習6-3 じゃんけんの<プレーヤ>を表す抽象クラスを定義せよ。そのクラスから、以下のクラスを派生すること。
・人間プレーヤクラス(出す手をキーボードから読み込む)
・コンピュータプレーヤクラス(出す手を乱数で生成する)*/

#include<iostream>
#include"6-3_PlayerClass.h"
#include"6-3_ComputerClass.h"
#include"6-3_HumanClass.h"

using namespace std;


/**
* じゃんけんの勝敗を表示する
* @param humanHand 人間の手, computerHand コンピュータの手
* @author Sawa
* @since 8.1
*/
void judgeHands(int humanHand, int computerHand)
{
	//人間の手とコンピュータの手が等しい場合
	if (humanHand == computerHand) {

		//あいこであることを告知
		std::cout << "あいこです。";
	}

	//人間の手がコンピュータの手に勝った場合　
	else if ((humanHand != 0 && humanHand - 1 == computerHand) || (humanHand == 0 && computerHand == 2)) {

		//人間の勝利を告知
		std::cout << "あなたの勝ちです。";
	}

	//人間の手がコンピュータの手に負けた場合
	else {
		//人間の敗北を告知
		std::cout << "あなたの負けです。";
	}
}

int main()
{
	//人間クラスの初期化
	HumanClass yourHand;

	//コンピュータクラスの初期化
	ComputerClass computerHand;

	//人間クラスの手を表示
	yourHand.printHand();

	//コンピュータの手を表示
	computerHand.printHand();

	//改行
	cout << '\n';

	//勝敗を表示
	judgeHands(yourHand.getHand(), computerHand.getHand());
}