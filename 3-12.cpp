/*演習3-12 qsort関数と同じ形式で呼び出すことのできる以下の関数を作成せよ。
void mergesort(void* baseArray, size_t arrayNumber, size_t objectSize, int(*comparisionFunction)(void*, void*));
マージソートのアルゴリズムを用いて安全なソートを行うものとする。
*マージソートのアルゴリズムは自分で調べること*/

#include<iostream>

using namespace std;

/**
* int型の比較関数
* @param firstIntger 整数A, secondInteger 整数B
* @return differenceValue 整数Aから整数Bを引いた値
* @author Sawa
* @since 9.5
*/
int compareInteger(const void* firstInteger, const void* secondInteger)
{
	//整数Aから整数Bを引いた値
	int differenceValue = 0;

	//整数Aから整数Bを引いた値を計算
	differenceValue = *reinterpret_cast<const int*>(firstInteger) - *reinterpret_cast<const int*>(secondInteger);

	//整数Aから整数Bを引いた値を返却
	return differenceValue;
}

/**
* 配列中の要素を昇順にソートする
* @param baseArray,配列 arraySize 配列の要素数, objectSize オブジェクトの大きさ, comparisionFunction 比較関数
* @author Sawa
* @since 7.19
*/
void doMergeSort(void* baseArray, size_t arraySize, size_t objectSize, int(*comparisionFunction)(const void*, const void*))
{
	//要素数が1つの場合、分割終了
	if (arraySize <= 1) { return; }

	//前方側配列の要素数
	int pivotElement = arraySize / 2;

	//後方側配列の要素数
	int lastElement = arraySize - arraySize / 2;

	//配列分割後、前方側にある要素を新たに格納する配列
	char* frontArray = new char[pivotElement * objectSize];

	//配列分割後、後方側にある要素を新たに格納する配列
	char* backArray = new char[lastElement * objectSize];

	//配列の先頭要素へのポインタ
	char* temporaryPointer = reinterpret_cast<char*>(baseArray);

	//元の配列の要素を分割後の前方配列に1バイトずつ代入するループ
	for (int firstCounter = 0; firstCounter < pivotElement * objectSize; ++firstCounter) {

		//代入
		frontArray[firstCounter] = temporaryPointer[firstCounter];
	}

	//元の配列の要素を分割後の後方配列に1バイトずつ代入するループ
	for (int firstCounter = 0; firstCounter < lastElement * objectSize; ++firstCounter) {

		//代入
		backArray[firstCounter] = temporaryPointer[(pivotElement * objectSize) + firstCounter];
	}

	//前方配列に関して再帰的関数呼び出し
	doMergeSort(frontArray, pivotElement, objectSize, comparisionFunction);

	//後方配列に関して再帰的関数呼び出し
	doMergeSort(backArray, lastElement, objectSize, comparisionFunction);

	//比較中の前方配列の添字
	int frontElement = 0;

	//比較中の後方配列の添字
	int backElement = 0;

	//分割した配列を、昇順に統合する
	do {

		//前方側配列の要素の値が後方配列の要素の値以下の場合
		if (comparisionFunction(&frontArray[frontElement * objectSize], &backArray[backElement * objectSize]) <= 0) {

			//前方側要素の全バイトを元配列に統合するループ
			for (int firstCounter = 0; firstCounter < objectSize; ++firstCounter) {

				//前方側要素を元配列の指定位置に並べる
				static_cast<char*>(baseArray)[(frontElement + backElement) * objectSize + firstCounter] = frontArray[frontElement * objectSize + firstCounter];
			}
			//次の前方側要素を検討する
			++frontElement;
		}
		//後方側配列の要素の値が前方側要素の値以下の場合
		else {

			//後方側要素の全バイトを元配列に統合するループ
			for (int firstCounter = 0; firstCounter < objectSize; ++firstCounter) {

				//後方側要素を元配列の指定位置に並べる
				static_cast<char*>(baseArray)[(frontElement + backElement) * objectSize + firstCounter] = backArray[backElement * objectSize + firstCounter];
			}
			//次の後方側要素を検討する
			++backElement;
		}
		//どちらかの配列の要素がなくなるまで並び替え
	} while (frontElement < pivotElement && backElement < lastElement);

	//前方側要素が無くなり、後方側要素が残っている場合
	while (backElement < lastElement) {

		////後方側要素の全バイトを元配列に統合するループ
		for (int firstCounter = 0; firstCounter < objectSize; ++firstCounter) {

			//後方側要素を元配列の指定位置に並べる
			static_cast<char*>(baseArray)[(frontElement + backElement) * objectSize + firstCounter] = backArray[backElement * objectSize + firstCounter];

		}
		//次の後方側要素を検討する
		++backElement;
	}
	//後方側要素が無くなり、前方側要素が残っている場合
	while (frontElement < pivotElement) {

		//前方側要素の全バイトを元配列に統合するループ
		for (int firstCounter = 0; firstCounter < objectSize; ++firstCounter) {

			//前方側要素を元配列の指定位置に並べる
			static_cast<char*>(baseArray)[(frontElement + backElement) * objectSize + firstCounter] = frontArray[frontElement * objectSize + firstCounter];
		}
		//次の前方側要素を検討する
		++frontElement;
	}
}

int main()
{
	//配列の要素数
	const int arraySize = 6;

	//配列を初期化
	int baseArray[arraySize] = { 4, 5, 2, 1, 5, 10 };

	//配列をソート
	doMergeSort(baseArray, sizeof(baseArray) / sizeof(baseArray[0]), sizeof(int), compareInteger);

	//配列の全要素をくくる前括弧
	cout << '{';

	//ソートした配列を表示するループ
	for (int firstCounter = 0; firstCounter < sizeof(baseArray) / sizeof(baseArray[0]); ++firstCounter) {

		//配列を表示
		cout << baseArray[firstCounter] << ' ';
	}
	//配列の全要素をくくる後括弧
	cout << "}";
}