//
// Created by Steve on 5/22/2022.
//

#include <stdlib.h>
#include "macro.h"

double _sqrt1(double d,int*iter){
#define PRECISION 0.0001
    if(__builtin_expect(d<0,0))
        return -1;
    if(__builtin_expect(d<PRECISION,0))
        return 0;
    if(iter)
        *iter=0;
    double p,q,r;
    q=d/2;
    do{
        p=q;
        q=p-(p*p-d)/(2*p);
        r=p-q;
        if(iter)
            ++*iter;
    }while(r*r>PRECISION);
    return q;
}

/*
 * @ref
 *  musl sqrt
 *    (https://git.musl-libc.org/cgit/musl/tree/src/math/sqrt.c)
 *  boost core_arch_ops_gcc_x86.hpp
 *  gcc attribute weakref
 *    (https://gcc.gnu.org/onlinedocs/gcc-4.3.5/gcc/Function-Attributes.html)
 */
double _sqrt2(double d,int*iter){
    if(iter)
        *iter=0;
    double r __attr(__vector_size__(16));
    __asm__("vsqrtsd %0,%0,%%xmm0":"=x"(r));
    return *(double*)&r;
}

static double _sqrt(double,int*) __attr(weakref("_sqrt2"));

int main(int argc,char*argv[]){
    double d=128;
    if(argc>1)
        d=atof(argv[1]);
    int n;
    double r=_sqrt(d,&n);
    log1("%.6f #%d",r,n);
    return 0;
}
