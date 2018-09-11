#ifndef ___ClassDefinition
#define ___ClassDefinition

/**
* キュークラスのコンストラクタ
* @param inputSize スタックの容量
* @author Sawa
* @since 9.4
*/
template <class ClassType> QueueClass<ClassType>::QueueClass(int inputSize)

//キューの容量を引数で、キューポインタを0で初期化
	: queueSize(inputSize), queuePointer(0)
{
	//キューの容量ぶんの配列を動的確保
	queueArray = new ClassType[queueSize]();
}

/**
* キューのデストラクタ
* @author Sawa
* @since 9.4
*/
template<class ClassType> QueueClass<ClassType>::~QueueClass()
{
	//確保した配列を開放
	delete[] queueArray;
}

/**
* 値をキューに追加する
* @param inputValue 追加する値
* @return 次の要素の値
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType& QueueClass<ClassType>::pushValue(const ClassType& inputValue)
{
	//キューが満杯の場合
	if (isFull() == true) {

		//オーバーフロー例外を送出
		throw Overflow();
	}
	//キューポインタが指す要素に引数を代入し、キューポインタを一つ進めた要素を返却
	return queueArray[queuePointer++] = inputValue;
}

/**
* 値をキューから除外する
* @return 前の要素の値
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType QueueClass<ClassType>::popValue()
{
	//キューが空の場合
	if (isEmpty() == true) {

		//アンダーフロー例外を送出
		throw EmptyClass();
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

/**
* 頂上のデータを削除することなく返す
* @return 前の要素の値
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType& QueueClass<ClassType>::getPeekValue() const
{
	//キューが満杯でない場合
	if (isFull() == false) {

		//頂上データが無い例外を送出
		throw NoPeek();
	}
	//頂上のデータを返却する
	return queueArray[queuePointer - 1];
}

/**
* キューの容量を返却
* @return queueSize キューの容量
* @author Sawa
* @since 9.4
*/
template<class ClassType> int QueueClass<ClassType>::getCapacity() const
{
	//キューの容量を返却
	return queueSize;
}

/**

/**
* キューが満杯であるかどうかを判定
* @return boolenValue 満杯であるか否か
* @author Sawa
* @since 9.4
*/
template<class ClassType> bool QueueClass<ClassType>::isFull() const
{
	//満杯であるか否か
	bool boolenValue;

	//キューポインタが容量以上の場合
	if (queuePointer >= queueSize) {

		//満杯
		boolenValue = true;
	}
	//そうでない場合
	else {

		//満杯ではない
		boolenValue = false;
	}
	//真理値を返却
	return boolenValue;
}

/**
* キューが空であるかどうかを判定
* @return boolenValue 空であるか否か
* @author Sawa
* @since 9.4
*/
template<class ClassType> bool QueueClass<ClassType>::isEmpty() const
{
	//空であるか否か
	bool boolenValue;

	//キューポインタが0の場合
	if (queuePointer == 0) {

		//空
		boolenValue = true;
	}
	//そうでない場合
	else {

		//空ではない
		boolenValue = false;
	}
	//真理値を返却
	return boolenValue;
}


#endif