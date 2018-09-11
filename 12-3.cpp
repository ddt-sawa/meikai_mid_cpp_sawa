/*演習12-3 List12-7のプログラムにおける現在の日付・自国の取得を、第1章で作成したクラスDateを利用して
行うように変更したプログラムを作成せよ。*/

#include<fstream>
#include<iostream>
#include"12-3_DateClass.h"
#include"12-3_MemberDefinition.h"

using namespace std;

//参照するファイル名
char fileName[] = "lastTime.txt";

/**
* 前回プログラム実行時の日付・時刻を外部ファイルから取得し、コンソールに出力する
* @author Sawa
* @since 8.21
*/
void getDate()
{
	//"lastTime.txt"を入力ストリームとして開く
	ifstream fileStream(fileName);

	//ファイルが開けない(存在しない)場合
	if (fileStream.fail()) {

		//初回実行であることを表示
		cout << "本プログラムを実行するのは初めてですね。\n";
	}
	//ファイルが開けた場合
	else {

		//読み込む値を宣言
		int lastYear;  //年
		int lastMonth; //月
		int lastDay;   //日
		int lastHour;  //時
		int lastMinute;//分
		int lastSecond;//秒

		//値を読み込む
		fileStream >> lastYear >> lastMonth >> lastDay >>lastHour >> lastMinute >> lastSecond;

		//読みこんだ値を文字列表現にして表示
		cout << "前回は" << lastYear << "年" << lastMonth << "月" << lastDay << "日" << lastHour << "時" << lastMinute << "分" << lastSecond << "秒でした。\n";
	}
}

/**
* 第1章で作成したクラスDateを利用し、現在の日付・時刻を取得したうえで外部ファイルに書き込む
* @author Sawa
* @since 8.21
*/
void putDate()
{
	//"lastTime.txt"を出力ストリームとして開く。ファイルが存在しない場合は新規作成する。
	ofstream fileStream(fileName);

	//ファイルが開けなかった場合
	if (fileStream.fail()) {

		//その旨を告知
		cout << "ファイルをオープンできません。\n";
	}
	//ファイルが開けた場合
	else {
		//DateClass型デフォルトコンストラクタを利用して現在の日付を取得
        DateClass currentDate;

		//現在の時刻を取得
		time_t currentTime = time(NULL);

		//取得した時刻を格納する構造体を宣言
		struct tm exactTime;

		//取得した時刻を構造体に格納
		localtime_s(&exactTime, &currentTime);

		//要素ごとに空白を入れて外部ファイルに書き込む
		fileStream << currentDate << " " << exactTime.tm_hour << " " <<  exactTime.tm_min << " " << exactTime.tm_sec << '\n';
	}
}

int main()
{
	//前回プログラム実行時の日付・時刻を"lastTime.txt"から取得し、コンソールに出力する
	getDate();

	//現在の日付・時刻を取得したうえで"lastTime.txt"に書き込む
	putDate();
}
