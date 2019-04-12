#pragma once

#include "Animation_base.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

class Fade_animation : public Animation_base
{
        public:
        // Animation() - default constructor. Calls default base class constuctor Animation_Effect{}
        // and initialize m_is_animated_now to false.
        Fade_animation() = default; 
        
        Fade_animation(float time_break, sf::Uint8 begin, sf::Uint8 end, sf::Uint8 step);

        void do_animation(sf::Sprite& sprite);

        float time_of_animation() const
        {
                return abs(m_end - m_begin) * m_time_break / m_step;
        }

        float time_break()
        {
                return m_time_break;
        }

        private:
        float m_time_break;
        // sf::Uint8 m_begin;
        // sf::Uint8 m_end;
        // sf::Uint8 m_step;
        int m_begin;
        int m_end;
        int m_step;
        int m_sign;
        sf::Color m_p;
};
