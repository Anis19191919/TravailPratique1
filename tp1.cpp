#include<string>
#include<iostream>

using namespace std;

int main() {
    int numerateur, denominateur;
    int CalculDiviseur(int numerateur, int denominateur);
    int CalculDiviseur(int numerateur, int denominateur);

    std::cout << "Donner le numerateur ";
    std::cin >> numerateur;
    std::cout << "Donner le denominateur ";
    std::cin >> denominateur;

    std::cout << AffichageSimplifier(numerateur, denominateur);

}



int CalculDiviseur(int numerateur, int denominateur) {
    int minimum = numerateur;
    int div = 1;
    if (denominateur < minimum)
        minimum = denominateur;
    for (int diviseur = 1; diviseur <= minimum; diviseur++)
    {
        if ((numerateur % diviseur == 0) && (denominateur % diviseur == 0))
            div = diviseur;
    }
    return(div);
}

std::string AffichageSimplifier(int numerateur, int denominateur) {
    int nvnum = numerateur / CalculDiviseur(numerateur, denominateur);
    int nvdenom = denominateur / CalculDiviseur(numerateur, denominateur);
    string retour;
    retour = to_string(nvnum) + " / " + to_string(nvdenom);
    return(retour);

}