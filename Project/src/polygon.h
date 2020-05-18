#ifndef POLYGON_H
#define POLYON_H

#include "./vector.h"
#include <iostream>
using namespace std;

class Polygon {
private:
    Vector *_vertices;
    int _vernum; //number of vertices

public:
    Polygon(Vector vertices[], int vernum){
        _vernum = vernum;
        _vertices = new Vector[_vernum];
        for(int i = 0; i < _vernum; i++){
            _vertices[i] = vertices[i];
        }
        //Vector g = centroid(vertices, vernum); 
    }

    ~Polygon(){
        if(_vertices){
            delete [] _vertices;
        }
    }

    Vector point(int i){
        if(i > _vernum  || i < 0){
            throw std::string("The point does not exist.");
        }else{
            return _vertices[i - 1];
        } 
    }

    int sides(){
        return _vernum ;
    }
};
#endif