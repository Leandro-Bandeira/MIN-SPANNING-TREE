#include <iostream>
#include "kruskal.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "list.h"
#include <bits/stdc++.h>
std::vector < std::vector < int > > * leitorInstancia(char* instanciaName){
	
	std::string linha;
	std::string valor;
	
	std::fstream* arquivo = new std::fstream(instanciaName, std::ios::in);



	std::vector < std::vector <int>  > * grafo = new std::vector < std::vector < int > >();

	while(std::getline(*arquivo, linha)){
		std::vector < int > arestaValores;
		std::stringstream dadosLinha(linha);
		arestaValores.clear();

		while(std::getline(dadosLinha, valor, ' ')){
			
			std::string::size_type sz;

			arestaValores.push_back(std::stod(valor, &sz));
		}

		grafo->push_back(arestaValores);

	}
	
	arquivo->close();
	return grafo;


}


int main(int argc, char** argv){
	
	if(argc < 2){

		std::cout << "Digite ./main -nome instancia-\n";
		exit(1);
	}

	std::vector < std::vector < int > >* grafo = leitorInstancia(argv[1]);
	
	int size = grafo->size();

	for(int i = 0; i < size; i++){

		std::vector < int > vertice = grafo->at(i);
		
		for(int i = 0; i < vertice.size(); i++){
				
			std::cout << vertice[i] << " ";
		}
		std::cout << std::endl;
	}
	time_t start, end;
	time(&start);
	Kruskal kruskal(grafo);
	List* result = kruskal.algorithmKruskal();
	time(&end);
	std::cout << kruskal.caminhoValue << std::endl;
	std::cout << std::fixed << double(end-start) << std::setprecision(5) << std::endl;
	kruskal.caminho();
	return 0;
}
