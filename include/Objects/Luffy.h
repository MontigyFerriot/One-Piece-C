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

#ifndef LUFFY_H 
#define LUFFY_H

#include <SFML/Graphics.hpp>
#include "../Animations/Animation.h"
#include "../Resource_manager.h"
#include "Character_base.h"

/*
  We need to:
  -draw luffy to the screen ( we use draw() method)
  -DON'T need to input to luffy 
  -logic ( this is logic() method which can be used directly by Luffy or Character* ) 
*/

class Luffy : public Character_base
{
  public:
    explicit Luffy(Resource_manager& resource_manager);

    void standing(float current_time);
    void shake_hands(float current_time);
    void walking_right(float current_time);
    void walking_left(float current_time);

    // Defining virtual void logic() from Object_base
    void logic_first(float dt, float current_time);
    
    // Defining virtual void logic() from Object_base
    void logic_second(float dt, float current_time);
  private:
    // Defining virtual void set_up_animations() from Object_base
    void set_up_animations();
    
    // Defining virtual void unique_set_up() from Object_base
    void unique_set_up(Resource_manager& resource_manager); 
     
  private:
    sf::Texture m_luffy_left;
    sf::Texture m_luffy_right;

    Animation m_standing;
    Animation m_shaking_hands;
    Animation m_walking_left;
    Animation m_walking_right;
    //Animation m_basic_attack_left;
    //Animation m_basic_attack_right;
};

#endif //LUFFY_H
