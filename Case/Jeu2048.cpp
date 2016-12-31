#include "Jeu2048.hpp"

Jeu2048::Jeu2048(int t):Jeu(t), highestFus(0){
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++){
      plat(i,j,make_shared<Vide>()); //on instancie un plateau vide
    }
  }
  place();//on y place deux cases
  place();
}

bool Jeu2048::right(){
  bool move=false; //boolean vérifiant si il y a déplacement
  int taille = getTaille();
  for(int i=0;i<taille;i++){
    for(int j=taille-2;j>=0;j--){//parcours de gauche à droite sans la derniere case
      if(!plat.get(i,j)->isEmpty()){ //si la case est un chiffre
	int k=j+1;//on regarde la case d'après
	while(plat.get(i,k)->isEmpty()){ //tant que c'est vide on peut avancez
	  k++;
	  move =true;
	  if(k==taille){ //si on est arrivé au bout on arrête
	    break;
	  }
	}
	if(k!=taille){// si on est pas au bout on est donc sur un chiffre
	  shared_ptr<Chiffre> c = static_pointer_cast<Chiffre>(plat.get(i,j));
	  shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,k));
	  if(c->moveTo(c2)){ //on verifie si les chiffres peuvent fusionner
	    plat(i,j,make_shared<Vide>());//on met la case déplacer à vide
	    int v= c2->getVal();
	    if(v != 0){//on vérifie qu'il n'y pas eu fusion d'opposé
	      if(v>highestFus)//si la valeur de fusion est supérieur aux autres chiffres on lui donne cette valeur
		highestFus = v;
	    }
	    else
	      plat(i,k,make_shared<Vide>());
	    move=true;
	  }
	  else if(k!=j){//si la case c'est déplacé on échange avec la case vide
	    k--;
	    plat.swap(i,j,i,k);
	  }
	}
	else if(k!=j){//si la case c'est déplacé on échange avec la case vide
	  k--;
	  plat.swap(i,j,i,k);
	}
      }
    }
    
  }
  return move;
}

bool Jeu2048::down(){
  plat.rotation();//on tourne la plateau une fois pour pouvoir tourner à droite
  bool move =right();//on déplace les cases vers la droite
  plat.rotation();//on remet le plateau dans le bon sens
  plat.rotation();
  plat.rotation();
  return move;
}

bool Jeu2048::left(){
  plat.rotation();//on tourne deux fois pour pouvoir tourner à droite
  plat.rotation();
  bool move =right();//on déplace les cases vers la droite
  plat.rotation();//on remet le plateau dans le bon sens
  plat.rotation();
  return move;
}

bool Jeu2048::up(){
  plat.rotation();//on tourne trois fois pour  pouvoir tourner à droite
  plat.rotation();
  plat.rotation();
  bool move =right();//on déplace les cases vers la droite
  plat.rotation();//on remet le plateau dans le bon sens
  return move;
}


void Jeu2048::place(){
  int x,y;
  int t = getTaille();
  do{//on cherche une case vide aléatoirement
    x = Fonction::aleat(0,t-1);
    y = Fonction::aleat(0,t-1);
  }while(!plat.get(x,y)->isEmpty());
  plat(x,y,make_shared<ChiffreBase2>());
  
}

bool Jeu2048::endTurn(){
  if(!win() && !loose()){//si le jeu n'est pas terminé
    int t = getTaille();
    for(int i=0;i<t;i++){
      for(int j=0;j<t;j++){
	plat.get(i,j)->endTurn();//on applique endTurn de case sur tout le plateau
      }
    }
    place();//on place une nouvelle case
    return true;
  }
  else
    return false;
}
void Jeu2048::affiche(){
  plat.affiche();
}

bool Jeu2048::win(){
  if(highestFus==2048)//si la valeur la plus haute est égal à 2048 on à gagné
    return true;
  else
    return false;
}

bool Jeu2048::canHor(){
  int t=getTaille();
  for(int i=0;i<t;i++){
    for(int j=0;j<t-1;j++){
      if(!(plat.get(i,j)->isEmpty() || plat.get(i,j+1)->isEmpty())){//si la case et la case voisine de droite ne sont pas vide
	shared_ptr<Chiffre> c = static_pointer_cast<Chiffre>(plat.get(i,j));
	shared_ptr<Chiffre> c2 = static_pointer_cast<Chiffre>(plat.get(i,j+1));
	if(c->getVal()== c2->getVal() || c->getVal()== -(c2->getVal()))//on vérifie si elles peuvent fusionner
	  return true;
      }
      else //si l'une est vide alors on peut se déplacer
	return true;
    }
  }
  return false;//si aucune case ne peut fusionner horizontalement et que aucune est vide on renvoie false
}



bool Jeu2048::canVert(){
  plat.rotation();//on tourne une fois pour préparer la vérification horizontal
  bool m = canHor();//on vérifie si un déplacement horizontal est possible
  plat.rotation();//on remet le plateau dans le bon sens
  plat.rotation();
  plat.rotation();
  return m;
}
bool Jeu2048::loose(){
  if(canHor())//si l'on peut se déplacer horizontalement ou verticalement on renvoie false
    return false;
  else if(canVert())
    return false;
  return true;//sinon on à perdu
}
  


