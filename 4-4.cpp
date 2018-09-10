#include<iostream>
#include "4-4_Member.h"
#include "4-4_ResigningMember.h"

using namespace std;

int main()
{
	//派生クラスオブジェクト
	ResigningMember firstPerson("Sawa", 580, 42.5);

	//アップキャスト(エラー)
	//MemberClass* firstPersonPointer = &firstPerson;

	//private派生だったのでアップキャストできなかったものと思われる
}