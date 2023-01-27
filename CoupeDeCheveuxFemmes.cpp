#include "CoupeDeCheveuxFemmes.h"

// Constructeur
CoupeDeCheveuxFemmes::CoupeDeCheveuxFemmes() : CoupeDeCheveux()
{
  this->meches_ = false;
}

// Constructeur avec paramètres longueur, forme, tarif, meches
CoupeDeCheveuxFemmes::CoupeDeCheveuxFemmes(std::string longueur, std::string forme,double tarif, bool meches)
    : CoupeDeCheveux(longueur, forme,tarif)
{
  this->meches_ = meches;
}

// Destructeur
CoupeDeCheveuxFemmes::~CoupeDeCheveuxFemmes()
{
}

// Accesseur et mutateur pour les mèches
bool CoupeDeCheveuxFemmes::getMeches() const {
  return this->meches_;
}

void CoupeDeCheveuxFemmes::setMeches(bool meches) {
  this->meches_ = meches;
}


// Fonctions pour afficher la description d'une coupe de cheveux
std::string CoupeDeCheveuxFemmes::description() const {
  std::string description = CoupeDeCheveux::description();
  if (meches_) {
    description += " avec mèches";
  } else {
    description += " sans mèches";
  }
  return description;
}

// Fonction pour calculer le tarif d'une coupe de cheveux
double CoupeDeCheveuxFemmes::getTarif() const {
  double tarif = CoupeDeCheveux::getTarif();
  if (meches_) {
    tarif += 10;
  }
  return tarif;
}
