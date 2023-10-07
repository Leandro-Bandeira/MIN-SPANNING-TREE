#include "ListAdj.h"



// Inicializamos os nós
ListAdj::ListAdj(){
	nodes = new std::vector < Node*>();
	this->nodes->clear();
}

ListAdj::~ListAdj(){}

int ListAdj::getSize(){

	return this->nodes->size();
}
void ListAdj::insertEnd(int v){
	Node* node = new Node();
	node->vertice = v;
	node->adj = NULL;
	this->nodes->push_back(node);
}

Node* ListAdj::getNode(int indiceVertice){

	return this->nodes->at(indiceVertice); 
}

// Função responsável por adicionar um nó adjacente a um determinado no
void ListAdj::insertAdj(int indiceVertice, int indiceAdjVertice){
	Node* nodeAdj = new Node();
	nodeAdj->vertice = indiceAdjVertice;
	nodeAdj->adj = NULL;


	Node* node = this->nodes->at(indiceVertice);
	Node* aux = node;
	while(aux->adj != NULL){
		aux = aux->adj;
	}
	aux->adj = nodeAdj;

}
