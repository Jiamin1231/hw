#ifndef VECTOR_H
#define VECTOR_H
#include<math.h>

using namespace std;
class Vector{
private:
    double *_vec;
    int _dim;

public:
    Vector(){
        _dim = 0;
        _vec = nullptr;
    }

    Vector(int dim){
        _dim = dim;
        _vec = new double[_dim];
        for(int i = 0; i < _dim; i++){
            _vec[i] = 0;
        }
    }
    
    Vector(double a[], int dim){
        _dim = dim;
        _vec = new double[_dim];
        for(int i = 0; i < _dim; i++){
            _vec[i] = a[i];
        }
    }

    ~Vector(){
        if(_vec){
            delete [] _vec;
        }
    }

    Vector(Vector const & v){
        _dim = v._dim;
        _vec = new double[_dim];
        for(int i = 0; i < _dim; i++){
            _vec[i] = v._vec[i];
        }
    }

    Vector operator=(Vector const & v){
        if(_vec != 0){
            delete [] _vec;
        }
        _dim = v._dim;
        _vec = new double[_dim];
        for(int i = 0; i < _dim; i++){
            _vec[i] = v._vec[i];
        }
        return *this;
    }

    int dim() const{
        return _dim;
    }

    //at need exception
    double & at(int i) { //i starts from 1
        double result = _vec[i-1];
        return *(new double (result));
    }

    Vector & operator+(Vector const & v){ 
        cout << " + called"<<endl;       
        Vector result = *this;
        for(int i = 0; i < result._dim; i++){
            result._vec[i] += v._vec[i]; 
        }
        return *(new Vector(result));
    }

    Vector & operator-(Vector const & v){        
        Vector result = *this;
        for(int i = 0; i < result._dim; i++){
            result._vec[i] -=  v._vec[i]; 
        }
        return *(new Vector(result));
    }

    double length() const{
        double value = 0;
        for(int i = 0; i < _dim; i++){
            value += _vec[i]*_vec[i];
        }
        return sqrt(value);
    }

    double angle(Vector u) const{
        double angle = 0;
        double dot = 0;
        for(int i = 0; i < _dim; i++){
            dot += _vec[i] * u._vec[i];
        }
        double length = this->length() * u.length();
        double value = dot / length;
        angle = acos (value) * 180.0 / M_PI;
        return angle;
    }
};

Vector centroid(Vector u[], int n){
    Vector result(u[0].dim());
    for(int k =0; k < n; k++){
        result = result + u[k];
    }
    for(int i = 1; i < u[0].dim(); i++){
        result.at(i) *=  (1.0/n);
         cout << result.at(i) <<endl;
    }
    result.at(1) = result.at(1) / 4.0;
    return result;
}

class AngleComparator{
private:
    Vector _g;
    Vector _r;

public:
    AngleComparator(Vector const & g, Vector const & r){
        
    }

};

#endif