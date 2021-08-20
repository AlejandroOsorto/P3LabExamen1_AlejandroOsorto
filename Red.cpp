#include <iostream>
#include <string>

#include "Red.hpp"

using namespace std;

void mostrarPCs(vector<PC*> lista)
{
	for (int i = 0; i < lista.size(); i++)
	{
		cout << "PC#" << i+1 << ": "<< lista[i]->getHost() << endl;
	}
}

int seleccionarPC(vector<PC*> lista)
{
	cout << "LISTA DE PCs" << endl;
	mostrarPCs(lista);
	
	int num = 0;
	cout << "Ingrese la posicion del PC a seleccionar: ";
	cin >>	num;
	num--;
	
	while (num > lista.size())
	{
		cout << "Posicion ingresada no valida, ingrese otra: ";
		cin >> num;
		num--;
	}
	
	return num;
}

void comandoShow(PC* pc)
{
	cout << "	IP: " << pc->getIP() << endl;
	cout << "	Netmask: " << pc->getMask() << endl;
}

void comandoIP(PC* pc, string ipe)
{
	
}
