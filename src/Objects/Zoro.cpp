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

#include "Objects/Zoro.hpp"

Zoro::Zoro(Resource_manager& resource_manager)
        :Character_base{resource_manager,"zoro.png",Direction::Left,100},
        m_zoro{resource_manager.get_texture("zoro.png")},
        m_standing_right{},
        m_standing_left{},
        m_walking_left{},
        m_walking_right{}
{
        m_sprite.setTexture(m_zoro);

        set_up(resource_manager);

        m_sprite.setTextureRect(m_standing_right.get_frames()[0].m_frame);
        m_sprite.setPosition(100.0f,130.0f);
        m_sprite.setScale(3.0f,3.0f);
}

void Zoro::logic_first(float dt, float current_time)
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
                walking_left(current_time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
                walking_right(current_time);
        }
        else
        {
                standing(current_time);
        }
}

void Zoro::logic_second(float dt, float current_time)
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
                walking_left(current_time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
                walking_right(current_time);
        }
        else
        {
                standing(current_time);
        }
}

void Zoro::standing(float current_time)
{
        if(m_direction != Direction::Right)
        {
                m_standing_left.animate(m_sprite, current_time);
        }
        else
        {
                m_standing_right.animate(m_sprite, current_time);
        }
}

void Zoro::walking_right(float current_time)
{
        if(m_direction != Direction::Right)
        {
                m_direction = Direction::Right;
        }
        m_sprite.move(sf::Vector2f{1.0f,0.0f});
        m_walking_right.animate(m_sprite, current_time);
}

void Zoro::walking_left(float current_time)
{
        if(m_direction != Direction::Left)
        {
                m_direction = Direction::Left;
        }
        m_sprite.move(sf::Vector2f{-1.0f,0.0f});
        m_walking_left.animate(m_sprite, current_time);
}

void Zoro::unique_set_up(Resource_manager& resource_manager)
{

}

void Zoro::set_up_animations()
{ 
        m_standing_right.add_frame(sf::IntRect{10,20,39,66},0.3f);
        m_standing_right.add_frame(sf::IntRect{59,21,39,65},0.3f);
        m_standing_right.add_frame(sf::IntRect{108,22,39,64},0.3f);
        m_standing_right.add_frame(sf::IntRect{157,21,39,65},0.3f);

        m_standing_left.add_frame(sf::IntRect{157,107,39,65},0.3f);
        m_standing_left.add_frame(sf::IntRect{108,108,39,64},0.3f);
        m_standing_left.add_frame(sf::IntRect{59,107,39,65},0.3f);
        m_standing_left.add_frame(sf::IntRect{10,106,39,66},0.3f); 
        
        m_walking_right.add_frame(sf::IntRect{246,30,48,56},0.1f);
        m_walking_right.add_frame(sf::IntRect{304,31,49,55},0.1f);
        m_walking_right.add_frame(sf::IntRect{363,31,51,55},0.1f);
        m_walking_right.add_frame(sf::IntRect{424,27,50,59},0.1f);
        m_walking_right.add_frame(sf::IntRect{484,29,50,57},0.1f);
        m_walking_right.add_frame(sf::IntRect{544,31,55,55},0.1f);
        m_walking_right.add_frame(sf::IntRect{609,32,56,54},0.1f);
        m_walking_right.add_frame(sf::IntRect{675,29,45,57},0.1f);
        
        m_walking_left.add_frame(sf::IntRect{675,116,45,57},0.1f);
        m_walking_left.add_frame(sf::IntRect{609,117,56,54},0.1f);
        m_walking_left.add_frame(sf::IntRect{544,117,55,55},0.1f);
        m_walking_left.add_frame(sf::IntRect{484,113,50,57},0.1f);
        m_walking_left.add_frame(sf::IntRect{424,115,50,59},0.1f);
        m_walking_left.add_frame(sf::IntRect{363,117,51,55},0.1f);
        m_walking_left.add_frame(sf::IntRect{304,118,49,55},0.1f);
        m_walking_left.add_frame(sf::IntRect{246,115,48,56},0.1f);
}