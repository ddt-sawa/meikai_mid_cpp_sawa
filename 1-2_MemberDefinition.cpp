/*演習1-2 本文で学習したクラスは、例えば2015年2月30日といった不正な日付での初期化や代入などを許してしまう。
コンストラクタなどに与えられた日付が不正であれば、正しい日付に補正するよう書き換えたクラスを作成せよ。*/

#ifndef ___MemberDefinition
#define ___MemberDefinition

#include<ctime>
#include<sstream>
#include<iostream>
#include"1-2_DateClass.h"

using namespace std;

//平年の各月の日数
int DateClass::dayOfMax[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
* その年の日数を返却
* @param inputYear 年
* @return int型の値 366,365
* @author Sawa
* @since 7.27
*/
int DateClass::dayOfYear(int inputYear)
{
	//閏年なら366を、そうでなければ365を返却
	return 365 + leapYear(inputYear);
}

/**
* その月の日数を返却
* @param inputYear 年, inputMonth 月
* @return dayofMax 日数
* @author Sawa
* @since 7.27
*/
int DateClass::dayOfMonth(int inputYear, int inputMonth)
{
	//平年の日数を返却するが、閏年2月の場合1を加える
	return dayOfMax[inputMonth - 1] + (inputMonth == 2 && leapYear(inputYear));
}

/**
* 現在の日付で初期化するデフォルトコンストラクタ
* @author Sawa
* @since 7.27
*/
DateClass::DateClass()
{
	//現在の日付を取得
	time_t currentDate = time(NULL);

	//取得した日付を格納する構造体を宣言
	struct tm exactTime;

	//取得した日付を構造体に格納
	localtime_s(&exactTime, &currentDate);

	//年を初期化
	userYear = exactTime.tm_year + 1900;

	//月を初期化
	userMonth = exactTime.tm_mon + 1;

	//日を初期化
	userDay = exactTime.tm_mday;
}

/**
* コンストラクタ
* @input inputYear 年, inputMonth 月, inputDay 日
* @author Sawa
* @since 7.27
*/
DateClass::DateClass(int inputYear, int inputMonth, int inputDay)
{
	setDate(inputYear, inputMonth, inputDay);
}

/**
* 入力年が閏年かどうかを判断
* @param inputYear 年
* @author Sawa
* @since 7.27
*/
bool DateClass::leapYear(int inputYear)
{
	//閏年ならTrueを、そうでなければFalseを返却
	return inputYear % 4 == 0 && (inputYear % 100 != 0 || inputYear % 400 == 0);
}

/**
* 静的メンバ関数を呼び出し、閏年かどうかを判断
* @author Sawa
* @since 7.27
*/
bool DateClass::leapYear() const { return leapYear(userYear); }

/**
* 年のゲッタ
* @return userYear 年
* @author Sawa
* @since 7.27
*/
int DateClass::getYear() const { return userYear; }

/**
* 月のゲッタ
* @return userMonth 月
* @author Sawa
* @since 7.27
*/
int DateClass::getMonth() const { return userMonth; }

/**
* 日のゲッタ
* @return userDay 日
* @author Sawa
* @since 7.27
*/
int DateClass::getDay() const { return userDay; }

/**
* 年のセッタ
* @param inputYear 年
* @author Sawa
* @since 7.27
*/
void DateClass::setYear(int inputYear) { userYear = inputYear; }

/**
* 月のセッタ
* @param inputMonth 月
* @author Sawa
* @since 7.27
*/
void DateClass::setMonth(int inputMonth) { userMonth = inputMonth; }

/**
* 日のセッタ
* @param inputDay 日
* @author Sawa
* @since 7.27
*/
void DateClass::setDay(int inputDay) { userDay = inputDay; }

/**
* 日付のセッタ
* @param inputDay 年, inputMonth 月, inputDay 日
* @author Sawa
* @since 7.27
*/
void DateClass::setDate(int inputYear, int inputMonth, int inputDay)
{
	//年
	userYear = inputYear;

	//月
	userMonth = inputMonth;

	//日
	userDay = inputDay;

	//日数がその月の最大日数より大きい場合
	if (inputDay > dayOfMonth(inputYear, inputMonth)) {

		//超過日数を計算
		int overDate = (inputDay - dayOfMonth(inputYear, inputMonth));

		//超過日数分、日付を進める
		(*this) += overDate;
	}
}

/**
* 前日の日付を求める
* @return temporaryDate 前日の日付
* @author Sawa
* @since 7.27
*/
DateClass DateClass::precedingDay() const
{
	//計算用に自身の値を保存
	DateClass temporaryDate(*this);
	//計算用オブジェクトをデクリメントして返却
	return --temporaryDate;
}

/**
* 翌日の日付を求める
* @return temporaryDate 翌日の日付
* @author Sawa
* @since 7.27
*/
DateClass DateClass::followingDay() const
{
	//計算用に自身の値を保存
	DateClass temporaryDate(*this);
	//計算用オブジェクトをインクリメントして返却
	return ++temporaryDate;
}

/**
* 年内経過日数を返却
* @return spendDays 年内経過日数
* @author Sawa
* @since 7.27
*/
int DateClass::dayOfYear() const
{
	//年内経過日数を現在の日数に設定
	int spendDays = userDay;

	//正月から前月までの日数を加算代入するループ
	for (int firstCounter = 1; firstCounter < userMonth; ++firstCounter) {

		//月ごとの日数を加算代入
		spendDays += dayOfMonth(userYear, firstCounter);
	}
	//年内経過日数を返却
	return spendDays;
}

/**
* その日付の曜日に対応した整数を返却
* @return int型の値 0-6(日-土に対応)
* @author Sawa
* @since 7.27
*/
int DateClass::dayOfWeek() const
{
	//計算用に年を保存
	int temporaryYear = userYear;
	//計算用に月を保存
	int temporaryMonth = userMonth;

	//1月または2月の場合
	if (temporaryMonth == 1 || temporaryMonth == 2) {

		//計算用年数をデクリメント
		--temporaryYear;

		//計算用月数に12を加える
		temporaryMonth += 12;
	}
	//ツェラーの公式を適用し、値を返却
	return (temporaryYear + temporaryYear / 4 - temporaryYear / 100 + temporaryYear / 400 + (13 * temporaryMonth + 8) / 5 + userDay) % 7;
}

/**
* 1970年からの経過日数を返却する変換関数
* @return long型の値 日数
* @author Sawa
* @since 7.27
*/
DateClass::operator long() const
{
	//経過日数をlong型で返却する
	return *this - DateClass(1970, 1, 1);
}

/**
* 日付を1日進める(前置増分演算子)
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass& DateClass::operator++()
{
	//日数をインクリメントし、その値が月の最大日数を超えた場合
	if (++userDay > dayOfMonth(userYear, userMonth)) {

		//月数をインクリメントし、その値が12を超えた場合
		if (++userMonth > 12) {

			//年数をインクリメント
			++userYear;

			//月を1月に設定
			userMonth = 1;
		}

		//日数を朔日に設定
		userDay = 1;
	}
	//自身への参照を返却
	return *this;
}

/**
* 日付を1日進める(後置増分演算子)
* @return 元の日付
* @author Sawa
* @since 7.27
*/
DateClass DateClass::operator++(int)
{
	//返却用に値をコピー
	DateClass temporaryDate(*this);

	//前置増分演算子を自身に適用
	++(*this);

	//コピーしていた値を返却
	return temporaryDate;
}

/**
* 日付を1日戻す(前置減分演算子)
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass& DateClass::operator--()
{
	//日数をデクリメントし、その値が1より小さい場合
	if (--userDay < 1) {

		//月数をデクリメントし、その値が1より小さい場合
		if (--userMonth < 1) {

			//年数をデクリメント
			--userYear;

			//月数を12に設定
			userMonth = 12;
		}
		//日数をその年の最大日数に設定
		userDay = dayOfMonth(userYear, userMonth);
	}
	//自身への参照を返却
	return *this;
}

/**
* 日付を1日戻す(後置減分演算子)
* @return temporaryDate 元の日付
* @author Sawa
* @since 7.27
*/
DateClass DateClass::operator--(int)
{
	//返却用に値を保存
	DateClass temporaryDate(*this);

	//自身に前置減分演算子を適用
	--(*this);

	//保存していた値を返却
	return temporaryDate;
}

/**
* 日付を指定日数進める
* @inputDay 指定日数
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass&DateClass::operator+=(int inputDay)
{
	//指定日数が負の場合
	if (inputDay < 0) {

		//-=演算子を適用
		return *this -= -inputDay;
	}

	//現在の日付に指定日数を加算代入
	userDay += inputDay;

	//日数がその月の最大日数より小さくなるまでループ
	while (userDay > dayOfMonth(userYear, userMonth)) {

		//日数にその月の最大日数を減算代入
		userDay -= dayOfMonth(userYear, userMonth);

		//月をインクリメントし、その値が12を超えた場合
		if (++userMonth > 12) {

			//年をインクリメント
			++userYear;

			//月数を1に設定
			userMonth = 1;
		}
	}
	//自身への参照を返却
	return *this;
}

/**
* 日付を指定日数戻す
* @inputDay 指定日数
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass& DateClass::operator-=(int inputDay)
{
	//指定日数が負の場合
	if (inputDay < 0) {

		//+=演算子を適用
		return *this += -inputDay;
	}
	//現在の日付に指定日数を加算代入
	userDay -= inputDay;

	//日数が１以上になるまでループ
	while (userDay < 1) {

		//月数をデクリメントし、その値が1より小さい場合
		if (--userMonth < 1) {

			//年数をデクリメント
			--userYear;

			//月数を12に設定
			userMonth = 12;
		}
		//日数にその月の最大日数を加算代入
		userDay += dayOfMonth(userYear, userMonth);
	}
	//自身への参照を返却
	return *this;
}

/**
* 日付の指定日後を求める (日付 + int)
* @inputDay 指定日数
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass DateClass::operator+(int inputDay) const
{
	//返却用に値を保存
	DateClass temporaryDate(*this);

	//返却用の値に入力日数を加算代入
	return temporaryDate += inputDay;
}

/**
* 日付の指定日後を求める (int + 日付)
* @inputDay 指定日数
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass operator+(int inputDay, const DateClass& inputDate)
{
	//(DateClass + int)の間接演算子を適用　
	return inputDate + inputDay;
}

/**
* 日付の指定日前を求める (日付 - int)
* @inputDay 指定日数
* @return 自身への参照
* @author Sawa
* @since 7.27
*/
DateClass DateClass::operator-(int inputDay) const
{
	//返却用に値を保存
	DateClass temporaryDate(*this);

	//返却用の値に入力日数を減算代入
	return temporaryDate -= inputDay;
}

/**
* 日付の差を求める (日付 - 日付)
* @inputDay 指定日数
* @return long型の値 日数差
* @author Sawa
* @since 7.27
*/
long DateClass::operator-(const DateClass& inputDate) const
{

	//合計日数差
	long differenceofDate = 0;

	//自身の年内経過日数
	long selfValue = this->dayOfYear();

	//引数の年内経過日数
	long inputValue = inputDate.dayOfYear();

	//両日付の年数が等しい場合
	if (userYear == inputDate.userYear) {

		//年内経過日数の差が合計日数差となる
		differenceofDate = selfValue - inputValue;
	}

	//そうでなく、自身の年数の方が大きい場合の場合
	else if (userYear > inputDate.userYear) {

		//合計日数差に、引数のその年における残り日数を加算し、さらに自身の年内経過日数を加算する
		differenceofDate = (inputDate.userYear) - inputValue + selfValue;

		//両日付の年数差-1（既に1年分は前行で計算しているため）を日数差に換算するループ
		for (int firstCounter = inputDate.userYear + 1; firstCounter < userYear; ++firstCounter) {

			//年数差を日数差に変換し、合計日数差に加算代入する
			differenceofDate += dayOfYear(firstCounter);
		}
	}
	//そうでなく、引数の年数の方が大きい場合の場合
	else {
		//合計日数差に、引数のその年における残り日数を加算し、さらに自身の年内経過日数を加算する
		differenceofDate = -(dayOfYear(userYear) + inputValue - selfValue);

		//両日付の年数差-1（既に1年分は前行で計算しているため）を日数差に換算するループ
		for (int firstCounter = userYear + 1; firstCounter < inputDate.userYear; ++firstCounter) {

			//年数差を日数差に変換し、合計日数差に加算代入する
			differenceofDate += dayOfYear(firstCounter);
		}
	}
	//合計日数差を返却する
	return differenceofDate;
}

/**
* 二つの日付が等しいかを判断する演算子関数==
* @param inputDate 日付
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator==(const DateClass& inputDate) const
{
	//日付が等しければTrue、そうでなければFalseを返却
	return userYear == inputDate.userYear && userMonth == inputDate.userMonth && userDay == inputDate.userDay;
}

/**
* 二つの日付が等くないかを判断する演算子関数!=
* @param inputDate 日付
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator!=(const DateClass& inputDate) const
{
	//日付が等しければFalse、そうでなければTrueを返却
	return !(*this == inputDate);
}
/**
* 自身の日付が引数より大きいかどうかを判断する演算子関数>
* @param inputDate
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator>(const DateClass& inputDate) const
{

	//日付の年数が異なる場合
	if (userYear != inputDate.userYear) {

		//年数の大小を比較
		return userYear > inputDate.userYear;
	}

	//そうでなく、日付の月数が異なる場合
	else if (userMonth != inputDate.userMonth) {

		//月数の大小を比較
		return userMonth > inputDate.userMonth;
	}

	//そうでない場合
	else {

		//日にちの大小を比較
		return userDay > inputDate.userDay;
	}
}

/**
* 自身の日付が引数以上かどうかを判断する演算子関数>=
* @param inputDate 日付
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator>=(const DateClass& inputDate) const
{
	//<演算子の結果に!演算子を適用
	return !(*this < inputDate);
}

/**
* 自身の日付が引数より小さいかどうかを判断する演算子関数>
* @param inputDate 日付
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator<(const DateClass& inputDate) const
{
	//日付の年数が異なる場合
	if (userYear != inputDate.userYear) {

		//年数の大小を比較
		return userYear < inputDate.userYear;
	}

	//そうでなく、日付の月数が異なる場合
	else if (userMonth != inputDate.userMonth) {

		//月数の大小を比較
		return userMonth < inputDate.userMonth;
	}

	//そうでない場合
	else {

		//日にちの大小を比較
		return userDay < inputDate.userDay;
	}
}

/**
* 自身の日付が引数以下かどうかを判断する演算子関数>=
* @param inputDate 日付
* @return bool型の値
* @author Sawa
* @since 7.26
*/
bool DateClass::operator<=(const DateClass& inputDate) const
{
	//>算子の結果に!演算子を適用
	return !(*this < inputDate);
}

/**
* DateClass型のオブジェクトに年月日を加えた文字列を返却する
* @return string型の値　DateClass型の文字列表現
* @author Sawa
* @since 7.25
*/
string DateClass::getString() const
{
	//文字列ストリームを宣言
	ostringstream inputString;

	//DateClass型のオブジェクトに年月日を加えた文字列を文字列ストリームに挿入
	inputString << userYear << "年" << userMonth << "月" << userDay << "日";

	//文字列ストリームの情報を文字列にして返却
	return inputString.str();
}

/**
* 出力ストリームにDateClass型の文字列表現を挿入
* @param userString 出力ストリーム, userDate DateClass型オブジェクト
* @return ostream型 TimeClass型オブジェクトの文字列表現を挿入した出力ストリームへの参照
* @author Sawa
* @since 7.26
*/
ostream& operator<<(ostream& inputString, const DateClass& inputDate)
{
	//DateClass型オブジェクトの文字列表現を挿入した出力ストリームへの参照を返却
	return inputString << inputDate.getString();
}

/**
* 文字列表現からDateClass型の情報を抜き取る
* @param inputString 入力ストリーム, inputDate 情報格納先のDateClass型オブジェクト
* @return istream型 入力ストリームへの参照
* @author Sawa
* @since 7.26
*/
istream& operator>>(istream& inputString, DateClass& inputDate)
{
	int inputYear;    //年
	int inputMonth;   //月
	int inputDay;     //日

	char spaceCharacter; // 読み飛ばす文字

	//文字列表現から年月日の情報を取得
	inputString >> inputYear >> spaceCharacter >> inputMonth >> spaceCharacter >> spaceCharacter >> inputDay;

	//取得した情報を日付クラスに代入
	inputDate = DateClass(inputYear, inputMonth, inputDay);

	//入力ストリームへの参照を返却
	return inputString;
}

#endif