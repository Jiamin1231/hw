#include "../src/polygon.h"
#include "../src/vector.h"

class PolygonTest : public ::testing::Test {
protected:
    void SetUp() override {
        Vector va1(a1, 2);
        Vector va2(a2, 2);
        Vector va3(a3, 2);
        Vector va4(a4, 2);
        a[0] = va1;
        a[1] = va2;
        a[2] = va3;
        a[3] = va4;
    }
    double a1[2] = {1, 0};
    double a2[2] = {2, 0};
    double a3[2] = {2, 4};
    double a4[2] = {1, 4};
    int a_vernum = 4;
    Vector a[4];
};

TEST_F(PolygonTest, Constructor){
    // Polygon p(a, a_vernum);

}

TEST_F(PolygonTest, Point){
    Polygon p(a, a_vernum);
    ASSERT_EQ(1, p.point(1).at(1));
    ASSERT_EQ(0, p.point(1).at(2));
}

TEST_F(PolygonTest, Sides){
    Polygon p(a, a_vernum);
    ASSERT_EQ(4, p.sides());
}

TEST_F(PolygonTest, Centroid){
    Vector g = centroid(a, a_vernum);
    ASSERT_EQ(2, g.dim());
    ASSERT_NEAR(1.5, g.at(1), 0.001);
}