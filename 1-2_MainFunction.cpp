/*演習1-2 本文で学習したクラスは、例えば2015年2月30日といった不正な日付での初期化や代入などを許してしまう。
コンストラクタなどに与えられた日付が不正であれば、正しい日付に補正するよう書き換えたクラスを作成せよ。*/

#include<iostream>
#include<string>
#include"1-2_MemberDefinition.cpp"
#include"1-2_DateClass.h"

using namespace std;

/**
* 日付に関する情報を表示
* @param inputDate 日付
* @author Sawa
* @since 7.26
*/
void displayDate(const DateClass& inputDate)
{
	//曜日を格納した文字列配列
	string dayOfWeek[] = { "日", "月", "火", "水", "木", "金", "土" };

	//日付の情報を表示することを告知
	cout << "・日付" << inputDate << "に関する情報\n";

	//曜日を表示
	cout << "  曜日は" << dayOfWeek[inputDate.dayOfWeek()] << "曜日";

	//年内経過日数を表示
	cout << "  年内経過日数は" << inputDate.dayOfYear() << "日";

	//1970年からの経過日数を表示
	cout << "  1970年1月1日の" << long(inputDate) << "日後";

	//閏年かどうかを表示
	cout << "  その年は閏年で" << (inputDate.leapYear() ? "ある。" : "はない ") << '\n';
}

/**
* 日付を変更する
* @param inputDate 日付
* @author Sawa
* @since 7.26
*/
void changeDate(DateClass& inputDate)
{
	//日付変更を行うループ
	while (true) {

		//メニューを表示
		cout << "[1]年変更　[2]月変更　[3]日変更　[4]年月日変更　[5]n日進める　[6]n日戻す　[0]戻る :  ";

		//メニューの番号
		int userSelect;

		//メニューの番号を入力
		cin >> userSelect;

		//入力番号が0
		if (userSelect == 0) {

			//日付変更終了
			return;
		}

		int inputYear;   //変更後の年　
		int	inputMonth;  //変更後の月
		int	inputDay;    //変更後の日
		int	changeDay;   //変化させたい日数

						 //入力番号が1か4
		if (userSelect == 1 || userSelect == 4) {

			//変更後の年の入力を促す
			cout << "年 : ";
			//入力
			cin >> inputYear;
		}

		//入力番号が2か4
		if (userSelect == 2 || userSelect == 4) {

			//変更後の月の入力を促す
			cout << "月 : ";
			//入力
			cin >> inputMonth;

		}

		//入力番号が3か4
		if (userSelect == 3 || userSelect == 4) {

			//変更後の日の入力を促す
			cout << "日 : ";
			//入力
			cin >> inputDay;
		}

		//入力番号が5か6
		if (userSelect == 5 || userSelect == 6) {

			//変更を加える日数の入力を促す
			cout << "日数 : ";
			//入力
			cin >> changeDay;
		}

		//入力番号によって処理を分岐
		switch (userSelect) {
			//入力番号が1
		case 1:
			//年数変更
			inputDate.setYear(inputYear);
			//日付変更メニューに戻る
			break;

			//入力番号が2
		case 2:
			//月数変更
			inputDate.setMonth(inputMonth);
			//日付変更メニューに戻る
			break;

			//入力番号が3
		case 3:
			//日数変更
			inputDate.setDay(inputDay);
			//日付変更メニューに戻る
			break;

			//入力番号が4
		case 4:
			//年月日を変更
			inputDate.setDate(inputYear, inputMonth, inputDay);
			//日付変更メニューに戻る
			break;

			//入力番号が5
		case 5:
			//日数を進める
			inputDate += changeDay;
			//日付変更メニューに戻る
			break;

			//入力番号が6
		case 6:
			//日数を戻す
			inputDate -= changeDay;
			//日付変更メニューに戻る
			break;

			//入力番号がそれ以外
		default:
			//日付変更メニューに戻る
			break;
		}
		//更新後の日付を表示
		cout << inputDate << "に更新されました。\n";
	}
}

/**
* 日付をインクリメントかデクリメント
* @param inputDate 日付
* @author Sawa
* @since 7.26
*/
void adaptIncrementDecrement(DateClass& inputDate)
{
	//日付変更を行うループ
	while (true) {

		//メニューを表示
		cout << "[1]++day  [2]day++  [3]--day  [4]day-- [0]戻る : ";

		//メニューの番号
		int userSelect;

		//メニューの番号を入力
		cin >> userSelect;

		//入力番号が0
		if (userSelect == 0) {

			//日付変更終了
			return;
		}

		//入力番号によって処理を分岐
		switch (userSelect) {

			//入力番号が1
		case 1:
			//前置増分演算子を適用して表示
			cout << "++day = " << ++inputDate << '\n';
			//日付変更メニューに戻る
			break;

			//入力番号が2
		case 2:
			//後置増分演算子を適用して表示
			cout << "day++ = " << inputDate++ << '\n';
			//日付変更メニューに戻る
			break;

			//入力番号が3
		case 3:
			//前置減分演算子を適用して表示
			cout << "--day = " << --inputDate << '\n';
			//日付変更メニューに戻る
			break;

			//入力番号が4
		case 4:
			//後置減分演算子を適用して表示
			cout << "day-- = " << inputDate-- << '\n';
			//日付変更メニューに戻る
			break;

			//入力番号がそれ以外
		default:
			//日付変更メニューに戻る
			break;
		}
		//変更後の日付を表示
		cout << "day  = " << inputDate << '\n';
	}
}

/**
* 前後の日付を求める
* @param inputDate 日付
* @author Sawa
* @since 7.26
*/
void beforeAfter(DateClass& inputDate)
{
	//前後の日付を求めるループ
	while (true) {

		//メニューを表示
		cout << "[1]翌日 [2]前日 [3]n日後(day+n) [4]n日後(n+day) [5]n日前 [0]戻る : ";


		//メニューの番号
		int userSelect;

		//メニューの番号を入力
		cin >> userSelect;

		//入力番号が0
		if (userSelect == 0) {

			//日付計算終了
			return;
		}

		//計算に使用する日数
		int changeDay;

		//入力番号が3か5の場合
		if (userSelect >= 3 && userSelect <= 5) {

			//計算に使用する日数の入力を促す
			cout << "日数 : ";

			//入力
			cin >> changeDay;
		}

		cout << "それは";

		//入力番号によって処理を分岐
		switch (userSelect)
		{
			//入力番号が1
		case 1:
			//翌日の日付を表示
			cout << inputDate.followingDay();
			//日付計算メニューに戻る
			break;

			//入力番号が2
		case 2:
			//前日の日付を表示
			cout << inputDate.precedingDay();
			//日付計算メニューに戻る
			break;

			//入力番号が3
		case 3:
			//入力日数後の日付を表示
			cout << inputDate + changeDay;
			//日付計算メニューに戻る
			break;

			//入力番号が4
		case 4:
			//入力日数後の日付を表示
			cout << changeDay + inputDate;
			//日付計算メニューに戻る
			break;

			//入力番号が5
		case 5:
			//入力日数前の日付を表示
			cout << inputDate - changeDay;
			//日付計算メニューに戻る
			break;
		}
		//語尾
		cout << "です。\n";
	}
}

/**
* 日付の比較を行う
* @param inputDate 日付
* @author Sawa
* @since 7.26
*/
void compareDate(const DateClass& inputDate)
{
	//比較対象となる日付day2のデータメンバ

	int inputYear;  //年
	int inputMonth; //月
	int inputDay;   //日

					//日付の入力を促す
	cout << "比較対象の日付day2を入力せよ。\n";

	//年入力
	cout << "年 : ";
	cin >> inputYear;

	//月入力
	cout << "月 : ";
	cin >> inputMonth;

	//日入力
	cout << "日 : ";
	cin >> inputDay;

	//day2を初期化
	DateClass secondDate(inputYear, inputMonth, inputDay);

	//bool型の値を"True" or "False"で表示
	cout << boolalpha;

	//日付を表示
	cout << "day = " << inputDate << '\n';

	//day2を表示
	cout << "day2 = " << secondDate << '\n';

	//演算子関数を適用した結果を表示
	cout << "day  - day2 = " << (inputDate - secondDate) << '\n';  // =
	cout << "day2 - day  = " << (secondDate - inputDate) << '\n';  // -
	cout << "day == day2 = " << (inputDate == secondDate) << '\n'; // ==
	cout << "day != day2 = " << (inputDate != secondDate) << '\n'; // !=
	cout << "day  > day2 = " << (inputDate > secondDate) << '\n';  // >
	cout << "day >= day2 = " << (inputDate >= secondDate) << '\n'; // >=
	cout << "day  < day2 = " << (inputDate < secondDate) << '\n';  // <
	cout << "day <= day2 = " << (inputDate <= secondDate) << '\n'; // <=
}

void mainMenu(DateClass& inputDate)
{
	//表示した日付に関する操作を行うループ
	while (true) {

		//メインメニュー表示
		cout << "[1]情報表示 [2]日付の変更 [3]増減分演算子 [4]前後の日付 [5]比較 [0]終了 : ";

		//メニューの番号
		int userSelect;

		//メニューの番号を入力
		cin >> userSelect;

		//入力番号が0以外の場合
		if (userSelect != 0) {

			switch (userSelect) {

				//入力番号が1
			case 1:
				//日付の情報を表示
				displayDate(inputDate);
				//メインメニューに戻る
				break;

				//入力番号が2
			case 2:
				//日付の変更を行う
				changeDate(inputDate);
				//メインメニューに戻る
				break;

				//入力番号が3
			case 3:
				//日付に増減分演算子を適用
				adaptIncrementDecrement(inputDate);
				//メインメニューに戻る
				break;

				//入力番号が4
			case 4:
				//日付を前後させた値を表示
				beforeAfter(inputDate);
				//メインメニューに戻る
				break;

				//入力番号が5
			case 5:
				//日付の比較を行う
				compareDate(inputDate);
				//メインメニューに戻る
				break;

				//入力番号がそれ以外
			default:
				//再入力
				break;
			}
		}
		//入力番号が0
		if (userSelect == 0) {

			//プログラム終了
			break;
		}
	}
}

int main()
{
	//日付day1のデータメンバ
	int inputYear;  //年
	int inputMonth; //月
	int inputDay;   //日

	//日付として適切な値を入力させるループ
	do {
		//年の入力を促す
		cout << "年 : ";
		//入力
		cin >> inputYear;

		//月の入力を促す
		cout << "月 : ";
		//入力
		cin >> inputMonth;

		//日の入力を促す
		cout << "日 : ";
		//入力
		cin >> inputDay;

	} while (inputYear < 1 || (inputMonth < 1 || inputMonth > 12) || inputDay < 1);

	//日付を初期化
	DateClass inputDate(inputYear, inputMonth, inputDay);

	//メインメニューを開く
	mainMenu(inputDate);
}
