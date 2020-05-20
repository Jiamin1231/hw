#include "../src/polygon.h"
#include "../src/vector.h"
#include <vector>

using namespace std;
#include <iostream>

class PolygonTest : public ::testing::Test {
protected:
    void SetUp() override {
        Vector va1(a1, 2);      //a_area      : 4 
        Vector va2(a2, 2);      //a_perimeter : 10
        Vector va3(a3, 2);
        Vector va4(a4, 2);
        a[0] = va1;
        a[1] = va2;
        a[2] = va3;
        a[3] = va4;

        Vector vb1(b1, 2);      //b_area      : 1 
        Vector vb2(b2, 2);      //b_perimeter : 4
        Vector vb3(b3, 2);
        Vector vb4(b4, 2);
        b[0] = vb1;
        b[1] = vb2;
        b[2] = vb3;
        b[3] = vb4;

        Vector vc1(c1, 2);      //c_area      : 3 
        Vector vc2(c2, 2);      //c_perimeter : 8
        Vector vc3(c3, 2);
        Vector vc4(c4, 2);
        c[0] = vc1;
        c[1] = vc2;
        c[2] = vc3;
        c[3] = vc4;
    }
    double a1[2] = {1, 0};
    double a2[2] = {2, 4};
    double a3[2] = {2, 0};
    double a4[2] = {1, 4};
    int a_vernum = 4;
    Vector a[4];

    double b1[2] = {1, 0};
    double b2[2] = {2, 0};
    double b3[2] = {2, 1};
    double b4[2] = {1, 1};
    int b_vernum = 4;
    Vector b[4];

    double c1[2] = {1, 0};
    double c2[2] = {4, 0};
    double c3[2] = {4, 2};
    double c4[2] = {1, 2};
    int c_vernum = 4;
    Vector c[4];
};

TEST_F(PolygonTest, Constructor){
    Polygon p(a, a_vernum);
    ASSERT_EQ(1, p.point(1).at(1));
    ASSERT_EQ(0, p.point(1).at(2));
    ASSERT_EQ(2, p.point(2).at(1));
    ASSERT_EQ(0, p.point(2).at(2));
    ASSERT_EQ(2, p.point(3).at(1));
    ASSERT_EQ(4, p.point(3).at(2));
    ASSERT_EQ(1, p.point(4).at(1));
    ASSERT_EQ(4, p.point(4).at(2));

}

TEST_F(PolygonTest, Point){
    Polygon p(a, a_vernum);
    ASSERT_EQ(1, p.point(1).at(1));
    ASSERT_EQ(0, p.point(1).at(2));
    ASSERT_EQ(2, p.point(2).at(1));
    ASSERT_EQ(0, p.point(2).at(2));
    ASSERT_EQ(2, p.point(3).at(1));
    ASSERT_EQ(4, p.point(3).at(2));
    ASSERT_EQ(1, p.point(4).at(1));
    ASSERT_EQ(4, p.point(4).at(2));
}

TEST_F(PolygonTest, Sides){
    Polygon p(a, a_vernum);
    ASSERT_EQ(4, p.sides());
}

TEST_F(PolygonTest, Perimeter){
    Polygon p(a, a_vernum);
    ASSERT_EQ(10, p.perimeter());
}

TEST_F(PolygonTest, AngleComparator){
    
    Vector g = centroid(a, a_vernum);
    Vector r = a[0] - g;
    AngleComparator comp(g, r);
    sort(a, a + a_vernum, comp);
    
}

TEST_F(PolygonTest, Area){
    Polygon p(a, a_vernum);
    ASSERT_NEAR(4, p.area(),0.001);
}

TEST_F(PolygonTest, FindAll){
    Polygon w(a, a_vernum);
    Polygon x(b, b_vernum);
    Polygon y(c, c_vernum);
    std::vector<Polygon > polygons;
    polygons.push_back(x); 
    polygons.push_back(y); 
    polygons.push_back(w); 
    std::vector<Polygon *> result = findAll(polygons.begin(), polygons.end(), [](Polygon *s) {
        return s->area() > 2 && s->area() < 5.5;
    }); // find polygon that area larger then 2 and less then 5

}
