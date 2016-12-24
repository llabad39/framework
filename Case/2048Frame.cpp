#include <SFML/Graphics.hpp>
#include "Jeu2048.hpp"

sf::RenderWindow window(sf::VideoMode(38*4, 38*4), "2048");
sf::Sprite sprite[4][4];

Jeu2048 jeu(4);
void griddraw(){
  int taille = jeu.getTaille();
  for(int i=0;i<taille;i++){
    for(int j=0;j<taille;j++){
      sf::Texture texture;
      texture.loadFromFile(jeu.get(i,j)->getImage());
      sf::Text t;
      /*t.setString("4");
      t.setPosition(19*j,19*i);
      tileText.setCharacterSize(32);*/
      sprite[i][j].setTexture(texture);
      sprite[i][j].setPosition(38*j,38*i);
      window.draw(t);
      window.draw(sprite[i][j]);
    }
  }
}

int main(){
  while (window.isOpen()) {
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
	else{
	  played=false;
	}
	if(played)
	  jeu.endTurn();
	jeu.affiche();
	
      }
    }
     griddraw();
     window.display();
  }
}

