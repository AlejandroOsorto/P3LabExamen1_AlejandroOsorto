#pragma once
using namespace std;
class PC
{
	string IP;
	string mask;
	string host;
	public:
		PC();
		PC(string, string, string);
		
		void setIP(string);
		string getIP();
		
		void setMask(string);
		string getMask();
		
		void setHost(string);
		string getHost();
};