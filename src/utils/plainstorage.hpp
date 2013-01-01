#ifndef __PLAINSTORAGE_HPP__
#define __PLAINSTORAGE_HPP__

#include <array>

template<uint8_t HAUTEUR, uint8_t LARGEUR> class PlainStorage
{
public:
    typedef std::array<double, HAUTEUR*LARGEUR> type_array;
    typedef PlainStorage<LARGEUR, HAUTEUR> type_transposed_storage;

    constexpr static uint8_t largeur = LARGEUR;
    constexpr static uint8_t hauteur = HAUTEUR;

    PlainStorage(): m_array() {}

    virtual ~PlainStorage() {}

    inline double operator()(uint8_t hauteur, uint8_t largeur) const
    {
        return m_array[hauteur * HAUTEUR + largeur];
    }

    inline double& operator()(uint8_t hauteur, uint8_t largeur)
    {
        return m_array[hauteur * HAUTEUR + largeur];
    }

    inline double operator()(uint8_t n) const
    {
        static_assert(HAUTEUR == 1 || LARGEUR == 1, "");
        return ( HAUTEUR == 1 ? (*this)(0, n) : (*this)(n, 0) );
    }

    inline double& operator()(uint8_t n)
    {
        static_assert(HAUTEUR == 1 || LARGEUR == 1, "");
        return ( HAUTEUR == 1 ? (*this)(0, n) : (*this)(n, 0) );
    }

private:
    type_array m_array;
};

#endif // __PLAINSTORAGE_HPP__

