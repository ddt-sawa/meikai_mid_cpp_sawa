/*演習9-11 本節で作成したスタッククラス群と、その利用例のプログラムをもとにして、キュークラス群と
その利用例のプログラムを作成せよ。*/

#include<iostream>
#include"9-11_QueueClass.h"
#include"9-11_QueueArray.h"
#include"9-11_QueueList.h"
#include"9-11_QueueVector.h"

using namespace std;

//作成可能なキューの種類
enum QueueType { queueArray, queueList, queueVector };

//キューに対して行う操作の種類
enum OperationType { quitOperationNumber, pushOperationNumber, popOperationNumber, whollyPopOperationNumber };


/**
* 引数によって異なる種類のキューインスタンスを作成し、それに対するポインタを返却する
* @param inputValue キューの種類
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
template <class ClassType> QueueClass<ClassType>* generateQueue(QueueType inputValue)
{
	//返却する基底クラスのポインタを宣言
	QueueClass<ClassType>* returnPointer;

	//選択されたキューの種類に応じて、作成するインスタンスを変更する
	switch (inputValue) {

		//配列型が選択された場合
	case queueArray:

		//配列型キューインスタンスを作成し、そのポインタを返却値とする
		returnPointer = new ArrayClass<ClassType>();

		//分岐終了
		break;

		//線形リスト型が選択された場合
	case queueList:

		//線形リスト型キューインスタンスを作成し、そのポインタを返却値とする
		returnPointer = new ListClass<ClassType>();

		//分岐終了
		break;

		//ベクトル型が選択された場合
	case queueVector:

		//ベクトル型キューインスタンスを作成し、そのポインタを返却値とする
		returnPointer = new VectorClass<ClassType>();

		//分岐終了
		break;

		//それ以外の値が選択された場合
	default:

		//nullポインタを返却値とする
		returnPointer = nullptr;

		//分岐終了
		break;
	}
	//ポインタを返却する
	return returnPointer;
}

/**
* プッシュに関する一連の処理を行う
* @param inputObject インスタンスへのポインタ
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
template <class ClassType> void pushOperation(QueueClass<ClassType>* inputObject)
{
	//プッシュするデータ
	int pushedValue;

	//プッシュするデータの入力を促す
	cout << "データ : ";

	//プッシュするデータの入力
	cin >> pushedValue;

	//例外を探索
	try {
		//プッシュを行う
		inputObject->pushValue(pushedValue);
	}
	//オーバーフロー例外を検出した場合
	catch (const QueueClass<ClassType>::Overflow& catchedError) {

		//オーバーフローメッセージを表示
		catchedError.returnMessage();
	}
}

/**
* ポップに関する一連の処理を行う
* @param inputObject インスタンスへのポインタ
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
template <class ClassType> void popOperation(QueueClass<ClassType>* inputObject)
{
	//ポップした値
	ClassType poppedValue = 0;

	//例外を探索
	try {
		//ポップを行う
		poppedValue = inputObject->popValue();

		//ポップした値の表示
		cout << "ポップした値は" << poppedValue << "です。\n";
	}
	//アンダーフロー例外を検出した場合
	catch (const QueueClass<ClassType>::EmptyClass& catchedError) {

		//アンダーフローメッセージを表示
		catchedError.returnMessage();
	}
}


/**
* 全てのキューデータを表示し、除外する
* @param inputObject インスタンスへのポインタ
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
template <class ClassType> void whollyPopOperation(QueueClass<ClassType>* inputObject)
{
	//表示するポップ群の前枠を表示
	cout << "{";

	//ポップした値
	ClassType poppedValue;

	//例外を探索する
	try {

		//空例外が発生するまで、ポップを行い続ける
		while (true) {

			//ポップを行う
			poppedValue = inputObject->popValue();

			//ポップした値を表示
			cout << poppedValue << " ";
		}
	}
	//空例外を捕捉した場合ループを抜ける
	catch (const QueueClass<ClassType>::EmptyClass&) {};

	//表示するポップ群の後枠を表示
	cout << "}\n";
}


/**
* 作成するキューの種類を入力し、その値を返却する
* @param inputObject インスタンスへのポインタ
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
QueueType inputQueueType()
{
	//作成するキューの種類
	int queueType = 0;

	//作成するキューの種類を選択させるループ
	do {
		//作成するキューの種類の選択を促す
		cout << "スタックの種類(0---配列/ 1---リスト/ 2---ベクトル) : ";

		//種類入力
		cin >> queueType;

		//入力値が選択肢として妥当ではない場合再入力
	} while (queueType < queueArray || queueType > queueVector);

	//作成するキューの種類を返却
	return static_cast<QueueType>(queueType);
}

/**
* メインメニューを表示し、入力された値によって操作を行う
* @param inputObject インスタンスへのポインタ
* @return returnPointer 返却するポインタ
* @author Sawa
* @since 9.5
*/
template <class ClassType> void printMenu(QueueClass<ClassType>* inputObject)
{

	//操作の種類
	int menuValue = 0;

	//終了が選択されるまで操作を行う
	while (true) 
	{
		//操作の選択を促す
		cout << "(1)プッシュ (2)ポップ (3) 全ポップ&表示 (0)終了 : ";

		//操作を選択
		cin >> menuValue;

		//選択によって場合分け
		switch (menuValue) {

		//プッシュ操作が選ばれた場合
		case pushOperationNumber:

			//プッシュを行う
			pushOperation(inputObject);

			//分岐終了
			break;

		//ポップ操作が選ばれた場合
		case popOperationNumber:

			//ポップを行う
			popOperation(inputObject);

			//分岐終了
			break;

		//全ポップ&表示操作が選ばれた場合
		case whollyPopOperationNumber:

			//全ポップ・表示を行う
			whollyPopOperation(inputObject);

			//分岐終了
			break;

		//それ以外の値が入力された場合
		default:

			//分岐終了
			break;
		}
		//終了が選ばれていた場合
		if (menuValue == quitOperationNumber) {

			//ループを抜け、プログラムを終了する
			break;
		}
	}
}

int main()
{
	//作成するキューの種類
	QueueType inputValue;

	//作成するキューの種類を選択
	inputValue = inputQueueType();

	//選択されたキューを<int>型に明示的特殊化を行ったインスタンスへのポインタ
	QueueClass<int>* sampleQueue;

	//上記インスタンスを作成
	sampleQueue = generateQueue<int>(inputValue);

	//作成したインスタンスに対し、メインメニューで操作を行う
	printMenu<int>(sampleQueue);

}