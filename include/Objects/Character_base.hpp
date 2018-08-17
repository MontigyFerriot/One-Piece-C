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
* 
**********************************************************************************************************************************/

#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include "SFML/Graphics.hpp"
#include "Object_base.hpp"
#include "Resource_manager.hpp"

// enum which represent the direction of character 
enum class Direction
{ 
  Left,
  Right
};

class Character_base : public Object_base
{
  public:
    // Character_base is an abstract class, copying prevented 
    Character_base(const Character_base& another) = delete;
    void operator=(const Character_base& another) = delete;

    // These two function provides logic for first and second player.
    // Each one of them use different set of keys, so they need different logics
    virtual void logic_first(float dt, float current_time) = 0;
    virtual void logic_second(float dt, float current_time) = 0;
    
  protected:
    // Character_base is an abstract class, copying prevented. Constructor is innaccessible outside the class 
    Character_base(Resource_manager& resource_manager,std::string texture_name,Direction direction, int health);
  protected:
    Direction m_direction; // represent direction of the class 
    int m_health; // represent health of the class 
};


#endif // CHARACTER_BASE_H