#include <iostream>
#include <string>

#include "PC.hpp"

using namespace std;

PC::PC(){}
PC::PC(string IP, string mask, string host)
{
	this ->IP = IP;
	this ->mask = mask;
	this ->host = host;
}



void PC::setIP(string){}
string PC::getIP()
{
	return this->IP;
}

void PC::setMask(string){}
string PC::getMask()
{
	return this->mask;
}

void PC::setHost(string){}
string PC::getHost()
{
	return this ->host;
}