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
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

using music_ptr = std::shared_ptr<sf::Music>;

class Resource_manager
{
  public:
    Resource_manager();

    // "geters" which return reference to resource:
    sf::Texture& get_texture(const std::string& texture_name);
    sf::SoundBuffer& get_sound(const std::string& sound_name);
    sf::Font& get_font(const std::string& font_name);
    music_ptr& get_music(const std::string& music_name);

  private:
    // import_texture() allows to add textures in a simple way 
    // just by adding its name without path to it for instance: file.png
    // throws std::runtime_error if texture doesn't load.
    void import_texture(const std::string& texture_name);
    
    // import_sound() allows to add sounds in a simple way 
    // just by adding its name without path to it for instance: file.png
    // throws std::runtime_error if sound doesn't load.
    void import_sound(const std::string& sound_name);
   
    // import_font() allows to add fonts in a simple way 
    // just by adding its name without path to it for instance: file.png
    // throws std::runtime_error if font doesn't load.
    void import_font(const std::string& font_name);
    
    // import_music() allows to add music in a simple way 
    // just by adding its name without path to it for instance: import_music("file.png");
    // throws std::runtime_error if music doesn't load.
    void import_music(const std::string& music_name);

    // adds all required textures to the program
    void load_textures();
    
    // adds all required sounds to the program
    void load_sounds();

    // adds all required fonts to the program
    void load_fonts();
    
    // adds all required musics to the program
    void load_musics();

  private:
    std::map<std::string, sf::Texture> m_textures; // holds textures

    std::map<std::string, sf::SoundBuffer> m_sounds; // holds sounds

    std::map<std::string, sf::Font> m_fonts; // holds fonts
    
    std::map<std::string, music_ptr> m_musics; // holds musics

    friend class Music_player;
};


#endif // RESOURCE_MANAGER_H