#include "../src/vector.h"

class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {
      a[0] = 1;
      a[1] = 3;
      a_dim = 2;

      b[0] = 3;
      b[1] = 4;
      b_dim = 2;
    }
    double a[2];
    int a_dim;

    double b[2];
    int b_dim;
};

TEST_F(VectorTest, DefaultConstructor){
    Vector v;
    ASSERT_EQ(0, v.dim());
}

TEST_F(VectorTest, Constructor){
    Vector v(a, a_dim);
    ASSERT_EQ(2, v.dim());
    ASSERT_EQ(1, v.at(1));
    ASSERT_EQ(3, v.at(2));
}

TEST_F(VectorTest, CopyConstructor){
    Vector v(a, a_dim);
    Vector u = v;
    ASSERT_EQ(2, u.dim());
    ASSERT_EQ(1, u.at(1));
    ASSERT_EQ(3, u.at(2));
}
TEST_F(VectorTest, Dim){
    Vector v(a, a_dim);
    ASSERT_EQ(2, v.dim());
}

TEST_F(VectorTest, At){
    Vector v(a, a_dim);
    ASSERT_EQ(1, v.at(1));
    ASSERT_EQ(3, v.at(2));
}

TEST_F(VectorTest, AddOperator){
    Vector u(a, a_dim);
    Vector v(b, b_dim);
    Vector result = u + v;
    ASSERT_EQ(2, result.dim());
    ASSERT_EQ(4, result.at(1));
    ASSERT_EQ(7, result.at(2));
}

TEST_F(VectorTest, SubstractOperator){
    Vector u(a, a_dim);
    Vector v(b, b_dim);
    Vector result = u - v;
    ASSERT_EQ(2, result.dim());
    ASSERT_EQ(-2, result.at(1));
    ASSERT_EQ(-1, result.at(2));
}

TEST_F(VectorTest, Length){
    Vector v(b, b_dim);
    ASSERT_EQ(5, v.length());
}

TEST_F(VectorTest, Angle){
    Vector u(a, a_dim);
    Vector v(b, b_dim);
    ASSERT_NEAR(18.434, u.angle(v),0.001);
}