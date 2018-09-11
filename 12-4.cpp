/*演習12-4 List12-7のプログラムに、現在の"気分"を表す文字列を追加したプログラムを作成せよ。
すなわち、前回の時刻(と前回の気分)を表示した後に、『現在の気分は : 』と入力を促してキーボードから文字列を読み込んで、ファイルに書き込む 。
例えば、"最高!!"と入力した場合、次回に実行したときは、『前回は9999年99月99日99時99分99秒で、気分は最高!!でした。』と表示すること。*/

#include<string>
#include<fstream>
#include<iostream>
#include<ctime>

using namespace std;

//参照するファイル名
char fileName[] = "lastTime.txt";

/**
* 前回プログラム実行時の日付・時刻・気分を外部ファイルから取得し、コンソールに出力する
* @author Sawa
* @since 8.21
*/
void getDate()
{
	//外部ファイルを入力ストリームとして開く
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
		string lastFeelings; //気分

		//値を読み込む
		fileStream >> lastYear >> lastMonth >> lastDay >> lastHour >> lastMinute >> lastSecond >> lastFeelings;

		//読みこんだ値を文字列表現にして表示
		cout << "前回は" << lastYear << "年" << lastMonth << "月" << lastDay << "日" << lastHour << "時" << lastMinute << "分" << lastSecond << "秒で、気分は" << lastFeelings << "でした。\n";
	}
}

/**
* 現在の日付・時刻・気分を取得したうえで外部ファイルに書き込む
* @author Sawa
* @since 8.21
*/
void putDate()
{
	//外部ファイルを出力ストリームとして開く。ファイルが存在しない場合は新規作成する。
	ofstream fileStream(fileName);

	//ファイルが開けなかった場合
	if (fileStream.fail()) {

		//その旨を告知
		cout << "ファイルをオープンできません。\n";
	}
	//ファイルが開けた場合
	else {

		//現在の時刻を取得
		time_t currentTime = time(NULL);

		//取得した時刻を格納する構造体を宣言
		struct tm exactTime;

		//取得した時刻を構造体に格納
		localtime_s(&exactTime, &currentTime);

		//要素ごとに空白を入れて外部ファイルに書き込む
		fileStream << exactTime.tm_year + 1900 << " " << exactTime.tm_mon + 1 << " " << exactTime.tm_mday << " " << exactTime.tm_hour << " " << exactTime.tm_min << " " << exactTime.tm_sec << '\n';

		//現在の気分
		string currentFeelings;

		//気分の入力を促す
		cout << "現在の気分は : ";

		//入力
		cin >> currentFeelings;

		//入力された気分を外部ファイルに書き込む
		fileStream << currentFeelings;
	}
}

int main()
{
	//前回プログラム実行時の日付・時刻を外部ファイルから取得し、コンソールに出力する
	getDate();

	//現在の日付・時刻を取得したうえで外部ファイルに書き込む
	putDate();
}
