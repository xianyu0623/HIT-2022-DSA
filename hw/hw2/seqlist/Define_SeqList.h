#ifndef SEQLIST_DEFINE_SEQLIST_H
#define SEQLIST_DEFINE_SEQLIST_H
const int N = 200;//最长的表长

//定义seqlist
typedef struct {
    int data[N];//存储数据的数组
    int len;//顺序表的长度
} seqlist;

#endif //SEQLIST_DEFINE_SEQLIST_H
