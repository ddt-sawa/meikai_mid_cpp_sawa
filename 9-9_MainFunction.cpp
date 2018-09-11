/*演習9-9 スタッククラステンプレートSimpleStack<>に、以下のメンバ関数を追加せよ。
Type& peek() 頂上のデータを削除することなく変えず。
int capacity() スタックの容量を返す。
bool is_full() スタックが満杯であるかどうかを返す。
bool is_empty() スタックが空であるかどうかを返す。
なお、例外が送出・捕捉されるような利用例のプログラムも併せて作ること。
*/

#include<string>
#include<iostream>
#include"9-9_StackClass.h"

using namespace std;

/**
* スタックのポップ処理を司るテンプレート関数
* @param inputStack ポップしたいスタック
* @author Sawa
* @since 9.4
*/
template<class ClassType> void doPop(StackClass<ClassType>& inputStack)
{
	//ポップする文字数
	int popNumber = 0;

	//ポップする文字数の入力を促す
	cout << "ポップする文字数 : ";

	//文字数の入力
	cin >> popNumber;

	//スタックから文字を指定数ぶんポップするループ
	for (int firstCounter = 0; firstCounter < popNumber; firstCounter++) {

		//文字をポップし、アンダーフローが起きた場合例外を送出
		char poppedValue = inputStack.popValue();

		//ポップした値を表示
		cout << poppedValue << '\n';
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

	//入力した文字列の長さを元にスタックを作成
	StackClass<char> sampleStack(inputString.length());

	//例外を探知する
	try {
		//入力した文字列をスタックにコピーするループ
		for (int firstCounter = 0; firstCounter < inputString.length(); firstCounter++) {

			//文字をスタックに代入し、オーバーフローが起きた場合例外を送出
			sampleStack.pushValue(inputString[firstCounter]);
		}
		//ポップを行う
		doPop(sampleStack);

		//スタックの容量を表示する
		cout << "スタックの容量 : " << sampleStack.getCapacity() << '\n';

		//頂上のデータを表示する。頂上のデータが無い場合例外を送出する
		cout << "頂上のデータ : " << sampleStack.getPeekValue() << '\n';
	}
	//例外を補足した場合
	catch (const StackClass<char>::StackError& inputError) {
		
		//例外に応じたメッセージを返却
		inputError.returnMessage();
	}
}