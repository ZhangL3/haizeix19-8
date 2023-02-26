#ifndef _LINKLIST_H
#define _LINKLIST_H

// 求 T 类型的 name 域的偏移量
// 0 转成 T* 类型，再取他 name 段的地址，再把字段的地址强转成 int
#define offset(T, name) ((long long)(&(((T *)(0))->name)))

// p: 下一个节点链表指针域的地址, T: 下一个节点的数据类型, name: 指针域的名字
// 返回下一个节点 (T*类型) 的首地址
// 强转 *p 为 char，找到那个 byte，减去偏移量，再转成 T*
#define Head(p, T, name) ((T *)(((char *)p) - offset(T, name)))

struct LinkNode {
  // 指针域
  struct LinkNode *next;
};

#endif