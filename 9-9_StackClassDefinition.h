#ifndef ___ClassDefinition
#define ___ClassDefinition

/**
* スタッククラスのコンストラクタ
* @param inputSize スタックの容量
* @author Sawa
* @since 9.4
*/
template <class ClassType> StackClass<ClassType>::StackClass(int inputSize) 
	
	//スタックの容量を引数で、スタックポインタを0で初期化
	: stackSize(inputSize), stackPointer(0)
{
	//スタックの容量ぶんの配列を動的確保
	stackArray = new ClassType[stackSize]();
}

/**
* スタッククラスのデストラクタ
* @author Sawa
* @since 9.4
*/
template<class ClassType> StackClass<ClassType>::~StackClass()
{
	//確保した配列を開放
	delete[] stackArray;
}

/**
* 値をスタックに追加する
* @param inputValue 追加する値
* @return 次の要素の値 
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType& StackClass<ClassType>::pushValue(const ClassType& inputValue)
{
	//スタックが満杯の場合
	if (isFull() == true) {

		//オーバーフロー例外を送出
		throw Overflow();
	}
	//スタックポインタの位置に引数を代入し、スタックポインタを一つ進めた要素を返却
	return stackArray[stackPointer++] = inputValue;

}

/**
* 値をスタックから除外する
* @return 前の要素の値
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType StackClass<ClassType>::popValue()
{
	//スタックが空の場合
	if (isEmpty() == true) {

		//アンダーフロー例外を送出
		throw EmptyClass();
	}
	//スタックポインタを一つ戻した要素を返却
	return stackArray[--stackPointer];
}

/**
* 頂上のデータを削除することなく返す
* @return 前の要素の値
* @author Sawa
* @since 9.4
*/
template<class ClassType> ClassType& StackClass<ClassType>::getPeekValue()
{
	//スタックが満杯でない場合
	if (isFull() == false) {

		//頂上データが無い例外を送出
		throw NoPeek();
	}
    //頂上のデータを返却する
	return stackArray[stackPointer - 1];
}

/**
* スタックの容量を返却
* @return stackSize スタックの容量
* @author Sawa
* @since 9.4
*/
template<class ClassType> int StackClass<ClassType>::getCapacity()
{
	//スタックの容量を返却
	return stackSize;
}

/**
* スタックが満杯であるかどうかを判定
* @return boolenValue 満杯であるか否か
* @author Sawa
* @since 9.4
*/
template<class ClassType> bool StackClass<ClassType>::isFull()
{
	//満杯であるか否か
	bool boolenValue;

	//スタックポインタが容量以上の場合
	if (stackPointer >= stackSize) {

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
* スタックが空であるかどうかを判定
* @return boolenValue 空であるか否か
* @author Sawa
* @since 9.4
*/
template<class ClassType> bool StackClass<ClassType>::isEmpty()
{
	//空であるか否か
	bool boolenValue;

	//スタックポインタが0の場合
	if (stackPointer == 0) {

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