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

#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"
#include "Animation_effect.hpp"
#include <iostream>
#include <algorithm>

class Animation : public Animation_effect
{
    public:
        // Animation() - default constructor. Calls default base class constuctor Animation_Effect{}
        // and initialize m_is_animated_now to false.
        Animation();

        // void animate(sf::Sprite& sprite,float current_time); is main logic member function. It animates sprite
        // by setting frames continuously in time with a small gap of time beetween each frame.
        // It also checks if Animation is currently used (is being animated), if not it sets m_is_animated_now to false.
        void animate(sf::Sprite& sprite,float current_time);

    public:
        // float longest_frame_gap(); - it returns biggest time gap beetween frames.
        // return: float of unsigned value
        float longest_frame_gap();

    private:
        // indicates if Animation is currently used. By default it is initialied to false
        bool m_is_animated_now;
};


#endif // ANIMATION_H