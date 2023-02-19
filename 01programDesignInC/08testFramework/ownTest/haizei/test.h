#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"

#define GREE(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

// 函数名不能写死了，因为可能有多个测试用例 TEST，函数名不能重复
// ## 用于粘连两个传入的符号，不做替换
// 带有 constructor 属性的函数，会先于主函数去执行

// 这个函数 (add) 会被先于主函数执行, 因为被标记为 constructor
// 添加函数指针到 list，让 RUN_ALL_TESTS 知道都有哪些测试用例

// void a##_haizei_##b() 后面是 TEST(a, b) 后的大括号
#define TEST(a, b) \
void a##_haizei_##b(); \
__attribute__((constructor)) \
void add##_haizei_##a##_haizei_##b() { \
  add_function(Name(a, b), Str(a, b)); \
} \
void a##_haizei_##b()

#define Name(a, b) a##_haizei_##b
#define Str(a, b) #a"."#b

// #define Str(a, b) #a "_haize_" #b

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
