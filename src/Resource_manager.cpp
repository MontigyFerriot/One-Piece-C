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
*
*
*   WARN: get_texture(), get_sound(), get_font() return reference
*   and they cannot be const member functions like most of the "getters"
*   (The value of reference may be changed)
*
*   WARN: std::map has operator[](Key&& key) overload.
*   You can insert types with resources with it.
***********************************************************************/

#include "Resource_manager.hpp"

Resource_manager::Resource_manager()
{
        // loading all resources:
        load_textures();
        //load_sounds(); 
        //load_fonts();
        load_musics();
}

// adds all required textures to the program
void Resource_manager::load_textures()
{
        std::size_t n = 0;
        import_texture("ace_background.png", n++);
        import_texture("background.png", n++);
        import_texture("ice_texture.png", n++);
        import_texture("katakuri_background.png", n++);
        import_texture("luffy_gear_second.png", n++);
        import_texture("luffy_left.png", n++);
        import_texture("luffy_right.png", n++);
        import_texture("marineford_bay.png", n++);
        import_texture("one_piece_logo.png", n++);
        import_texture("strawhats1.png", n++);
        import_texture("zoro.png", n++);
}

// adds all required sounds to the program
void Resource_manager::load_sounds()
{
}

// adds all required fonts to the program
void Resource_manager::load_fonts()
{
}

// adds all required musics to the program
void Resource_manager::load_musics()
{
        std::size_t n = 0;
        import_music("music_overtaken.ogg", n++);
        import_music("music_the_very_strongest.ogg", n++);
        import_music("music_we_are.ogg", n++);
}

sf::Texture& Resource_manager::get_texture(const std::string& texture_name)
{
        return binary_search(m_textures, texture_name);
}

sf::SoundBuffer& Resource_manager::get_sound(const std::string& sound_name)
{
        return binary_search(m_sounds, sound_name);
}

sf::Font& Resource_manager::get_font(const std::string& font_name)
{
        return binary_search(m_fonts, font_name);
}

void Resource_manager::import_texture(const std::string& texture_name, std::size_t n)
{
        sf::Texture texture; 
        if(!texture.loadFromFile(("../img/" + texture_name)))
        { 
                throw std::runtime_error("Cannot load texture: " + texture_name); 
        }
        else
                m_textures[n] = std::make_pair(texture_name, texture);
}

void Resource_manager::import_sound(const std::string& sound_name, std::size_t n)
{
        //Something is wrong here
        sf::SoundBuffer sound; 
        if(!sound.loadFromFile(("../sfx/" + sound_name)))
        { 
                throw std::runtime_error("Cannot load sound: " + sound_name); 
        }
        else
                m_sounds[n] = std::make_pair(sound_name, sound);
}

void Resource_manager::import_font(const std::string& font_name, std::size_t n)
{
        sf::Font font; 
        if(!font.loadFromFile(("../fonts/" + font_name)))
        { 
                throw std::runtime_error("Cannot load font: " + font_name); 
        }
        else
                m_fonts[n] = std::make_pair(font_name, font);
}

void Resource_manager::import_music(const std::string& music_name, std::size_t n)
{
        music_ptr music = std::make_shared<sf::Music>(); 
        if(!music->openFromFile(("../sfx/" + music_name)))
        { 
                throw std::runtime_error("Cannot load music: " + music_name); 
        }
        else
                m_musics[n] = std::make_pair(music_name, music);
}