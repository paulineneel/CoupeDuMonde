#ifndef COIFFEUR_SPECIALISTE_HOMMES_H
#define COIFFEUR_SPECIALISTE_HOMMES_H

#include "Coiffeur.h"

class CoiffeurSpecialisteHommes : public Coiffeur {
 public:
  // Constructeurs et Destructeur
  CoiffeurSpecialisteHommes();
  CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville);
  CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::string pays, std::string ville, std::vector<CoupeDeCheveux*> coupesDeCheveux);
  ~CoiffeurSpecialisteHommes();

  // Redéfinition de la fonction virtuelle
  double tarifTotal(bool meche,bool barbe) const override;

};

#endif  // COIFFEUR_SPECIALISTE_HOMMES_H
