#ifndef LIST_H
#define LIST_H
#include <iostream>

typedef struct element{
	
	int info;
	struct element* next; // Proximo elemento da lista
	struct element* rep; // Representante da lista

}Node;

class List{
		
	public:
		List();
		~List();

	private:
		int tamanho;
		Node* head;
		Node* tail;



};

#endif
