#include "list.h"





List::List(){

	this->tamanho = 0;
	this->head = NULL;	
}

List::~List(){

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
		std::cout << "entrou aqui" << std::endl;
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

	std::cout << "Adicionou ao fim" << std::endl;
}

int List::top(){
	std::cout << "entrou no top" << std::endl;	
	Node* vertice = this->head;
	std::cout << "here1" << std::endl;
	int verticeInfo = vertice->info;
	this->head = this->head->next;
	std::cout << "here2" << std::endl;
	if(tamanho == 1){
		std::cout<< "here2.5" << std::endl;
		this->tail = NULL;
		std::cout << "here2.6" << std::endl;
	}
	std::cout << "here3" << std::endl;	
	this->tamanho--;
	std::cout << "antes do delete" << std::endl;
	delete vertice;
	return verticeInfo;
}
