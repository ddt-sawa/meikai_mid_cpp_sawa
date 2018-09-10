/*演習7-4 3次元クラスThreeDimensionを抽象基底クラスとして定義せよ。さらに、ThreeDimensionを継承するクラスを自由に作成せよ。*/

#ifndef ___Shape
#define ___Shape

#include<string>
#include<sstream>
#include<iostream>

//図形クラス(抽象クラス)
class ShapeClass {
public:
	//純粋仮想デストラクタ
	virtual ~ShapeClass() = 0;

	//複製を行う(純粋仮想関数)
	virtual ShapeClass* makeClone() const = 0;

	//描画を行う(純粋仮想関数)
	virtual void printShape() const = 0;

	//図形情報を獲得する(純粋仮想関数)
	virtual std::string getString() const = 0;

	//図形情報を表示し、描画を行う
	void printInformation() const
	{
		//図形情報を表示
		std::cout << getString() << '\n';

		//描画
		printShape();
	}

	//デバッグ用情報を表示する(純粋仮想関数)
	virtual void printDebug() const = 0;
};

//純粋仮想デストラクタ
inline ShapeClass::~ShapeClass() {}

/**
* デバッグ用情報を表示する仮想関数
* @author Sawa
* @since 8.1
*/
inline void ShapeClass::printDebug() const
{
	//デバッグ情報を表示することを告知
	std::cout << "--デバッグ情報--\n";

	//型情報を表示
	std::cout << "型 : " << typeid(*this).name() << '\n';

	//アドレスを表示
	std::cout << "アドレス : " << this << '\n';
}

/**
* ShapeClass型オブジェクト用の挿入子
* @param userString 出力ストリーム inputShape 図形
* @return ostreamへの参照 図形情報の文字列表現
* @author Sawa
* @since 8.1
*/
inline std::ostream& operator<<(std::ostream& userString, const ShapeClass& inputShape) {return userString << inputShape.getString();}
#endif