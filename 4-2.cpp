/*演習4-2 デストラクタの起動の順序を確認できるように、List4-16のプログラムを書き換えたプログラムを作成せよ。*/

#include<iostream>

using namespace std;

//基底クラス
class BaseClass {
public:

	/**
	* BaseClass型オブジェクトのデフォルトコンストラクタ
	* @param inputInteger 整数値
	* @author Sawa
	* @since 7.31
	*/
	BaseClass(int inputInteger = 0) : baseInteger(inputInteger) 
	{
		//データメンバの値を表示
		cout << "BaseClass::baseIntegerを" << baseInteger << "で初期化。\n"; 
	}

	//デストラクタの起動時(今回の場合プログラム終了時)に、データメンバの値を表示する
	~BaseClass() { cout << "BaseClass::baseInteger = " << baseInteger << "を破棄しました。\n"; }

private:
	int baseInteger; //整数値
};

//派生クラスにメンバとして含まれるクラス
class MemberClass {
public:

	/**
	* MemberClass型オブジェクトのデフォルトコンストラクタ
	* @param inputInteger 整数値
	* @author Sawa
	* @since 7.31
	*/
	MemberClass(int inputInteger = 0) : memberInteger(inputInteger)
	{
		//データメンバの値を表示
		cout << "MemberClass::memberIntegerを" << memberInteger << "で初期化。\n";
	}

	//デストラクタの起動時(今回の場合プログラム終了時)に、データメンバの値を表示する
	~MemberClass() { cout << "MemberClass::memberInteger = " << memberInteger << "を破棄しました。\n"; }

private:
	int memberInteger; //整数値
};

//派生クラス
class DerivedClass : public BaseClass {

public:

	/**
	* DereivedClass型オブジェクトのデータメンバを0で初期化し、その値を表示す
	* @author Sawa
	* @since 7.31
	*/
	void clearInteger() { derivedInteger = 0; cout << "Derived::derivedIntegerを" << derivedInteger << "で初期化。\n"; }

	/**
	* DerivedClass型オブジェクトのデフォルトコンストラクタ
	* @author Sawa
	* @since 7.31
	*/
	//データメンバを0で初期化し、その値を表示する関数を呼び出す
	DerivedClass() { clearInteger(); }

	/**
	* DerivedClass型オブジェクトのコンストラクタ
	* @param secondMemberInteger クラスメンバ2に代入する整数,　firstMemberInteger クラスメンバ1に代入する整数, baseInteger 基底クラスオブジェクトに代入する整数
	* @author Sawa
	* @since 7.31
	*/
	//①基底クラス部分オブジェクト、②クラスメンバ1、③クラスメンバ2の順でコンストラクタが起動することを確認するために、敢えてバラバラに初期化子を配置する
	DerivedClass(int secondMemberInteger, int firstMemberInteger, int baseInteger) : secondMember(secondMemberInteger), firstMember(firstMemberInteger), BaseClass(baseInteger) { clearInteger(); }

	//デストラクタの起動時(今回の場合プログラム終了時)に、データメンバの値を表示する
	~DerivedClass() { cout << "DerivedClass::derivedInteger = " << derivedInteger << "を破棄しました。\n"; }

private:
	int derivedInteger;       //整数値
	MemberClass firstMember;  //クラスメンバ1
	MemberClass secondMember; //クラスメンバ2
};

int main()
{
	//全要素に0が代入されるオブジェクト
	DerivedClass firstDerivedObject;

	//各データメンバへ順番に0,1,2,3を代入(0はデフォルトコンストラクタ)し、コンストラクタとデストラクタの働きを見やすくしたオブジェクト
	DerivedClass secondDerivedObject(1, 2, 3);
}

//コンストラクタと逆順にデストラクタが起動していることを確認