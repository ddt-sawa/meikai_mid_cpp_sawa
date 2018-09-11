/*演習11-1 本文では、string型のメンバ関数の一部のみを学習した。本文で学習していないメンバ関数を利用するプログラムを作成せよ。*/

#include<iostream>
#include<string>

using namespace std;

//何かしら整数値が必要になったときの引数
const int argumentNumber = 2;

//文字列を拡張する際のサイズ
const int extendedSize = 7;


//本文及び演習課題において登場しなかったメンバ関数の動作チェックを行う。多重定義されているものは逐一チェックしない
int main()
{
	//文字列A
	string testString = "ABCDE";

	//比較に使う文字列B
	string compareString = "FG";

	//最大のサイズ
	cout << testString.max_size() << '\n'; //2147483647

	//文字列を削除する
	testString.clear();

	//文字列が空であるかどうかを調べる
	cout << testString.empty() << '\n'; //1

	//文字列表示
	cout << testString << '\n'; //空

	//文字列サイズを変更し,拡張部分を'A'で埋め尽くす
	testString.resize(extendedSize, 'A');

	//文字列表示
	cout << testString << '\n'; //AAAAAAA

	//文字列に文字列Bを代入する
	cout << testString.assign(compareString) << '\n'; //FG

	//文字列中に文字列Bを挿入する
	cout << testString.insert(argumentNumber, compareString) << '\n'; //FGFG

	//文字列中の文字を削除する
	cout << testString.erase(argumentNumber) << '\n';//FG

	//文字列内に文字列Bが存在する場合、その末尾の添え字
	cout << testString.rfind(compareString) << '\n';//0

	//文字列内に文字列Bが持っている文字が存在する場合、その先頭の添字
	cout << testString.find_first_of(compareString) << '\n'; //0

	//文字列内に文字列Bが持っている文字が存在する場合、その末尾の添字
	cout << testString.find_last_of(compareString) << '\n'; //1

	//文字列内に文字列Bが持っていない文字がある場合、その先頭の添え字
	cout << testString.find_first_not_of(compareString) << '\n'; //不定値

	//文字列内に文字列Bが持っていない文字がある場合、その末尾の添え字
	cout << testString.find_last_not_of(compareString) << '\n';  //不定値

	//文字列を途中から表示する
	cout << testString.substr() << '\n'; //FG

}