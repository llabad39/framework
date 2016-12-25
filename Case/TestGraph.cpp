#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow w(sf::VideoMode(800,600),"my window");
    sf::Sprite sprite;
    sf::Texture texture;
    if(!texture.create(30,30)){
    }
  if (!texture.loadFromFile("109.png"))
{
  return EXIT_FAILURE;
}
  sprite.setTexture(texture);
  sprite.setPosition(sf::Vector2f(10, 50));
  sprite.setColor(sf::Color(255,255,255));

  w.draw(sprite);
  
  while(w.isOpen()){
    sf::Event event;
    while(w.pollEvent(event)){
      if(event.type == sf::Event::Closed){
	
	w.close();
      }
      for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
	  sf::Sprite sprite;
	  sf::Texture texture;
	  if(!texture.create(30,30)){
	  }
	  if (!texture.loadFromFile("109.png"))
	{
	  return EXIT_FAILURE;
	}
	  sprite.setTexture(texture);
	  sprite.setPosition(sf::Vector2f(i*64, j*64));
	  sprite.setColor(sf::Color(255,255,255));
      
	  w.draw(sprite);
	  w.display();
	}
      }
    }
  }
}
