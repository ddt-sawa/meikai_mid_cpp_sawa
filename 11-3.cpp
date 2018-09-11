/*演習11-3 コマンドラインから与えられた文字列のソートやシャッフルなどを行うプログラムを作成せよ。*/

#include<string>
#include<iostream>
#include<vector>
//sort,random_shuffle関数を使用する
#include<algorithm>


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

/**
* 入力した文字列をベクトルに追加する
* @return inputVector ベクトル
* @author Sawa
* @since 9.7
*/
void pushString(vector<string>& inputVector)
{
	//文字列
	string inputString;

	//追加する文字列数
	int inputNumber = 0;

	//追加する文字列数の入力を促す
	cout << "ベクトルに追加する文字列数 : ";

	//ベクトルに追加する文字列数を入力させるループ
	do {
		//文字列数を入力
		cin >> inputNumber;

		//入力値が負なら再試行
	} while (inputNumber < 0);

	//文字列を指定回数ぶん入力させ、ベクトルに追加するループ
	for (int firstCounter = 0; firstCounter < inputNumber; ++firstCounter) {

		//文字列の入力を促す
		cout << "文字列 : ";

		//文字列を入力
		cin >> inputString;

		//入力した文字列をベクトルに追加
		inputVector.push_back(inputString);
	}
}


int main()
{
	//文字列ベクトル
	vector<string> stringVector;

	//ベクトルに文字列を追加
	pushString(stringVector);

	//入力した文字列群を昇順ソート
	sort(stringVector.begin(), stringVector.end());

	//ソートした文字列群を表示
	putStringVector(stringVector);

	//入力した文字列をシャッフル
	random_shuffle(stringVector.begin(), stringVector.end());

	//シャッフルした文字列群を表示
	putStringVector(stringVector);
}
