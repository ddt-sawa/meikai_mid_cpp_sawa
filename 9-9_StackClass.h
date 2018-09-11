#ifndef ___SimpleStack
#define ___SimpleStack

template<class ClassType> class StackClass {
public:

	//例外抽象クラス
    class StackError 
    { 
        public: 
		
		//例外エラーメッセージを表示する純粋仮想関数
	    virtual void returnMessage()const = 0; 
  
    };

	//満杯のスタックへのプッシュに対する例外クラス(オーバーフロー)
	class Overflow : public StackError
	{
	    public:

		/**
		* オーバーフローしたコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "満杯のスタックにプッシュしようとしました。\n"; }
	};

	//空のスタックからのポップに対する例外クラス(アンダーフロー)
	class EmptyClass : public StackError {

	    public:

		/**
		* アンダーフローしたコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "空のスタックにポップしようとしました。\n"; }
	};

	//頂上のデータがない時に頂上のデータをサーチした例外クラス
	class NoPeek: public StackError {
		
	    public:

		/**
		* 頂上のデータがないコメントを表示する
		* @author Sawa
		* @since 9.4
		*/
		void returnMessage()const { cout << "頂上のデータはありません。\n"; }
	};

	//明示的コンストラクタ
	explicit StackClass(int inputSize);

	//デストラクタ
	~StackClass();

	//プッシュ(スタックにデータ追加)
	ClassType& pushValue(const ClassType& inputValue);

	//ポップ(スタックからデータ除外)
	ClassType popValue();

	//頂上のデータを削除することなく返す。
	ClassType& getPeekValue();

	//スタックの容量を返す
	int getCapacity();

	//スタックが満杯であるかどうかを返す
	bool isFull();

	//スタックが空であるかどうかを返す
	bool isEmpty();


private:
	// スタックの容量
	int stackSize;

	//スタックポインタ(現在のデータ数)
	int stackPointer;

	//配列本体へのポインタ
	ClassType* stackArray;

	//宣言のみを行い、コピーコンストラクタを無効化
	StackClass(const StackClass<ClassType>&);

	//宣言のみを行い、代入演算子を無効化
	StackClass& operator=(const StackClass<ClassType>&);

};

#include "9-9_StackClassDefinition.h"
#endif