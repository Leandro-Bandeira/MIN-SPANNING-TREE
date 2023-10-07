#ifndef LISTADJ_H
#define LISTADJ_H


typedef struct element{
	struct element* adj;
	int vertice;
	int peso; // É o valor da aresta, esse valor só será adicionado quando for adicionado um vertice adjacente
}Node;

// NodeAux que guarda o vertice, chave e o pai daquele vertice
typedef struct{
	int vertice;
	int chave;
	Node* pai;
}NodeData;

#include <vector>
#include <iostream>

class ListAdj{
	public:
		ListAdj();
		void insertEnd(int vertice);
		Node* getNode(int indiceVertice);
		int getSize();
		void insertAdj(int indiceVertice, int indiceVerticeAdj, int peso);
		~ListAdj();
	private:
		
		std::vector < Node * > *nodes; // Indica os vertices que possuem vertices adjacentes no grafo

};









#endif
