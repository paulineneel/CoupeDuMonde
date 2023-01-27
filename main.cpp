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
    if (!input_file.is_open()) { // On vérifie que le fichier est bien ouvert
        std::cerr << "Could not open the file - '" // Sinon on affiche une erreur
             << path << "'" << std::endl; // On affiche le chemin du fichier
        exit(EXIT_FAILURE); // On arrête l'exécution
    }
    ss << input_file.rdbuf(); // On lit le fichier
    return ss.str(); // On retourne le contenu du fichier
}

std::vector<std::vector<std::string>> transformCSVtoString(std::string filename,char del)  
{
  /*
  *   @return vector<vector<string>>
  *   
  *   Lis un fichier csv et le transforme en vecteur de chaine de caractères
  * 
  */

  std::vector<std::vector<std::string>> csv_contents; // vecteur de vecteurs de string
  std::string file_contents; // string qui contient le contenu du fichier
  file_contents = readFileIntoString(filename); // on lit le fichier

  std::istringstream sstream(file_contents); // on crée un flux de string
  std::vector<std::string> items; // vecteur de string qui contient les éléments d'une ligne
  std::string record; 

  int counter = 0;
  while (std::getline(sstream, record)) // on lit le flux ligne par ligne
  {
    std::istringstream line(record); //
    while (std::getline(line, record, del))  // on lit la ligne caractère par caractère
    {
      items.push_back(record); // on ajoute le caractère au vecteur
      counter += 1; // on incrémente le compteur
    }
    csv_contents.push_back(items); // on ajoute le vecteur de caractères au vecteur de vecteurs
    items.clear(); // on vide le vecteur de caractères
    counter = 0; // on remet le compteur à 0
  }
  return csv_contents; // on retourne le vecteur de vecteurs
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

  std::vector<std::vector<std::string>> csv_coiffeurs = transformCSVtoString(filename1,delimiter); // on transforme le fichier csv en vecteur de vecteurs de string
  std::vector<std::vector<std::string>> csv_coiffures = transformCSVtoString(filename2,delimiter); // on transforme le fichier csv en vecteur de vecteurs de string

  std::vector<CoiffeurSpecialisteHommes*> coiffeurHommes; // vecteur de coiffeurs hommes
  std::vector<CoiffeurSpecialisteFemmes*> coiffeurFemmes; // vecteur de coiffeurs femmes
  
  int ind_csv_coiffure = 1; //indice de parcours du vecteur csv_coiffures

  int nbTotalCoiffure = csv_coiffures.size(); //nombre total de coupes de cheveux
  int nbCoiffeur = csv_coiffeurs.size(); //nombre total de coiffeurs

  /***** Création des coiffeurs *****/

  for(int i = 1; i< nbCoiffeur;i++ ) //on commence à 1 car 1ere ligne = nom des attributs
  {     // créer des coiffeurs selon leur specialite
    
    if(csv_coiffeurs[i][4] == "F") //coiffeurSpeFemmes
    {
      coiffeurFemmes.push_back(new CoiffeurSpecialisteFemmes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2], //nom, ville, pays
      csv_coiffeurs[i][3]));//specialite
    }
    else
    {
      coiffeurHommes.push_back(new CoiffeurSpecialisteHommes(csv_coiffeurs[i][0],csv_coiffeurs[i][1],csv_coiffeurs[i][2], //nom, ville, pays
      csv_coiffeurs[i][3])); //specialite
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
      for(auto coif : coiffeurFemmes) //pour chaque coiffeur
      {
        if (coif->getNom() == nom) //si le nom du coiffeur est le même que celui de la coupe
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxFemmes); //on ajoute les coupes au coiffeur
        }
      }
    }
    
    else
    {
      std::vector<CoupeDeCheveuxHommes*> coupesDeCheveuxHommes; // vecteur de coupes de cheveux hommes
    
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
        if (coif->getNom() == nom) //si le nom du coiffeur est le même que celui de la coupe
        {
          coif->setCoupesDeCheveux(coupesDeCheveuxHommes); //on ajoute les coupes au coiffeur
        }
      }
    }

    if(ind_csv_coiffure<nbTotalCoiffure) //pour éviter de dépasser le tableau
      nom = csv_coiffures[ind_csv_coiffure][0]; //nom du prochain coiffeur
  }

  // Fin création


  /***** Début Appli *****/

  std::string genreUtilisateur; // H ou F
  std::string paysUtilisateur; // pays 
  std::string villeUtilisateur; // ville

  std::cout << "Bienvenue sur Coupes du monde\n" << "L'appli des coupes INTER PLANET HAIR\n" <<std::endl; // titre
  std::cout << "Entrer votre genre (H ou F)" << std::endl;  // demande genre
  std::cin >> genreUtilisateur; // récupère genre
  if (genreUtilisateur != "F"  && genreUtilisateur != "H") // test genre
  {
    std::cout << "ERREUR genre non reconnu\n\n" << "Veuillez relancer l'appli !"  << std::endl; // erreur genre
    return 0; // fin appli
  }

  std::string tmp; // pour récupérer le reste de la ligne
 
  std::cout << "\nDans quel pays vous situez vous ?" << std::endl; // demande pays
  std::cin >> paysUtilisateur; // récupère pays
  std::getline(std::cin,tmp); // récupère le reste de la ligne
  paysUtilisateur += tmp; // ajoute le reste de la ligne au pays
  if (!findInVector(csv_coiffeurs,2,paysUtilisateur)){ // test pays
    std::cout << "ERREUR pays non disponible\n\n" << std::endl; // erreur pays
    return 0; 
  }

  std::cout << "\nDans quel ville vous situez vous ?" << std::endl; // demande ville
  std::cin >> villeUtilisateur; // récupère ville
  std::getline(std::cin,tmp); // récupère le reste de la ligne
  villeUtilisateur += tmp; // ajoute le reste de la ligne à la ville
  if (!findInVector(csv_coiffeurs,3,villeUtilisateur)){ // test imbriqué à faire
    std::cout << "ERREUR ville non disponible\n\n" << std::endl;  // erreur ville si pas de coiffeur
    return 0; 
  }
  
  std::set<std::string> coupeDispo; // set des coupes disponibles
  std::vector<std::string> coiffeursDispo = indInVector(csv_coiffeurs,2,villeUtilisateur,paysUtilisateur,genreUtilisateur); // vecteur des coiffeurs disponibles

  if (genreUtilisateur == "F") // si femme
  {
    for(auto coif : coiffeursDispo) // pour chaque coiffeur disponible
      for(auto coifFemme : coiffeurFemmes) // pour chaque coiffeur femme
        if(coifFemme->getNom() == coif) // si le coiffeur est le même que celui de la liste des coiffeurs disponibles
        {
          for(auto coupe : coifFemme->getCoupesDeCheveux()) // pour chaque coupe de cheveux du coiffeur
          {
            coupeDispo.insert(coupe->getForme()); // ajoute la coupe au set des coupes disponibles
          }
        }
  }


  if (genreUtilisateur == "H") // si homme
  {
    for(auto coif : coiffeursDispo) // pour chaque coiffeur disponible
      for(auto coifHomme : coiffeurHommes) // pour chaque coiffeur homme
        if(coifHomme->getNom() == coif) // si le coiffeur est le même que celui de la liste des coiffeurs disponibles
        {
          for(auto coupe : coifHomme->getCoupesDeCheveux()) // pour chaque coupe de cheveux du coiffeur
            coupeDispo.insert(coupe->getForme());// ajoute la coupe au set des coupes disponibles
        }
  }

  std::cout << "\nCoupes disponibles à " << villeUtilisateur << " " << paysUtilisateur << " pour "; // affiche les coupes disponibles

  if(genreUtilisateur == "F") // si femme
    std::cout << "Femme:" << std::endl; // affiche femme
  
  else
    std::cout << "Homme:" << std::endl; // affiche homme

  if (coupeDispo.empty()) // si pas de coupe disponible
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