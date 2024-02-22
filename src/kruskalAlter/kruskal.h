#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "tree.h"
#include <queue>


class Kruskal{
	public:
		Kruskal(Tree* tree, std::vector< std::vector<int>>*grafo);
		void makeSet();
		int findSet(int vertice);
		int setUnion(int vertice_a, int vertice_b);
		void algorithm();
		void calculate_grau(); // Calcula o grau de todos os vértices da solução
		int result;
	private:
		Tree* tree;
		std::vector < std::vector < int>>*grafo;
		std::vector < std::pair<int,int>> graus; // Vetor que indica o vértice e seu grau
		std::vector < Aresta > arestasIn;
};






#endif
