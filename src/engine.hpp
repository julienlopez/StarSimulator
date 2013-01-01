#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <utils/matrix.hpp>

class Engine
{
    public:
        Engine();
        virtual ~Engine();

    private:
        Vector2D m_position;
        Vector2D m_direction;
};

#endif // __ENGINE_HPP__
