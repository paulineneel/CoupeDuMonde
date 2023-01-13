#include "Coiffeur.h"

// Constructeurs et Destructeur
Coiffeur::Coiffeur() {}

Coiffeur::Coiffeur(std::string nom, std::string adresse, std::vector<CoupeDeCheveux*> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
}


Coiffeur::~Coiffeur()
{
}


// Accesseurs et mutateurs
std::string Coiffeur::getNom() const 
{
  return this->nom_;
}

void Coiffeur::setNom(std::string nom) 
{
  this->nom_ = nom;
}

std::string Coiffeur::getAdresse() const 
{
  return this->adresse_;
}

void Coiffeur::setAdresse(std::string adresse) 
{
  this->adresse_ = adresse;
}

std::vector<CoupeDeCheveux*> Coiffeur::getCoupesDeCheveux() const 
{
  return this->coupesDeCheveux_;
}

void Coiffeur::setCoupesDeCheveux(std::vector<CoupeDeCheveux*> coupesDeCheveux) 
{
  this->coupesDeCheveux_ = coupesDeCheveux;
}
