/*
* new1-1.h
*
*  Created on: 2018/07/12
*      Author: ddt
*/

/*���K1-1 �N���XHuman�̃R���X�g���N�^��{�y�[�W�Ɏ������悤�ɏ����������v���O�������쐬���A
�����������Ғʂ�ɍs���邱�Ƃ��m�F����B*/


#ifndef ___NEW1_1_H_
#define ___NEW1_1_H_

#include<string>

//�l�ԃN���XHumanClass
class HumanClass {


	std::string fullName;  //���O
	int userHeight;        //�g��
	int userWeight;        //�̏d

public:

	//�R���X�g���N�^
	HumanClass(const std::string& inputName, int inputHeight, int inputWeight);

	//���O�̃Q�b�^
	std::string getName() const;

	//�g���̃Q�b�^
	int getHeight() const;

	//�̏d�̃Q�b�^
	int getWeight() const;

	//�̏d�𑝂₷
	void increaseWeight(int plusHeight);

	//�̏d�����炷
	void decreaseWeight(int minusHeight);
};

#endif
