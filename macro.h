//
// Created by Steve on 8/22/2021.
//

#ifndef AMS_YYDS_MACRO_H
#define AMS_YYDS_MACRO_H

#define MAIN() int main()
#define MAIN_EX(c,v) int main(int c,const char*v[])

typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

#define __nl "\n"
//#define __char_bit 8

#define __attr(...) __attribute__((__VA_ARGS__))

#include <stdio.h>

#define __log(fp,fmt,...) fprintf(fp,fmt "\n",##__VA_ARGS__)
#define LOG1(...) __log(stdout,__VA_ARGS__)
#define LOG2(...) __log(stderr,__VA_ARGS__)
#define log1 LOG1
#define log2 LOG2

#endif //AMS_YYDS_MACRO_H
