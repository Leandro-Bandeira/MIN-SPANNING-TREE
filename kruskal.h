
#include <iostream>
#include <vector>

class Kruskal{
	public:
		Kruskal(std::vector<std::vector < int > *>* grafo);
		void makeSet();

	private:
		std::vector < std::vector < int >* >* grafo;

};
