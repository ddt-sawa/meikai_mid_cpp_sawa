/*演習3-11 List3-17(p.126)の関数quicksortを利用するプログラムを作成せよ。*/

#include<iostream>
#include<cstdlib>

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
* 第一引数と第二引数のバイトを整数値ぶん交換する
* @param firstArgument,第一引数へのポインタ secondArgument 第二引数へのポインタ, byteNumber 交換バイト数
* @author Sawa
* @since 7.19
*/
namespace {
	void swapBytes(void* firstArgument, void* secondArgument, size_t byteNumber)
	{
		//第一引数をバイト数1であるchar型に直したポインタを保存
		unsigned char* firstArgumentPointer = reinterpret_cast<unsigned char*>(firstArgument);

		//第二引数をバイト数1であるchar型に直したポインタを保存
		unsigned char* secondArgumentPointer = reinterpret_cast<unsigned char*>(secondArgument);

		//バイト数分引数の値を交換するループ
		for (; byteNumber--; ++firstArgumentPointer, ++secondArgumentPointer) {

			//第一引数のバイトを保存
			unsigned char temporaryValue = *firstArgumentPointer;

			//第二引数のバイトを第一引数に代入
			*firstArgumentPointer = *secondArgumentPointer;

			//第一引数のバイトを第二引数に代入
			*secondArgumentPointer = temporaryValue;
		}
	}
}

/**
* 配列中の要素を昇順にソートする
* @param baseArray,配列 arraySize 配列の要素数, objectSize オブジェクトの大きさ, comparisionFunction 比較関数
* @author Sawa
* @since 7.19
*/
void doQuickSort(void* baseArray, size_t arraySize, size_t objectSize, int(*comparisionFunction)(const void*, const void*))
{
	//要素が存在する場合
	if (arraySize > 0) {

		//配列の先頭要素へのポインタ
		char* firstElementPointer = reinterpret_cast<char*>(baseArray);

		//左から配列要素を走査していく添字
		size_t leftElement = 0;

		//右から配列要素を走査していく添字
		size_t rightElement = arraySize - 1;

		//枢軸の添え字
		size_t axisElement = arraySize / 2;

		//枢軸更新用の添字
		size_t centralElement = (leftElement + rightElement) / 2;

		//要素をソートするためのループ
		do {
			//枢軸へのポインタ
			char* searchPointer = &firstElementPointer[(axisElement)* objectSize];

			//枢軸が中央値になっていない場合
			if (axisElement != centralElement) {

				//枢軸へのポインタを中央値へのポインタに更新
				searchPointer = &firstElementPointer[(axisElement = centralElement) * objectSize];
			}

			//左カーソルの要素の値が枢軸の値より小さい場合
			while (comparisionFunction(reinterpret_cast<void*>(&firstElementPointer[leftElement * objectSize]), searchPointer) < 0) {

				//交換すべき値ではないので左カーソルを進める
				++leftElement;
			}

			//右カーソルの要素の値が枢軸のアドレスより大きい場合
			while (comparisionFunction(reinterpret_cast<void*>(&firstElementPointer[rightElement * objectSize]), searchPointer) > 0) {

				//交換すべき値ではないので右カーソルを進める
				--rightElement;
			}

			//交換すべき値を確保し、両カーソルが交差していない場合
			if (leftElement <= rightElement) {

				//左カーソルが枢軸の場合　中央添字を右カーソルに、そうでなく右カーソルが枢軸の場合中央添字を右カーソルに、そうでないなら枢軸に変更
				centralElement = (leftElement == axisElement) ? rightElement : (rightElement == axisElement) ? leftElement : axisElement;

				//両カーソルが示す要素のバイト値を交換
				swapBytes(reinterpret_cast<void*>(&firstElementPointer[leftElement * objectSize]), reinterpret_cast<void*>(&firstElementPointer[rightElement * objectSize]), objectSize);

				//左カーソルを進める
				++leftElement;

				//右カーソルを進める
				--rightElement;
			}
			//カーソルが交差するまで再試行
		} while (leftElement <= rightElement);

		//右カーソルが0以上の場合
		if (0 < rightElement) {

			//低数値群を再度ソート
			doQuickSort(reinterpret_cast<void*>(&firstElementPointer[0]), rightElement + 1, objectSize, compareInteger);
		}

		//左カーソルが最後尾ではない場合
		if (leftElement < arraySize - 1) {

			//高数値群を再度ソート
			doQuickSort(reinterpret_cast<void*>(&firstElementPointer[leftElement * objectSize]), arraySize - leftElement, objectSize, compareInteger);
		}
	}
}

int main()
{
	//配列の要素数
	const int arraySize = 10;

	//配列を初期化
	int baseArray[arraySize] = { 10, 0, 3, 50, 4, 5, 3, 100, -5, 1 };

	//配列をソート
	doQuickSort(baseArray, sizeof(baseArray) / sizeof(baseArray[0]), sizeof(int), compareInteger);

	//配列要素をくくる前括弧
	cout << '{';

	//ソートした配列を表示するループ
	for (int firstCounter = 0; firstCounter < sizeof(baseArray) / sizeof(baseArray[0]); ++firstCounter) {

		//配列の要素を表示
		cout << baseArray[firstCounter] << ' ';
	}
	//配列要素をくくる後括弧
	cout << "}";
}