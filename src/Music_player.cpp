/**********************************************************************************************************************************
* Copyright (c) 2017-2018 El F. Percy
* Standard Header. 
*
* This project is One Piece: Gigant Battle! 2 New World almost copy. 
* I do not take any advantages of this project and resources taken from OP: GB! 2 are for learning purposes. 
* Under this message I list all people, companies or organization which materials I've used in this project:
* - Hopson97: Structure of this game is based on his structures of games. Link:
* - Bandai Namco Entertainment and Shūeisha published One Piece: Gigant Battle! 2 New World. 
*   I used many features of their product (including texture, sound etc.) 
*
* MIT License
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
**********************************************************************************************************************************/

#include "Music_player.hpp"

Music_player::Music_player(Resource_manager& resource_manager)
  	:m_resource_manager{resource_manager},
   	m_current_music{0U},
   	m_last_activity_time{0.0f}
{

}

void Music_player::play() noexcept
{
  	m_resource_manager.m_musics[m_current_music].second->play();
}

void Music_player::restart(float t) noexcept
{
  	if(t - m_last_activity_time < delay)
    	return;
  	m_last_activity_time = t;
  	m_resource_manager.m_musics[m_current_music].second->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
}

void Music_player::stop() noexcept
{
  	m_resource_manager.m_musics[m_current_music].second->stop();
}

void Music_player::next(float t) noexcept
{
  	if(t - m_last_activity_time < delay or 
      m_current_music == (m_resource_manager.m_musics.size() - 1))
      	return;

  	m_last_activity_time = t;
  	m_resource_manager.m_musics[m_current_music].second->stop();
  	m_resource_manager.m_musics[m_current_music].second->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
  	++m_current_music;
  	m_resource_manager.m_musics[m_current_music].second->play();
}

void Music_player::previous(float t) noexcept
{
  	if(t - m_last_activity_time < delay or m_current_music == 0U)
      	return;

  	m_last_activity_time = t;
  	m_resource_manager.m_musics[m_current_music].second->stop();
  	m_resource_manager.m_musics[m_current_music].second->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
  	--m_current_music;
  	m_resource_manager.m_musics[m_current_music].second->play();
}

void Music_player::shuffle_play(float t) noexcept
{
  	if(t - m_last_activity_time < delay)
    	return;
  	m_last_activity_time = t;

	std::size_t i; 
    while((i = util::randomize(0,m_resource_manager.m_musics.size() - 1)) == m_current_music);

  	m_resource_manager.m_musics[m_current_music].second->stop();
  	m_resource_manager.m_musics[m_current_music].second->setPlayingOffset(sf::Time{sf::seconds(0.0f)});
  	m_current_music = i;
	m_resource_manager.m_musics[m_current_music].second->play();
}

Music_player::~Music_player()
{
	m_resource_manager.m_musics[m_current_music].second->stop();
}