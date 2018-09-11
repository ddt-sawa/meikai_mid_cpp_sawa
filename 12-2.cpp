/*演習12-2 List12-2の関数file_existでオープンするストリームをifstream型からofstream型に書き換えると、
オープンしたファイルの名前が全部消去されることを確認せよ。
なお、ファイル名入力の際に表示するのは、「存在を確認したいファイルの名前 : 」ではなくて、
「中身を空にしたいファイルの名前 : 」に変更すること。 */

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
	//出力ストリームとしてファイルを開く
	ofstream fileStream(fileName);

	//ファイルが開けたかどうかをbool型の値で返却
	return !fileStream.fail();
}

int main()
{
	//ファイル名を宣言
	string fileName;

	//ファイルの名前の入力を促す
	cout << "中身を空にしたいファイルの名前 : ";

	//ファイルの名前を入力
	cin >> fileName;

	//ファイルが存在するか否かを表示
	cout << "そのファイルは存在" << (checkFile(fileName.c_str()) ? "します。\n" : "しません。\n");

	//中身が空になっていることを確認
}