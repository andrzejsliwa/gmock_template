#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "turtle.h"

class MockTurtle : public Turtle {
 public:
  MOCK_METHOD0(PenUp, void());
  MOCK_METHOD0(PenDown, void());
  MOCK_METHOD1(Forward, void(int distance));
  MOCK_METHOD1(Turn, void(int degrees));
  MOCK_METHOD2(GoTo, void(int x, int y));
  MOCK_CONST_METHOD0(GetX, int());
  MOCK_CONST_METHOD0(GetY, int());
};


using ::testing::AtLeast;                     

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                          
  EXPECT_CALL(
    turtle, PenDown()
  ).Times(AtLeast(1));

  turtle.PenDown();                        

  EXPECT_TRUE(1);
}                                             

int main(int argc, char** argv) {
  
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}