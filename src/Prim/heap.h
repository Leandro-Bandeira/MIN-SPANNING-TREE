#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "ListAdj.h"


class Heap{
	public:
		Heap(std::vector<NodeData>&nodes);
		void minHeapify(int i);
		void buildMinHeap();
		NodeData top();
		void trocar(int i, int indiceMenor);
		bool empty();
		void heapMinSort();
		void pop_top();
		void printHeap();
		void decreaseKey(int vertice, NodeData&);

	private:
		std::vector<NodeData> nodes;
		int tamanhoHeap;
};









#endif
