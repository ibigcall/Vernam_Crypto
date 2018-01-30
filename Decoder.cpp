#include <iostream>
#include <string>  
#include "math.h"

#include <fstream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) 
{
	
	ifstream fout1("Cypher.txt");
	ifstream fout2("Key.txt");
	int k;
	int mass_size=128;
	vector<char> alph(128);
	for(int i=0; i<mass_size; i++)
	{
		alph[i]=(char)i;
	}
	string key,cypher;
	getline(fout2,key);
	getline(fout1,cypher);
	fout1.close();
	fout2.close();
	int MassOfCode[cypher.length()];
	string str;
	for(int i=0; i<cypher.length(); i++)
	{
		for(int j=0; j<mass_size+1; j++)
		{
			if(key[i]==alph[j])
			{
				MassOfCode[i]=j;
			}
		}
	}
	for(int i=0; i<cypher.length(); i++)
	{
		for(int j=0; j<mass_size+1; j++)
		{
			if(cypher[i]==alph[j])
			{
				if((MassOfCode[i]-j)<0)
				{
					k=j-MassOfCode[i];
				}
				else
				{
					 k=mass_size-(MassOfCode[i]-j);
				}
				
				cout<<alph[k];
				
			}
		}
	}
	cout<<"\n";

}