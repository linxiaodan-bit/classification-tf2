#include "DynamicArray.h"


DynamicArray::DynamicArray() {
	this->size = 0;
	this->capacity = 20;
	this->pAddr = new int[capacity];
}

DynamicArray::~DynamicArray() {
	delete[] pAddr;
}
	
// β��
void DynamicArray::pushBackArray(int value) {
	if (this->pAddr == nullptr)
	{
		return;
	}
	if (this->size == this->capacity)
	{
		int* newplace = new int[capacity * 2];
		memcpy(newplace, pAddr, capacity * sizeof(int));
		delete[] pAddr;
		this->pAddr = newplace;
		this->capacity = capacity * 2;
	}
	this->pAddr[this->size] = value;
	this->size++;
}
// ��ָ��λ�ò���һ������
void DynamicArray::insertArray(int pos, int value) {
	if (this->pAddr == nullptr)
	{
		return;
	}
	if (pos > this->size || pos < 0)
	{
		return;
	}
	if (this->size == this->capacity)
	{
		int* newplace = new int[capacity * 2];
		memcpy(newplace, pAddr, capacity * sizeof(int));
		delete[] pAddr;
		this->pAddr = newplace;
		this->capacity = capacity * 2;
	}
	int* test = new int[size - pos];
	for (int i=0;i < size-pos;i++)
	{
		test[i] = this->pAddr[pos + i];
	}
	pAddr[pos] = value;

	for (int i=1;i<=size-pos;i++)
	{
		pAddr[pos + i] = test[i-1];
	}
	this->size++;
	delete test;
	
}
// βɾ
void DynamicArray::popBackArray() {
	if (this->pAddr == nullptr) {
		return;
	}
	if (this->size == 0) {
		return;
	}
	this->size--;
}
// ��λ��ɾ��
void DynamicArray::removeArrayPos(int pos) {
	if (this->pAddr == nullptr) {
		return;
	}
	if (this->size <= pos || pos < 0) {
		return;
	}
	for (int i = pos; i < this->size - 1; i++) {
		this->pAddr[i] = this->pAddr[i + 1];
	}
	this->size--;
}
// ����ֵɾ��
void DynamicArray::removeArrayVal(int value) {
	if (this->pAddr == nullptr) {
		return;
	}
	int pos = findArrayPos(value);
	removeArrayPos(pos);
}
// �������
void DynamicArray::clearArray() {
	this->size = 0;
}
// ����
int DynamicArray::findArrayPos(int value) {
	if (this->pAddr == nullptr) {
		return -1;
	}
	for (int i = 0; i < this->size; i++) {
		if (this->pAddr[i] == value) {
			return i;
		}
	}
	return -1;
}
// ��ö�̬�����е�ǰԪ�صĸ���
int DynamicArray::getSizeArray() {
	return size;
}
// �����������
int DynamicArray::getCapactity() {
	return capacity;
}
// ���ĳ��λ�õ�Ԫ�ص�ֵ�Ƿ�Ϊ�����ֵ
bool DynamicArray::atArray(int pos, int& value) {
	if (this->pAddr == nullptr) {
		return false;
	}
	if (pos < 0 || pos >= size) {
		return false;
	}
	value = this->pAddr[pos];
	return true;
}
// ��ӡ����
void DynamicArray::showArray() {
	if (this->pAddr == nullptr) {
		return;
	}
	if (this->size == 0) {
		cout << "����Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < this->size; i++) {
		cout << this->pAddr[i] << " ";
	}
	cout << endl;
}