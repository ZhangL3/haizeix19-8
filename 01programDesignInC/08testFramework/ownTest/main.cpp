#include <stdio.h>
#include <stdlib.h>
#include <haizei/test.h>

int add(int a, int b) {
	return a + b;
}

TEST(testFunc, add) {
	EXPECT_EQ(add(5, 3), 8);
	EXPECT_NE(add(5, 3), 9);
	EXPECT_GT(add(6, 7), 10);
	EXPECT_LT(add(6, 7), 13);
	EXPECT_GE(add(6, 7), 20);
}

TEST(testFunc, add2) {
	EXPECT_EQ(add(5, 3), 8);
	EXPECT_EQ(add(5, 3), 8);
	EXPECT_EQ(add(6, 7), 13);
}

int main(int argc, char *argv[]) {
  // RUN_ALL_TESTS 怎么知道有多少个测试用例: 函数指针
	return RUN_ALL_TESTS();
}
