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
	private:
		Tree* tree;
		std::vector < std::vector < int>>*grafo;
};






#endif
