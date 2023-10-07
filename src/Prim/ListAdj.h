#ifndef LISTADJ_H
#define LISTADJ_H


typedef struct element{
	struct element* adj;
	int vertice;
}Node;

#include <vector>
#include <iostream>

class ListAdj{
	public:
		ListAdj();
		void insertEnd(int vertice);
		Node* getNode(int indiceVertice);
		int getSize();
		void insertAdj(int indiceVertice, int indiceVerticeAdj);
		~ListAdj();
	private:
		std::vector < Node * > *nodes; // Indica os vertices que possuem vertices adjacentes no grafo

};









#endif
