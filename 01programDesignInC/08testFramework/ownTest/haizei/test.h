#ifndef _TEST_H
#define _TEST_H

// 函数名不能写死了，因为可能有多个测试用例 TEST，函数名不能重复
// ## 用于粘连两个传入的符号
// 带有 constructor 属性的函数，会先于主函数去执行
#define TEST(a, b) \
void a##_haizei_##b(); \
__attribute__((constructor)) \
// 这个函数会被先于主函数执行
// 添加函数指针到 list，让 RUN_ALL_TESTS 知道都有哪些测试用例
void add##_haizei_##a##_haizei_##b() { \
  add_function(a##_haizei_##b, #a "_haize_" #b); \
  // add_function(Name(a, b), Str(Name(a, b)));
} \
void a##_haizei__##b()

// # 替换传入的符号
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False" );

typedef void (*TestFuncT)();

struct Function {
  TestFuncT func;
  const char *str;
};

int RUN_ALL_TESTS();
// 第一个参数是函数指针
// 第二个参数是字符串，函数名
void add_function(TestFuncT, const char *);


#endif
