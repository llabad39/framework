#include <SFML/Graphics.hpp>
#include "Jeu2048Plus.hpp"

sf::RenderWindow window(sf::VideoMode(480, 700), "2048Plus");
sf::Text caseText;//texte nécessaire au jeu
sf::Text titleGame;
sf::Text consigne;
sf::Text endText;
sf::RectangleShape caseBack(sf::Vector2f(100, 100));//carré pour les cases
sf::Color textColor(255, 255, 255, 255);
Jeu2048Plus jeu(4);
bool win;
bool loose;
void griddraw(){
  window.clear(sf::Color(102,102,102,255));
  int taille = jeu.getTaille();
  window.draw(titleGame);//écriture des textes fixes
  window.draw(consigne);
  if(!win && !loose){
    for(int i=0;i<taille;i++){//dessin de chaque case du plateau
      for(int j=0;j<taille;j++){
      	caseBack.setPosition(105*j+30,105*i+150);
	if(!jeu.get(i,j)->isEmpty()){
	  caseBack.setFillColor(sf::Color(252, 220, 18,255));
	  caseText.setString(jeu.get(i,j)->getImage());
	  int dec = jeu.get(i,j)->getImage().length();
	  caseText.setPosition(105*j+65-(dec-1)*10,105*i+195);
	  caseText.setCharacterSize(35-(dec-1)*5);
	  window.draw(caseBack);
	  window.draw(caseText);
	}
	else{
	  caseBack.setFillColor(sf::Color::White);
	  window.draw(caseBack);
	}
      }
    }
  }
  else{//sinon écriture du texte de fin:gagné où perdu
    if(win){
      endText.setString("YOU\nWIN");
      endText.setCharacterSize(200);
      endText.setPosition(60,150);
    }
    else{
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
  if (!fontC.loadFromFile("police/emmasophia.ttf")) {//chargement des polices
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
  caseText.setFont(fontC);
  caseText.setCharacterSize(4);
  caseText.setColor(textColor);
  
  titleGame.setString("2048Plus");//mise en place du texte du titre
  titleGame.setPosition(10,0);
  titleGame.setCharacterSize(120);
  titleGame.setFont(fontT);
  titleGame.setColor(sf::Color(0,100,0,255));
  
  consigne.setString("fusionner les cases pour faire 2048\nattention aux impairs et negatifs\nappuyer sur espace pour recommencer");//mise en place du texte des consignes
  consigne.setPosition(10,600);
  consigne.setFont(fontCons);
  consigne.setCharacterSize(20);

  
  endText.setFont(fontWin);
  endText.setColor(sf::Color::Black);
  
  win=false;
  loose=false;
  while (window.isOpen()) {//on s'occupes des evenemments lorsque la fenêtre est ouverte
    sf::Event event;
   
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
	bool played;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
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
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
	  jeu = Jeu2048Plus(4);
	  played=false;
	  win=false;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
	  loose = true;
	  played=false;
	  window.display();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){//jouer en mode automatique
	  played = jeu.oneMove();
	}
	else{
	  played=false;
	}
	if(played)
	  jeu.endTurn();
      }
    }
    win = jeu.win();
    loose = jeu.loose();
    griddraw();//on dessine la fenêtre
    window.display();
  }
}
