#include <SFML/Graphics.hpp>
#include "JeuSokoban.hpp"

sf::RenderWindow window(sf::VideoMode(1080, 1200), "Taquin");
sf::Text titleGame;
sf::Text consigne;
sf::Text winText;
sf::Sprite caseIm;

JeuSokoban jeu(10);
bool win;
void griddraw(){
  window.clear(sf::Color(102,102,102,255));
  int taille = jeu.getTaille();
  window.draw(titleGame);
  window.draw(consigne);
  if(!win){
    for(int i=0;i<taille;i++){
      for(int j=0;j<taille;j++){
	sf::Texture texture;
	if(!jeu.get(i,j)->isEmpty()){
	  texture.loadFromFile(jeu.get(i,j)->getImage());
	}
	else{
	  if(jeu.isPers(i,j)){
	    texture.loadFromFile("image/perso.png");
	  }else{ 
	    if(jeu.isObj(i,j)){
	      texture.loadFromFile("image/objectif.png");
	    }else{
	      texture.loadFromFile("image/sol.png");
	    }
	  }
	}
	caseIm.setTexture(texture);
	caseIm.setPosition(100*j+30,100*i+150);
	window.draw(caseIm);
      }
    }
  }
  else{
    window.draw(winText);
  }
}

int main(){
  sf::Font fontC;
  sf::Font fontT;
  sf::Font fontCons;
  sf::Font fontWin;
  if (!fontC.loadFromFile("police/emmasophia.ttf")) {
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
    
  titleGame.setString("Sokoban");
  titleGame.setPosition(350,0);
  titleGame.setCharacterSize(120);
  titleGame.setFont(fontT);
  titleGame.setFillColor(sf::Color(0,100,0,255));
  
  consigne.setString("poussez les caisses sur les objectifs\nappuyer sur espace pour recommencer");
  consigne.setPosition(10,1150);
  consigne.setFont(fontCons);
  consigne.setCharacterSize(20);

  winText.setString("YOU\nWIN");
  winText.setPosition(100,100);
  winText.setFont(fontWin);
  winText.setCharacterSize(500);
  winText.setFillColor(sf::Color::Black);
  
  win=false;
  while (window.isOpen()) {
    sf::Event event;
   
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      if (event.type == sf::Event::KeyPressed) {
	bool played = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	  if(!win)
	    played = jeu.up();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	  if(!win)
	    played = jeu.right();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	  if(!win)
	    played = jeu.down();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	  if(!win)
	    played = jeu.left();
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
	  jeu = JeuSokoban(10);
	}
	
	else{
	  played=false;
	}
	if(played)
	  jeu.endTurn();	
      }
    }
    win = jeu.win();
    griddraw();
    window.display();
  }
}
