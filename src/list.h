#ifndef LIST_H
#define LIST_H
#include <iostream>

typedef struct aresta{
	int vertice_A;
	int vertice_B;
	int peso;

}Aresta;

/* Classe que define com o conceito de lista de
 * vertices disjuntos
 * Nesse conceito temos o representante que aponta para o primeiro elemento
 * o primeiro elemento aponta para o proximo e assim por diante
 * se dois vertice possuem o mesmo representante, significa que 
 * eles estão na mesma arvore*/

class List{
		
	public:
		List();
		void insertEnd(List* vertice, int info, bool isFirst);
		~List();
		typedef struct element{
			int info;
			struct element* next; // Proximo elemento da lista
			List* rep; //Representante da lista
			Aresta arestaPertence;
		}Node;

		int top();
		Node* head; // Ponteiro para o primeiro elemento
		Node* tail; // Ponteiro para o ultimo  elemento
		int tamanho;
	private:



};

#endif
