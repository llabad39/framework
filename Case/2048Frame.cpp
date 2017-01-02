#include <SFML/Graphics.hpp>
#include "Jeu2048.hpp"

sf::RenderWindow window(sf::VideoMode(480, 700), "2048");
sf::Text caseText;//texte pour chaque case
sf::Text titleGame;//texte du titre
sf::Text consigne;//consigne du jeu
sf::Text endText;//texte de fin si gagné ou perdu
sf::RectangleShape caseBack(sf::Vector2f(100, 100));//une case
sf::Color textColor(255, 255, 255, 255);//la couleur du chiffre
Jeu2048 jeu(4);//jeu 2048 de taille 4*4
bool win;
bool loose;
void griddraw(){
  window.clear(sf::Color(102,102,102,255));
  int taille = jeu.getTaille();
  window.draw(titleGame);
  window.draw(consigne);
  if(!win && !loose){
    for(int i=0;i<taille;i++){
      for(int j=0;j<taille;j++){
      	caseBack.setPosition(105*j+30,105*i+150);
	if(!jeu.get(i,j)->isEmpty()){
	  caseBack.setFillColor(sf::Color(252, 220, 18,255));//couleur de fond d'une case
	  caseText.setString(jeu.get(i,j)->getImage());//on écrit le chiffre de la case
	  int dec = jeu.get(i,j)->getImage().length();//on regarde la taille du chiffre
	  caseText.setPosition(105*j+65-(dec-1)*10,105*i+195);//on place la case au bonne endroit en laissant un petit espace
	  caseText.setCharacterSize(35-(dec-1)*5);
	  window.draw(caseBack);//on dessine la case
	  window.draw(caseText);//on écrit le chiffre
	}
	else{
	  caseBack.setFillColor(sf::Color::White);//on met la couleur à blance
	  window.draw(caseBack);//on dessine la case vide
	}
      }
    }
  }
  else{
    if(win){//on écrit le texte de victoire
      endText.setString("YOU\nWIN");
      endText.setCharacterSize(200);
      endText.setPosition(60,150);
    }
    else{//on écrit le texte de défaite
      endText.setString(" YOU\nLOOSE");
      endText.setCharacterSize(150);
      endText.setPosition(25,150);
    }
    window.draw(endText);
  }
    
}

int main(){
  sf::Font fontC;
  sf::Font fontT;
  sf::Font fontCons;
  sf::Font fontWin;
  if (!fontC.loadFromFile("police/emmasophia.ttf")) {//on charge les différentes police
		printf("can't find font");
		return -1;
  }
  if (!fontT.loadFromFile("police/Sketchy.ttf")) {
		printf("can't find font");
		return -1;
  }
  if (!fontCons.loadFromFile("police/CWGSans.ttf")) {
		printf("can't find font");
		return -1;
  }
  if (!fontWin.loadFromFile("police/CR21MODERN.ttf")) {
		printf("can't find font");
		return -1;
  }
  caseText.setFont(fontC);//réglage des cases
  caseText.setCharacterSize(4);
  caseText.setColor(textColor);
  
  titleGame.setString("2048");//réglages du titre
  titleGame.setPosition(80,0);
  titleGame.setCharacterSize(120);
  titleGame.setFont(fontT);
  titleGame.setColor(sf::Color(0,100,0,255));
  
  consigne.setString("fusionner les cases pour faire 2048\nappuyer sur espace pour recommencer");//réglages des consignes
  consigne.setPosition(10,600);
  consigne.setFont(fontCons);
  consigne.setCharacterSize(20);

  
  endText.setFont(fontWin);//réglages du texte de fin
  endText.setColor(sf::Color::Black);
  
  win=false;
  loose=false;
  while (window.isOpen()) {
    sf::Event event;
   
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
	bool played;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {//différent de type de déplacement au clavier
	  played = jeu.up();
	  window.display();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	  played= jeu.right();
	  window.display();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  played = jeu.down();
	  window.display();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  played = jeu.left();
	  window.display();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){//touche pour recommencer
	  jeu = Jeu2048(4);
	  played=false;
	  win=false;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){//jouer en mode automatique
	  played = jeu.oneMove();
	}
	else{
	  played=false;
	}
	if(played)//si le déplacement à bien eu lieu
	  jeu.endTurn();
      }
    }
    win = jeu.win();//on vérifie que le jeu n'est pas finis
    loose = jeu.loose();
    griddraw();//on redessine la grille
    window.display();
  }
}


