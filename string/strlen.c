//
// Created by Steve on 5/17/2022.
//
#include <stddef.h>

/*
 * @ref
 *  '&',earlyclobber operand
 *    (https://gcc.gnu.org/onlinedocs/gcc/Modifiers.html#Modifiers)
 *  constrains a,c,D
 *    (https://gcc.gnu.org/onlinedocs/gcc/Machine-Constraints.html#Machine-Constraints)
 *  string_32.c
 *    (https://docs.huihoo.com/doxygen/linux/kernel/3.7/string__32_8c_source.html)
 *  set disassemble-next-line on
 *    (https://stackoverflow.com/questions/1902901/show-current-assembly-instruction-in-gdb)
 *  AT&T syntax
 *    (https://stackoverflow.com/questions/13856792/gcc-inline-assembly-error-error-junk-esp-after-expression)
 *  lea
 *    (https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)
 */
int _strlen(const char*s){
//    int l=0;
//#define NL "\n"
//    __asm__("xor %%eax,%%eax" NL
//            "mov -1,%%rcx" NL
//            "repne scasb" NL
//            "not %%rcx" NL
//            "lea -1(%%rcx),%0"
//            :"=r"(l)
//            :
//            :"rax","rcx","rdi","memory");
//    return l;
    size_t r;
    int d;
    __asm__("repne scasb"
            :"=c"(r),"=&D"(d)
            :"0"(0xffffffffu),"1"(s),"a"(0)
            :"memory");
    return ~r-1;
}

#include "macro.h"
int main(int argc,char*argv[]){
    log1("%d",_strlen(argc<2?argv[0]:argv[1]));
    return 0;
}
