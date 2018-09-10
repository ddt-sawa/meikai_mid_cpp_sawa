/*演習4-1 List4-15のクラスBaseのコンストラクタを上記の②に置き換えたプログラムを作成して、
本ページで解説されている内容を確認せよ。*/

#include<iostream>

using namespace std;

//基底クラスの宣言
class BaseClass {
public:

	/**
	* 課題の指定通りに書き換えたデフォルトコンストラクタ
	* @author Sawa
	* @since 7.31
	*/
	BaseClass(int inputInteger = 99) : integerValue(inputInteger) {

		//データメンバの値を表示
		cout << "Base::integerValueを" << integerValue << "で初期化。\n";
	}

	/**
	* データメンバのゲッタ
	* @return integerValue 整数
	* @author Sawa
	* @since 7.31
	*/
	int getInteger() const { return integerValue; }

private:

	int integerValue;   //整数値
};

//派生クラスの宣言
class DerivedClass : public BaseClass {

	//何も定義しない

};

int main()
{
	//派生クラスオブジェクトを直接基底クラスのデフォルトコンストラクタによって初期化
	DerivedClass firstDerivedObject;

	//直接基底クラスのデフォルトコンストラクタによってコンパイルエラーを回避しつつ、データメンバを99で初期化したことを確認
	cout << "firstDerivedObject.getInteger() = " << firstDerivedObject.getInteger() << '\n';
}
