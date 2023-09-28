#include "list.h"





List::List(){

	this->tamanho = 0;
	this->head = NULL;	
}

void List::insertEnd(List* data, int info, bool isFirst){
	
	Node* vertice = new Node();

	if(vertice == NULL){

		std::cout << "Erro ao criar a regiao de memoria\n";
	}

	vertice->info = info;
	vertice->next = NULL;

	if(this->tamanho == 0){
		this->head = vertice;
	}
	else{
		Node* aux = this->head;
		
		// Caminha até o ultimo nó da lista
		while(aux->next != NULL){
			aux = aux->next;
		}
		//Atualiza o próximo do ultimo nó, que é o novo ultimo nó
		aux->next = vertice;
	}
	this->tamanho++;
	this->tail = vertice;
	if(isFirst)
		vertice->rep = data;
}

int List::pop(){
	
	Node* vertice = this->head;
	this->head = this->head->next;
	if(tamanho == 1){

		this->tail = this->head->next;
	}
	
	this->tamanho--;
	delete vertice;
	return vertice->info;
}
