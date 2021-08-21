#include <vector>

#include "PC.hpp"

using namespace std;

void mostrarPCs(vector<PC*>);
int seleccionarPC(vector<PC*>);
bool buscarIP(vector<PC*>, string);

void comandoShow(PC*);
void comandoPing(PC*, string, vector<PC*>);

void ping(int, string);
