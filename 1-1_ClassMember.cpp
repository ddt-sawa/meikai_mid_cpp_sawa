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
* コンストラクタ
* @param inputName 名前 inputHeight 身長 inputWeight 体重
* @author Sawa
* @since 7.27
*/
HumanClass::HumanClass(const string& inputName, int inputHeight, int inputWeight)

//課題に従い、コンストラクタ初期化子を使って初期化
: fullName(inputName), userHeight(inputHeight), userWeight(inputWeight){}

/**
* 体重のゲッタ
* @return fullName 名前
* @author Sawa
* @since 7.27
*/
const string& HumanClass::getName() const
{
	return fullName;
}

/**
* 身長のゲッタ
* @return userHeight 身長
* @author Sawa
* @since 7.27
*/
int HumanClass::getHeight() const
{
	return userHeight;
}

/**
* 体重のゲッタ
* @return userWeight 体重
* @author Sawa
* @since 7.27
*/
int HumanClass::getWeight() const
{
	return userWeight;
}

/**
* 体重を増やす
* @return plusWeight 加重量
* @author Sawa
* @since 7.27
*/
void HumanClass::increaseWeight(int plusWeight)
{
	userHeight += plusWeight;
}

/**
* 体重を減らす
* @return minusWeight 減重量
* @author Sawa
* @since 7.27
*/
void HumanClass::decreaseWeight(int minusWeight)
{
	userWeight -= minusWeight;
}
