#include "../src/queue.h"


#include<iostream>
using namespace std;

TEST(NodeTest, Constructor1){
    node<int> n;
    ASSERT_EQ(nullptr, n.next());
}

TEST(NodeTest, Constructor2){
    node<int> n(4);
    ASSERT_EQ(4, n.data());
    ASSERT_EQ(nullptr, n.next());
}

TEST(NodeTest, Getnextptr){
    node<double> a;
    ASSERT_EQ(nullptr, a.next());
}

TEST(NodeTest, GetData){
    node<int> a(1);
    ASSERT_EQ(1, a.data());
}

TEST(NodeTest, SetData){
    node<char> a;
    a.setdata('a');
    ASSERT_EQ('a', a.data());
}

TEST(NodeTest, SetNextPtr){
    
    node<double> a;
    a.setdata(1.1);
    node<double> p;
    p.setnext(&a);
    node<double> *k;
    k = p.next();
    ASSERT_NEAR(1.1, k->data(), 0.0001);
}

TEST(QueueTest, Constructor){
    Queue<double> q;
    ASSERT_EQ(0, q.size());
}

TEST(QueueTest, PushDouble){
    Queue<double> q;
    q.push(1.1);
    ASSERT_EQ(1, q.size());
    ASSERT_NEAR(1.1, q.at(0), 0.0001);
}

TEST(QueueTest, PushInt){
    Queue<int> p;
    p.push(35);
    ASSERT_EQ(1, p.size());
    ASSERT_EQ(35, p.at(0));
}

TEST(QueueTest, PushChar){
    Queue<char> r;
    r.push('a');
    ASSERT_EQ(1, r.size());
    ASSERT_EQ('a', r.at(0));
}

TEST(QueueTest, PopDouble){
    Queue<double> p;
    p.push(2.5);
    ASSERT_NEAR(2.5, p.pop(), 0.0001);
    ASSERT_EQ(0, p.size());
}

TEST(QueueTest, PopInt){
    Queue<int> q;
    q.push(9);
    ASSERT_EQ(9, q.pop());
    ASSERT_EQ(0, q.size());
}

TEST(QueueTest, PopChar){
    Queue<char> r;
    r.push('c');
    ASSERT_EQ('c', r.pop());
    ASSERT_EQ(0, r.size());
}

TEST(QueueTest, PopException){
    Queue<int> q;
    ASSERT_THROW(q.pop(), string);
}

TEST(QueueTest, AtException){
    Queue<int> q;
    q.push(1);
    q.push(2);
    ASSERT_THROW(q.at(-1), string);
    ASSERT_THROW(q.at(5), string);
}

TEST(QueueTest, At){
    Queue<double> q;
    q.push(1.1);
    q.push(2.2);
    q.push(3.3);
    ASSERT_EQ(3, q.size());
    ASSERT_EQ(1.1, q.at(0));
    ASSERT_EQ(2.2, q.at(1));
    ASSERT_EQ(3.3, q.at(2));
}

TEST(QueueTest, Size){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    ASSERT_EQ(3, q.size());
}

TEST(QueueTest, Clear){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    ASSERT_EQ(3, q.size());
    q.clear();
    ASSERT_EQ(0, q.size());
}