#ifndef COIFFEUR_SPECIALISTE_FEMMES_H
#define COIFFEUR_SPECIALISTE_FEMMES_H

#include "Coiffeur.h"

class CoiffeurSpecialisteFemmes : public Coiffeur {
 public:
  // Constructeurs et Destructeur
  CoiffeurSpecialisteFemmes();
  CoiffeurSpecialisteFemmes(std::string nom, std::string adresse,std::string pays,std::string ville);
  CoiffeurSpecialisteFemmes(std::string nom, std::string adresse,std::string pays,std::string ville, std::vector<CoupeDeCheveux*> coupesDeCheveux);
  ~CoiffeurSpecialisteFemmes();

  // Redéfinition de la fonction virtuelle
  double tarifTotal(bool meche,bool barbe) const override;
};

#endif  // COIFFEUR_SPECIALISTE_FEMMES_H
