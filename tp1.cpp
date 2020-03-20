#include<string>
#include<iostream>

using namespace std;

struct fraction {
    int numerateur;
    int denominateur;
};
int CalculDiviseur(int numerateur , int denominateur);
void SimplifierFraction(int& numerateur, int& denominateur);
void EntrerFractions(int qteFraction, fraction* tabFractionIni);
void afficherFracSimple(int qteFraction, fraction* tabFractionIni, fraction* tabFractionSimple);
int PGCD(int numerateur, int denominateur);




int main() {
    int qteFraction;
    cout << "Donner le nombre de fractions : ";
    cin >> qteFraction;
    cout << endl;
    //tableau de type fraction pour sauvegarder les fractions initiales
    fraction* tabFractionIni = new fraction[qteFraction];
    //tableau de type fraction pour sauvegarder les fractions apres simplification
    fraction* tabFractionSimple = new fraction[qteFraction];

    EntrerFractions(qteFraction, tabFractionIni);
    afficherFracSimple(qteFraction, tabFractionIni, tabFractionSimple);
    delete tabFractionIni, tabFractionSimple;
}


//calcule et retourne le PGDC de deux nombres entiers
int CalculDiviseur(int numerateur , int denominateur) {
    int minimum = numerateur , div = 1;
    if (denominateur < minimum)    minimum = denominateur; 
    for (int diviseur = 1; diviseur <= minimum; diviseur++)
        if ( (numerateur % diviseur == 0) && (denominateur % diviseur == 0) )   div = diviseur;
            
    return div;
}

//Simplifie une fraction en modifiant le numerateur et le denominateur (passes ici par reference) apres les avoir divises sur le PGDC
void SimplifierFraction(int& numerateur , int& denominateur) {
    int numer = numerateur / PGCD(numerateur, denominateur);
    int denom = denominateur / PGCD(numerateur, denominateur);
    numerateur = numer;
    denominateur = denom;
}

//demande les numerateurs et denominateurs selon le nombre qteFraction
//sauvegarde les fractions dans le tableau tabFractionIni
void EntrerFractions(int qteFraction , fraction* tabFractionIni) {
    for (int i = 0; i < qteFraction; i++)
    {
        int numer = 0, denom = 0;
        //redemande un numerateur tant qu il est nul ou negatif
        do {
            cout << "Donner le numerateur de la fraction # " << i+1 << " : ";
            cin >> numer ;
            if (numer <= 0) cout << "Le numerateur doit etre superieur a 0"<<endl;
        } while (numer <= 0);
        tabFractionIni[i].numerateur = numer;

        //redemande un denominateur tant qu il est nul ou negatif
        do {
            cout << "Donner le denominateur de la fraction # " << i+1 << " : ";
            cin >> denom;
            if (denom <= 0) cout << "Le denominateur doit etre superieur a 0" << endl;
        } while (denom <= 0);
        tabFractionIni[i].denominateur = denom;
        cout << endl;
    }
}

//affiche les fractions initiales et les fractions simplifiees
//sauvegarde les fractions simplifiees dans le tableau tabFractionSimple
void afficherFracSimple(int qteFraction, fraction* tabFractionIni , fraction* tabFractionSimple) {
    cout << "====================================="<<endl<<"Fraction initiale >>> Fraction simplifiee" <<endl;
    for (int i = 0; i < qteFraction; i++)
    {
        int num = tabFractionIni[i].numerateur;
        int denom = tabFractionIni[i].denominateur;
        
        SimplifierFraction(num, denom);
        tabFractionSimple[i].numerateur = num;
        tabFractionSimple[i].denominateur = denom;

        cout << tabFractionIni[i].numerateur << "/" << tabFractionIni[i].denominateur << " >>> " <<
            tabFractionSimple[i].numerateur << "/" << tabFractionSimple[i].denominateur << endl;
    }
}


int  PGCD(int num1, int num2) {
    if (num1 == num2)
        return num1;
    if (num1 == 0 && num2 == 0)
        return 0;
    if (num1 == 0)
        return num2;
        if (num2 == 0)
            return num1;
        if (num1 % 2 == 0 && num2 % 2 == 0)
            return(PGCD(num1 / 2, num2 / 2) * 2);
        if (num1 % 2 == 0 && num2 % 2 != 0)
            return PGCD(num1 / 2, num2);
        if (num1 % 2 != 0 && num2 % 2 == 0)
            return PGCD(num1, num2 / 2);
        if (num1 % 2 != 0 && num2 % 2 != 0)
            if (num1 >= num2)
                return PGCD((num1 - num2) / 2, num2);
            else
                return PGCD((num2 - num1) / 2, num1);
}