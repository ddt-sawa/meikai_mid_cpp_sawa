/*演習12-5 要素型がdouble型で要素数が10である配列の全要素の値を読み書きするプログラムを作成せよ。*/

#include<iomanip>
#include<fstream>
#include<iostream>

using namespace std;

//問題の指定に従い配列の要素数を10とする
const int arraySize = 10;

/**
* 配列を作成し、要素として入力した値を外部ファイルに出力する
* @param arraySize 配列の要素数
* @author Sawa
* @since 8.21
*/
void getData(const int arraySize)
{
	//配列を作成
	double* inputArray = new double[arraySize]();

	//配列に代入する値
	double inputValue = 0;

	//外部ファイルにバイナリモードで出力を行うファイルストリームを定義
	ofstream outputFileStream("doubleFile.bin", ios_base::binary);

	//外部ファイルが開けない場合
	if (!outputFileStream) {

		//その旨を告知
		cout << "ファイルをオープンできません。\n";
	}
	//ファイルが開けた場合
	else {
		//入力用配列の全要素に値を代入するループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//値の入力を促す
			cout << "inputArray[" << firstCounter << "] = ";

			//値の入力
			cin >> inputValue;

			//値を代入
			inputArray[firstCounter] = inputValue;

			//値を外部ファイルに書き込む
			outputFileStream.write(reinterpret_cast<char*>(&inputArray[firstCounter]), sizeof(double));
		}
	}
	//配列を破棄
	delete[] inputArray;
}

/**
* 配列を作成し、外部ファイルの値を要素として取り込んだ後表示する
* @param arraySize 配列の要素数
* @author Sawa
* @since 8.21
*/
void printData(const int arraySize)
{
	//配列を作成
	double* outputArray = new double[arraySize];

	//外部ファイルをバイナリモードで読み込むファイルストリームを定義
	ifstream inputFileStream("doubleFile.bin", ios_base::binary);

	//外部ファイルが開けない場合
	if (!inputFileStream) {

		//その旨を告知
		cout << "ファイルをオープンできません。\n";
	}
	//開けた場合
	else {
		//外部ファイルの値を出力用配列に読み込むループ
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//値を読み込む
			inputFileStream.read(reinterpret_cast<char*>(&outputArray[firstCounter]), sizeof(double));

			//読み込んだ値を表示
			cout << "outputArray[" << firstCounter << "] = " << outputArray[firstCounter] << '\n';
		}
	}
	//配列を破棄
	delete[] outputArray;
}

int main()
{
	//配列を作成し、要素として入力した値を外部ファイルに出力する
	getData(arraySize);

	//配列を作成し、外部ファイルの値を要素として取り込んだ後表示する
	printData(arraySize);
}