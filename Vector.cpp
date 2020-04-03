#include <iostream>
#include <vector>

using namespace  std;

class Queue {

private:
	
	unsigned int top_;   //позиция верхнего элемента
	unsigned int bottom_;//позиция последнего элемента
	unsigned int size_;  //размер буфера
	unsigned int real_size_; //количество элементов в буфере

public:
	
	vector<int> buff;

	//конструктор
	Queue(unsigned int size){
		top_ = 0;
		bottom_ = 0;
		size_ = 0;
		buff.reserve(size);
		for (int i = 0; i < value; i++) {
			buff.push_back(0);
			this->size_++;
		}
	}

	//добавление элемента в буфер
	void enqueue(int value) {
		if (bottom_ < size_) {
			this->buff[bottom_] = value;
			bottom_ += 1;
		}
		else {
			this->buff[0] = value;
			this->bottom_ = 1;
		}
		if (real_size_ < size_) {
			this->real_size_++;
		}
		else {
			this->real_size_ = 10;
		}
	}

	//удаление элемента из буфера
	int dequeue() {
		int deleted;
		if (top_ < size_) {
			deleted = this->buff[top_];
			this->buff[top_] = 0;
			this->top_++;
		}
		else {
			deleted = this->buff[top_];
			this->buff[top_] = 0;
			this->top_ = 0;
		}
		if (real_size_ > 0) {
			this->real_size_--;
		}
		else {
			this->real_size_ = 0;
		}
		return deleted;
	}
	
	//значение верхнего элемента
	int first(){
		if (top_ == size_) {
			this->top_ = 0;
		}
		return this->buff[top_];
	}
	
	//размер буфера
	int size_of() {
		return this->buff.size();
	}

	//флаг пустого буфера
	bool isEmpty() {
		if (this->real_size_ == 0) { return true; }
		else return false;
	}


};