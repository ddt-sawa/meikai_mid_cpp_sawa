/*演習12-1 List12-2の網掛け部を、本文で示した別実現例1および2に置き換えたプログラムを作成して、動作を検証せよ。
b.実現例2 return fis; */

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/**
* 引数として受け取った名前のファイルがあるかどうかを返却する
* @param fileName 名前
* @return booleanValue ファイルが存在するかどうか
* @author Sawa
* @since 8.21
*/
bool checkFile(const char* fileName)
{
	//ファイルが存在するかどうか
	bool booleanValue = true;

	//入力ストリームとしてファイルを開く
	ifstream fileStream(fileName);

	//ファイルを開けた場合
	if (fileStream) {

		//trueを返却
		booleanValue = true;
	}
	//開けなかった場合
	else {

		//falseを返却
		booleanValue = false;
	}
	//存在するかどうかを返却
	return booleanValue;
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