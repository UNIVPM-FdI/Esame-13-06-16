#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream input;

void sinistra(char *testo[],int righe)
{
	input.open(testo[1],ios::in);
	char c;
	while(input.get(c))
	{
	cout << c;
	}
	input.close();
}
void destra(char*testo[],int righe,int maxlungriga)
{
	int i=0,a=0,d=0;
	char c;
	char parola[righe][maxlungriga];
	input.open(testo[1],ios::in);
	while(input.get(c))
	{
		parola[a][i]=c;
		i++;
		if (c=='\n')
		{
			d=maxlungriga-i;
			for(int g=0;g<=d;g++) cout << " ";
			for (int f=0;f<i;f++) cout << parola[a][f];
			//cout << endl;
			i=0;d=0;a++;}
		}
		input.close();
	}
	void centro(char*testo[],int righe,int maxlungriga)
{
	int i=0,j=0,d=0;
	char c;
	char parola[righe][maxlungriga];
	input.open(testo[1],ios::in);
	while(input.get(c))
	{
		parola[j][i]=c;
		i++;
		if (c=='\n')
		{
			d=maxlungriga-i;
			if(d==0)
			{
				for (int k=0;k<i;k++) cout << parola[j][k];
			}
			else {
					for(int g=0;g<=(d/2);g++) cout << " ";
					for (int k=0;k<i;k++) cout << parola[j][k];
				    for(int e=0;e<=(d/2);e++) cout << " ";
			}
			//cout << endl;
			 j++;i=0;d=0;
		}
	}
	input.close();
}
int main(int argc, char **argv)
{
	char c;
	int riga=0,lungriga=0,temp=0;
	input.open(argv[1],ios::in);
	while(input.get(c))
	{
		lungriga++;
		if (c=='\n')
		{
			riga++;
			if(lungriga>temp)
			{
				temp=lungriga;
				lungriga=0;
			}
		}
	}
	input.close();
	char lettera;
	do{
	cin >> lettera;
	switch (lettera)
	{
		case 'd':{
			destra(argv,riga,temp);
		}break;
		case 's':
			{
				sinistra(argv,riga);
			}break;
			case 'c':
			{
				centro(argv,riga,temp);
			}break;
			default: {}break;
	}
	}
	while(lettera=='s'|| lettera=='d'||lettera=='c');
	return 0;
}
	
