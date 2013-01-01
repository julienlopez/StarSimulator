#ifndef __SHIP_HPP__
#define __SHIP_HPP__

#include <utils/matrix.hpp>

#include <list>
#include <memory>

class Engine;

class Ship
{
    public:
        typedef std::shared_ptr<Engine> sp_engine;
        typedef std::list<sp_engine> type_list_engine;


        Ship();
        virtual ~Ship();

    private:
        double m_mass;
        Vector2D m_position;
        double m_inertia;
        type_list_engine m_engines;

};

#endif // __SHIP_HPP__
