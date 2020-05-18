#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template<class T>
class node{
private:
    T _data;
    node<T> *_next;
public :
    node(){
        _next = nullptr;
    }

    node(T data){
        _data = data; 
        _next = nullptr;
    }

    node<T>* next(){
        return _next;
    }

    T data(){
        return _data;
    }

    void setdata(T data){
        _data = data;
    }

    void setnext(node<T> *p){
        _next = p;
    }

};

template<class T>
class Queue{
private:
    node<T> *head;
    node<T> *tail;
public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    ~Queue(){
        node<T> *p;
        p = head;
        while(p != nullptr){
            head = head->next();
            node<T> *k;
            k = p;
            p = head;
            delete k;
        }
        tail = nullptr;
        head = nullptr;
        delete p;
    }

    void push(T element){
        node<T> *newnode;
        newnode = new node<T>;          
        newnode->setdata(element);      //newnode->data() = element;
        if(tail == nullptr){            //tail->next() = newnode;
            head = newnode;
            tail = newnode;
            return;
        }
        tail->setnext(newnode);
        tail = newnode;
    }

    T pop(){
        if(head == nullptr){
            throw string("It is empty.");
        }
        if(head == tail){
            T result = head->data();
            node<T> *p;
            p = head;
            head = nullptr;
            tail =nullptr;
            delete p;
            return result;
        }else{
            T result = head->data();
            node<T> *p;
            p = head;
            head = head->next();
            delete p;
            return result;
        }
        
    }

    int size(){
        int result = 1;
        if(head == nullptr){
            int resultp = 0;
            return resultp;
        }
        if(head != nullptr && head == tail ){
            return result;
        }else{
            node<T> *p;
            for(p = head; p != tail; p = p->next()){
                result ++;
            }
            return result;
        }
    }

    T at(int pos){
        int k = 0;
        node<T> *p;
        if(pos < 0 or pos > size() - 1){
            throw string("It does not exist.");
        }else{
            for(p = head; k < pos + 1 ; p = p->next(), k++){
                if(k == pos){
                    return p->data();
                }
            } 
        }  
    }

    void clear(){
        node<T> *p;
        p = head;
        while(p != nullptr){
            head = head->next();
            node<T> *k;
            k = p;
            p = head;
            delete k;
        }
        tail = nullptr;
        head = nullptr;
        delete p;
    }
};

#endif
