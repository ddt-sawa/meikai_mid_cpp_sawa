#ifndef ___Line
#define ___Line

#include <string>
#include<sstream>
#include<iostream>
#include "6-1_ShapeClass.h"

//�����N���X(���ۃN���X)
class LineClass : public ShapeClass {
public:

	/**
	* lineClass�^�I�u�W�F�N�g�̃R���X�g���N�^
	* @param inputLength ����
	* @author Sawa
	* @since 8.1
	*/
	LineClass(int inputLength) : lineLength(inputLength) {}

	/**
	* �����̃Q�b�^
	* @return lineLength ����
	* @author Sawa
	* @since 8.1
	*/
	int getLength() const { return lineLength; }

	/**
	* �����̃Z�b�^
	* @param inputLength ����
	* @author Sawa
	* @since 8.1
	*/
	void getLength(int inputLength) { lineLength = inputLength; }

	/**
	* �f�o�b�O����\��
	* @author Sawa
	* @since 8.1
	*/
	void printDebug() const
	{
		//��{�f�o�b�O����\��
		ShapeClass::printDebug();
		//������\��
		std::cout << "lineLength : " << lineLength << '\n';
	}
//�f�[�^�����o
protected:
	int lineLength; //����
};

//���������N���X
class HorizontalLineClass : public LineClass {

public:

	/**
	* HorizontalLineClass�^�I�u�W�F�N�g�̃R���X�g���N�^
	* @param inputLength ����
	* @author Sawa
	* @since 8.1
	*/
	HorizontalLineClass(int inputLength) : LineClass(inputLength) {}

	/**
	* ���������𕡐�����
	* @return ���������^�I�u�W�F�N�g�ւ̎Q��
	* @author Sawa
	* @since 8.1
	*/
	virtual HorizontalLineClass* makeClone() const {
		return new HorizontalLineClass(lineLength);
	}

	/**
	* ����������\������
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//�����̒����Ԃ�L����\�����郋�[�v
		for (int firstCounter = 1; firstCounter <= lineLength; ++firstCounter) {
			
			//�L����\��
			std::cout << '-';
		}
		//���s
		std::cout << '\n';
	}

	/**
	* ���������̏��𕶎���ɂ��ĕԋp����
	* @return ������\��
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//�o�̓X�g���[��
		std::ostringstream userStream;

		//�o�̓X�g���[���ɐ}�`�̏���}��
		userStream << "HorizontalLineClass(lineLenght:" << lineLength << ")";

		//�������ԋp
		return userStream.str();
	}
};

//���������N���X
class VerticalLineClass : public LineClass {

public:

	/**
	* VerticalLineClass�^�I�u�W�F�N�g�̃R���X�g���N�^
	* @param inputLength ����
	* @author Sawa
	* @since 8.1
	*/
	VerticalLineClass(int inputLength) : LineClass(inputLength) {}

	/**
	* ���������𕡐�����
	* @return ���������^�I�u�W�F�N�g�ւ̎Q��
	* @author Sawa
	* @since 8.1
	*/
	virtual VerticalLineClass* makeClone() const {
		return new VerticalLineClass(lineLength);
	}

	/**
	* ����������\������
	* @author Sawa
	* @since 8.1
	*/
	void printShape() const
	{
		//�����̒����Ԃ�L����\�����郋�[�v
		for (int firstCounter = 1; firstCounter <= lineLength; ++firstCounter) {

			//�L����\��
			std::cout << '|';

			//���s
			std::cout << '\n';
		}
	}

	/**
	* ���������̏��𕶎���ɂ��ĕԋp����
	* @return ������\��
	* @author Sawa
	* @since 8.1
	*/
	std::string getString() const
	{
		//�o�̓X�g���[��
		std::ostringstream userStream;

		//�o�̓X�g���[���ɐ}�`�̏���}��
		userStream << "VerticalLineClass(lineLength:" << lineLength << ")";

		//�������ԋp
		return userStream.str();
	}
};

#endif