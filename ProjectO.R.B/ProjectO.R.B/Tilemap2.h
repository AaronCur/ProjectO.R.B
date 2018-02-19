#pragma once
#ifndef TILEMAP2
#define TILEMAP2
#include <tmxlite\Map.hpp>
#include <SFML\Graphics.hpp>
#include "tmxlite\SFMLOrthogonalLayer.hpp"
#include <iostream>
/// <summary>
/// author Aaron Curry
/// time taken: 9:00 - 16:00

class TileMap2
{
public:
	TileMap2();
	~TileMap2();
	void render(sf::RenderWindow& window);
	void update();


	std::vector<sf::Vector2f> m_object_position;
	std::vector<sf::Vector2f> m_object_WH;
	std::vector<sf::Vector2f> m_wall_position;
	std::vector<sf::Vector2f> m_wall_WH;
	std::vector<sf::Vector2f> m_goal_WH;
	std::vector<sf::Vector2f> m_goal_position;
	std::vector<sf::Vector2f> m_checkpoint_position;
	std::vector<sf::Vector2f> m_checkpoint_WH;
	std::vector<sf::Vector2f> m_trap_position;
	std::vector<sf::Vector2f> m_ceiling_position;
	std::vector<sf::Vector2f> m_ceiling_WH;
	std::vector<sf::Vector2f> m_trap_WH;
	std::vector<sf::Vector2f> m_gem_position;
	bool parse = true;
private:
	std::vector<MapLayer *>map1;

	tmx::Map map;
	sf::RenderWindow window;

};
#endif // !Tilemap