/*演習9-10 キューを実現するクラステンプレートを作成せよ。キューは、FIFOすなわち先入れ先出し
(最初に入れたデータが最初に取り出される)の構造を持つ。
*/

#include<string>
#include<iostream>
#include"9-10_QueueClass.h"

using namespace std;

/**
* キューのポップ処理を司るテンプレート関数
* @param inputStack ポップしたいスタック
* @author Sawa
* @since 9.4
*/
template<class ClassType> void doPop(QueueClass<ClassType>& inputQueue)
{
	//ポップする要素数
	int poppedNumber = 0;

	//ポップする要素数の入力を促す
	cout << "ポップする要素数 : ";

	//要素数の入力
	cin >> poppedNumber;

	//キューから要素を指定数ぶんポップするループ
	for (int firstCounter = 0; firstCounter < poppedNumber; firstCounter++) {

		//要素をポップし、アンダーフローが起きた場合例外を送出
		char poppedElement = inputQueue.popValue();

		//ポップした要素を表示
		cout << poppedElement << '\n';
	}
}

int main()
{
	//文字列
	string inputString;

	//文字列の入力を促す
	cout << "文字列 : ";

	//文字列の入力
	cin >> inputString;

	//入力した文字列の長さを元にキューを作成
	QueueClass<char> sampleQueue(inputString.length());

	//例外を探知する
	try {
		//入力した文字列をキューにコピーするループ
		for (int firstCounter = 0; firstCounter < inputString.length(); firstCounter++) {

			//文字をキューに代入し、オーバーフローが起きた場合例外を送出
			sampleQueue.pushValue(inputString[firstCounter]);
		}
		//ポップを行う
		doPop(sampleQueue);

		//キューの容量を表示する
		cout << "キューの容量 : " << sampleQueue.getCapacity() << '\n';

		//頂上のデータを表示する。頂上のデータが無い場合例外を送出する
		cout << "頂上のデータ : " << sampleQueue.getPeekValue() << '\n';
	}
	//例外を補足した場合
	catch (const QueueClass<char>::QueueError& inputError) {

		//例外に応じたメッセージを返却
		inputError.returnMessage();
	}
}