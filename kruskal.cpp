#include <iostream>
#include "kruskal.h"

#include "list.h"


Kruskal::Kruskal(std::vector<std::vector<int> >* grafo){

	this->grafo = grafo;
	this->vertices = new std::vector < Node*>(grafo->size());
	result = NULL;

}

void Kruskal::makeSet(){
	
	int qVertices = this->grafo->size();
	
	for(int i = 0; i < qVertices; i++){
		
		List* rep = new List();

		if(rep == NULL){
			std::cout << "Nao foi possivel criar o representante" << std::endl;
		}
		rep->insertEnd(rep, i, 1); // O(1) porque sempre esstamos adicionando o primeiro elemento
		this->representantes->push_front(rep); // O(1) pois é uma lista encadeada então na teoria so precisamos alterar os valores das regioes de memoria
		this->vertices->at(i) = rep->head; //Adiciona inicialmente cada vertice
	}
}

List* Kruskal::algorithmKruskal(){
	
	makeSet();
	
	
	/* Função lambda responsável pela comparação em ordem não decrescente	*/
	auto comp = [](const Aresta& a, const Aresta& b){

		return a.peso <= b.peso;
	};

	//decltype pega a função sem reavaliar seu valor
	std::priority_queue< Aresta, std::vector<Aresta>,decltype(comp) > arestasOrdenadas(comp);
	/* Percorrendo as arestas	*/
	int qVertices = this->grafo->size();

	for(int i = 0; i < qVertices; i++){
		
		
		int qCol = this->grafo->at(i).size();

		for(int j = 0; j < qCol; j++){
		
			/* Cria-se a aresta e então adiciona na priority_queue	*/
			Aresta aresta;
			aresta.vertice_A = i;
			aresta.vertice_B = j;
			aresta.peso = (this->grafo->at(i))[j];
			arestasOrdenadas.push(aresta);
		}

	}
	

	while(!arestasOrdenadas.empty()) {
		Aresta aresta = arestasOrdenadas.top();
		int vertice_A = aresta.vertice_A;
		int vertice_B = aresta.vertice_B;
		Node* nodeVertice_A = this->vertices->at(vertice_A);
		Node* nodeVertice_B = this->vertices->at(vertice_B);

		if(findSet(nodeVertice_A) != findSet(nodeVertice_B)){
			result = unionList(nodeVertice_A, nodeVertice_B);
		}
		arestasOrdenadas.pop();
	}
	
	return result;

}


List* Kruskal::unionList(Node* verticeA, Node* verticeB){
	List* rep1 = verticeA->rep;
	List* rep2 = verticeB->rep;

	List* repPrimario = NULL; // Para onde vai os novos nos
	List* repSecundario = NULL; // De onde sai os nos
	
	if(rep1->tamanho <= rep2->tamanho){
		
		repPrimario = rep2;
		repSecundario = rep1;
		
	}else{
		
		repPrimario = rep1;
		repSecundario = rep2;

	}

	while(repSecundario->tamanho){
		repPrimario->insertEnd(NULL ,repSecundario->pop(), 0);
	}
	return repPrimario;
}
List* Kruskal::findSet(Node* node){
	
	return node->rep;


}
