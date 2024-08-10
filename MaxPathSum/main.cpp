#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int maxSumme(int zahl,int a,int b){
    return max(zahl+a,zahl+b);
}

int main()
{
    int wahl,n; string file;

    //Auswahl Teil 1 oder 2
    cout<<"1. Teil 1"<<endl<<"2. Teil 2"<<endl<<"Bitte auswaehlen [1/2]: ";
    cin>>wahl;

    //Dateiname und Zeilenanzahl
    if (wahl==1) {
        file="triangle1.txt";
        n=15;
    }
    else if (wahl==2) {
        file="triangle.txt";
        n=100;
    }
    else{
        cout<<"Falsche Auswahl.";
        return 1;
    }

    int dEck[n][n];
    ifstream Dreieck(file);

    //Lesen von den txt-Datei
    for (int i=0;i<n;i++){
        for (int j=0;j<i+1;j++){
            Dreieck >> dEck[i][j];
        }
    }

    //Aufsummieren von unten nach oben und die Größte rausnehmen
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            dEck[i][j]=maxSumme(dEck[i][j],dEck[i+1][j],dEck[i+1][j+1]);
        }
    }

    cout<<endl<<"Die maximale Summe ist "<<dEck[0][0]<<endl;

    return 0;
}
