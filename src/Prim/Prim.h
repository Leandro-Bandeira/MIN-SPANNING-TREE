#ifndef PRIM_H
#define PRIM_H
#include "ListAdj.h"



class Prim{
	public:
		Prim(ListAdj* list);
		void algorithm();
	private:
		ListAdj* listadj;
};




#endif
