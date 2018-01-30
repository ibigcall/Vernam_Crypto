#include <iostream>
#include <string>   
#include <fstream>
#include <vector>
using namespace std;


static vector<char> alph(128);
 void init()
{

	for (int i = 0; i<alph.size(); i++)
	{
		alph[i]=((char)i);
	}

}
int main(int argc, char *argv[])
{
	cout<<"Enter the message:\n";
	init();
	ofstream fout1("Cypher.txt");
	ofstream fout2("Key.txt");

	srand(time(NULL));


	string str;
	string str2;
	string keylog;
	getline(cin, str);
	for (int i = 0; i<str.length(); i++)       //generating key
	{
		for (int j = 0; j<alph.size()+ 1; j++)       
		{
			if (str[i] == alph[j])
			{

				int randomii = rand() % alph.size();
				int l = (randomii + j) % alph.size();
				str2 += alph[l];
				keylog += alph[randomii];


			}
		}
	}
	fout1 << str2;     //writing encrypted message
	fout1.close();
	fout2 << keylog;   //writing generated key
	fout2.close();
	cout << str2 << '\n';
	cout << keylog;

}
