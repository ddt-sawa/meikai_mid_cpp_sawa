/*
* new1-1test.cpp
*
*  Created on: 2018/07/12
*      Author: ddt
*/

#include<iostream>
#include<string>
#include"1-1_Header.h"

using namespace std;

int main()
{
	//����
	HumanClass TaroNakano("���쑾�Y", 173, 65);
	//�X�c
	const HumanClass KoujiMorita("�X�c�F�i", 168, 71);

	//�R���X�g���N�^�������q�ɂ���ď��������ł��Ă��邩���m�F
	cout << "TaroNakano = " << TaroNakano.getName() << "  " << TaroNakano.getHeight() << "cm  " << TaroNakano.getWeight() << "kg\n";

	//����
	cout << "KoujiMorita = " << KoujiMorita.getName() << "  " << KoujiMorita.getHeight() << "cm  " << KoujiMorita.getWeight() << "kg\n";
}

//���������m�F
