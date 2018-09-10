/*演習4-3 List4-12(p.153)のクラスBase型とDerived型に対して、アップキャストとダウンキャストを試みる
プログラムを作成せよ。List4-22(p.168)を参考にすること。*/

#ifndef ___Member
#define ___Member

//基底クラス
class BaseClass{
public:

	/**
	* 基底クラスのデフォルトコンストラクタ
	* @ param inputFirstBaseInteger 整数1, inputSecondBaseInteger 整数2
	* @author Sawa
	* @since 7.31
	*/
	BaseClass(int inputFirstBaseInteger, int inputSecondBaseInteger)
		: firstBaseInteger(inputFirstBaseInteger), secondBaseInteger(inputSecondBaseInteger) {}

	/**
	* 基底クラスのデータメンバを表示する
	* @author Sawa
	* @since 7.31
	*/
	void printBaseInteger() const
	{
		//整数1を表示
		std::cout << "firstBaseInteger = " << firstBaseInteger << '\n';

		//整数2を表示
		std::cout << "secondBaseInteger = " << secondBaseInteger << '\n';
	}

private:
	int firstBaseInteger;   //整数1
	int secondBaseInteger;  //整数2
};

//派生クラス
class DerivedClass : public BaseClass {
public:

	/**
	* 派生クラスのデフォルトコンストラクタ
	* @ param inputFirstBaseInteger 整数1, inputSecondBaseInteger 整数2, inputDerivedInteger 整数3
	* @author Sawa
	* @since 7.31
	*/
	DerivedClass(int inputFirstBaseInteger, int inputSecondBaseInteger, int inputDerivedInteger) : BaseClass(inputFirstBaseInteger, inputSecondBaseInteger), derivedInteger(inputDerivedInteger) {}

	/**
	* 基底クラス・派生クラスのデータメンバを表示する
	* @author Sawa
	* @since 7.31
	*/
	void printDerivedInteger() const
	{
		//基底クラスのデータメンバ(整数1,2)を表示
		printBaseInteger();

		//整数3を表示
		std::cout << "DerivedInteger = " << derivedInteger << '\n';
	}

private:
	int derivedInteger; //整数3
};

#endif