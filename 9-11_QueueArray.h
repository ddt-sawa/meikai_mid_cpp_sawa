/*演習9-11 本節で作成したスタッククラス群と、その利用例のプログラムをもとにして、キュークラス群と
その利用例のプログラムを作成せよ。*/

#ifndef ___QueueArray
#define ___QueueArray

#include "9-11_QueueClass.h"

//要素数固定配列によるキュークラステンプレート
template <class ClassType> class ArrayClass : public QueueClass<ClassType> {
public:

	//要素数固定配列コンストラクタ
	ArrayClass() : queuePointer(0) {}

	//要素数固定配列デストラクタ
	~ArrayClass() {}

	/**
	* 要素数固定配列のデータを一つ追加する
	* @param inputValue
	* @author Sawa
	* @since 9.5
	*/
	void pushValue(const ClassType& inputValue)
	{
		//キューポインタが満杯の場合
		if (queuePointer >= arraySize) {

			//オーバーフロー例外を送出
			throw QueueClass<ClassType>::Overflow();
		}
		//現在のキューポインタの位置に値を代入し、キューポインタを一つ進める
		queueArray[queuePointer++] = inputValue;
	}

	/**
	* 要素数固定配列のデータを一つ除外する
	* @author Sawa
	* @since 9.5
	*/
	ClassType popValue()
	{
		//キューが空の場合
		if (queuePointer <= 0) {

			//アンダーフロー例外を送出
			throw QueueClass<ClassType>::EmptyClass();
		}
		//除外される値
		ClassType poppedValue;

		//除外される値(キューの先頭要素)を代入
		poppedValue = queueArray[0];

		//キューポインタ以前の要素を一つずつ前にずらすループ
		for (int firstCounter = 0; firstCounter < queuePointer - 1; firstCounter++) {

			//キューの要素を前にずらす
			queueArray[firstCounter] = queueArray[firstCounter + 1];
		}
		//キューポインタをデクリメントし、末尾要素に0を代入
		queueArray[--queuePointer] = 0;

		//除外された値を返却
		return poppedValue;
	}

private:
	//キューの容量(10で固定)
	static const int arraySize = 10;

	//キューポインタ
	int queuePointer;

	//キューの本体
	ClassType queueArray[arraySize];

};

#endif