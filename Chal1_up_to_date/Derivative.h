//
// Created by Davide Galbiati on 18/03/2023.
//

#ifndef CHAL1_DERIVATIVE_H
#define CHAL1_DERIVATIVE_H

#endif //CHAL1_DERIVATIVE_H

template<unsigned int N>
constexpr auto derive =[](auto f, auto h)
{
    if constexpr (N==0u)
    {
        return [f](auto x){return f(x);};
    }
    else
    {
        auto prev = derive<N-1u>(f,h);
        return [=] (auto x){
            return (prev(x+h)-prev(x-h))/(2.*h);
        };
    }
};