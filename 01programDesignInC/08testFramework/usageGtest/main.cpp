#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

int add(int a, int b) {
	return a + b;
}

TEST(testFunc, add) {
	EXPECT_EQ(add(5, 3), 8);
	// EXPECT 遇到错误不结束
	EXPECT_EQ(add(5, 3), 9);
	// ASSERT 遇到错误强行结束
	ASSERT_EQ(add(5, 3), 9);
	EXPECT_EQ(add(6, 7), 15);
}

int main(int argc, char *argv[]) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}