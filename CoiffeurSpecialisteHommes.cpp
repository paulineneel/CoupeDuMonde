#include "CoiffeurSpecialisteHommes.h"

// Constructeurs
CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes() : Coiffeur() {}

CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays, ville)
{
}

CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux *> coupesDeCheveux)
  : Coiffeur(nom, adresse, pays, ville, coupesDeCheveux)
{
}

CoiffeurSpecialisteHommes::~CoiffeurSpecialisteHommes()
{
}

// Fonctions
double CoiffeurSpecialisteHommes::tarifTotal(bool meche,bool barbe) const {
  double tarifTotal = 0;
  for (auto coupeDeCheveux : coupesDeCheveux_) {
    tarifTotal += coupeDeCheveux->getTarif();
  }
  return tarifTotal;
}
