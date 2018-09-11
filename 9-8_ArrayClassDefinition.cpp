#ifndef ___ArrayClassDefinition
#define ___ArrayClassDefinition

/**
* �Y�����z��N���X�I�u�W�F�N�g�ɂ����đÓ��ł��邩�𔻒f����
* @param inputIndex �Y��
* @return bool�^�̒l
* @author Sawa
* @since 8.13
*/
template <class TypeName>
bool ArrayClass<TypeName>::judgeIndex(int inputIndex) {

	//�Y����0�ȏォ�v�f����菬�������True,�����łȂ����False��ԋp
	return inputIndex >= 0 && inputIndex < arraySize;
}

/**
*�@�Y�����G���[�N���X�̃R���X�g���N�^
* @param inputPointer, inputIndex
* @return
* @author Sawa
* @since 8.13
*/
template<class TypeName>
ArrayClass<TypeName>::IndexError::IndexError(const ArrayClass* inputPointer, int inputIndex)

//�G���[���N�������I�u�W�F�N�g�ւ̃|�C���^�ƁA�s���ȓY�������f�[�^�����o�ɑ��
	: errorPointer(inputPointer), errorIndex(inputIndex) {}

/**
* �s���ȓY���̃Q�b�^
* @return�@errorIndex �s���ȓY��
* @author Sawa
* @since 8.13
*/
template<class TypeName>
int ArrayClass<TypeName>::IndexError::getArrayIndex() const
{
	//�s���ȓY����ԋp
	return errorIndex;
}

/**
* ArrayClass�^�̖����I�R���X�g���N�^
* @param inputArraySize �v�f��, inputValue �������l
* @return
* @author Sawa
* @since 8.13
*/
template<class TypeName>
ArrayClass<TypeName>::ArrayClass(int inputArraySize, const TypeName& inputValue) : arraySize(inputArraySize)
{
	//�z��Ɏg�p���郁�����̈���m�ۂ��A�擪�v�f�ւ̃|�C���^���f�[�^�����o�ɑ��
	arrayPointer = new TypeName[arraySize];

	//�z��̑S�v�f�ɏ������l(�f�t�H���g�ł�0)�������郋�[�v
	for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

		//�z��̗v�f�������l����
		arrayPointer[firstCounter] = inputValue;
	}
}

/**
* ArrayClass�^�̃R�s�[�R���X�g���N�^
* @param inputArray ���^�̃I�u�W�F�N�g
* @return
* @author Sawa
* @since 8.13
*/
template<class TypeName>
ArrayClass<TypeName>::ArrayClass(const ArrayClass<TypeName>& inputArray) {

	//�������q�����g�ł����
	if (&inputArray == this) {

		//�v�f��0
		arraySize = 0;

		//NULL�|�C���^���f�[�^�����o�Ɏ��I�u�W�F�N�g���쐬
		arrayPointer = NULL;
	}
	//�����łȂ��ꍇ
	else {

		//�����̗v�f������
		arraySize = inputArray.arraySize;

		//�v�f���Ԃ�̃������̈���m�ۂ��A�擪�v�f�ւ̃|�C���^���f�[�^�����o�ɑ��
		arrayPointer = new TypeName[arraySize];

		//�����̒l���R�s�[���郋�[�v
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//�����̒l���R�s�[
			arrayPointer[firstCounter] = inputArray.arrayPointer[firstCounter];
		}
	}
}

/**
* ArrayClass�^�̃f�X�g���N�^
* @author Sawa
* @since 8.13
*/
template<class TypeName>
ArrayClass<TypeName>::~ArrayClass() { delete[] arrayPointer; }

/**
* �v�f���̃Q�b�^
* @return arraySize �v�f��
* @author Sawa
* @since 8.13
*/
template<class TypeName>
int ArrayClass<TypeName>::getArraySize() const
{
	//�v�f����ԋp
	return arraySize;
}

/**
* ArrayClass�^�ɑ�����Z�q=��K�p���邽�߂̉��Z�q�֐�
* @param inputArray ���^�̃I�u�W�F�N�g
* @return
* @author Sawa
* @since 8.13
*/
template<class TypeName>
ArrayClass<TypeName>&  ArrayClass<TypeName>::operator=(const ArrayClass<TypeName>& inputArray)
{
	//�������I�u�W�F�N�g�����g�łȂ��ꍇ
	if (&inputArray != this)
	{
		//�v�f�����قȂ�ꍇ
		if (arraySize != inputArray.arraySize) {

			//�I�u�W�F�N�g��j��
			delete[] arrayPointer;

			//�����̗v�f������
			arraySize = inputArray.arraySize;

			//�v�f���Ԃ�̃������̈���m�ۂ��A�擪�v�f�ւ̃|�C���^���f�[�^�����o�ɑ��
			arrayPointer = new TypeName[arraySize];
		}
		//�����̒l���R�s�[���郋�[�v
		for (int firstCounter = 0; firstCounter < arraySize; ++firstCounter) {

			//�����̒l���R�s�[
			arrayPointer[firstCounter] = inputArray.arrayPointer[firstCounter];
		}
	}
	//���g�ւ̎Q�Ƃ�ԋp
	return *this;
}

/**
* ArrayClass�^�I�u�W�F�N�g�ɓY�����Z�q[]��K�p�ł���悤�ɂ��鉉�Z�q�֐�
* @param inputIndex �Y��
* @return ArrayClass�^�I�u�W�F�N�g��[]��K�p�����l�ւ̎Q��
* @author Sawa
* @since 8.13
*/
template<class TypeName>
TypeName&  ArrayClass<TypeName>::operator[](int inputIndex)
{
	//�Y���Ƃ��đÓ��łȂ��Y�������o���ꂽ�ꍇ
	if (!judgeIndex(inputIndex)) {

		//�Y���G���[�𑗏o
		throw IndexError(this, inputIndex);
	}
	//ArrayClass�^�I�u�W�F�N�g��[]��K�p�����l�ւ̎Q�Ƃ�ԋp
	return arrayPointer[inputIndex];
}

/**
* ArrayClass�^�I�u�W�F�N�g�ɓY�����Z�q[]��K�p�ł���悤�ɂ��鉉�Z�q�֐� (const��)
* @param inputIndex �Y��
* @return ArrayClass�^�I�u�W�F�N�g��[]��K�p�����l�ւ̎Q��
* @author Sawa
* @since 8.13
*/
template<class TypeName>
const TypeName& ArrayClass<TypeName>::operator[](int inputIndex) const
{
	//�Y���Ƃ��đÓ��łȂ��Y�������o���ꂽ�ꍇ
	if (!judgeIndex(inputIndex)) {

		//�Y���G���[�𑗏o
		throw IndexError(this, inputIndex);
	}
	//ArrayClass�^�I�u�W�F�N�g��[]��K�p�����l�ւ̎Q�Ƃ�ԋp
	return arrayPointer[inputIndex];
}
#endif