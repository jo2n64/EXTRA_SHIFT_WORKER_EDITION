#include "TextureManager.h"
#include <assert.h>

TextureManager* TextureManager::m_instance = nullptr;

TextureManager::TextureManager()
{
	assert(m_instance == nullptr);
	m_instance = this;
}

sf::Texture& TextureManager::GetTexture(std::string const& filename)
{
	auto& m = m_instance->m_textures;

	auto kvp = m.find(filename);

	if (kvp != m.end()) {
		return kvp->second;
	}
	else {
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}
