/*演習11-2 関数テンプレートput_string_vectorでの文字列の走査を、[]演算子ではなく反復子を用いて行うよう書き換えたプログラムを作成せよ。*/

#include<string>
#include<vector>
#include<iostream>

using namespace std;

/**
* 反復子を用いて、文字列のベクトルを1文字ずつ走査表示する
* @param inputVector 文字列のベクトル
* @author Sawa
* @since 9.7
*/
template <typename ClassAllocator> void putStringVector(const vector<string, ClassAllocator>& inputVector)
{
	//表示する文字列群を格納する前括弧
	cout << "{ ";

	//文字列を、反復子を用いて走査表示するループ
	for (typename vector<string, ClassAllocator>::const_iterator firstCounter = inputVector.begin(); firstCounter != inputVector.end(); ++firstCounter) {

		//文字列ごとの前区切り
		cout << '"';

		//文字を反復子を用いて走査表示するループ
		for (string::const_iterator secondCounter = (*firstCounter).begin(); secondCounter != (*firstCounter).end(); ++secondCounter) {

			//文字を表示
			cout << *secondCounter;
		}
		//文字列ごとの後ろ区切り
		cout << "\" ";
	}
	//文字列群の後括弧
	cout << "}";

}

int main()
{
	//文字列を格納するベクトル
	vector<string> stringVector;

	//文字列A
	string firstString = "ABC";

	//文字列Aをベクトルに追加
	stringVector.push_back(firstString);

	//文字列B
	string secondString = "DEF";

	//文字列Bをベクトルに追加
	stringVector.push_back(secondString);

	//ベクトル内の文字列を表示
	putStringVector(stringVector);
}