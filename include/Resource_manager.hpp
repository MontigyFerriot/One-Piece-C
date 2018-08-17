/**********************************************************************************************************************************
* Copyright (c) 2017-2018 Maciej Falkowski  
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
* 
**********************************************************************************************************************************/

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <iostream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <algorithm>

using music_ptr = std::shared_ptr<sf::Music>;

class Resource_manager
{
  private:
    using Texture = std::pair<std::string, sf::Texture>;
    using Sound   = std::pair<std::string, sf::SoundBuffer>;
    using Font    = std::pair<std::string, sf::Font>;
    using Music   = std::pair<std::string, music_ptr>;
    
  public:
    Resource_manager();

    sf::Texture& get_texture(const std::string& texture_name);
    sf::SoundBuffer& get_sound(const std::string& sound_name);
    sf::Font& get_font(const std::string& font_name);

  private:
    // import resources to the manager. Requires resource's name without path.
    void import_texture(const std::string& texture_name, std::size_t n);
    void import_sound(const std::string& sound_name, std::size_t n);
    void import_font(const std::string& font_name, std::size_t n);
    void import_music(const std::string& music_name, std::size_t n);

    void load_textures();
    void load_sounds();
    void load_fonts();
    void load_musics();

    template<typename Array>
    typename Array::value_type::second_type& binary_search(Array& arr, const std::string& value)
    {
        std::size_t low = 0, high = arr.size(), middle;

        while(low < high)
        { 
            middle = low + (high - low) / 2;

            if(value < arr[middle].first)
                high = middle;
            else if(value > arr[middle].first)
                low = middle + 1;
            else
                return arr[middle].second;
        }

        throw std::runtime_error{"binary_search(): Cannot find " + value};
    }

    static constexpr std::size_t m_textures_size = 11; 
    static constexpr std::size_t m_sounds_size   = 1; 
    static constexpr std::size_t m_fonts_size    = 1; 
    static constexpr std::size_t m_music_size    = 3; 
  private:
    std::array<Texture, m_textures_size> m_textures;
    std::array<Sound, m_sounds_size>     m_sounds;
    std::array<Font, m_fonts_size>       m_fonts;
    std::array<Music, m_music_size>      m_musics;

    friend class Music_player;
};

#endif // RESOURCE_MANAGER_H