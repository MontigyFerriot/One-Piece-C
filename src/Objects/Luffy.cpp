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

#include "Objects/Luffy.hpp"

Luffy::Luffy(Resource_manager& resource_manager)
    :Character_base{resource_manager,"luffy_right.png",Direction::Right,100},
     m_luffy_left{resource_manager.get_texture("luffy_left.png")},
     m_luffy_right{resource_manager.get_texture("luffy_right.png")},
     m_standing{},
     m_shaking_hands{},
     m_walking_left{},
     m_walking_right{}
{
    
    m_sprite.setTexture(m_luffy_right);

    set_up(resource_manager);

    m_sprite.setTextureRect(m_shaking_hands.get_frames()[0].m_frame);
    m_sprite.setPosition(50.0f,130.0f);

    m_sprite.setScale(3.0f,3.0f);
}

void Luffy::logic_first(float dt, float current_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        walking_left(current_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        walking_right(current_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        shake_hands(current_time);
    }
    else
    {
        standing(current_time);
    } 
}

void Luffy::logic_second(float dt, float current_time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        walking_left(current_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        walking_right(current_time);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shake_hands(current_time);
    }
    else
    {
        standing(current_time);
    }
}

void Luffy::standing(float current_time)
{
    if(m_direction != Direction::Right)
    {
        m_direction = Direction::Right;
        m_sprite.setTexture(m_luffy_right);
    }
    m_standing.animate(m_sprite,current_time);
}

void Luffy::shake_hands(float current_time)
{
    if(m_direction != Direction::Right)
    {
        m_direction = Direction::Right;
        m_sprite.setTexture(m_luffy_right);
    }
    m_shaking_hands.animate(m_sprite,current_time);
}

void Luffy::walking_right(float current_time)
{
    if(m_direction != Direction::Right)
    {
        m_direction = Direction::Right;
        m_sprite.setTexture(m_luffy_right);
    }
    m_sprite.move(sf::Vector2f{1.0f,0.0f});
    m_walking_right.animate(m_sprite, current_time);
}

void Luffy::walking_left(float current_time)
{
    if(m_direction != Direction::Left)
    {
        m_direction = Direction::Left;
        m_sprite.setTexture(m_luffy_left);
    }
    m_sprite.move(sf::Vector2f{-1.0f,0.0f});
    m_walking_left.animate(m_sprite, current_time);
}

void Luffy::unique_set_up(Resource_manager& resource_manager)
{

}

void Luffy::set_up_animations()
{ 
    m_standing.add_frame(sf::IntRect{2,10,42,65},0.5f);
    m_standing.add_frame(sf::IntRect{45,9,42,66},0.5f);
    m_standing.add_frame(sf::IntRect{88,8,42,67},0.5f);
    
    m_shaking_hands.add_frame(sf::IntRect{143,7,34,68},0.1f);
    m_shaking_hands.add_frame(sf::IntRect{182,5,34,70},0.1f);
    m_shaking_hands.add_frame(sf::IntRect{223,7,34,68},0.1f);
    m_shaking_hands.add_frame(sf::IntRect{261,7,34,68},0.3f);
    m_shaking_hands.add_frame(sf::IntRect{295,8,34,67},0.5f);
    m_shaking_hands.add_frame(sf::IntRect{329,5,34,70},0.1f);
    
    m_walking_right.add_frame(sf::IntRect{392,18,49,57},0.1f);
    m_walking_right.add_frame(sf::IntRect{441,16,49,59},0.1f);
    m_walking_right.add_frame(sf::IntRect{490,21,57,54},0.1f);
    m_walking_right.add_frame(sf::IntRect{547,17,46,58},0.1f);
    m_walking_right.add_frame(sf::IntRect{597,18,50,57},0.1f);
    m_walking_right.add_frame(sf::IntRect{647,16,51,59},0.1f);
    m_walking_right.add_frame(sf::IntRect{698,21,58,54},0.1f);
    m_walking_right.add_frame(sf::IntRect{756,16,48,59},0.1f);
    
    m_walking_left.add_frame(sf::IntRect{441,18,49,57},0.1f); 
    m_walking_left.add_frame(sf::IntRect{392,16,49,59},0.1f);
    m_walking_left.add_frame(sf::IntRect{335,21,57,54},0.1f);
    m_walking_left.add_frame(sf::IntRect{285,17,46,58},0.1f);
    m_walking_left.add_frame(sf::IntRect{235,18,50,57},0.1f);
    m_walking_left.add_frame(sf::IntRect{184,16,51,59},0.1f);
    m_walking_left.add_frame(sf::IntRect{126,21,58,54},0.1f);
    m_walking_left.add_frame(sf::IntRect{78,16,48,59},0.1f);
}