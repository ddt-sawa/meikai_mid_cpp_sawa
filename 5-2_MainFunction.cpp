/*演習5-2 List5-18の関数senior_printの引数を、ポインタでなく参照に書き換えたプログラムを作成せよ。*/

//一般会員定義
#include "5-2_Member.h"
//優待会員定義
#include "5-2_VipMember.h"
//長寿会員定義
#include "5-2_SeniorMember.h"
#include<iostream>
#include<string>

using namespace std;

/**
* 長寿会員のみの情報を表示する
* @param inputMember 会員インスタンス
* @author Sawa
* @since 9.5
*/
void printOnlySenior(MemberClass& inputMember)
{
	//例外を探知
	try {
		//一般会員から長寿会員へのダウンキャストを実行
		MemberClass& memberPointer = dynamic_cast<SeniorMemberClass&>(inputMember);

		//ダウンキャストが成功した場合自己紹介を表示
		memberPointer.printInformation();
	}

	//ダウンキャストに失敗した場合何も表示しない
	catch (bad_cast) {};
}

int main()
{
	//一般会員A
	MemberClass normalMember("武田俊也", 1, 65.4);

	//優待会員B
	VipMemberClass vipMember("三須健太郎", 2, 100, "20%OFF");

	//長寿会員C
	SeniorMemberClass seniorMember("伊藤隆二", 3, 45.8, 4);

	//一般会員(表示されない)
	printOnlySenior(normalMember);

	//優待会員(表示されない)
	printOnlySenior(vipMember);

	//長寿会員(自己紹介が表示)
	printOnlySenior(seniorMember);
}