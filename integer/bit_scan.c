#include "macro.h"

// @ref
//  *https://www.fermimn.edu.it/linux/quarta/x86/bsr.htm
//    BSR, Bit Scan Reverse(from the most significant bit to the least significant bit)
//  *https://www.fermimn.edu.it/linux/quarta/x86/bsf.htm
//    BSF, Bit Scan Forward
//  *https://dmalcolm.fedorapeople.org/gcc/2015-08-31/rst-experiment/how-to-use-inline-assembly-language-in-c-code.html
//    *Basic Asm
//      The asm keyword is a GNU extension. When Writing code that can be compiled with
//      -ansi and the various -std options, use __asm__ instead of asm.
//    *Output Operands
//      *constraint
//        'r' for register
//        'm' for memory
//        When you list more than one possible location, the compiler chooses the most
//        efficient one based on the current context. If you list as many alternates as
//        the asm statement allows, you permit the optimizers to produce the best possible
//        code. If you must use a specific register, but your Machine Constrains do not
//        provide sufficient control to select the specific register you want, local
//        register variables may provide a solution.
#define __bit_scan(op,x,r) ({__asm__("bs" #op " %1,%0":"=r"(r):"rm"(x));r;})
#define __bsf32(x,r) __bit_scan(fl,x,r)
#define __bsr32(x,r) __bit_scan(rl,x,r)

#if TEST_BS
MAIN(){
    u32 r1,r2;
    u32 x=0x55006600;
    log1("%u,%u",__bsf32(x,r1),__bsr32(x,r2));
    log1("%u,%u",__builtin_ctz(x),31-__builtin_clz(x));
    return 0;
}
#endif
