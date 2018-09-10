/*演習7-2 List7-1(p.242)のクラスDerivedにメンバ関数printを追加せよ。なお、メンバ関数printは、以下の形式の表示を行うものとする。

①Base1クラスです : x = 1
②Base2クラスです : x = 2
③Derivedクラスです : y = 3

なお、①と②の表示の実現は、それぞれBase1::printとBase2::printに委ねること。
*/

#include<iostream>

using namespace std;

//Base1クラス
class FirstBase {
public:

	//整数x
	int integerValue;    

	/**
	* Base1型オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param inputInteger 整数
	* @author Sawa
	* @since 8.2
	*/
	FirstBase(int inputInteger = 0) : integerValue(inputInteger) { cout << "Base1::xを" << integerValue << "に初期化しました。\n"; }

	/**
	* Base1型データメンバの所属クラスと値を表示する
	* @author Sawa
	* @since 8.2
	*/
	void printDataMember() { cout << "Base1クラスです : x = " << integerValue << '\n'; }
};

//Base2クラス
class SecondBase {
public:

	//整数x
	int integerValue; 

	/**
	* Base2型オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param inputInteger 整数
	* @author Sawa
	* @since 8.2
	*/
	SecondBase(int inputInteger = 0) : integerValue(inputInteger) { cout << "Base2::xを" << integerValue << "に初期化しました。\n"; }

	/**
	* Base2型データメンバの所属クラスと値を表示する
	* @author Sawa
	* @since 8.2
	*/
	void printDataMember() { cout << "Base2クラスです : x = " << integerValue << '\n'; }
};

//Derivedクラス
class DerivedClass : public FirstBase, public SecondBase {

	//整数y
	int derivedInteger; 

public:

	/**
	* Derivedクラス型オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param firstInteger, secondInteger, thirdInteger 整数
	* @author Sawa
	* @since 8.2
	*/
	DerivedClass(int firstInteger, int secondInteger, int thirdInteger) : derivedInteger(thirdInteger), SecondBase(secondInteger), FirstBase(firstInteger)
	{
		cout << "Derived::yを" << derivedInteger << "に初期化しました。\n";
	}


	/**
	* Base1型とBase2型の基底クラス部分オブジェクトをセッタ
	* @param firstBaseInteger Base1型のデータメンバに代入する整数, secondBaseInteger Base2型のデータメンバに代入する整数
	* @author Sawa
	* @since 8.2
	*/
	void setBaseDataMember(int firstBaseInteger, int secondBaseInteger) {

		//Base1基底クラス部分オブジェクトに代入
		FirstBase::integerValue = firstBaseInteger;

		//Base2基底クラス部分オブジェクトに代入
		SecondBase::integerValue = secondBaseInteger;
	}

	/**
	* Base1型とBase2型の同名関数を有効範囲解決演算子で呼び出しつつ、Derived型データメンバの所属クラスと値を表示する
	* @author Sawa
	* @since 8.2
	*/
	void printDataMember()
	{
		//FirstBase型基底クラス部分オブジェクトを表示
		FirstBase::printDataMember();

		//SecondBase型基底クラス部分オブジェクトを表示
		SecondBase::printDataMember();

		//Derivedクラスのメンバ部分オブジェクトを表示
		cout << "Derivedクラスです : x = " << derivedInteger << '\n';
	}
};
	
int main()
{
	//テスト用のクラスZ型オブジェクト
	DerivedClass testObject(1, 2, 3);

	//データメンバを表示
	testObject.printDataMember();


}