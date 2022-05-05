#include "DynamicArray.h"


DynamicArray::DynamicArray() {
	this->size = 0;
	this->capacity = 20;
	this->pAddr = new int[capacity];
}

DynamicArray::~DynamicArray() {
	delete[] pAddr;
}
	
// 尾插
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
// 在指定位置插入一个数据
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
// 尾删
void DynamicArray::popBackArray() {
	if (this->pAddr == nullptr) {
		return;
	}
	if (this->size == 0) {
		return;
	}
	this->size--;
}
// 据位置删除
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
// 根据值删除
void DynamicArray::removeArrayVal(int value) {
	if (this->pAddr == nullptr) {
		return;
	}
	int pos = findArrayPos(value);
	removeArrayPos(pos);
}
// 清空数组
void DynamicArray::clearArray() {
	this->size = 0;
}
// 查找
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
// 获得动态数组中当前元素的个数
int DynamicArray::getSizeArray() {
	return size;
}
// 获得数组容量
int DynamicArray::getCapactity() {
	return capacity;
}
// 获得某个位置的元素的值是否为输入的值
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
// 打印数组
void DynamicArray::showArray() {
	if (this->pAddr == nullptr) {
		return;
	}
	if (this->size == 0) {
		cout << "数组为空" << endl;
		return;
	}
	for (int i = 0; i < this->size; i++) {
		cout << this->pAddr[i] << " ";
	}
	cout << endl;
}