#include "CoupeDeCheveuxHommes.h"

// Constructeurs
CoupeDeCheveuxHommes::CoupeDeCheveuxHommes() : CoupeDeCheveux()
{
  this->barbe_ = false;
}

// Constructeur avec paramètres longueur, forme, tarif, barbe
CoupeDeCheveuxHommes::CoupeDeCheveuxHommes(std::string longueur, std::string forme,double tarif, bool barbe)
    : CoupeDeCheveux(longueur, forme,tarif)
{
  this->barbe_ = barbe;
}

// Destructeur
CoupeDeCheveuxHommes::~CoupeDeCheveuxHommes()
{
}

// Accesseur et mutateur pour la barbe
bool CoupeDeCheveuxHommes::getBarbe() const {
  return this->barbe_;
}

void CoupeDeCheveuxHommes::setBarbe(bool barbe) {
  this->barbe_ = barbe;
}


// Fonctions pour afficher la description d'une coupe de cheveux
std::string CoupeDeCheveuxHommes::description() const {
  std::string description = CoupeDeCheveux::description();
  if (barbe_) {
    description += " avec barbe";
  } else {
    description += " sans barbe";
  }
  return description;
}


// Fonction pour calculer le tarif d'une coupe de cheveux
double CoupeDeCheveuxHommes::getTarif() const {
  double tarif = CoupeDeCheveux::getTarif();
  if (barbe_) {
    tarif += 5;
  }
  return tarif;
}


