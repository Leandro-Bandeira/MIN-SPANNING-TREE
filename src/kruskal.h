#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <queue>
#include <iostream>
#include <vector>
#include <list>

#include "list.h"


class Kruskal : public List{
	public:
		Kruskal(std::vector<std::vector < int > >* grafo);
		List* algorithmKruskal();
		void makeSet();
		List* unionList(Node* nodeA, Node* nodeB);
		List* findSet(Node* node);
		void caminho();

		int caminhoValue;
		~Kruskal();
	private:
		std::vector < Node*> *vertices;
		std::vector < std::vector < int > >* grafo;
		std::list < List* > *representantes; // Armazena todos os conjuntos que são criados no makeSet
		List* result;
};

#endif
