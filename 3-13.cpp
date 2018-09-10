/*演習3-13 List3-19は、ユーザが年/月/日の中から選んだ値を当てさせる日付当てゲームであった。
年/月/日のすべてを、この順で当てさせるように変更したプログラムを作成せよ。
なお、すべての値が当たるまでは、プログラムは終了しないものとする。*/

#include<iostream>
#include"3-13.h"

using namespace std;

int main()
{
	//ゲッタに名前を付ける
	typedef int (DateClass::*getFunction) () const;

	//ゲッタを格納する
	getFunction currentGet[] = {
		&DateClass::getYear,    //年のゲッタ
		&DateClass::getMonth,   //月のゲッタ
		&DateClass::getDay      //日のゲッタ
	};

	//日付差を返却する関数ポインタ配列に名前を付ける
	typedef int (DateClass::*compareFunction) (int) const;

	//関数ポインタ配列に日付差を返す各メンバ関数を格納する
	compareFunction currentFunction[] = {
		&DateClass::compareYear,  //年数差
		&DateClass::compareMonth, //月数差
		&DateClass::compareDay    //日数差
	};

	//誕生日
	const DateClass myBirthday(1993, 7, 1);

	//ゲームの趣旨を説明
	cout << "私の誕生日を当ててください。\n";

	//回答を初期化
	int answerNumber = 0;

	//誕生年の正解が出るまで回答を続けるループ
	while (true) {

		//回答の入力を促す
		cout << "誕生年 : ";

		//回答入力
		cin >> answerNumber;

		//回答が正解より小さい場合
		if ((myBirthday.*currentGet[0])() > answerNumber) {

			//差分を告知
			cout << -(myBirthday.*currentFunction[0])(answerNumber) << "だけ小さいです。\n";
		}

		//回答が正解より大きい場合
		else if ((myBirthday.*currentGet[0])() < answerNumber) {

			//差分を告知
			cout << (myBirthday.*currentFunction[0])(answerNumber) << "だけ大きいです。\n";

		}
		//回答が正解だった場合
		else {

			//正解したことを告知
			cout << "正解です。\n";

			//ループを抜ける
			break;
		}
	}

	//誕生月の正解が出るまで回答を続けるループ
	while (true) {

		//回答の入力を促す
		cout << "誕生月 : ";

		//回答入力
		cin >> answerNumber;

		//回答が正解より小さい場合
		if ((myBirthday.*currentGet[1])() > answerNumber) {

			//差分を告知
			cout << -(myBirthday.*currentFunction[1])(answerNumber) << "だけ小さいです。\n";
		}

		//回答が正解より大きい場合
		else if ((myBirthday.*currentGet[1])() < answerNumber) {

			//差分を告知
			cout << (myBirthday.*currentFunction[1])(answerNumber) << "だけ大きいです。\n";

		}
		//回答が正解だった場合
		else {

			//正解したことを告知
			cout << "正解です。\n";

			//ループを抜ける
			break;
		}
	}

	//誕生日の正解が出るまで回答を続けるループ
	while (true) {

		//回答の入力を促す
		cout << "誕生日 : ";

		//回答入力
		cin >> answerNumber;

		//回答が正解より小さい場合
		if ((myBirthday.*currentGet[2])() > answerNumber) {

			//差分を告知
			cout << -(myBirthday.*currentFunction[2])(answerNumber) << "だけ小さいです。\n";
		}

		//回答が正解より大きい場合
		else if ((myBirthday.*currentGet[2])() < answerNumber) {

			//差分を告知
			cout << (myBirthday.*currentFunction[2])(answerNumber) << "だけ大きいです。\n";

		}
		//回答が正解だった場合
		else {

			//正解したことを告知
			cout << "正解です。\n";

			//ループを抜ける
			break;
		}
	}
}