#include "heap.h"
#include <cmath>



Heap::Heap(std::vector <NodeData> &nodes){

	this->nodes = nodes;
	this->tamanhoHeap = nodes.size() - 1;
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


	if (indiceL <= this->tamanhoHeap and chaveL < chaveMenor){
		indiceMenor = indiceL;
	}
	if (indiceR <= this->tamanhoHeap and chaveR < chaveMenor){
		
		indiceMenor = indiceR;

	}

	if (indiceMenor != i){
		trocar(i, indiceMenor);
		minHeapify(indiceMenor);
	}

}


void Heap::buildMinHeap(){
	
	int piso = std::floor(this->tamanhoHeap/2);

	for(int i = piso; i < 0; i--){
		minHeapify(i);
	}

}


NodeData Heap::top(){
	return nodes[0];
}

void Heap::pop_top(){
	trocar(0, this->tamanhoHeap);
	this->tamanhoHeap -= 1;
	this->minHeapify(0);
}

bool Heap::empty(){

	return (this->tamanhoHeap > 0 ? false:true);

}


void Heap::heapMinSort(){
	
	buildMinHeap();
	
	int size = this->tamanhoHeap;
	
	// Apos o buildMinHeap o menor é a raiz e o maior é o ultimo elemento
	for(int i = size; i < 0; i--){
		//Troca o primeiro que é o menor pelo ultimo
		trocar(0, i);
		size = size - 1;
		minHeapify(0);
	}
	

}
