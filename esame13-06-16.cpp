#include <iostream>
#include <fstream>
#include <cstring> // lo dava l'esame ma io non l'ho usato 
using namespace std;

fstream input;

void sinistra(char *testo[],int righe)
{ // è il classico modo di scrivere 
	input.open(testo[1],ios::in);
	char c;
	while(input.get(c)) // prende il carattere...
	{
	cout << c; // e lo scrive 
	}
	input.close();
}
void destra(char*testo[],int righe,int maxlungriga)
{
	int i=0,a=0,d=0;
	char c;
	char parola[righe][maxlungriga]; //utilizzo la matrice per scrivere il file di testo 
	input.open(testo[1],ios::in);
	while(input.get(c))
	{
		parola[a][i]=c; //inserisce la parola letta nella matrice 
		i++; 
		if (c=='\n') // quando arriva al carattere "invio"
		{
			d=maxlungriga-i; // calcola la differenza tra la lunghezza base e la parola letta 
			for(int g=0;g<=d;g++) cout << " "; //la differenza sono spazi 
			for (int f=0;f<i;f++) cout << parola[a][f]; // e poi scrive la parola
			//cout << endl;
			i=0;d=0;a++;} // azzera il contatore e passa alla riga successiva
		}
		input.close();
	}
	void centro(char*testo[],int righe,int maxlungriga)
{
	int i=0,j=0,d=0;
	char c;
	char parola[righe][maxlungriga]; //utilizzo la matrice per scrivere il file di testo 
	input.open(testo[1],ios::in);
	while(input.get(c))
	{
		parola[j][i]=c; //inserisce la parola letta nella matrice 
		i++;
		if (c=='\n') // quando arriva al carattere "invio"
		{
			d=maxlungriga-i; // calcola la differenza tra la lunghezza base e la parola letta 
			if(d==0) // questo è il caso dove hai la parola massima (opzionale)
			{
				for (int k=0;k<i;k++) cout << parola[j][k];
			}
			else { //metto metà spazi a detsra e metà a sinistra 
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
	input.open(argv[1],ios::in); // gli passo il nome del file di testo come argomento 
	while(input.get(c))
	{
		lungriga++;
		if (c=='\n')
		{
			riga++; // calcolo quante righe sono 
			if(lungriga>temp) //calcolo la lunghezza massima 
			{
				temp=lungriga;
				lungriga=0; // azzera la riga e passa a quella successiva
			}
		}
	}
	input.close();
	char lettera;
	do{
	cout << "s: allineato a sinistra" << endl;
        cout << "d: allineato a destra" << endl;
        cout << "c: allineato al centro" << endl;
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
	
