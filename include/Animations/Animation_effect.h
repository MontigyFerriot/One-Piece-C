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

#ifndef ANIMATION_EFFECT_H
#define ANIMATION_EFFECT_H

#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>
#include <array>

// Frame is pure data structure. 
struct Frame
{
    sf::IntRect m_frame;
    float m_time_to_next_frame;
};

class Animation_effect
{
  public:
    // creates an object of Frame type and pushes it back to vector m_frames 
    void add_frame(const sf::IntRect& rect, float t);

    template<typename... Ts>
    void add_frames(Ts&&... ts)
    {
      add_frame(std::forward<Ts>(ts)...);
    }

    // switch_to next_frame() is main logic member of this class.
    // It changes frame to the next one and if it hits end of the vector, it wraps to the beginning 
    void switch_to_next_frame(float current_time);

    // returns current frame 
    int get_current_frame() const;
    
    std::vector<Frame>& get_frames() { return m_frames; }
  protected:
    //default constructor. Initializes m_current_frame and m_old_time both to 0
    Animation_effect();

    // holds all frames 
    std::vector<Frame> m_frames;

    // number of current frame
    unsigned int m_current_frame;

    // time from last animation 
    float m_old_time;
};
#endif // ANIMATION_EFFECT_H