/*演習3-9 List3-15(p.122)の関数binsearchを利用するプログラムを作成せよ*/

#include<cstdlib>
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
* 配列に対して指定値の2分探索を行い、値が存在した場合その要素へポインタを返却
* @param keyValue 指定値, baseArray 配列, arraySize 要素数, objectSize オブジェクトの大きさ, comparisionFunction　比較関数
* @return searchPointer 指定値を持つ要素へのポインタ
* @author Sawa
* @since 7.20
*/
void* doBinarySearch(void* keyValue, void* baseArray, size_t arraySize, size_t objectSize, int(*comparisionFunction)(const void*, const void*))
{
	//指定値を持つ要素へのポインタ
	void* searchPointer = nullptr;

	//要素数が正の場合
	if (arraySize > 0) {

		//配列の先頭要素へのポインタ
		char* arrayPointer = reinterpret_cast<char*>(baseArray);

		//探索範囲先頭の添字
		size_t firstElement = 0;

		//探索範囲末尾の添字
		size_t lastElement = arraySize - 1;

		//探索範囲がなくなるまで二分探索を行うループ
		for (; firstElement != lastElement;) {

			//探索範囲中央の添字
			size_t centralElement = (firstElement + lastElement) / 2;

			//探索値と中央要素の持つ値の比較を行う
			int comparisionValue = comparisionFunction(keyValue, reinterpret_cast<void*>(&arrayPointer[(centralElement * objectSize)]));

			//探索値が走査中要素の値より大きい場合
			if (comparisionValue > 0) {

				//次回探索範囲を中央要素の次の要素～探索値範囲の最終要素に指定
				firstElement = centralElement + 1;
			}
			//探索値が走査中要素の値より小さい場合
			else if (comparisionValue < 0) {

				//次回探索範囲を探索範囲の先頭要素～中央要素の前の要素に指定
				lastElement = centralElement - 1;
			}
			//探索値を発見した場合
			else {

				//その要素へのポインタを返却値に代入
				searchPointer = const_cast<void*>(reinterpret_cast<const void*>(&arrayPointer[centralElement * objectSize]));

				//ループを抜ける
				break;
			}
		}
	}
	//指定値を持つ要素へのポインタを返却
	return searchPointer;
}

int main()
{
	//探索値
	int keyObject = 5;

	//配列の要素数
	const int arraySize = 10;

	//探索範囲となる配列
	int baseArray[arraySize] = { 10, 0, 3, 50, 4, 5, 3, 100, -5, 1 };

	//線形探索を行い、探索する値が存在する要素へのポインタを返却
	int* keyPointer = reinterpret_cast<int*>(doBinarySearch(&keyObject, baseArray, sizeof(baseArray) / sizeof(baseArray[0]), sizeof(int), compareInteger));

	//探索が成功した場合
	if (keyPointer != nullptr) {

		//探索値と同じ値を持つ要素の添字を返却
		cout << keyPointer - baseArray;
	}
}