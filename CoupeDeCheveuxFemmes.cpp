#include "CoupeDeCheveuxFemmes.h"

// Constructeurs
CoupeDeCheveuxFemmes::CoupeDeCheveuxFemmes() : CoupeDeCheveux()
{
  this->meches_ = false;
}

CoupeDeCheveuxFemmes::CoupeDeCheveuxFemmes(std::string longueur, std::string couleur, std::string forme,double tarif, bool meches)
    : CoupeDeCheveux(longueur, couleur, forme,tarif)
{
  this->meches_ = meches;
}


// Accesseur et mutateur
bool CoupeDeCheveuxFemmes::getMeches() const {
  return this->meches_;
}

void CoupeDeCheveuxFemmes::setMeches(bool meches) {
  this->meches_ = meches;
}


// Fonctions
std::string CoupeDeCheveuxFemmes::description() const {
  std::string description = CoupeDeCheveux::description();
  if (meches_) {
    description += " avec mèches";
  } else {
    description += " sans mèches";
  }
  return description;
}

double CoupeDeCheveuxFemmes::tarif() const {
  double tarif = CoupeDeCheveux::getTarif();
  if (meches_) {
    tarif += 10;
  }
  return tarif;
}
