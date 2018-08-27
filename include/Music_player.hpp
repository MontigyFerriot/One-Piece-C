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

#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include <SFML/Audio.hpp>
#include "Resource_manager.hpp"
#include "Utility.hpp"

class Music_player
{
    public:
        explicit Music_player(Resource_manager& resource_manager);

        // float t stands for time value
        void play() noexcept;
        void restart(float t) noexcept;
        void stop() noexcept;
        void next(float t) noexcept;
        void previous(float t) noexcept;
        void shuffle_play(float t) noexcept;

        ~Music_player();
    private:
        Resource_manager& m_resource_manager;
        std::size_t m_current_music;
        float m_last_activity_time;
        static constexpr float delay = 0.5f;
};

#endif // MUSIC_PLAYER_H