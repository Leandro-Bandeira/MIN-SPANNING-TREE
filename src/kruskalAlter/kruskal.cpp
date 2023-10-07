#include "kruskal.h"


Kruskal::Kruskal(Tree* tree,std::vector<std::vector<int>>*grafo ){

	this->tree = tree;
	this->grafo = grafo;
	this->result = 0;
}


void Kruskal::makeSet(){

	int qVertices = this->tree->getSize();
	
	// Seta o pai de cada nó inicialmente como sendo ele próprio
	// OU seja, cada nó é um nó raiz inicialmente
	for(int i = 0; i < qVertices; i++){
		
			this->tree->setFather(i, i);
			this->tree->setRank(i, 0);
	}
}


// A função findSet é uma função recursiva que retorna o pai de um elemento
// vamos subindo a arvore recursivamente, então seu caso base é quando
// encontramos a raiz, ou seja, o pai do nó é o próprio nó pai[x] = x
// e quando estivermos voltando na recursividade
// devemos atualizar os valores do pai de todos os outros nós para o nó raiz
// esse metodo anteriormente descrito é o pathcompression
int Kruskal::findSet(int vertice){
	int i = vertice;

	if (this->tree->getFather(i) == i){
			
		return i;
	}	
	else{ 
		  
		int father = this->tree->getFather(i);
		int raiz = findSet(father);
		this->tree->setFather(i, raiz);
		return raiz;
	} 
}

// Na função setUnion temos que encontrar a raiz de ambos os vertices
// Dito isso temos que chamar a função find-set para cada vertice e então
// verificar o rank de cada raiz, a raiz de rank menor terá o pai como sendo
// a raiz de rank maior para construir arvores mais balanceadas
int Kruskal::setUnion(int vertice_a, int vertice_b){
	
	int raiz_a = findSet(vertice_a);
	int raiz_b = findSet(vertice_b);
	if (raiz_a == raiz_b){
		return 0;
	}
	int rank_a = this->tree->getRank(raiz_a);
	int rank_b = this->tree->getRank(raiz_b);

	int vertice_maiorRank = rank_a <= rank_b ? raiz_b : raiz_a;
	int vertice_menorRank = rank_a <= rank_b ? raiz_a : raiz_b;
	std::cout << vertice_maiorRank << " " << vertice_menorRank << std::endl;	

	this->tree->setFather(vertice_menorRank, vertice_maiorRank);
	this->tree->setRank(vertice_maiorRank, this->tree->getRank(vertice_menorRank));
	return 1;

}

void Kruskal::algorithm(){
		
	makeSet();

	std::cout << "Fez o makeset" << std::endl;	
	
		/* Função lambda responsável pela comparação em ordem não decrescente	*/
	auto comp = [](const Aresta& a, const Aresta& b){

		return a.peso >= b.peso;
	};

	//decltype pega a função sem reavaliar seu valor
	std::priority_queue< Aresta, std::vector<Aresta>,decltype(comp) > arestasOrdenadas(comp);
	/* Percorrendo as arestas	*/
	int qVertices = this->tree->getSize();
	for(int i = 0; i < qVertices; i++){
		
		int col = this->grafo->at(i).size();

		for(int j = 0; j < col; j++){
		
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
	
	std::cout << "here" << std::endl;
	while(!arestasOrdenadas.empty()){
		Aresta aresta = arestasOrdenadas.top();
		std::cout << aresta.peso << std::endl;
		int vertice_a = aresta.vertice_A;
		int vertice_b = aresta.vertice_B;
		
		int resultUnion = setUnion(vertice_a, vertice_b);
		if (resultUnion){
			
			result += aresta.peso;
		}
		
		arestasOrdenadas.pop();

	}

}
