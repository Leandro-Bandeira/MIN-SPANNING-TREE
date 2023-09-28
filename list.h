#ifndef LIST_H
#define LIST_H
#include <iostream>



class List{
		
	public:
		List();
		void insertEnd(List* vertice, int info);
		~List();


	private:
		typedef struct element{
			int info;
			struct element* next; //Proximo elemento da lista
			List* rep; //Repressentada da lista
		}Node;
		int tamanho;
		Node* head; // Ponteiro para o primeiro elemento
		Node* tail; // Ponteiro para o ultimo  elemento



};

#endif
