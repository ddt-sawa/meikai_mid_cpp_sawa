/*演習7-1 以下のクラス群のクラス階層図を描き、クラスZ型オブジェクトを初期化する際の
基底クラス部分オブジェクトの初期化の順序を示せ。

class A {*}
class B {*}
class X : A, B {*}
class Y : B, A {*}
class Z : X, Y {*}
*/

/*  クラス階層図


	 【 A 】 【 B 】【 B 】 【 A 】
		↑     ↑     ↑      ↑
　　　 【　 X   】   【   Y   】
　　　　　　  ↑       ↑
			 【    Z　  】
*/

#include<iostream>

using namespace std;

//Aクラス定義
class FirstBaseClass {
public:

	int firstInteger; //整数

/**
* Aクラス型基底部分オブジェクトを初期化し、そのことを告知するコンストラクタ
* @param inputInteger 整数
* @author Sawa
* @since 8.1
*/
	FirstBaseClass(int inputInteger = 0) : firstInteger(inputInteger) {
		cout << "firstBaseClass型データメンバが初期化されました。\n";
	}
};

//Bクラス定義
class SecondBaseClass {
public:

	int secondInteger; //整数

/**
* Bクラス型基底部分オブジェクトを初期化し、そのことを告知するコンストラクタ
* @param inputInteger 整数
* @author Sawa
* @since 8.1
*/
	SecondBaseClass(int inputInteger = 0) : secondInteger(inputInteger) {
		cout << "SecondBaseClass型データメンバが初期化されました。\n";
	}
};

//Xクラス定義
class FirstDerivedClass : public FirstBaseClass, public SecondBaseClass {
public:

	/**
	* Xクラス型基底部分オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param inputInteger 整数
	* @author Sawa
	* @since 8.1
	*/
	FirstDerivedClass(int inputInteger = 0) : FirstBaseClass(inputInteger), SecondBaseClass(inputInteger) {
		cout << "firstDerivedClass型データメンバが初期化されました。\n";
	}
};

//Yクラス定義
class SecondDerivedClass : public SecondBaseClass, public FirstBaseClass {
public:

	/**
	* Yクラス型基底部分オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param inputInteger 整数
	* @author Sawa
	* @since 8.1
	*/
	SecondDerivedClass(int inputInteger = 0) : SecondBaseClass(inputInteger), FirstBaseClass(inputInteger) {
		cout << "SecondDerivedClass型データメンバが初期化されました。\n";
	}
};

//Zクラス定義
class LastDerivedClass : public FirstDerivedClass, public SecondDerivedClass {
public:

	/**
	* Zクラス型基底部分オブジェクトを初期化し、そのことを告知するコンストラクタ
	* @param inputInteger 整数
	* @author Sawa
	* @since 8.1
	*/
	LastDerivedClass(int inputInteger = 0) : FirstDerivedClass(inputInteger), SecondDerivedClass(inputInteger) {
		cout << "LastDerivedClass型データメンバが初期化されました。\n";
	}
};

int main()
{
	//テスト用のクラスZ型オブジェクト
	LastDerivedClass testObject(1);
}

//教科書の表記に合わせると、((A,B,X),(B,A,Y)),Zの順番に初期化が行われました。