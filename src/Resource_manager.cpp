/**********************************************************************************************************************************
	std::string s =
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
***********************************************************************/

#include "Resource_manager.hpp"
#include "Utility.hpp"
#include "rapidjson/document.h"
#include <functional>

namespace rj = rapidjson;

Resource_manager::Resource_manager()
{
        std::string json;
        json.reserve(1500U);
        util::parse_json_file(json, "../resources.json");

        rj::Document doc;
        doc.Parse(json.c_str());        

        std::size_t n;
        rj::SizeType i; 
        const rj::Value* arr;

        const char* resources[] = {"textures", "fonts", "sounds", "music"};

        for (int x = 0; x < sizeof(resources) / sizeof(resources[0]); ++x) 
        {
                arr = &doc[resources[x]];
                assert(arr->IsArray());
                for (i = 0, n = 0; i < arr->Size(); ++i, ++n) 
                        switch (x) {
                        case 0:
                                import_texture((*arr)[i].GetString(), n);
                        break;
                        case 1:
                                import_font((*arr)[i].GetString(), n); 
                        break;
                        case 2:
                                import_sound((*arr)[i].GetString(), n); 
                        break;
                        case 3:
                                import_music((*arr)[i].GetString(), n);
                        break;
                        default:
                                throw std::runtime_error{"lols"};
                        }
        }
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
                throw std::runtime_error("Cannot load texture: " + texture_name); 
        else
                m_textures[n] = std::make_pair(texture_name, texture);
}

void Resource_manager::import_sound(const std::string& sound_name, std::size_t n)
{
        //Something is wrong here
        sf::SoundBuffer sound; 
        if(!sound.loadFromFile(("../sfx/" + sound_name)))
                throw std::runtime_error("Cannot load sound: " + sound_name); 
        else
                m_sounds[n] = std::make_pair(sound_name, sound);
}

void Resource_manager::import_font(const std::string& font_name, std::size_t n)
{
        sf::Font font; 
        if(!font.loadFromFile(("../fonts/" + font_name)))
                throw std::runtime_error("Cannot load font: " + font_name); 
        else
                m_fonts[n] = std::make_pair(font_name, font);
}

void Resource_manager::import_music(const std::string& music_name, std::size_t n)
{
        music_ptr music = std::make_shared<sf::Music>(); 
        if(!music->openFromFile(("../sfx/" + music_name)))
                throw std::runtime_error("Cannot load music: " + music_name); 
        else
                m_music[n] = std::make_pair(music_name, music);
}
