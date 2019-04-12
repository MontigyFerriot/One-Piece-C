#include "Animations/Fade_animation.hpp"

#include <iostream>

Fade_animation::Fade_animation(float time_break, sf::Uint8 begin, sf::Uint8 end, sf::Uint8 step)
        :m_time_break{time_break},
         m_begin{begin},
         m_end{end},
         m_step{step},
         m_sign{end - begin > 0 ? 1 : -1}
{

}

void Fade_animation::do_animation(sf::Sprite& sprite)
{
        m_p = sprite.getColor();
        
        // condition is completely fucked up
        //if current color is greater then step and we can increment
        // if (m_sign > 0 ? m_p.a + m_step <= m_end : m_p.a >= m_step and m_p.a - m_step >= m_end)
        if ((!m_sign ? m_p.a >= m_step : true) and
                m_sign > 0 ? m_p.a + (m_sign * m_step) <= m_end : m_p.a + (m_sign * m_step) >= m_end)
                m_p.a += m_sign * m_step;
        else 
                return;

        sprite.setColor(m_p);
}
