#pragma once 

#include <SFML/Graphics.hpp>

template<typename Animation>
class Animation_launcher
{
    public:
        Animation_launcher()
                :m_animation{},
                 m_old_time{0.0f},
                 m_infinite_animation{false}
        {
        }

        // Animation() - default constructor. Calls default base class constuctor Animation_Effect{}
        // and initialize m_is_animated_now to false.
        Animation_launcher(const Animation& animation, bool is_infinite_animation = false)
                :m_animation{animation},
                 m_old_time{0.0f},
                 m_infinite_animation{is_infinite_animation}
        {
        }

        // void animate(sf::Sprite& sprite,float current_time); is main logic member function. It animates sprite
        // by setting frames continuously in time with a small gap of time beetween each frame.
        // It also checks if Animation is currently used (is being animated), if not it sets m_is_animated_now to false.
        template<typename... Args>
        void animate(float current_time, sf::Sprite& sprite, Args&&... args)
        {
                // if enough time has passed
                if(current_time >= m_old_time + m_animation.time_break())
                {
                        m_animation.do_animation(sprite, std::forward(args)...);
                        m_old_time = current_time; 
                }
        }             

        Animation& get_animation()
        {
                return m_animation;
        }

        void set_infinite_animation(bool b) 
        { 
                m_infinite_animation = b; 
        }
    private:
        Animation m_animation;

        // time from last animation 
        float m_old_time;

        bool m_infinite_animation;
        
        //bool m_is_animated_now;
};
