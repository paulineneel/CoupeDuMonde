#include "CoiffeurSpecialisteHommes.h"
#include "CoupeDeCheveuxHommes.h"

int CoiffeurSpecialisteHommes::count = 0;

// Constructeurs
CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes() : Coiffeur() {
  this->id_ = count;
  this->count++;
}

CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays, ville)
{
  this->id_ = count;
  this->count++;
}

CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveuxHommes *> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
  this->pays_ = pays;
  this->ville_ = ville;
  this->id_ = count;
  this->count++;
}

CoiffeurSpecialisteHommes::~CoiffeurSpecialisteHommes()
{
}

std::string CoiffeurSpecialisteHommes::descriptionCoiffeur()
{
  return "Coiffeur specialisé dans les coupes pour Hommes";
}

std::vector<CoupeDeCheveuxHommes*> CoiffeurSpecialisteHommes::getCoupesDeCheveux() const 
{
  return this->coupesDeCheveux_;
}

void CoiffeurSpecialisteHommes::setCoupesDeCheveux(std::vector<CoupeDeCheveuxHommes*> coupesDeCheveux) 
{
  this->coupesDeCheveux_ = coupesDeCheveux;
}
