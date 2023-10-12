#include "Prim.h"
#include <queue>
#include <algorithm>
#include "heap.h"


Prim::Prim(ListAdj* list){
	
	this->listadj = list;
	this->result = 0;

}


void Prim::algorithm(){
	
	int qVertices = listadj->getSize();
	std::vector < NodeData >vertices(qVertices);
	// O valor armazenado no vetor indicar se o indice está ou não na queue
	std::vector < bool > verticesInQueue(qVertices);

	for(int i = 0; i < qVertices; i++){
		vertices[i].vertice = i;
		vertices[i].chave = 9999999;
		vertices[i].pai = NULL;
		verticesInQueue[i] = true;

	}
	// Vamos iniciar como a raiz sendo sempre zero inicialmente
	vertices[0].chave = 0;
	

	// Agora devemos inicializar uma fila de prioridade baseada no valor da chave
	// Vamos iniciar a fila do menor para o maior valor em ordem nao decrescente

	Heap priority_queue = Heap(vertices);
	priority_queue.buildMinHeap();

	while(!priority_queue.empty()){
		
		NodeData nodeData = priority_queue.top();
		priority_queue.pop_top();

		// Vamos agora percorrer todos os nos adjacentes a esse vertice
		Node* nodeU = listadj->getNode(nodeData.vertice);
		Node* nodeAux = nodeU->adj; //Acessa o primeiro adjacente
		if(nodeAux->vertice == 54){
			std::cout << "Achou" << std::endl;
			getchar();
		}	
		while(nodeAux != NULL){
		
			int adjVertice = nodeAux->vertice;
			int peso = nodeAux->peso;
			int chave = vertices[adjVertice].chave;
			
			if(verticesInQueue[adjVertice] and peso < chave){
				vertices[adjVertice].pai = nodeU;
				vertices[adjVertice].chave = peso;
				nodeAux->peso = peso;
				priority_queue.decreaseKey(adjVertice, vertices[adjVertice]);
			}
			nodeAux = nodeAux->adj;
			
		}
		verticesInQueue[nodeData.vertice] = false;
	
	}
	
	
	for(int i = 0; i < qVertices; i++){

		std::cout << "Vertice: " << i << "possui chave: " << vertices[i].chave << std::endl;
		result += vertices[i].chave;

	}
	

}
