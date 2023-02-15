#ifndef _TEST_H
#define _TEST_H

// 函数名不能写死了，因为可能有多个测试用例 TEST，函数名不能重复
// ## 用于粘连两个传入的符号
#define TEST(a, b) void a##b()
// # 替换传入的符号
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False" );

int RUN_ALL_TESTS();

#endif
