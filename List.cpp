#include <iostream>
#include <memory>

using namespace std;

//Данные в буффер
struct Node {
	int data;
	shared_ptr<Node> next;
};

//Реализация буфера. 
class Queue {
private:
	
	shared_ptr<Node> top;
	shared_ptr<Node> bottom;
	unsigned int count = 0;

public:

	Queue(unsigned int size) {
	
		shared_ptr<Node> current(new Node);
		shared_ptr<Node> begin(new Node);
		current->data = 0;
		current->next = current;
		begin = current;

		this->top = begin;
		for (int i = 1; i < size; i++) {
			shared_ptr<Node> tmp(new Node);
			bottom = tmp;
			tmp->data = 0;
			tmp->next = begin;
			current->next = tmp;
			current = current->next;
		}
	}

	//Добавение элемента в буфер
	void enqueue(int value){

		bottom = bottom->next;
		bottom->data = value;
		count++;

	}

	//Удаление элемента из буфера	
	int dequeue(){
		if (count != 0) {
			int deleted;
			deleted = top->data;
			top->data = 0;
			top = top->next;
			count--;
			return deleted;
		}
		else {
			return -1;
		}
	}

	//Возвращает количество элементов в буфере
	unsigned int size() {
		return count;
	}

	//Флаг пустого буфера
	bool isEmpty(){
		if (count == 0) { return true; }
		else return false;
	}

	//Возвращение первого элемента в очереди
	int first() {
		return top->data;
	}

};