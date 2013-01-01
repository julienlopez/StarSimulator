#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <array>
#include <initializer_list>

template<uint8_t N> class Vector
{
public:
    typedef std::array<double, N> type_array;

    Vector(std::initializer_list<double> lst)
    {
        std::copy(lst.begin(), lst.end(), m_array.begin());
    }

    template<uint8_t I> inline constexpr double get()
    {
        static_assert(I<N, "Index out of bound");
        return m_array[I];
    }

    template<uint8_t I> inline double& get()
    {
        static_assert(I<N, "Index out of bound");
        return m_array[I];
    }

    double inline get(uint8_t i) const
    {
        return m_array[i];
    }

    typename type_array::const_iterator begin() const
    {
        return m_array.begin();
    }

    typename type_array::const_iterator end() const
    {
        return m_array.end();
    }

    typename type_array::iterator begin()
    {
        return m_array.begin();
    }

    typename type_array::iterator end()
    {
        return m_array.end();
    }

    Vector<N> operator+(const Vector<N>& v) const
    {
        Vector<N> res(*this);
        for(uint8_t i = 0; i < N; i++)
            res.get(i) += v.get(i);
        return res;
    }

    Vector<N> operator-(const Vector<N>& v) const
    {
        Vector<N> res(*this);
        for(uint8_t i = 0; i < N; i++)
            res.get(i) -= v.get(i);
        return res;
    }

private:
    type_array m_array;
};

typedef Vector<2> Vector2D;
typedef Vector<3> Vector3D;
typedef Vector<4> Vector4D;

#endif // __VECTOR_HPP__

