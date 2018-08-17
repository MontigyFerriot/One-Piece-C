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
**********************************************************************************************************************************/

#ifndef FUNCTION_ANIMATION_H
#define FUNCTION_ANIMATION_H

#include <SFML/Graphics.hpp>
#include "Standard_function_animation.hpp"

template<typename Fct = Standard_function_animation> 
class Function_animation
{
  public:   
    // Function_animation() - constructor
    // and initialize m_is_animated_now to false. 
    explicit Function_animation(const Fct& function)
        :m_function{function},
         m_infinite_animation{false},
         m_is_animated_now{false}
    {
    }

    // void animate(sf::Sprite& sprite,float current_time); is main logic member function. It animates sprite
    // by setting frames continuously in time with a small gap of time beetween each frame.
    // It also checks if Animation is currently used (is being animated), if not it sets m_is_animated_now to false. 
    void animate(sf::Sprite& sprite,float current_time)
    {
            if(!m_infinite_animation) {}
            else if(m_function.get_time_to_next_frame() > (current_time - m_function.get_old_time() ) + 0.5f)
            { 
                m_is_animated_now = false;
            }
            if(!m_is_animated_now)
            {
                m_function.set_old_time(current_time);
                m_is_animated_now = true;
            }
        sprite.setTextureRect(m_function(current_time));
    }

    bool is_end() const { return m_function.is_end(); }
    void restart() { m_function.restart(); }
    void set_infinite_animation(bool b) { m_infinite_animation = b; }
  private:
    // main functor which does animation for us.
    Fct m_function;
    // indicates if Animation is currently used. By default it is initialied to false
    bool m_infinite_animation;
    bool m_is_animated_now;
};

#endif // FUNCTION_ANIMATION_H