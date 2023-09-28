#include <iostream>
#include "kruskal.h"

#include "list.h"


Kruskal::Kruskal(std::vector<std::vector<int>*>* grafo){

	this->grafo = grafo;
}

void Kruskal::makeSet(){
	
	int qVertices = this->grafo->size();
	
	for(int i = 0; i < qVertices; i++){
		
		List* rep = new List();

		if(rep == NULL){
			std::cout << "Nao foi possivel criar o representante" << std::endl;
		}
		rep->insertEnd(rep, i); // O(1) porque sempre esstamos adicionando o primeiro elemento
		representantes->push_front(rep); // O(1) pois é uma lista encadeada então na teoria so precisamos alterar os valores das regioes de memoria
	}
}
