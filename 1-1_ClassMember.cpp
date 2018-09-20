/*
 * new1-1.cpp
 *
 *  Created on: 2018/07/11
 *      Author: ddt
 */


#include<string>
#include<iostream>
#include"new1-1.h"

using namespace std;

/**
* �R���X�g���N�^
* @param inputName ���O inputHeight �g�� inputWeight �̏d
* @author Sawa
* @since 7.27
*/
HumanClass::HumanClass(const string& inputName, int inputHeight, int inputWeight)

//�ۑ�ɏ]���A�R���X�g���N�^�������q���g���ď�����
: fullName(inputName), userHeight(inputHeight), userWeight(inputWeight){}

/**
* �̏d�̃Q�b�^
* @return fullName ���O
* @author Sawa
* @since 7.27
*/
const string& HumanClass::getName() const
{
	return fullName;
}

/**
* �g���̃Q�b�^
* @return userHeight �g��
* @author Sawa
* @since 7.27
*/
int HumanClass::getHeight() const
{
	return userHeight;
}

/**
* �̏d�̃Q�b�^
* @return userWeight �̏d
* @author Sawa
* @since 7.27
*/
int HumanClass::getWeight() const
{
	return userWeight;
}

/**
* �̏d�𑝂₷
* @return plusWeight ���d��
* @author Sawa
* @since 7.27
*/
void HumanClass::increaseWeight(int plusWeight)
{
	userHeight += plusWeight;
}

/**
* �̏d�����炷
* @return minusWeight ���d��
* @author Sawa
* @since 7.27
*/
void HumanClass::decreaseWeight(int minusWeight)
{
	userWeight -= minusWeight;
}
