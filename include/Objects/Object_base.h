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

#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "Resource_manager.h"
#include "SFML/Graphics.hpp"

// An Object_base is an abstract base class. 
// It provides an interface to draw an object
// Every drawable object needs to inherit after it. 
class Object_base 
{
  public:
    // Character_base is an abstract class, copying prevented 
    Object_base(const Object_base& another) = delete;
    void operator=(const Object_base& another) = delete;
    
    // draws an object to window 
    void draw(sf::RenderWindow& window);

    // set object position to the center 
    void center_origin();

    // returns reference to sprite
    sf::Sprite& get_sprite();

  protected:
    // Character_base is an abstract class, copying prevented. Constructor is innaccessible outside the class 
    Object_base(Resource_manager& resource_manager, std::string texture_name);

    // set up is main function. It calls set_up_animations() and unique_set_up()
    void set_up(Resource_manager& resource_manager);

    // set all of the animations in derived class  
    virtual void set_up_animations() = 0;

    // other set up's in derived class
    virtual void unique_set_up(Resource_manager& resource_manager) = 0;

  protected:
    sf::Sprite m_sprite;
};

#endif // OBJECT_BASE_H