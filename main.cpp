#include <iostream>
#include <string>
#include <vector>

#include "PC.hpp"
#include "Red.hpp"

using namespace std;

int menu();
bool verificarIP(string);
string consolaPC(string);

int main(int argc, char** argv) 
{
	vector<PC*> lista;
	PC* compu;
	int opcion = 0;
	
	while ((opcion = menu()) != 3)
	{
		switch (opcion)
		{
			case 1:
				{
					fflush(stdin); //Limpia el buffer
					cout << "AGREGAR PC" << endl;
					
					string IP, mascara, host;
					cout << "Ingrese la direccion IP: ";
					getline(cin, IP);
					
					while (!verificarIP(IP))
					{
						cout << "Direccion IP no valida, debe tener 4 numeros separados por un punto, ingrese otro: ";
						getline(cin, IP);
					}
					
					cout << "Ingrese la mascara de red: ";
					getline(cin, mascara);
					while (!verificarIP(mascara))
					{
						cout << "Direccion IP no valida, debe tener 4 numeros separados por un punto, ingrese otro: ";
						getline(cin, mascara);
					}
					cout << "Ingrese el Hostname: ";
					getline(cin, host);
					
					//Quitar espacios de los strings
					int i = 0, j = 0;
					while (IP[i])
					{
						if (IP[i] != ' ')
						{
							IP[j++] = IP[i];
						}
						i++;
					}
					IP[j] = '\0';
					
					i = 0, j = 0;
					while (mascara[i])
					{
						if (mascara[i] != ' ')
						{
							mascara[j++] = mascara[i];
						}
						i++;
					}
					mascara[j] = '\0';
					
					i = 0, j = 0;
					while (host[i])
					{
						if (host[i] != ' ')
						{
							host[j++] = host[i];
						}
						i++;
					}
					host[j] = '\0';
					// Fin quitar espacios
					
					compu = new PC(IP, mascara, host);
					lista.push_back(compu);
					
				} break;
			case 2:
				{
					if (lista.empty())
					{
						cout << "No se han encontrado PCs, por favor agregue uno." << endl;
					}
					else
					{
						int i = seleccionarPC(lista);
					
						string comando, subComando, comandoIP;
						
						while ((comando = consolaPC(lista[i]->getHost())).compare("exit") != 0)
						{
							subComando = comando.substr(0,5);
							if (comando.compare("show") == 0)
							{
								comandoShow(lista[i]);
							}
							else if (subComando.compare("ping_") == 0)
							{
								comandoIP = comando.substr(5);
								if (verificarIP(comandoIP))
								{
									comandoPing(lista[i], comandoIP, lista);
								}
								else cout << "Direccion IP ingresada no valida." << endl;
							}
						}
						cout << "Saliendo del PC . . ." << endl;
					}
				} break;
		}
	}
	
	delete compu;
	return 0;
}

int menu()
{
	int i = 0;
	
	cout << "----MENU----" << endl;
	cout << "1) Agregar PC" << endl;
	cout << "2) Ingresar a una PC" << endl;
	cout << "3) Salir del programa" << endl;
	cout << "------------" << endl;
	
	cin >> i;
	
	return i;
}

bool verificarIP(string ip)
{
	
	//Cuenta la cantidad de puntos
	int cont = 0;
	for (int i = 0; i < ip.size(); i++)
	{
		if (ip[i] == '.')
		{
			cont++;
		}
	}
	if (cont == 3)
	{
		return true;
	}
	else return false;
	//Fin contador de puntos
	
	//Revisa que los numeros esten en el rango correcto 0-255
	stringstream ss(ip);
	string token;
	
	while (getline(ss, token, '.'))
	{
		int num = stoi(token);
		if ((num > 255) || (num < 0))
		{
			return false;
		}
	}
	//Fin revision
}

string consolaPC(string host)
{
	fflush(stdin); //Limpia el buffer
	string comando;
	cout << host << "#";
	getline(cin, comando);
	
	//Quito espacios
	int i = 0, j = 0;
	while (comando[i])
	{
		if (comando[i] != ' ')
		{
			comando[j++] = comando[i];
		}
		i++;
	}
	comando[j] = '\0';
	
	return comando;
}
