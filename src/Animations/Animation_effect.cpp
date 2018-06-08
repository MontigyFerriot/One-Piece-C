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

#include "../../include/Animations/Animation_effect.h"

//default constructor. Initializes m_current_frame and m_old_time both to 0
Animation_effect::Animation_effect()
    :m_current_frame{0},
     m_old_time{0}
{
}


// creates an object of Frame type and pushes it back to vector m_frames 
void Animation_effect::add_frame(const sf::IntRect& rect, float t)
{
    //create and intialize object
    Frame frame;
    frame.m_frame = rect;
    frame.m_time_to_next_frame = t;

    //push it back to vector
    m_frames.emplace_back(frame);
}

// switch_to next_frame() is main logic member of this class.
// It changes frame to the next one and if it hits end of the vector, it wraps to the beginning 
void Animation_effect::switch_to_next_frame(float current_time)
{    
    if(current_time >= m_old_time + m_frames[m_current_frame].m_time_to_next_frame) // if enough time has passed
    {
        if(m_current_frame == m_frames.size() - 1) // if animation is on its last frame 
        {
            m_current_frame = 0; // it starts from beginning another time
        }
        else
        {
            ++m_current_frame; // if not it proceed futher 
        }
        m_old_time = current_time; 
    }
}

int Animation_effect::get_current_frame() const
{ 
    return m_current_frame; 
}
