#pragma once
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H
#include <SFML/Audio.hpp>
#include <map>
#include <SFML/Window/Event.hpp>

class SoundManager
{
private:
	sf::SoundBuffer m_testSoundBuffer;
	sf::Sound m_testSound;

	bool m_isMuted;

public:
	SoundManager();
	void playTestSound();

	void pollEvent(sf::Event event);
};
#endif
