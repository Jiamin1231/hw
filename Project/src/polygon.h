#ifndef POLYGON_H
#define POLYON_H

#include "./vector.h"
#include <iostream>
#include <vector>
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
        Vector g = centroid(_vertices, _vernum);
        Vector r = _vertices[0] - g;
        AngleComparator comp(g, r);
        sort(_vertices, _vertices + _vernum, comp); 
    }

    // Polygon(Vector *vertices, int vernum){
    //     _vernum = vernum;
    //     _vertices = new Vector[_vernum];
    //     for(int i = 0; i < _vernum; i++){
    //         _vertices[i] = vertices[i];
    //     }
    //     Vector g = centroid(_vertices, _vernum);
    //     Vector r = _vertices[0] - g;
    //     AngleComparator comp(g, r);
    //     sort(_vertices, _vertices + _vernum, comp); 
    // }

    Polygon(){
        _vernum = 0;
        _vertices = nullptr;
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

    double perimeter(){
        double result = 0;
        for(int i = 1; i < _vernum; i++){
            result += (_vertices[i] - _vertices[i - 1]).length();
        }
        result += (_vertices[0] - _vertices[_vernum - 1]).length();
        return result;
    }

    double area(){
        double result = 0;
        for(int i = 1; i < _vernum - 1; i++){
            result += _vertices[0].areawith(_vertices[i], _vertices[i + 1]);
        }
        return result;
    }
};
#endif

template <class RandomAccessIterator, class Condition>
std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond) {
    std::vector<Polygon *> result;
    //cout<< begin[0] -> sides()<<endl;
    for(RandomAccessIterator it = result.begin(); it != result.end(); it++) {
        //cout <<"here"<<endl;
        //cout << it[0]->area()<<endl;
        if (cond(*it))
             result.push_back(*it);
    }
    return result;
}