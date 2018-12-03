#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int square[1000][1000];
    bool ok[1353];
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            square[i][j] = 0;
        }
    }
    int sup = 0;
	string stringvalues;
	ifstream fichier("input_jour3.txt", ios::in);
	if (fichier){
		string ligne;
        while(getline(fichier, ligne)){
            int i = 1;
            string id = "";
            while (ligne[i] != ' '){
                id += ligne[i];
                i++;
            }
            int id_f = stoi(id);

            i+=3;
            string left = "";
            while (ligne[i] != ','){
                left += ligne[i];
                i++;
            }
            int left_edge = stoi(left);

            i++;
            string top = "";
            while (ligne[i] != ':'){
                top += ligne[i];
                i++;
            }
            int top_edge = stoi(top);

            i+=2;
            string wide = "";
            while (ligne[i] != 'x'){
                wide += ligne[i];
                i++;
            }
            int wide_f = stoi(wide);

            i++;
            string tall = "";
            while (i < ligne.length()){
                tall += ligne[i];
                i++;
            }
            int tall_f = stoi(tall);

            ok[id_f - 1] = true;
            for (i = left_edge; i < (wide_f + left_edge); i++){
                for (int j = top_edge; j < (tall_f + top_edge); j++){
                    if (square[i][j] == 0){
                        square[i][j] = id_f;
                    }else{
                        if(square[i][j] != -1){
                            sup++;
                            ok[square[i][j] - 1] = false;
                            square[i][j] = -1;
                        }
                        ok[id_f-1] = false;
                    }
                }
            }
        }
       	fichier.close();
        cout << sup << endl;
        int i = 0;
        while (!ok[i]) i++;
        cout << i+1 << endl;
	}else cout << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}