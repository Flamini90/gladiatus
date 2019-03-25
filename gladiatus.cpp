#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct gladiatori{
	string nome;
	float onore_old;
	float onore_new;
	float onore_attuale;
};
gladiatori totali[40];
gladiatori temp;
int giocatori;
string elenco_nomi[15]={"ypnos","blodgharm","rana","thewolf","thefury","konrad","guardia","malan","lagertha","pistrok","hannya","flamini","darcos","cap","sfondamuri"};
int elenco_onore[15]={4784999,2452400,2326080,5616127,19322245,16952065,3400982,14880668,5056730,4274123,6064462,7055538,9244228,2190134,2639196};
void inserimento(){
	cout << "Inserisci il numero dei partecipanti al contest: ";
	cin >> giocatori;
	for(int i = 0;i < giocatori;i++){
		totali[i].nome = elenco_nomi[i];
		totali[i].onore_old = elenco_onore[i];
	}
		
	for(int i = 0;i < giocatori;i++){
		cout << "Inserisci l'onore attuale di " << elenco_nomi[i] << ": ";
		cin >> totali[i].onore_new;
	}
}
float calcolo(){
	float onore_attuale[giocatori];
	for(int i = 0;i < giocatori;i++){
		onore_attuale[i]= totali[i].onore_new - totali[i].onore_old;
		totali[i].onore_attuale = onore_attuale[i];
	}
}
void ordinamento(){
	for(int i = 0;i < giocatori;i++){
		for(int j = i+1;j < giocatori;j++){
			if(totali[j].onore_attuale > totali[i].onore_attuale){
				temp = totali[i];
				totali[i] = totali[j];
				totali[j] = temp;
			}
		}
	}
}

void stampa(){
	cout << "CLASSIFICA TEMPORANEA:\n\n";
	for(int i = 0;i < giocatori;i++)
		cout << i+1 << "." << totali[i].nome << " con onore: " << totali[i].onore_attuale << endl << endl;
}
int main()
{
	inserimento();
	calcolo();
	ordinamento();
	system("cls");
	stampa();
	
	return 0;
}
