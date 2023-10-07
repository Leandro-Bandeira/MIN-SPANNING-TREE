#include <iostream>
#include "ListAdj.h"
#include <fstream>
#include <sstream>
#include "Prim.h"
ListAdj* leitorInstancia(std::string instanciaName){
	std::string linha;
	std::string valor;

	std::fstream* arquivo = new std::fstream(instanciaName, std::ios::in);

	ListAdj* listAdj = new ListAdj();
	int i = 0;
	while(std::getline(*arquivo, linha)){
		listAdj->insertEnd(i);
		std::stringstream dadosLinha(linha);
		
		int j = 0;
		while(std::getline(dadosLinha, valor, ' ')){
				
			std::string::size_type sz;
			int peso = std::stod(valor, &sz);
			if(peso != 0){
				listAdj->insertAdj(i, j, peso);
			}
			j++;
		}
		i++;
	}

	arquivo->close();
	return listAdj;
}






int main(int argc, char** argv){
	if(argc < 2){
		
		std::cout << "Digite ./main -nome instancia\n";
		exit(1);
	}

	ListAdj* listAdj = leitorInstancia(argv[1]);
	int size = listAdj->getSize();
	for(int i = 0; i < size; i++){
		Node* node = listAdj->getNode(i);
		std::cout << node->vertice << " ";
		Node* nodeAdj = node->adj;
		while(nodeAdj != NULL){
			std::cout << nodeAdj->vertice << " " << nodeAdj->peso << " ";
			nodeAdj = nodeAdj->adj;
		}
		std::cout << std::endl;
	}
	Prim prim(listAdj);
	prim.algorithm();
	std::cout << "O valor eh: " << prim.result << std::endl;
	return 0;
}
