#include "ship.hpp"

Ship::Ship(): m_mass(1000000), m_position{0, 0}, m_inertia(1), m_engines()
{
    //ctor
}

Ship::~Ship()
{
    //dtor
}
