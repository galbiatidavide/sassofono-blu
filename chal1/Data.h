//
// Created by Alessandra Gotti on 17/03/23.
//

#include<iostream>
using namespace std



#ifndef CHAL1_DATA_H
#define CHAL1_DATA_H


class Data {

private:

    double ti = 0.;
    double tf = 0.;
public:
    double getTi() const {
        return ti;
    }

    void setTi(double ti) {
        Data::ti = ti;
    }

    double getTf() const {
        return tf;
    }

    void setTf(double tf) {
        Data::tf = tf;
    }

    double getH() const {
        return h;
    }

    void setH(double h) {
        Data::h = h;
    }

    int getNumInt() const {
        return num_int;
    }

    void setNumInt(int numInt) {
        num_int = numInt;
    }

    double getInitCond() const {
        return init_cond;
    }

    void setInitCond(double initCond) {
        init_cond = initCond;
    }

private:
    double h = 0.;
    int num_int = 0;
    double init_cond = 0.;



public:

    Data(double t1 = 0, double t2, double h_input, double i_cond) : ti(t1), tf(t2), h(h_input), init_cond(i_cond) {
        num_int = (tf-ti)/h;
    };

    auto f = [](double t,(double t, std::function<double(double)> y) y) {
        return -t*exp(-y(t));
    };




    //dominio tempo
    //condizione iniziale
    //soluzione esatta
    //forzante
    //passo
    //number of intervals
    /*gestione errore*/

};


#endif //CHAL1_DATA_H
