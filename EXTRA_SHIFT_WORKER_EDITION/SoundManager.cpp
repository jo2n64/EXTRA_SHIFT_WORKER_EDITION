#include "SoundManager.h"
#include <assert.h>


SoundManager::SoundManager()
{
	m_testSoundBuffer.loadFromFile("../assets/sounds/sleyar.wav");
	m_testSound.setBuffer(m_testSoundBuffer);

	m_isMuted = false;
}

void SoundManager::playTestSound()
{
	m_testSound.play();

}

void SoundManager::pollEvent(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::M)
		{
			m_isMuted = !m_isMuted;
			float volume = m_isMuted ? 0.f : 100.f;
			m_testSound.setVolume(volume);
		}
	}
}


