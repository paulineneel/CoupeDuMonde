#ifndef COIFFEUR_SPECIALISTE_HOMMES_H
#define COIFFEUR_SPECIALISTE_HOMMES_H

#include "Coiffeur.h"

class CoiffeurSpecialisteHommes : public Coiffeur {
 public:
  // Constructeurs
  CoiffeurSpecialisteHommes();
  CoiffeurSpecialisteHommes(std::string nom, std::string adresse, std::vector<CoupeDeCheveux*> coupesDeCheveux);

  // Redéfinition de la fonction virtuelle
  double tarifTotal() const override;

};

#endif  // COIFFEUR_SPECIALISTE_HOMMES_H
