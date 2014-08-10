//
//  main.cpp
//  Coursera_Cpp
//
//  Created by Tuo LI on 14-3-22.
//  Copyright (c) 2014年 Tuo LI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/

class Auteur {
    
    string nom;
    bool isPrized = false;
public:
    Auteur(){};
    
    Auteur(string x){
        nom = x;
    };
    
    Auteur(string x, bool f ){
        nom = x;
        isPrized = f;
    };
    
    string getNom(){
        return nom;
    };
    
    bool getPrix(){
        return isPrized;
    };
    
    ~Auteur(){};
    
};


class Oeuvre {
    
    string titre,langue;
    Auteur  au;
    
    Oeuvre(Oeuvre& x){
        titre = x.getTitre();
        au = x.getAuteur();
        langue = x.getLangue();
    };
    
public:
    
   Oeuvre(){};
    
    Oeuvre(string pa1, Auteur& pa2, string pa3):titre(pa1),au(pa2),langue(pa3) {
       };
    
    
    
    string getTitre(){
        return titre;};
    
    Auteur&  getAuteur(){
        return au;
    } ;
    
    string getLangue(){
        return langue;};
    
    void affiche(){
        cout << "<"<<titre<<">,"<<"<"<<au.getNom()<<">"<<"en"<<"<"<<langue<<">"<<endl;
    };
    

    ~Oeuvre(){
        cout << "L'oeuvre " <<"<"<< titre << ">, "<<"<"<< au.getNom() << ">, "<<"en<"<< langue << ">  n'est plus disponible."<<endl;
    };
    

};


class Exemplaire{
    
    Oeuvre* theWork;
    
public:
  
    //-----------
    
   Exemplaire(){};
    
    Exemplaire(Oeuvre &x){
      theWork = &x;
    cout<< " Nouvel exemplaire de : <"<<theWork->getTitre()<< ">,<"<<theWork->getAuteur().getNom()<<">, en<"<<theWork->getLangue()<<">"<<endl;
    };
    
   
    Exemplaire(Exemplaire& eg_src){
       
       theWork = &eg_src.getOeuvre();
    
       cout<<"Copie d'un exemplaire de : <" << theWork->getTitre()<<">, <"<<theWork->getAuteur().getNom()<<">, en <"<<theWork->getLangue()<<">"<<endl;
    };
    
  ~Exemplaire(){
        cout<<"un exemplaire de : <" << theWork->getTitre()<<">, <"<<theWork->getAuteur().getNom()<<">, en <"<<theWork->getLangue()<<">, a été jeté"<<endl;
    }
    
    void affiche()
    {
        cout<< "Exemplaire de : <"<< theWork->getTitre()<< ">,<"<<theWork->getAuteur().getNom()<<">, en<"<<theWork->getLangue()<<">"<<endl;
        
    }
    
    Oeuvre&  getOeuvre() {
        
        
    return *theWork;};
    
};



class Bibliotheque{
    
    string nom;
    vector<Exemplaire*> v;
    //vector<Oeuvre*> v;

public:
    Bibliotheque(){
    cout<< "   La bibliothèque [" << nom << "]est ouverte !"<<endl;
        
    };
    
    Bibliotheque(string name){
        nom = name;
        cout<< "   La bibliothèque [" << nom << "]est ouverte !"<<endl;
    
    };
    
    
    string getNom(){
        return nom;
        
    };
    
   void stocker(Oeuvre& work,int n=1){
      
       
       for(unsigned int i=0;i<n;i++){
        Exemplaire *exp= new Exemplaire(work);
       //    Exemplaire exp(work);
           v.push_back(exp);
       
       }
   };
    
    void listerExemp(string lan){
        
        for(int i=0; i<v.size();i++){
           if(v[i]->getOeuvre().getLangue()==lan){
            cout<< "    Exemplaire de : <"<< v.at(i)->getOeuvre().getTitre()<< ">,<"<<v.at(i)->getOeuvre().getAuteur().getNom()<<">, en<"<<v.at(i)->getOeuvre().getLangue()<<">"<<endl;
            //cout<< "    Exemplaire de : <"<< v.at(i)->getTitre()<< ">,<"<<v.at(i)->getAuteur().getNom()<<">, en<"<<v.at(i)->getLangue()<<">"<<endl;
               
           }
}};
    
    void listerExemp(){
        for(unsigned int i=0; i<v.size();i++){
        cout<< "    Exemplaire de : <"<< v.at(i)->getOeuvre().getTitre()<< ">,<"<<v.at(i)->getOeuvre().getAuteur().getNom()<<">, en<"<<v.at(i)->getOeuvre().getLangue()<<">"<<endl;
        //cout<< "    Exemplaire de : <"<< v.at(i)->getTitre()<< ">,<"<<v.at(i)->getAuteur().getNom()<<">, en<"<<v.at(i)->getLangue()<<">"<<endl;
            
        }
    };
    
    
    int countNb(Oeuvre& w){
        int n=0;
        for(int i=0; i<v.size();i++){
            if(v.at(i)->getOeuvre().getTitre() == w.getTitre()){
                n++;
            }};
        return n;
    }
    
    
    void afficherAuteurs(bool n){
        
        for(unsigned int i=0; i<v.size();i++){
            
            if (v.at(i)->getOeuvre().getAuteur().getPrix() == n) {
                cout<< "    Exemplaire de : <"<< v.at(i)->getOeuvre().getTitre()<< ">,<"<<v.at(i)->getOeuvre().getAuteur().getNom()<<">, en<"<<v.at(i)->getOeuvre().getLangue()<<">"<<endl;
            }
            
        }
    };

    ~Bibliotheque(){
    
        cout<< "   La bibliothèque [" << nom << "] est fermé !  et detruit des exemplaires! "<<endl;
    
   //     v.clear();
        
        for(unsigned int i=0; i<v.size();i++){
           v.at(i)->~Exemplaire();
        }
        
    }


};








/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
    Auteur a1("Victor Hugo"),
    a2("Alexandre Dumas"),
    a3("Raymond Queneau", true);
    
    Oeuvre o1("Les Misérables"           , a1, "français" ),
    o2("L'Homme qui rit"          , a1, "français" ),
    o3("Le Comte de Monte-Cristo" , a2, "français" ),
    o4("Zazie dans le métro"      , a3, "français" ),
    o5("The Count of Monte-Cristo", a2, "anglais" );
    
   
    Bibliotheque biblio("municipale");

    biblio.stocker(o1, 2);
    biblio.stocker(o2);
    biblio.stocker(o3, 3);
    biblio.stocker(o4);
    biblio.stocker(o5);
    
    
    cout << "La bibliothèque " << biblio.getNom()
    << " offre les exemplaires suivants :" << endl;
    biblio.listerExemp();
    
    const string langue("anglais");
    cout << " Les exemplaires en "<< langue << " sont :" << endl;
    biblio.listerExemp(langue);
    
    cout << " Les auteurs à succès sont :" << endl;
    // biblio.afficher_auteurs(true);
    
    cout << " Il y a " << biblio.countNb(o3) << " exemplaires de "
    << o3.getTitre() << endl;
    
    return 0;
}
