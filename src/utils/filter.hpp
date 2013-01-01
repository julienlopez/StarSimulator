#ifndef __FILTER_HPP__
#define __FILTER_HPP__

#include <cassert>

template<uint8_t N, uint8_t M> class Filter
{
public:
    Filter(): m_inputs(), m_outputs()
    {
        m_inputs.fill(0);
        m_outputs.fill(0);
    }

    double operator()(double input)
    {
        double res = 0;
        m_inputs[0] = input;
        for(uint8_t i = 0; i < N; i++)
            res += m_inputFactors[i] * m_inputs[i];
        for(uint8_t j = 0; j < M; j++)
            res += m_outputFactors[j] * m_outputs[j];
        shiftInputsAndOutputs(input, res);
        return res;
    }

    void setInputFactors(std::initializer_list<double> lst)
    {
        assert(lst.size() == N);
        std::initializer_list<double>::const_iterator it = lst.begin();
        for(uint8_t i = 0; i < N && it != lst.end(); ++it, i++)
            m_inputFactors[i] = *it;
    }

    void setOutputFactors(std::initializer_list<double> lst)
    {
        assert(lst.size() == M);
        std::initializer_list<double>::const_iterator it = lst.begin();
        for(uint8_t i = 0; i < M && it != lst.end(); ++it, i++)
            m_outputFactors[i] = *it;
    }

private:
    std::array<double, N> m_inputFactors;
    std::array<double, M> m_outputFactors;
    std::array<double, N> m_inputs;
    std::array<double, M> m_outputs;

    void shiftInputsAndOutputs(double input, double output)
    {
        m_inputs[0] = input;
        m_outputs[0] = output;
        for(uint8_t i = 0; i < N; i++)
            m_inputs[i] = m_inputs[i-1];
        for(uint8_t j = 0; j < M; j++)
            m_outputs[j] = m_outputs[j-1];
    }
};

#endif // __FILTER_HPP__

