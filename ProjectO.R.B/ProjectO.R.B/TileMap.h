#ifndef TILEMAP
#define TILEMAP
#include <tmxlite\Map.hpp>
#include <SFML\Graphics.hpp>
#include "tmxlite\SFMLOrthogonalLayer.hpp"
/// <summary>
/// author Aaron Curry
/// time taken: 9:00 - 16:00

class TileMap
{
public:
	TileMap();
	~TileMap();
	void render(sf::RenderWindow& window);
	void update();


	std::vector<sf::Vector2f> m_object_position;
	std::vector<sf::Vector2f> m_object_WH;
private:
	std::vector<MapLayer *>map1;
	
	tmx::Map map;
	sf::RenderWindow window;

};
#endif // !Tilemap