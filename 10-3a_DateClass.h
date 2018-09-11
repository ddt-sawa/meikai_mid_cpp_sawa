/*演習10-3 第1章で作成した日付クラスDateや、前章で作成したTwin<>などの2次元配列を作成するプログラムを作成せよ。
List10-10に相当するものと、List10-11に相当するものの両方を作ること。
a List10-10に相当するもの*/

#ifndef ___DateClass
#define ___DateClass

//日付を表すDateClass
class DateClass {
	int userYear;   //年
	int userMonth;  //月
	int userDay;    //日

					//平年の各月の日数
	static int dayOfMax[];

	//実際の各月の年数
	static int dayOfYear(int inputYear);

	//その月の日数
	static int dayOfMonth(int inputYear, int inputMonth);

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
};

//演算子関数<<
std::ostream& operator<<(std::ostream& inputString, const DateClass& inputDate);
//演算子関数>>
std::istream& operator>>(std::istream& inputString, DateClass& inputDate);

#endif
