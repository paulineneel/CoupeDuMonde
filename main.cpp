#include "CoupeDeCheveux.h"
#include "CoupeDeCheveuxHommes.h"
#include "CoupeDeCheveuxFemmes.h"
#include "Coiffeur.h"
#include "CoiffeurSpecialisteHommes.h"
#include "CoiffeurSpecialisteFemmes.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>

std::string readFileIntoString(const std::string& path) {
  /*
  *   @return string
  *   
  *   Lis un fichier/une ligne d'un fichier et le transforme en chaine de caractères
  * 
  */

    auto ss = std::ostringstream{};
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

std::vector<std::vector<std::string>> transformCSVtoString(std::string filename,char del) 
{
  /*
  *   @return vector<vector<string>>
  *   
  *   Lis un fichier csv et le transforme en vecteur de chaine de caractères
  * 
  */

  std::vector<std::vector<std::string>> csv_contents;
  std::string file_contents;
  file_contents = readFileIntoString(filename);

  std::istringstream sstream(file_contents);
  std::vector<std::string> items;
  std::string record;

  int counter = 0;
  while (std::getline(sstream, record)) 
  {
    std::istringstream line(record);
    while (std::getline(line, record, del)) 
    {
      items.push_back(record);
      counter += 1;
    }
    csv_contents.push_back(items);
    items.clear();
    counter = 0;
  }
  return csv_contents;
}

bool findInVector(std::vector<std::vector<std::string>> vect, int indSearch, std::string x)
{
  /*
  *   @return bool
  *   
  *   renvoie True si l'élément x appartient au vecteur
  * 
  */

  bool found = false;
  for(auto iterator : vect)
  {
    if(iterator[indSearch] == x)
      found = true;
  }

  return found;
}

std::vector<std::string> indInVector(std::vector<std::vector<std::string>> vect, int indSearch, std::string ville, std::string pays,std::string genre)
{
  /*
  *   @return vector<string>
  *   
  *   renvoie un vecteur des premiers éléments des vecteurs de vect qui contiennent ville et pays
  * 
  */

  std::vector<std::string> rep;
  for(auto iterator : vect)
  {
    if (iterator[indSearch+2] == genre)
      if(iterator[indSearch] == pays)
        if(iterator[indSearch + 1] == ville)
          rep.push_back(iterator[0]);
  }

  return rep;
}

int main() {
  // Lecture fichiers csv
  std::string filename1("liste_coiffeurs.csv");
  std::string filename2("liste_coupes_de_cheveux.csv");
  char delimiter = ';';

  std::vector<std::vector<std::string>> csv_coiffeurs = transformCSVtoString(filename1,delimiter);
  std::vector<std::vector<std::string>> csv_coiffures = transformCSVtoString(filename2,delimiter);

  std::vector<CoiffeurSpecialisteHommes*> coiffeurHommes;
  std::vector<CoiffeurSpecialisteFemmes*> coiffeurFemmes;
  
  int ind_csv_coiffure = 1;

  int nbTotalCoiffure = csv_coiffures.size();
  int nbCoiffeur = csv_coiffeurs.size();

  /***** Création des coiffeurs *****/

  for(int i = 1; i< nbCoiffeur;i++ ) //on commence à 1 car 1ere ligne = nom des attributs
  {     // créer des coiffeurs selon leur specialite
    
    if(csv_coiffeurs[i][4] == "F")
    {
      coiffeurFemmes.push_back(new CoiffeurSpecialisteFemmes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2],
      csv_coiffeurs[i][3]));
    }
    else
    {
      coiffeurHommes.push_back(new CoiffeurSpecialisteHommes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2],
      csv_coiffeurs[i][3]));
    }

  }

  /***** Création des coupes proposées par chaque coiffeur *****/

  std::string nom = csv_coiffures[1][0]; // nom 1er du coiffeur

  while(ind_csv_coiffure < nbTotalCoiffure) //on commence à 1 car 1ere ligne = nom des attributs
  {

    if (csv_coiffures[ind_csv_coiffure][3] == "F") //coiffeurSpeFemmes
    {
      std::vector<CoupeDeCheveuxFemmes*> coupesDeCheveuxFemmes;
    
      while(ind_csv_coiffure < nbTotalCoiffure && csv_coiffures[ind_csv_coiffure][0] == nom) //ajoute toutes les coupes d'un coiffeur
      {
        coupesDeCheveuxFemmes.push_back(new CoupeDeCheveuxFemmes(
            csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
            std::stof(csv_coiffures[ind_csv_coiffure][4]),false));

        ind_csv_coiffure++;
      }
    
      //On ajoute les coiffures au coiffeur correspondant
      for(auto coif : coiffeurFemmes)
      {
        if (coif->getNom() == nom)
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxFemmes);
        }
      }
    }
    
    else
    {
      std::vector<CoupeDeCheveuxHommes*> coupesDeCheveuxHommes;
    
      while(ind_csv_coiffure < nbTotalCoiffure && csv_coiffures[ind_csv_coiffure][0] == nom) //ajoute toutes les coupes d'un coiffeur
      {
        coupesDeCheveuxHommes.push_back(new CoupeDeCheveuxHommes(
            csv_coiffures[ind_csv_coiffure][1],csv_coiffures[ind_csv_coiffure][2],
            std::stof(csv_coiffures[ind_csv_coiffure][4]),false));

        ind_csv_coiffure++;
      }

      //On ajoute les coiffures au coiffeur correspondant
      for(auto coif : coiffeurHommes)
      {
        if (coif->getNom() == nom)
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxHommes);
        }
      }
    }

    if(ind_csv_coiffure<nbTotalCoiffure)
      nom = csv_coiffures[ind_csv_coiffure][0];
  }

  // Fin création


  /***** Début Appli *****/

  std::string genreUtilisateur;
  std::string paysUtilisateur;
  std::string villeUtilisateur;

  std::cout << "Bienvenue sur Coupes du monde\n" << "L'appli des coupes INTER PLANET HAIR\n" <<std::endl;
  std::cout << "Entrer votre genre (H ou F)" << std::endl;
  std::cin >> genreUtilisateur;
  if (genreUtilisateur != "F"  && genreUtilisateur != "H")
  {
    std::cout << "ERREUR genre non reconnu\n\n" << "Veuillez relancer l'appli !"  << std::endl;
    return 0;
  }

  std::string tmp;

  std::cout << "\nDans quel pays vous situez vous ?" << std::endl;
  std::cin >> paysUtilisateur;
  std::getline(std::cin,tmp);
  paysUtilisateur += tmp;
  if (!findInVector(csv_coiffeurs,2,paysUtilisateur)){
    std::cout << "ERREUR pays non disponible\n\n" << std::endl; 
    return 0;
  }

  std::cout << "\nDans quel ville vous situez vous ?" << std::endl;
  std::cin >> villeUtilisateur;
  std::getline(std::cin,tmp);
  villeUtilisateur += tmp;
  if (!findInVector(csv_coiffeurs,3,villeUtilisateur)){ // test imbriqué à faire
    std::cout << "ERREUR ville non disponible\n\n" << std::endl; 
    return 0;
  }
  
  std::set<std::string> coupeDispo;
  std::vector<std::string> coiffeursDispo = indInVector(csv_coiffeurs,2,villeUtilisateur,paysUtilisateur,genreUtilisateur);

  if (genreUtilisateur == "F")
  {
    for(auto coif : coiffeursDispo)
      for(auto coifFemme : coiffeurFemmes)
        if(coifFemme->getNom() == coif)
        {
          for(auto coupe : coifFemme->getCoupesDeCheveux())
          {
            coupeDispo.insert(coupe->getForme());
          }
        }
  }


  if (genreUtilisateur == "H")
  {
    for(auto coif : coiffeursDispo)
      for(auto coifHomme : coiffeurHommes)
        if(coifHomme->getNom() == coif)
        {
          for(auto coupe : coifHomme->getCoupesDeCheveux())
            coupeDispo.insert(coupe->getForme());
        }
  }

  std::cout << "\nCoupes disponibles à " << villeUtilisateur << " " << paysUtilisateur << " pour ";

  if(genreUtilisateur == "F")
    std::cout << "Femme:" << std::endl;
  
  else
    std::cout << "Homme:" << std::endl;

  if (coupeDispo.empty())
  {
    std::cout << "Pas de coiffeurs disponibles " << std::endl;
    return 0;
  }
  for(auto coupeD : coupeDispo)
  {
    std::cout << coupeD << std::endl;
  }

  std::string coupeChoisie;
  std::string coupe;
  std::string optMeche;
  std::string optBarbe;

  std::cout << "\n Choix de coupe " << std::endl;
  std::cin >> coupeChoisie;
  std::getline(std::cin,coupe);
  coupeChoisie = coupeChoisie + coupe;

  if (genreUtilisateur=="F")
  {
    std::cout << "\n Option mèches : Oui ou Non " << std::endl;
    std::cin >> optMeche;
    std::cout << std::endl;
  }
  else
  {
    std::cout << "\n Option barbe : Oui ou Non " << std::endl;
    std::cin >> optBarbe;
    std::cout << std::endl;
  }
  


  if (genreUtilisateur == "F")
  {
    for(auto coif : coiffeursDispo)
      for(auto coifFemme : coiffeurFemmes)
        if(coifFemme->getNom() == coif)
        {
          for(auto coupe : coifFemme->getCoupesDeCheveux())
          {
            if (coupe->getForme() == coupeChoisie)
            {
              if(optMeche == "Oui")
                coupe->setMeches(true);

              std::cout << coif << " : " << coupeChoisie << " = " << coupe->getTarif() << " euros" << std::endl;
            }
          }
            
        }
  }
  else
  {
    for(auto coif : coiffeursDispo)
      for(auto coifHomme : coiffeurHommes)
        if(coifHomme->getNom() == coif)
        {
          for(auto coupe : coifHomme->getCoupesDeCheveux())
          {
            if (coupe->getForme() == coupeChoisie)
            {
              if(optBarbe == "Oui")
                coupe->setBarbe(true);
              std::cout << coif << " : " << coupeChoisie << " = " << coupe->getTarif() << " euros" << std::endl;
            }
          }
            
        }
  }

  std::string coifChoisi;
  std::string coif;
  std::cout << "\n Choix du coiffeur " << std::endl;
  std::cin >> coifChoisi;
  std::getline(std::cin,coif);
  coifChoisi = coifChoisi + coif;



  if (genreUtilisateur == "F")
  {
    for(auto coiffeurF : coiffeurFemmes)
    {
      if(coifChoisi == coiffeurF->getNom())
      {
       std::cout << *coiffeurF << std::endl;
      }    
      std::cout << std::endl;
      
      
    }
  }
  else
  {
    for(auto coiffeurH : coiffeurHommes)
    {
      if(coifChoisi == coiffeurH->getNom())
      {
        std::cout << *coiffeurH << std::endl;
      }
      std::cout << std::endl;
    }
  }
 
  return 0;
}