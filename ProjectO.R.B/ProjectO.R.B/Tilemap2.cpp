//#pragma comment(lib,"libtmxlite-s-d.lib") 

#include <iostream>
#include "Tilemap2.h"
TileMap2::TileMap2()
{
	tmx::Map map;

	if (map.load("./resources/Map3.tmx"))
	{
		std::cout << "Loaded Map version: " << map.getVersion().upper << ", " << map.getVersion().lower << std::endl;

		const auto& mapProperties = map.getProperties();
		std::cout << "Map has " << mapProperties.size() << " properties" << std::endl;
		map1.push_back(new MapLayer(map, 0));
		map1.push_back(new MapLayer(map, 1));
		map1.push_back(new MapLayer(map, 2));


		for (const auto& prop : mapProperties)
		{
			std::cout << "Found property: " << prop.getName() << std::endl;
			std::cout << "Type: " << int(prop.getType()) << std::endl;
		}

		std::cout << std::endl;

		const auto& layers = map.getLayers();
		std::cout << "Map has " << layers.size() << " layers" << std::endl;
		for (const auto& layer : layers)
		{
			std::cout << "Found Layer: " << layer->getName() << std::endl;
			std::cout << "Layer Type: " << int(layer->getType()) << std::endl;

			if (layer->getType() == tmx::Layer::Type::Object)
			{
				const auto& objects = dynamic_cast<tmx::ObjectGroup*>(layer.get())->getObjects();
				std::cout << "Found " << objects.size() << " objects in layer" << std::endl;
				for (const auto& object : objects)
				{
					std::cout << "Object " << object.getName() << std::endl;





					if (object.getName() == "Wall")
					{
						m_wall_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_wall_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}

					else if (object.getName() == "Goal")
					{
						m_goal_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_goal_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}
					else if (object.getName() == "Checkpoint")
					{
						m_checkpoint_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_checkpoint_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}
					else if (object.getName() == "Trap")
					{
						m_trap_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_trap_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}
					else if (object.getName() == "Ceiling")
					{
						m_ceiling_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_ceiling_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}

					else if (object.getName() == "Gem")
					{
						m_gem_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
					}
					else
					{
						m_object_position.push_back(sf::Vector2f(object.getPosition().x, object.getPosition().y));
						m_object_WH.push_back(sf::Vector2f(object.getAABB().width, object.getAABB().height));
					}
					const auto& properties = object.getProperties();
					std::cout << "Object has " << properties.size() << " properties" << std::endl;
					for (const auto& prop : properties)
					{
						std::cout << "Found property: " << prop.getName() << std::endl;
						std::cout << "Type: " << int(prop.getType()) << std::endl;
					}
				}
			}

			const auto& properties = layer->getProperties();
			std::cout << properties.size() << " Layer Properties:" << std::endl;
			for (const auto& prop : properties)
			{
				std::cout << "Found property: " << prop.getName() << std::endl;
				std::cout << "Type: " << int(prop.getType()) << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Failed loading map" << std::endl;
	}

	std::cout << std::endl << "Press return to quit..." << std::endl;
	//std::cin.get();

	//return 0;
}
//void TileMap::update()
//{
//	tmx::Map map;
//
//		const auto& layers = map.getLayers();
//		std::cout << "Map has " << layers.size() << " layers" << std::endl;
//		for (const auto& layer : layers)
//		{
//			std::cout << "Found Layer: " << layer->getName() << std::endl;
//			std::cout << "Layer Type: " << int(layer->getType()) << std::endl;
//
//			if (layer->getType() == tmx::Layer::Type::Object)
//			{
//				const auto& objects = dynamic_cast<tmx::ObjectGroup*>(layer.get())->getObjects();
//				std::cout << "Found " << objects.size() << " objects in layer" << std::endl;
//				for (const auto& object : objects)
//				{
//					std::cout << "Object " << object.getName() << std::endl;
//					const auto& properties = object.getProperties();
//					std::cout << "Object has " << properties.size() << " properties" << std::endl;
//					for (const auto& prop : properties)
//					{
//						std::cout << "Found property: " << prop.getName() << std::endl;
//						std::cout << "Type: " << int(prop.getType()) << std::endl;
//					}
//				}
//			}
//
//			const auto& properties = layer->getProperties();
//			std::cout << properties.size() << " Layer Properties:" << std::endl;
//			for (const auto& prop : properties)
//			{
//				std::cout << "Found property: " << prop.getName() << std::endl;
//				std::cout << "Type: " << int(prop.getType()) << std::endl;
//			}
//		}
//	}


TileMap2::~TileMap2()
{

}

void TileMap2::render(sf::RenderWindow &window)
{
	for (int i = 0; i<map1.size(); i++)
		window.draw(*map1.at(i));
}