#include "CoiffeurSpecialisteFemmes.h"

// Constructeurs
CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes() : Coiffeur() {}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays,ville)
{
}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux *> coupesDeCheveux)
  : Coiffeur(nom, adresse, pays,ville, coupesDeCheveux) 
{
}

CoiffeurSpecialisteFemmes::~CoiffeurSpecialisteFemmes()
{
}

// Fonctions
double CoiffeurSpecialisteFemmes::tarifTotal(bool meche,bool barbe) const {
  double tarifTotal = 0;
  if (meche) {
    tarifTotal += 0;
  }
  return tarifTotal;
}
