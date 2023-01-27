#include "CoiffeurSpecialisteHommes.h"
#include "CoupeDeCheveuxHommes.h"

// Initialisation du compteur pour l'id
int CoiffeurSpecialisteHommes::count = 0;

// Constructeurs
CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes() : Coiffeur() {
  this->id_ = count;
  this->count++;
}

// Constructeur avec paramètres nom, adresse, pays, ville
CoiffeurSpecialisteHommes::CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville)
  : Coiffeur(nom, adresse, pays, ville)
{
  this->id_ = count;
  this->count++;
}


// Constructeur avec paramètres nom, adresse, pays, ville, coupesDeCheveux
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

// Destructeur
CoiffeurSpecialisteHommes::~CoiffeurSpecialisteHommes()
{
}

// fonction pour afficher la description du coiffeur spécialisé dans les coupes pour Hommes
std::string CoiffeurSpecialisteHommes::descriptionCoiffeur()
{
  return "Coiffeur specialisé dans les coupes pour Hommes";
}

// Accesseur et mutateur pour la liste des coupes de cheveux
std::vector<CoupeDeCheveuxHommes*> CoiffeurSpecialisteHommes::getCoupesDeCheveux() const 
{
  return this->coupesDeCheveux_;
}

void CoiffeurSpecialisteHommes::setCoupesDeCheveux(std::vector<CoupeDeCheveuxHommes*> coupesDeCheveux) 
{
  this->coupesDeCheveux_ = coupesDeCheveux;
}

//Surcharge d'opérateurs
bool operator==(const CoiffeurSpecialisteHommes &coiffeurH, const std::string pays)
{
  return coiffeurH.getPays() == pays;
}

std::ostream &operator<<(std::ostream &out, CoiffeurSpecialisteHommes &coiffeurH)
{
  std::string message = coiffeurH.descriptionCoiffeur() + "\n" +"- Nom: " + coiffeurH.getNom() + "\n" + "- Pays: " + coiffeurH.getPays() + "\n"
    + "- Ville: " + coiffeurH.getVille() + "\n" + "- Adresse: " + coiffeurH.getAdresse();

  return out << message;
}
