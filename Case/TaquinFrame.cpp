#include <SFML/Graphics.hpp>
#include "JeuTaquin.hpp"

sf::RenderWindow window(sf::VideoMode(480, 700), "Taquin");
sf::Text caseText;
sf::Text titleGame;
sf::Text consigne;
sf::Text winText;
sf::RectangleShape caseBack(sf::Vector2f(100, 100));//carré représentant une case
sf::Color textColor(255, 255, 255, 255);
JeuTaquin jeu(4);//jeu taquin de taille 4*4
bool win;
void griddraw(){
  window.clear(sf::Color(102,102,102,255));
  int taille = jeu.getTaille();
  window.draw(titleGame);
  window.draw(consigne);
  if(!win){//dessine le plateau du jeu tant que celui-ci n'est pas finie
    for(int i=0;i<taille;i++){
      for(int j=0;j<taille;j++){
      	caseBack.setPosition(105*j+30,105*i+150);
	if(!jeu.get(i,j)->isEmpty()){
	  caseBack.setFillColor(sf::Color(165,42,42,255));
	  caseText.setString(jeu.get(i,j)->getImage());
	  caseText.setPosition(105*j+65,105*i+195);//positionne les cases avec un espace entre chacune
	  caseText.setCharacterSize(35);
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
  else{//sinon dessine le texte de victoire
    window.draw(winText);
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
  caseText.setFont(fontC);//réglages du texte des chiffres
  caseText.setCharacterSize(4);
  caseText.setColor(textColor);
  
  titleGame.setString("Taquin");//réglages du titre
  titleGame.setPosition(80,0);
  titleGame.setCharacterSize(120);
  titleGame.setFont(fontT);
  titleGame.setColor(sf::Color(0,100,0,255));
  
  consigne.setString("remettez les chiffres dans le bonne ordre\nappuyer sur espace pour recommencer");//réglage des consignes
  consigne.setPosition(10,600);
  consigne.setFont(fontCons);
  consigne.setCharacterSize(20);

  winText.setString("YOU\nWIN");//réglage du texte de victoire
  winText.setPosition(60,150);
  winText.setFont(fontWin);
  winText.setCharacterSize(200);
  winText.setColor(sf::Color::Black);
  
  win=false;
  while (window.isOpen()) {//s'occupe des évennement tant que la fenêtre est ouverte
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
	  jeu = JeuTaquin(4);
	  played=false;
	  win=false;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
	  win = true;
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
    win = jeu.win();//on regarde si le jeu est finie
    griddraw();//on redessine la fenêtre
    window.display();
  }
}
