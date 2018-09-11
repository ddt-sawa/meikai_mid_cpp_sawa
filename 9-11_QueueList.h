/*演習9-11 本節で作成したスタッククラス群と、その利用例のプログラムをもとにして、キュークラス群と
その利用例のプログラムを作成せよ。*/

#ifndef ___QueueList
#define ___QueueList

#include"9-11_QueueClass.h"

//線形リストクラステンプレート
template <class ClassType> class ListClass : public QueueClass<ClassType> {

public:
	/**
	* 線形リストのコンストラクタ
	* @author Sawa
	* @since 9.5
	*/
	ListClass() {

		//先頭要素を指すポインタと、ダミーノードを指すポインタをnullポインタで初期化
		topNode = dummyNode = new NodeClass<ClassType>(NULL, NULL);
	}
	/**
	* 線形リストのデストラクタ
	* @author Sawa
	* @since 9.5
	*/
	~ListClass() {

		//先頭ノードへのポインタを作成
		NodeClass<ClassType>* temporaryPointer = topNode;

		//先頭ノードとダミーノードのポインタが一致しない間
		while (temporaryPointer != dummyNode) {

			//後続ノードへのポインタを作成
			NodeClass<ClassType>* nextNode = temporaryPointer->nextNode;

			//先頭ノードが持つデータを削除
			delete temporaryPointer->nodeData;

			//先頭ノードを指すポインタを削除
			delete temporaryPointer;

			//後続ノードを先頭ノードに設定する(次に消去するノードを設定)
			temporaryPointer = nextNode;
		}
		//全ノードの削除が終わったのち、ダミーノードを削除
		delete dummyNode;
	}

	/**
	* ノードの追加を行う
	* @param inputValue ノードが持つデータ
	* @author Sawa
	* @since 9.5
	*/
	void pushValue(const ClassType& inputValue) {

		//これから後続ノードになる、旧先頭ノードへのポインタを作成
		NodeClass<ClassType>* topPointer = topNode;

		//例外を検索
		try {
			//新たに挿入する先頭ノードを作成し、そのポインタを線形リストデータメンバに保存
			topNode = new NodeClass<ClassType>(new ClassType(inputValue), topPointer);
		}
		//メモリ領域の確保に失敗した場合
		catch (const bad_alloc&) {

			//オーバーフロー例外を送出
			throw QueueClass<ClassType>::Overflow();
		}
	}

	/**
	* ノードの削除を行う
	* @return semiLastPointer->NodeData 新しく最後尾ノードとなったノードが持つデータ
	* @author Sawa
	* @since 9.5
	*/
	ClassType popValue() {

		//キューが空の場合
		if (topNode == dummyNode) {

			//空例外を送出
			throw QueueClass<ClassType>::EmptyClass();
		}
		//キューに要素がある場合
		else {

			//削除するデータ
			ClassType poppedValue;

			//最後尾の前のノードを指すポインタを作成
			NodeClass<ClassType>* semiLastPointer = topNode;


			//要素数が1の場合、
			if (semiLastPointer->nextNode == dummyNode) {
				
				//削除するデータに先頭ノードのデータを保存
				poppedValue = *(semiLastPointer->nodeData);

				//先頭ノードのデータを削除
				delete semiLastPointer->nodeData;

				//先頭ノードを削除
				delete semiLastPointer;

				//先頭ノードをダミーノードに設定
				topNode = dummyNode;
			}
			//要素数が2以上の場合
			else {

				//次に指すノードがダミーノードになるまでの間
				while (semiLastPointer->nextNode->nextNode != dummyNode) {

					//ポインタを次のノードへのポインタに移動する
					semiLastPointer = semiLastPointer->nextNode;
				}

				//削除するデータに最後尾ノードのデータを保存
				poppedValue = *(semiLastPointer->nextNode->nodeData);

				//最後尾ノードが持つデータを削除
				delete semiLastPointer->nextNode->nodeData;

				//最後尾ノードを削除
				delete semiLastPointer->nextNode;

				//最後尾の前のノードを後続ノードをダミーノードに設定し、最後尾ノードとする
				semiLastPointer->nextNode = dummyNode;
			}
			//新最後尾ノードのデータを返却
			return poppedValue;
		}
	}
	private:
		//ノードクラステンプレート
		template <class ClassType> class NodeClass {
		public:
			/**
			* ノードのコンストラクタ
			* @param inputData データ, inputNode 後続ノード
			* @author Sawa
			* @since 9.5
			*/
			NodeClass(ClassType* inputData, NodeClass* inputNode) : nodeData(inputData), nextNode(inputNode) {}

		private:
			//線形リストクラスのフレンドであることを宣言
			friend class ListClass<ClassType>;

			//データへのポインタ
			ClassType* nodeData;

			//後続ノードへのポインタ
			NodeClass* nextNode;

		};
		//先頭ノードへのポインタ
		NodeClass<ClassType>* topNode;

		//ダミーノードへのポインタ
		NodeClass<ClassType>* dummyNode;

};
#endif