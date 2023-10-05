#include <iostream>
#include "kruskal.h"

#include "list.h"


Kruskal::Kruskal(std::vector<std::vector<int> >* grafo){

	this->grafo = grafo;
	this->vertices = new std::vector < Node*>(grafo->size());
	result = NULL;
	this->caminhoValue = 0;

}


Kruskal::~Kruskal(){

}
void Kruskal::makeSet(){
	
	int qVertices = this->grafo->size();
	std::cout << "Tamanho do grafo: " << qVertices << std::endl;
	std::cout << "Tamanho de vertices: " << this->vertices->size() << std::endl;
	for(int i = 0; i < qVertices; i++){
		
		List* rep = new List();

		if(rep == NULL){
			std::cout << "Nao foi possivel criar o representante" << std::endl;
		}
		rep->insertEnd(rep, i, 1); // O(1) porque sempre esstamos adicionando o primeiro elemento
		this->vertices->at(i) = rep->head; //Adiciona inicialmente cada vertice
		std::cout << "Criado o vertice: " << this->vertices->at(i)->info << std::endl;
	}
}

List* Kruskal::algorithmKruskal(){
	
	makeSet();
	std::cout << "Fez o makeset" << std::endl;	
	
	/* Função lambda responsável pela comparação em ordem não decrescente	*/
	auto comp = [](const Aresta& a, const Aresta& b){

		return a.peso >= b.peso;
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
			if (aresta.peso == 0)
				continue;
			std::cout << "Peso da aresta(" << i << " -> " << j << "): " << aresta.peso << std::endl;
			arestasOrdenadas.push(aresta);
		}

	}
	
	while(!arestasOrdenadas.empty()) {
		Aresta aresta = arestasOrdenadas.top();
		std::cout << "Aresta Peso: " << aresta.peso << std::endl;
		int vertice_A = aresta.vertice_A;
		int vertice_B = aresta.vertice_B;
		Node* nodeVertice_A = this->vertices->at(vertice_A);
		Node* nodeVertice_B = this->vertices->at(vertice_B);
		
		if(findSet(nodeVertice_A) != findSet(nodeVertice_B)){
			std::cout << "Uniao dos vertices: " << nodeVertice_A->info << " e " << nodeVertice_B->info << std::endl;
			result = unionList(nodeVertice_A, nodeVertice_B);
			this->caminhoValue += aresta.peso;
			nodeVertice_A->arestaPertence = aresta;
			nodeVertice_B->arestaPertence = aresta;
		}
		else{
			std::cout<< "Forma um ciclo" << std::endl;
		}
		arestasOrdenadas.pop();
	}
	
	return result;

}

void Kruskal::caminho(){

	Node* head = result->head;

	int tamanho = 0;
	int peso = 0;

	while(tamanho < result->tamanho){
		Aresta aresta = head->arestaPertence;
		int vertice_a = aresta.vertice_A;
		int vertice_b = aresta.vertice_B;
		std::cout << "(" << vertice_a  << "->" << vertice_b << ") ";
		head = head->next;
		
		tamanho++;
	}
	std::cout << std::endl;
	std::cout << "O valor da solucao eh: " << this->caminhoValue << std::endl; 

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
	std::cout << "Antes do while do union" << std::endl;
	while(repSecundario->tamanho){
		std::cout << "antes do top" << std::endl;
		int verticeInfo = repSecundario->top();
		std::cout << "Vertice retirado do inicio" << std::endl;
		repPrimario->insertEnd(repPrimario ,verticeInfo, 1);
	}
	return repPrimario;
}
List* Kruskal::findSet(Node* node){
	
	return node->rep;


}
