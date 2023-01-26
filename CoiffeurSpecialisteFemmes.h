#ifndef COIFFEUR_SPECIALISTE_FEMMES_H
#define COIFFEUR_SPECIALISTE_FEMMES_H

#include "Coiffeur.h"
#include "CoupeDeCheveuxFemmes.h"

class CoiffeurSpecialisteFemmes : public Coiffeur {
 public:
  // Constructeurs et Destructeur
  CoiffeurSpecialisteFemmes();
  CoiffeurSpecialisteFemmes(std::string nom, std::string adresse,std::string pays,std::string ville);
  CoiffeurSpecialisteFemmes(std::string nom, std::string adresse,std::string pays,std::string ville, std::vector<CoupeDeCheveuxFemmes*> coupesDeCheveux);
  ~CoiffeurSpecialisteFemmes();

  std::vector<CoupeDeCheveuxFemmes*> getCoupesDeCheveux() const;
  void setCoupesDeCheveux(std::vector<CoupeDeCheveuxFemmes*> coupesDeCheveux) ;

  std::vector<CoupeDeCheveuxFemmes*> coupesDeCheveux_;

  std::string descriptionCoiffeur() override;
};

#endif  // COIFFEUR_SPECIALISTE_FEMMES_H
