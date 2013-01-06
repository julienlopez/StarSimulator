#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <initializer_list>

#include <utils/plainstorage.hpp>

#include <iostream>

template<class STORAGE> class BasicMatrix : public STORAGE
{
public:
    BasicMatrix() = default;

    BasicMatrix(std::initializer_list<double> lst)
    {
        static_assert(STORAGE::largeur == 1, "");
        uint8_t n = 0;
        for(std::initializer_list<double>::const_iterator i = lst.begin(); i < lst.end(); ++i, n++)
            (*this)(n) = *i;
    }

    BasicMatrix(std::initializer_list<std::initializer_list<double>> lst)
    {
        uint8_t m = 0, n = 0;
        for(std::initializer_list<std::initializer_list<double>>::const_iterator i = lst.begin(); i < lst.end(); ++i, m++)
	        for(std::initializer_list<double>::const_iterator j = i->begin(); j < i->end(); ++j, n++)
    	        (*this)(m, n) = *j;
    }

    BasicMatrix<typename STORAGE::type_transposed_storage> transpose() const
    {
        typedef BasicMatrix<typename STORAGE::type_transposed_storage> type_transpose;
        type_transpose res;
        for(uint8_t i = 0; i < type_transpose::hauteur; i++)
            for(uint8_t j = 0; j < type_transpose::largeur; j++)
                res(i, j) = (*this)(j, i);
        return res;
    }

    void afficher(std::ostream& o) const
    {
        o << '[';
        for(uint8_t i = 0; i < STORAGE::hauteur; i++)
        {
            o << ' ';
            for(uint8_t j = 0; j < STORAGE::largeur; j++)
                o << (*this)(i, j) << ' ';
            if(i < STORAGE::hauteur-1)
                o << ';';
        }
        o << ']';
    }

    const BasicMatrix<STORAGE> operator + (const BasicMatrix<STORAGE>& m) const
    {
        BasicMatrix<STORAGE> res = *this;
        for(uint8_t i = 0; i < STORAGE::hauteur; i++)
            for(uint8_t j = 0; j < STORAGE::largeur; j++)
                res(i, j) += m(j, i);
        return res;
    }

    const BasicMatrix<STORAGE> operator - (const BasicMatrix<STORAGE>& m) const
    {
        BasicMatrix<STORAGE> res = *this;
        for(uint8_t i = 0; i < STORAGE::hauteur; i++)
            for(uint8_t j = 0; j < STORAGE::largeur; j++)
                res(i, j) -= m(j, i);
        return res;
    }
};

template<class STORAGE> std::ostream& operator<<(std::ostream& o, const BasicMatrix<STORAGE>& m)
{
    m.afficher(o);
    return o;
}

template<uint8_t HAUTEUR, uint8_t LARGEUR> using Matrix = BasicMatrix<PlainStorage<HAUTEUR, LARGEUR>>;
template<uint8_t N> using Vector = Matrix<N, 1>;

typedef Vector<2> Vector2D;
typedef Vector<3> Vector3D;
typedef Vector<4> Vector4D;

#endif // __MATRIX_HPP__

