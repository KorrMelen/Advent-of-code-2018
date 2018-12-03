#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

vector<string> lines;


int main(){
	int nb_two = 0;
	int nb_three = 0;
	string stringvalues ;
	ifstream fichier("input_jour2.txt", ios::in);
	if (fichier){
		string ligne;
        while(getline(fichier, ligne)){
        	lines.push_back(ligne);
        	bool two = false;
        	bool three = false;
        	while ((!two || !three) && ligne.length() > 0){
        		char letter = ligne[0];
        		string new_ligne = "";
        		for (int i = 0; i < ligne.length(); i++){
        			if(ligne[i] != letter){
        				new_ligne += ligne[i];
        			}
        		}
        		if(((ligne.length() - new_ligne.length()) == 2) && !two){
        			two = true;
        			nb_two++;
        		}
        		if(((ligne.length() - new_ligne.length()) == 3) && !three){
        			three = true;
        			nb_three++;
        		}
        		ligne = new_ligne;
        	}
        }
       	fichier.close();

       	bool find = false;
       	int i = 0;
       	while (!find){
       		int j = i+1;
       		while (!find && j < lines.size()){
       			int diff = 0;
       			int pos = 0;
       			for (int k = 0; k < lines[i].length(); k++){
       				if (lines[i][k] != lines[j][k]){
       					diff++;
       					pos = k;
       				}
       			}
       			if (diff == 1){
       				find = true;
       				cout << lines[i] << endl;
       				cout << lines[j] << endl;
       			}
       			j++;
       		}
       		i++;
       	}

       	cout << nb_two * nb_three << endl;
	}else cout << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}