#include "CoiffeurSpecialisteFemmes.h"
#include "CoupeDeCheveuxFemmes.h"

// Constructeurs
CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes() : Coiffeur() {}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays,ville)
{
}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveuxFemmes *> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
  this->pays_ = pays;
  this->ville_ = ville;
}

CoiffeurSpecialisteFemmes::~CoiffeurSpecialisteFemmes()
{
}

std::string CoiffeurSpecialisteFemmes::descriptionCoiffeur()
{
  return "Coiffeur Specialisé dans les coupes pour Femmes";
}

std::vector<CoupeDeCheveuxFemmes*> CoiffeurSpecialisteFemmes::getCoupesDeCheveux() const 
{
  return this->coupesDeCheveux_;
}

void CoiffeurSpecialisteFemmes::setCoupesDeCheveux(std::vector<CoupeDeCheveuxFemmes*> coupesDeCheveux) 
{
  this->coupesDeCheveux_ = coupesDeCheveux;
}
