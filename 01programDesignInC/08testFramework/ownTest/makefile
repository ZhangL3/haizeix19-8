.PHONY: clean

# 依赖两个文件 main.o, test.o
all: main.o haizei/test.o
		g++ -o ./bin/haizei main.o haizei/test.o

# main.o 依赖 main.cpp, 就是说，main.cpp 变里, main.o 就要重新编译
main.o: main.cpp
# -I./ 增加头文件的查找路径
		g++ -I./ -c main.cpp

# 声明和定义分开写
haizei/test.o: haizei/test.h haizei/test.cc
# 让 test.o 生成在 haizei 目录里
		g++ -I./ -o haizei/test.o -c haizei/test.cc

clean:
		rm -rf ./a.out *.o
