/*演習3-8 List3-14(p.120)の関数seqsearchを利用するプログラムを作成せよ。*/

#include<iostream>
#include<cstdlib>

using namespace std;

/**
* 線形探索関数
* @param keyObject 探索する値, baseArray 探索範囲となる配列, arraySize 配列の要素数, objectSize オブジェクトの大きさ, compareFunction 比較関数 
* @return keyPointer 配列中の探索値に対するポインタ
* @author Sawa
* @since 9.5
*/
void* sequenceSearch(const void* keyObject, const void* baseArray, size_t arraySize, size_t objectSize, int(*compareFunction)(const void*, const void*))
{
	//配列の先頭要素へのポインタ
	const char* arrayPointer = reinterpret_cast<const char*>(baseArray);

	//配列中の探索値に対するポインタ
    const void * keyPointer = nullptr;

	//配列を走査探索するループ
	for (size_t firstCounter = 0; firstCounter < arraySize; ++firstCounter) {
		
		//配列内に探索値と等しい要素が見つかった場合
		if (!compareFunction(keyObject, reinterpret_cast<const void*>(&arrayPointer[firstCounter * objectSize]))) {

			//探索値に対するポインタを返却値に代入
			keyPointer = reinterpret_cast<const void*>(&arrayPointer[firstCounter * objectSize]);

			//ループを抜ける
			break;
		}
	}
	//配列中の探索値に対するポインタを返却
	return const_cast<void*>(keyPointer);
}

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

//探索範囲となる配列の要素数
const int arraySize = 5;

int main()
{
	//探索する値
	int searchValue = 2;

	//探索範囲となる配列
	int intArray[arraySize] = { 0, 1, 2, 3 , 4 };

	//線形探索を行い、探索する値が存在する要素へのポインタを返却
	int* keyPointer = reinterpret_cast<int*>(sequenceSearch(&searchValue, intArray, sizeof(intArray) / sizeof(intArray[0]), sizeof(intArray[0]), compareInteger));

	//探索が成功した場合
	if (keyPointer != nullptr) {

		//探索値と同じ値を持つ要素の添字を返却
		cout << keyPointer - intArray;
	}

}