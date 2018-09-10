/*演習7-5 List7-14の各クラスにデストラクタを追加して、オブジェクト解体順序の確認を行え。*/

#include<iostream>

using namespace std;

//V1クラス
class FirstVirtualBase{
public:

	/**
	* 呼び出された時に初期化した自身の所属クラスを述べるコンストラクタ
	* @author Sawa
	* @since 8.2
	*/
	FirstVirtualBase() { cout << "V1を初期化\n"; }

	/**
	* 呼び出された時に破棄した自身の所属クラスを述べるデストラクタ
	* @author Sawa
	* @since 8.2
	*/
	~FirstVirtualBase() {cout << "V1を破棄\n";}
};

//V2クラス
class SecondVirtualBase {
public:

	/**
	* 呼び出された時に初期化した自身の所属クラスを述べるコンストラクタ
	* @author Sawa
	* @since 8.2
	*/
	SecondVirtualBase() { cout << "V2を初期化\n"; }

	/**
	* 呼び出された時に破棄した自身の所属クラスを述べるデストラクタ
	* @author Sawa
	* @since 8.2
	*/
	~SecondVirtualBase() { cout << "V2を破棄\n"; }
};

//Xクラス
class FirstBase : virtual public FirstVirtualBase, virtual public SecondVirtualBase {
public:

	/**
	* 呼び出された時に初期化した自身の所属クラスを述べるコンストラクタ
	* @author Sawa
	* @since 8.2
	*/
	FirstBase() { cout << "Xを初期化\n"; }

	/**
	* 呼び出された時に破棄した自身の所属クラスを述べるデストラクタ
	* @author Sawa
	* @since 8.2
	*/
	~FirstBase() { cout << "Xを破棄\n"; }
};

//Yクラス
class SecondBase : virtual public SecondVirtualBase, virtual public FirstVirtualBase {
public:

	/**
	* 呼び出された時に初期化した自身の所属クラスを述べるコンストラクタ
	* @author Sawa
	* @since 8.2
	*/
	SecondBase() { cout << "Yを初期化\n"; }

	/**
	* 呼び出された時に破棄した自身の所属クラスを述べるデストラクタ
	* @author Sawa
	* @since 8.2
	*/
	~SecondBase() { cout << "Yを破棄\n"; }
};

//Zクラス
class DerivedClass : virtual public FirstBase, virtual public SecondBase {
public:

	/**
	* 呼び出された時に初期化した自身の所属クラスを述べるコンストラクタ
	* @author Sawa
	* @since 8.2
	*/
	DerivedClass() { cout << "Zを初期化\n"; }

	/**
	* 呼び出された時に破棄した自身の所属クラスを述べるデストラクタ
	* @author Sawa
	* @since 8.2
	*/
	~DerivedClass() { cout << "Zを破棄\n"; }
};

int main()
{
	//オブジェクト解体の順序を確認する
	DerivedClass sampleObject;
}
//コンストラクタと逆順に解体されることを確認