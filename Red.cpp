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

bool buscarIP(vector<PC*> lista, string ip)
{
	for (int i = 0; i < lista.size(); i++)
	{
		if ((lista[i]->getIP()).compare(ip) == 0)
		{
			return true;
		}
	}
	return false;
}

void comandoShow(PC* pc)
{
	cout << "	IP: " << pc->getIP() << endl;
	cout << "	Netmask: " << pc->getMask() << endl;
}

void comandoPing(PC* pc, string ipe, vector<PC*> lista)
{
	if (buscarIP(lista, ipe))
	{
		
	}
	else ping(3, ipe);
}

void ping(int resultado, string ping)
{
	if (resultado == 1)
	{
		cout << endl << "Pinging to " << ping << "with 32 bytes of data:" << endl;
		cout << "Reply from " << ping << ": bytes=32 time=37ms TTL=36" << endl;
		cout << "Reply from " << ping << ": bytes=32 time=37ms TTL=36" << endl;
		cout << "Reply from " << ping << ": bytes=32 time=37ms TTL=36" << endl;
		cout << "Reply from " << ping << ": bytes=32 time=37ms TTL=36" << endl << endl;
		cout << "Ping statistics for " << ping << ":" << endl;
		cout << "	Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)" << endl;
	}
	else if (resultado == 2)
	{
		cout << endl << "Pinging to " << ping << "with 32 bytes of data:" << endl;
		cout << "Reply from " << ping << ": Destination host unreachable" << endl;
		cout << "Reply from " << ping << ": Destination host unreachable" << endl;
		cout << "Reply from " << ping << ": Destination host unreachable" << endl;
		cout << "Reply from " << ping << ": Destination host unreachable" << endl << endl;
		cout << "Ping statistics for " << ping << ":" << endl;
		cout << "	Packets: Sent = 4, Received = 4, Lost = 0 (0% loss)" << endl;
	}
	else if (resultado == 3)
	{
		cout << endl << "Pinging to " << ping << "with 32 bytes of data:" << endl;
		cout << "Request timed out." << endl;
		cout << "Request timed out." << endl;
		cout << "Request timed out." << endl;
		cout << "Request timed out." << endl << endl;
		cout << "Ping statistics for " << ping << ":" << endl;
		cout << "	Packets: Sent = 4, Received = 0, Lost = 4 (100% loss)" << endl;
	}
}
