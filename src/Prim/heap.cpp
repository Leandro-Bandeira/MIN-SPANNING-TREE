#include "heap.h"
#include <cmath>
#include <iostream>


Heap::Heap(std::vector <NodeData> &nodes){

	this->nodes = nodes;
	this->tamanhoHeap = nodes.size();
}

void Heap::trocar(int indicePrimeiro, int indiceMaior){
	

	NodeData nodeAux = nodes[indicePrimeiro];
	nodes[indicePrimeiro] = nodes[indiceMaior];
	nodes[indiceMaior] = nodeAux;


}


void Heap::minHeapify(int i){
	
	int indiceL = (2 * i) + 1;
	int indiceR = (2 * i) + 2;
	
	int chaveL = nodes[indiceL].chave;
	int chaveR = nodes[indiceR].chave;

	int indiceMenor = i;

	int chaveMenor = nodes[indiceMenor].chave;


	if (indiceL <= this->tamanhoHeap - 1 and chaveL < chaveMenor){
		indiceMenor = indiceL;
		chaveMenor = chaveL;
	}
	if (indiceR <= this->tamanhoHeap - 1 and chaveR < chaveMenor){
		
		indiceMenor = indiceR;
		chaveMenor = chaveL;

	}

	if (indiceMenor != i){
		trocar(i, indiceMenor);
		minHeapify(indiceMenor);
	}

}

void Heap::printHeap(){
	
	for(int i = 0; i < this->tamanhoHeap; i++){

		std::cout << nodes[i].chave << " ";
	}
	std::cout << std::endl;

}
void Heap::buildMinHeap(){
	
	int piso = std::floor(this->tamanhoHeap/2) - 1;

	for(int i = piso; i < 0; i--){
		minHeapify(i);
	}


}


NodeData Heap::top(){
	return nodes[0];
}

void Heap::pop_top(){
	trocar(0, this->tamanhoHeap -1);
	printHeap();
	this->tamanhoHeap -= 1;
	this->minHeapify(0);
	printHeap();
}

bool Heap::empty(){

	return (this->tamanhoHeap > 0 ? false:true);

}


void Heap::heapMinSort(){
	
	buildMinHeap();
	
	int size = this->tamanhoHeap - 1;
	
	// Apos o buildMinHeap o menor é a raiz e o maior é o ultimo elemento
	for(int i = size; i < 0; i--){
		//Troca o primeiro que é o menor pelo ultimo
		trocar(0, i);
		size = size - 1;
		minHeapify(0);
	}
	

}


void Heap::decreaseKey(int vertice, NodeData& newNode){
	int i;
	for(i = 0; i < this->tamanhoHeap; i++){

		if(nodes[i].vertice == vertice){
			break;
		}
	}
	nodes[i] = newNode; //Renova aquele nó
	while(1){
		int paiIndice = std::floor((i-1)/2);
		NodeData nodePai = nodes[paiIndice];
		NodeData filho = nodes[i];
		if(nodePai.chave > filho.chave){
			trocar(i, paiIndice);
		}
		else{
			break;
		}
		i = paiIndice;

	}

}
