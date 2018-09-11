#ifndef ___SimpleQueue
#define ___SimpleQueue

//キュークラス
template<class ClassType> class QueueClass {
public:

	//例外抽象クラス
	class QueueError
	{
	public:

		//例外エラーメッセージを表示する純粋仮想関数
		virtual void returnMessage()const = 0;

	};

	//満杯のキューへのプッシュに対する例外クラス(オーバーフロー)
	class Overflow : public QueueError
	{
	public:

		/**
		* オーバーフローしたコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "満杯のキューにプッシュしようとしました。\n"; }
	};

	//空のキューからのポップに対する例外クラス(アンダーフロー)
	class EmptyClass : public QueueError {

	public:

		/**
		* アンダーフローしたコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "空のキューにポップしようとしました。\n"; }
	};

	//頂上のデータがない時に頂上のデータをサーチした例外クラス
	class NoPeek : public QueueError {

	public:

		/**
		* 頂上のデータがないコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "頂上のデータはありません。\n"; }
	};

	//明示的コンストラクタ
	explicit QueueClass(int inputSize);

	//デストラクタ
	~QueueClass();

	//プッシュ(キューにデータ追加)
	ClassType& pushValue(const ClassType& inputValue);

	//ポップ(キューからデータ除外)
	ClassType popValue();

	//頂上のデータを削除することなく返す。
	ClassType& getPeekValue()const;

	//キューの容量を返す
	int getCapacity()const;

	//キューが満杯であるかどうかを返す
	bool isFull()const;

	//キューが空であるかどうかを返す
	bool isEmpty()const;

private:
	//キューの容量
	int queueSize;

	//キューポインタ(現在のデータ数)
	int queuePointer;

	//配列本体へのポインタ
	ClassType* queueArray;

	//宣言のみを行い、コピーコンストラクタを無効化
	QueueClass(const QueueClass<ClassType>&);

	//宣言のみを行い、代入演算子を無効化
	QueueClass& operator=(const QueueClass<ClassType>&);

};

#include "9-10_MemberDefinition.h"
#endif