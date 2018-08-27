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

#include "Animations/Standard_function_animation.hpp"

Standard_function_animation::Standard_function_animation(int origin_x_coord,int origin_y_coord,int max_x_coord,int max_y_coord,
        int width, int height,float time_to_next_frame,const Func& move_function)
        :m_current_x_coord{origin_x_coord},
        m_current_y_coord{origin_y_coord},
        m_origin_x_coord{origin_x_coord},
        m_origin_y_coord{origin_y_coord},
        m_max_x_coord{max_x_coord},
        m_max_y_coord{max_y_coord},
        m_width{width},
        m_height{height},
        m_is_end{false},
        m_time_to_next_frame{time_to_next_frame},
        m_old_time{0.0f},
        m_move_function{move_function},
        m_rectangle_function { [](int& x,int& y) {} }
{

}
    
Standard_function_animation::Standard_function_animation(const sf::Vector2i& origin_coordinates,const sf::Vector2i& max_coordinates,
        const sf::Vector2i rectangle,float time_to_next_frame,const Func& move_function)
        :m_current_x_coord{origin_coordinates.x},
        m_current_y_coord{origin_coordinates.y},
        m_origin_x_coord{origin_coordinates.x},
        m_origin_y_coord{origin_coordinates.y},
        m_max_x_coord{max_coordinates.x},
        m_max_y_coord{max_coordinates.y},
        m_width{rectangle.x},
        m_height{rectangle.y},
        m_is_end{false},
        m_time_to_next_frame{time_to_next_frame},
        m_old_time{0.0f},
        m_move_function{move_function},
        m_rectangle_function { [](int& x,int& y) {} }
{

}
Standard_function_animation::Standard_function_animation(int origin_x_coord,int origin_y_coord,int max_x_coord,int max_y_coord,
        int width, int height,float time_to_next_frame,const Func& move_function,const Func& rect_function)
        :m_current_x_coord{origin_x_coord},
        m_current_y_coord{origin_y_coord},
        m_origin_x_coord{origin_x_coord},
        m_origin_y_coord{origin_y_coord},
        m_max_x_coord{max_x_coord},
        m_max_y_coord{max_y_coord},
        m_width{width},
        m_height{height},
        m_is_end{false},
        m_time_to_next_frame{time_to_next_frame},
        m_old_time{0.0f},
        m_move_function{move_function},
        m_rectangle_function {rect_function}
{

}
    
Standard_function_animation::Standard_function_animation(const sf::Vector2i& origin_coordinates,const sf::Vector2i& max_coordinates,
        const sf::Vector2i rectangle,float time_to_next_frame,const Func& move_function,const Func& rect_function)
        :m_current_x_coord{origin_coordinates.x},
        m_current_y_coord{origin_coordinates.y},
        m_origin_x_coord{origin_coordinates.x},
        m_origin_y_coord{origin_coordinates.y},
        m_max_x_coord{max_coordinates.x},
        m_max_y_coord{max_coordinates.y},
        m_width{rectangle.x},
        m_height{rectangle.y},
        m_is_end{false},
        m_time_to_next_frame{time_to_next_frame},
        m_old_time{0.0f},
        m_move_function{move_function},
        m_rectangle_function {rect_function}
{

}

sf::IntRect Standard_function_animation::operator()(float current_time)
{
        if(m_is_end){}
        else if(current_time >= m_old_time + m_time_to_next_frame) // if enough time has passed
        {
                if(m_width <= 0 || m_height <= 0) throw std::runtime_error{"Animation rectangle: width or height is less than zero. Check rectangle functions"};
                if((m_current_x_coord >= m_max_x_coord) || (m_current_y_coord >= m_max_y_coord)) // if animation is on its last frame
                {
                        m_is_end = true;
                        m_current_x_coord = m_origin_x_coord; // it starts from beginning another time
                        m_current_y_coord = m_origin_y_coord; // it starts from beginning another time
                }
                else
                {
                        m_move_function(m_current_x_coord, m_current_y_coord); // if not it proceed futher
                        m_rectangle_function(m_width, m_height); // if not it proceed futher
                }
                m_old_time = current_time;
        }
        return sf::IntRect{m_current_x_coord, m_current_y_coord, m_width, m_height};
}