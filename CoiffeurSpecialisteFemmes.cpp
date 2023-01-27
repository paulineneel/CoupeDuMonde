#include "CoiffeurSpecialisteFemmes.h"
#include "CoupeDeCheveuxFemmes.h"

int CoiffeurSpecialisteFemmes::count = 0;

// Constructeurs
CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes() : Coiffeur() {
  this->id_ = count;
  this->count++;
}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays,ville)
{
  this->id_ = count;
  this->count++;
}

CoiffeurSpecialisteFemmes::CoiffeurSpecialisteFemmes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveuxFemmes *> coupesDeCheveux)
{
  this->nom_ = nom;
  this->adresse_ = adresse;
  this->coupesDeCheveux_ = coupesDeCheveux;
  this->pays_ = pays;
  this->ville_ = ville;
  this->id_ = count;
  this->count++;
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

//Surcharge d'opérateur

bool operator==(const CoiffeurSpecialisteFemmes &coiffeurF, const std::string pays)
{
  return coiffeurF.getPays() == pays;
}

std::ostream &operator<<(std::ostream &out, CoiffeurSpecialisteFemmes &coiffeurF)
{
  std::string message = coiffeurF.descriptionCoiffeur() + "\n" +"- Nom: " + coiffeurF.getNom() + "\n" + "- Pays: " + coiffeurF.getPays() + "\n"
    + "- Ville: " + coiffeurF.getVille() + "\n" + "- Adresse: " + coiffeurF.getAdresse();

  return out << message;
}