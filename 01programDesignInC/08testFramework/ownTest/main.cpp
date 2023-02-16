#include <stdio.h>
#include <stdlib.h>
#include <haizei/test.h>

int add(int a, int b) {
	return a + b;
}

TEST(testFunc, add) {
	EXPECT_EQ(add(5, 3), 8);
	// EXPECT 遇到错误不结束
	EXPECT_EQ(add(5, 3), 9);
	// ASSERT 遇到错误强行结束
	// ASSERT_EQ(add(5, 3), 9);
	EXPECT_EQ(add(6, 7), 15);
}

TEST(testFunc, add2) {
	EXPECT_EQ(add(5, 3), 8);
	// EXPECT 遇到错误不结束
	EXPECT_EQ(add(5, 3), 9);
	// ASSERT 遇到错误强行结束
	// ASSERT_EQ(add(5, 3), 9);
	EXPECT_EQ(add(6, 7), 15);
}

// 会有重定义的问题，可以在 TEST 宏定义里加特殊字符，如 _haizei_
TEST(test, Funcadd) {
	EXPECT_EQ(add(5, 3), 8);
	// EXPECT 遇到错误不结束
	EXPECT_EQ(add(5, 3), 9);
	// ASSERT 遇到错误强行结束
	// ASSERT_EQ(add(5, 3), 9);
	EXPECT_EQ(add(6, 7), 15);
}


int main(int argc, char *argv[]) {
  // RUN_ALL_TESTS 怎么知道有多少个测试用例: 函数指针
	return RUN_ALL_TESTS();
}
