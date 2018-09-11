/*演習9-2 1-2節で作成したDate型のTwin<>と、Date型のTwin<>のTwin<>を作るプログラムを作成せよ。*/

#ifndef ___DateClass
#define ___DateClass

//日付を表すDateClass
class DateClass {
public:

	//閏年かどうかを判断
	static bool leapYear(int inputYear)
	{
		//閏年ならTrueを、そうでなければFalseを返却
		return inputYear % 4 == 0 && (inputYear % 100 != 0 || inputYear % 400 == 0);
	}

	//デフォルトコンストラクタ
	DateClass();
	//コンストラクタ
	DateClass(int inputYear, int inputMonth = 1, int inputDay = 1);

	//閏年かどうかを判断する
	bool leapYear() const { return leapYear(userYear); }

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

	//その年の実際の日数を返却する
	static int dayOfYear(int inputYear);

	//その月の日数
	static int dayOfMonth(int inputYear, int inputMonth);

};

//演算子関数<<
std::ostream& operator<<(std::ostream& inputString, const DateClass& inputDate);
//演算子関数>>
std::istream& operator>>(std::istream& inputString, DateClass& inputDate);


#endif
