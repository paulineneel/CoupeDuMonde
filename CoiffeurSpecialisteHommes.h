#ifndef COIFFEUR_SPECIALISTE_HOMMES_H
#define COIFFEUR_SPECIALISTE_HOMMES_H

#include "Coiffeur.h"
#include "CoupeDeCheveuxHommes.h"

class CoiffeurSpecialisteHommes : public Coiffeur {
 public:
  // Constructeurs et Destructeur
  CoiffeurSpecialisteHommes();
  CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville);
  CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveuxHommes*> coupesDeCheveux);
  ~CoiffeurSpecialisteHommes();

  std::vector<CoupeDeCheveuxHommes*> getCoupesDeCheveux() const;
  void setCoupesDeCheveux(std::vector<CoupeDeCheveuxHommes*> coupesDeCheveux) ;

  std::vector<CoupeDeCheveuxHommes*> coupesDeCheveux_;

  std::string descriptionCoiffeur() override;

};

#endif  // COIFFEUR_SPECIALISTE_HOMMES_H
