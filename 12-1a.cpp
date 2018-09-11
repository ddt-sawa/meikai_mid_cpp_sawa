/*演習12-1 List12-2の網掛け部を、本文で示した別実現例1および2に置き換えたプログラムを作成して、動作を検証せよ。
a.実現例1 return !fis.fail(); */

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
* 引数として受け取った名前のファイルがあるかどうかを返却する
* @param fileName 名前
* @return bool型の値
* @author Sawa
* @since 8.21
*/
bool checkFile(const char* fileName)
{
	//入力ストリームとしてファイルを開く
	ifstream fileStream(fileName);

	//ファイルが開けたかどうかをbool型の値で返却
	return !fileStream.fail();

}

int main()
{
	//ファイル名を宣言
	string fileName;

	//ファイルの名前の入力を促す
	cout << "存在を確認したいファイルの名前 : ";

	//ファイルの名前を入力
	cin >> fileName;

	//ファイルが存在するか否かを表示
	cout << "そのファイルは存在" << (checkFile(fileName.c_str()) ? "します。\n" : "しません。\n");
}