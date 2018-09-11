/*演習1-2 本文で学習したクラスは、例えば2015年2月30日といった不正な日付での初期化や代入などを許してしまう。
コンストラクタなどに与えられた日付が不正であれば、正しい日付に補正するよう書き換えたクラスを作成せよ。*/

#ifndef ___NEW1_2_H_
#define ___NEW1_2_H_

//日付を表すDateClass
class DateClass {
public:

	// 入力年が閏年かどうかを判断
	static bool leapYear(int inputYear);

	//デフォルトコンストラクタ
	DateClass();
	//コンストラクタ
	DateClass(int inputYear, int inputMonth = 1, int inputDay = 1);

	//閏年かどうかを判断する
	bool leapYear() const;

	//年のゲッタ
	int getYear() const;
	//月のゲッタ
	int getMonth() const;
	//日のゲッタ
	int getDay() const;

	//年のセッタ
	void setYear(int inputYear);
	//月のセッタ
	void setMonth(int inputMonth);
	//日のセッタ
	void setDay(int inputDay);
	//日付のセッタ
	void setDate(int inputYear, int inputMonth, int inputDay);

	//前日の日付を求める
	DateClass precedingDay() const;

	//翌日の日付を求める
	DateClass followingDay() const;

	//年内の経過日数を返却
	int dayOfYear() const;

	//曜日を返却
	int dayOfWeek() const;

	//long型への変換関数
	operator long() const;

	//演算子関数++(前置)
	DateClass& operator++();

	//演算子関数++(後置)
	DateClass  operator++(int);

	//演算子関数--(前置)
	DateClass& operator--();
	//演算子関数--(後置)
	DateClass  operator--(int);

	//演算子関数+=
	DateClass& operator+=(int inputDay);

	//演算子関数-=
	DateClass&  operator-=(int inputDay);

	//演算子関数+
	DateClass operator+(int inputDay) const;

	//フレンド演算子関数+
	friend DateClass operator+(int inputDay, const DateClass& inputDate);

	//演算子関数-
	DateClass operator-(int inputDay) const;
	long operator-(const DateClass& inputDate) const;

	//演算子関数==
	bool operator== (const DateClass& inputDate) const;
	//演算子関数!=
	bool operator!= (const DateClass& inputDate) const;
	//演算子関数>
	bool operator> (const DateClass& inputDate) const;
	//演算子関数>=
	bool operator>= (const DateClass& inputDate) const;
	//演算子関数<
	bool operator< (const DateClass& inputDate) const;
	//演算子関数<=
	bool operator<= (const DateClass& inputDate) const;

	//日付を文字列にして返却
	std::string getString() const;

private:
	int userYear;   //年
	int userMonth;  //月
	int userDay;    //日

					//平年の各月の日数
	static int dayOfMax[];

	//実際の各月の年数
	static int dayOfYear(int inputYear);

	//その月の日数
	static int dayOfMonth(int inputYear, int inputMonth);

};

//演算子関数<<
std::ostream& operator<<(std::ostream& inputString, const DateClass& inputDate);
//演算子関数>>
std::istream& operator>>(std::istream& inputString, DateClass& inputDate);

#endif
