
#include <iostream>
#include <vector>
#include <list>

#include "list.h"
class Kruskal{
	public:
		Kruskal(std::vector<std::vector < int > *>* grafo);
		void makeSet();

	private:
		std::vector < std::vector < int >* >* grafo;
		std::list < List* > *representantes; // Armazena todos os conjuntos que são criados no makeSet
};
