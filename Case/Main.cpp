#include "JeuSokoban.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
int main(){
  JeuSokoban j(10);
  /*
  
 sf::RenderWindow window(sf::VideoMode(600, 600), "Sokoban");
    sf::Texture texture;
    if (!texture.loadFromFile("Mur.jpeg"))
      {
	// error...
      }
    //texture.setSmooth(true);
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
sprite.setTextureRect(sf::IntRect(10, 10, 32, 32));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
window.draw(sprite);
        window.display();
    }

    return 0;*/
    int ecrit;
  while(true){
    cin >> ecrit;
    switch (ecrit){
    case 6:{
     j.right();
     break;
    }
    case 4:{
      j.left();
      break;
    }
    case 8:{
      j.up();
      break;
    }
    case 2:{
      j.down();
      break;
    }
    }
    }
}
