/*演習5-1 会員クラス群に、自己紹介をする仮想関数introduceを追加せよ。表示内容は自分で考えること。*/

//一般会員定義
#include "5-1_Member.h"
//優待会員定義
#include "5-1_VipMember.h"
//長寿会員定義
#include "5-1_SeniorMember.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	//一般会員A
	MemberClass normalMember("武田俊也", 1, 65.4);

	//優待会員B
	VipMemberClass vipMember("三須健太郎", 2, 100, "20%OFF");

	//長寿会員C
	SeniorMemberClass seniorMember("伊藤隆二", 3, 45.8, 4);

	//一般会員クラスのポインタを生成
	MemberClass* memberClassPointer = NULL;

	//一般会員クラスのポインタに、一般会員Aのアドレスを代入
	memberClassPointer = &normalMember;

	//一般会員版自己紹介を確認
	memberClassPointer->printIntrodution();

	//一般会員クラスのポインタに、優待会員Bのアドレスを代入
	memberClassPointer = &vipMember;

	//優待会員版自己紹介を確認
	memberClassPointer->printIntrodution();

	//一般会員クラスのポインタに長寿会員Bのアドレスを代入
	memberClassPointer = &seniorMember;

	//長寿会員版自己紹介を確認
	memberClassPointer->printIntrodution();	
}
