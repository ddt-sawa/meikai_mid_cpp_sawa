/*演習3-1 List3-2(p.91)は、『良』の識別表示と『優または可』の識別表示を行うプログラムであった。
これら以外の条件でも識別表示するように変更したプログラムを作成せよ。*/

#include<iostream>

//rand関数を使うので、<ctime><cstdlib>ヘッダをインクルード
#include<ctime>
#include<cstdlib>

using namespace std;

//成績リストの数
const int listNumber = 10;

/**
* 成績が優・可の場合trueを返す
* @param userScore 成績
* @author Sawa
* @since 9.5
*/

bool checkAorC(int userScore){	return (userScore >= 80 && userScore <= 100) || (userScore >= 60 && userScore <= 69);}


/**
* 成績が良の場合trueを返す
* @param userScore 成績
* @author Sawa
* @since 9.5
*/
bool checkB(int userScore) {return (userScore >= 70 && userScore <= 79);}


/**
* 成績が不可の場合trueを返す
* @param userScore 成績
* @return
* @author Sawa
* @since 9.5
*/
bool checkD(int userScore){	return (userScore >= 0 && userScore <= 59);}


/**
* 特定の成績に星を付けて表記する
* @param intArray 成績リスト, arraySize 成績の数, activeFunction 星をつける成績を判断する
* @author Sawa
* @since 9.5
*/
void putList(const int intArray[], int arraySize, bool activeFunction(int))
{
	//成績リストを走査するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter)
	{
		//成績が条件に合っていた場合
		if (activeFunction(intArray[firstCounter])) {

			//文頭に星を付ける
			cout << "★";
		}
		//条件に合っていなかった場合
		else {
			
			//空白文字を付ける
			cout << "　";
		}
		//成績を表示
		cout << "a[" << firstCounter << "] = " << intArray[firstCounter] << '\n';
	}
	
}

int main()
{
	//成績リスト
	int intArray[listNumber];

	//成績の数
	int arraySize = sizeof(intArray) / sizeof(intArray[0]);

	//乱数テーブルの準備
	srand(time(NULL));

	//全成績の値を入力するループ
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//0-100までの乱数を成績として出力
		intArray[firstCounter] = rand() % 101;
	}

	//優・可に星をつけて表示することを告知
	cout << "優または可_______\n";

	//優・可に星をつけて表示
	putList(intArray, arraySize, checkAorC);

	//良に星をつけて表示することを告知
	cout << "良_______________\n";

	//良に星をつけて表示
	putList(intArray, arraySize, checkB);

	//可に星をつけて表示することを告知
	cout << "不可_____________\n";

	//可に星をつけて表示
	putList(intArray, arraySize, checkD);

}