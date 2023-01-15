#ifndef COIFFEUR_H
#define COIFFEUR_H

#include "CoupeDeCheveux.h"

#include <string>
#include <vector>

class Coiffeur {
 public:
  // Constructeur par défaut
  Coiffeur();

  // Constructeur avec initialisation des champs
 
  Coiffeur(std::string nom, std::string adresse, std::vector<CoupeDeCheveux*> coupesDeCheveux);

  //Destructeur
  ~Coiffeur();

  // Accesseurs et mutateurs pour les champs
  std::string getNom() const;
  void setNom(std::string nom);
  std::string getAdresse() const;
  void setAdresse(std::string adresse);
  std::string getPays() const;
  void setPays(std::string pays);
  std::string getVille() const;
  void setVille(std::string ville);
  std::vector<CoupeDeCheveux*> getCoupesDeCheveux() const;
  void setCoupesDeCheveux(std::vector<CoupeDeCheveux*> coupesDeCheveux);
  std::vector<double> getTarifs() const;
  void setTarifs(std::vector<double> tarifs);

  // Fonction virtuelle pure pour obtenir le tarif total des coupes de cheveux proposées par le coiffeur
  virtual double tarifTotal() const = 0;

 protected:
  // Champs privés de la classe
  std::string nom_;
  std::string adresse_;
  std::string pays_;
  std::string ville_;
  std::vector<CoupeDeCheveux*> coupesDeCheveux_;
  std::vector<double> tarifs_;
};

#endif  // COIFFEUR_H
