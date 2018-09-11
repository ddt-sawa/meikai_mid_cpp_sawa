/*演習9-11 本節で作成したスタッククラス群と、その利用例のプログラムをもとにして、キュークラス群と
その利用例のプログラムを作成せよ。*/

#ifndef ___SimpleQueue
#define ___SimpleQueue

//抽象キュークラステンプレート
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

	//純粋仮想デストラクタ
	virtual ~QueueClass() = 0;

	//プッシュ(キューにデータ追加)
	virtual void pushValue(const ClassType& inputValue) = 0;

	//ポップ(キューからデータ除外)
	virtual ClassType popValue() = 0;
};

//デストラクタ
template <class ClassType> QueueClass<ClassType>::~QueueClass() {}

#endif