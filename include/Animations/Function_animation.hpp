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

#ifndef STANDARD_FUNCTION_ANIMATION_H
#define STANDARD_FUNCTION_ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>
#include "Animation_base.hpp"

using Func = std::function<void(int&,int&)>;

class Function_animation : public Animation_base
{ 
    public:
        Function_animation(int origin_x_coord,int origin_y_coord,int max_x_coord,int max_y_coord,
            int width, int height, float time_to_next_frame, const Func& move_function);
        
        Function_animation(const sf::Vector2i& origin_coordinates,const sf::Vector2i& max_coordinates,
            const sf::Vector2i rectangle,float time_to_next_frame,const Func& move_function);

        Function_animation(int origin_x_coord,int origin_y_coord,int max_x_coord,int max_y_coord,
            int width, int height,float time_to_next_frame,const Func& move_function,const Func& rect_function);
        
        Function_animation(const sf::Vector2i& origin_coordinates,const sf::Vector2i& max_coordinates,
            const sf::Vector2i rectangle,float time_to_next_frame,const Func& move_function,const Func& rect_function);

        float time_of_animation() const;
        float time_break();

        void do_animation(sf::Sprite& sprite);

        bool is_end()
        {
                return m_is_end;
        }

        void restart();

    private:
        int m_current_x_coord;
        int m_current_y_coord;
        
        int m_origin_x_coord;
        int m_origin_y_coord;
        
        const int m_max_x_coord;
        const int m_max_y_coord;

        float m_time_to_next_frame;

        bool m_is_end;
        
        int m_width;
        int m_height;
        
        Func m_move_function;
        Func m_rectangle_function;
};

#endif // STANDARD_FUNCTION_ANIMATION_H
