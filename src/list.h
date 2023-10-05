#ifndef LIST_H
#define LIST_H
#include <iostream>

typedef struct aresta{
	int vertice_A;
	int vertice_B;
	int peso;

}Aresta;

class List{
		
	public:
		List();
		void insertEnd(List* vertice, int info, bool isFirst);
		~List();
		typedef struct element{
			int info;
			struct element* next; // Proximo elemento da lista
			List* rep; //Representante da lista
		}Node;

		int top();
		Node* head; // Ponteiro para o primeiro elemento
		Node* tail; // Ponteiro para o ultimo  elemento
		int tamanho;
	private:



};

#endif
