#ifndef ___Math_Exception
#define ___Math_Exception

//数値演算による例外クラス
class MathException {};

//0による除算例外クラス
class DividedByZero : public MathException {};

//オーバーフロー例外クラス
class OverflowClass : public MathException {
public:
	/**
	* オーバーフロークラスのコンストラクタ
	* @param inputValue オーバーフローした値
	* @author Sawa
	* @since 9.10
	*/
	OverflowClass(int inputValue) : overflowValue(inputValue) {}

	/**
	* オーバーフローした際の値のゲッタ
	* @author Sawa
	* @since 9.10
	*/
	int getValue() const { return overflowValue;}

//データメンバ
private:
	//オーバーフローした値
	int overflowValue;
};

//アンダーフロー例外クラス
class UnderflowClass : public MathException{
public:

	/**
	* アンダーフロークラスのコンストラクタ
	* @param inputValue アンダーフローした値
	* @author Sawa
	* @since 9.10
	*/
	UnderflowClass(int inputValue) : underflowValue(inputValue) {}

	/**
	* アンダーフローした際の値のゲッタ
	* @author Sawa
	* @return underflowValue アンダーフローした値
	* @since 9.10
	*/
	int getValue() const { return underflowValue;}

//データメンバ
private:
	//アンダーフローした値
	int underflowValue;
};

#endif
