#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[0;" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR_HL(a, 33)
#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

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

// 泛型宏
#define TYPE_STR(a) _Generic((a), \
  int : "%d", \
  double : "%lf", \
  float : "%f", \
  long long : "%lld" \
)

#define P(a, color) { \
  char frm[1000]; \
  sprintf(frm, color("%s"), TYPE_STR(a)); \
  printf(frm, a); \
}

#define Name(a, b) a##_haizei_##b
#define Str(a, b) #a"."#b

// 用 __typeof 可以避免 a 是 a++ 被多次加的情况

#define EXPECT(a, b, comp) { \
  __typeof(a) _a = (a), _b = (b); \
  haizei_test_info.total += 1; \
  if (_a comp _b) haizei_test_info.success += 1; \
  else { \
    printf("\n"); \
    printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__); \
    printf(YELLOW_HL("\t\texpect" #a " " #comp " " #b " actual : ")); \
    P(_a, YELLOW_HL); \
    printf("\n"); \
  } \
  printf(GREEN("[-----------] ") #a " " #comp " " #b); \
  printf(" %s\n", (_a) comp (_b) ? GREEN_HL("TRUE") : RED_HL("FALSE")); \
}

# define EXPECT_EQ(a, b) EXPECT(a, b, ==)
# define EXPECT_LT(a, b) EXPECT(a, b, <)
# define EXPECT_LE(a, b) EXPECT(a, b, <=)
# define EXPECT_GT(a, b) EXPECT(a, b, >)
# define EXPECT_GE(a, b) EXPECT(a, b, >=)
# define EXPECT_NE(a, b) EXPECT(a, b, !=)

// # 替换传入的符号
// #define EXPECT_EQ(a, b) { \
//   printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False" ); \
// }

// #define EXPECT_LT(a, b) { \
//   printf("%s == %s ? %s\n", #a, #b, (a) < (b) ? "True" : "False" ); \
// }

typedef void (*TestFuncT)();

struct Function {
  TestFuncT func;
  const char *str;
};
//
   
// 定义全局变量，储存测试信息
struct FunctionInfo {
  int total, success;
};
// 声明外部变量，编译的时候知道这个变量的存在，不会报错，链接的时候肯定能找到
// 原始声明在 test.cc 里
extern struct FunctionInfo haizei_test_info;


int RUN_ALL_TESTS();
// 第一个参数是函数指针   
// 第二个参数是字符串，函数名
void add_function(TestFuncT, const char *);


#endif
