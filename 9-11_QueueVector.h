/*演習9-11 本節で作成したスタッククラス群と、その利用例のプログラムをもとにして、キュークラス群と
その利用例のプログラムを作成せよ。*/

#ifndef ___QueueVector
#define ___QueueVector

#include"9-11_QueueClass.h"
#include<vector>

//ベクターキュークラステンプレート
template <class ClassType> class VectorClass : public QueueClass<ClassType> {
public: 

	//ベクタキューコンストラクタ
	VectorClass() {};

	//ベクターキューデストラクタ
	~VectorClass() {}

	/**
	* キューの要素を末尾に追加する
	* @param inputValue 追加する要素の値
	* @author Sawa
	* @since 9.5
	*/
	void pushValue(const ClassType& inputValue) {

		//例外を探索
		try {
			//ベクトルライブラリのプッシュプロパティを使用
			queueVector.push_back(inputValue);
		}
		//例外を検出した場合
		catch (...) {
			
			//オーバーフロー例外を送出
			throw QueueClass<ClassType>::Overflow();
		}
	}

	/**
	* キューの先頭要素を削除する
	* @param poppedValue 削除した要素の値 
	* @author Sawa
	* @since 9.5
	*/
	ClassType popValue() {

		//キューが空の場合
		if (queueVector.empty()) {

			//空例外を送出
			throw QueueClass<ClassType>::EmptyClass();
		}
		//削除する値を保持
		ClassType poppedValue = *(queueVector.begin());

		//先頭要素を削除
		queueVector.erase(queueVector.begin());

		//削除した値を返却
		return poppedValue;
	}

private:
	//本体となるベクトル
	std::vector<ClassType> queueVector;
};

#endif