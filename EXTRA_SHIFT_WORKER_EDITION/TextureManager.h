#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
class TextureManager
{
private:
	std::map<std::string, sf::Texture> m_textures;
	static TextureManager* m_instance;
public:
	TextureManager();
	static sf::Texture& GetTexture(std::string const& filename);

};
#endif
