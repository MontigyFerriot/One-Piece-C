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

#ifndef ZORO_H 
#define ZORO_H

#include <SFML/Graphics.hpp>
#include "Animations/Animation_launcher.hpp"
#include "Animations/Frame_animation.hpp"
#include "Resource_manager.hpp"
#include "Character_base.hpp"

class Zoro : public Character_base
{
    public:
        explicit Zoro(Resource_manager& resource_manager);

        void standing(float current_time);
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
        sf::Texture m_zoro;

        Animation_launcher<Frame_animation> m_standing_right;
        Animation_launcher<Frame_animation> m_standing_left;
        Animation_launcher<Frame_animation> m_walking_left;
        Animation_launcher<Frame_animation> m_walking_right;
        //Animation m_basic_attack_left;
        //Animation m_basic_attack_right;
};

#endif //ZORO_H
