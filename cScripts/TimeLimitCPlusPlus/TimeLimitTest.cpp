//
//  TimeLimitTest.cpp
//  timeLimitCPlusPlus
//
//  Created by Eduardo dos Santos Leal on 18/05/16.
//  Copyright © 2016 TCARVI. All rights reserved.
//

#include "TimeLimitTest.hpp"

using std::cout;

void  timeLimitTest ( long long (*f)(int), int parameter ) {
    typedef uint64_t clock_t;
    clock_t initialProcessorTimeUsed = clock();
    int varLoopEficiencia;
    for (varLoopEficiencia=0; varLoopEficiencia < 10000000; varLoopEficiencia++) {
        // Processamento avaliado
        (*f)(parameter);
    }
    clock_t endProcessorTimeUsed = clock();
    clock_t totalProcessorTimeUsed = endProcessorTimeUsed - initialProcessorTimeUsed;
    cout <<  "Tempo de processamento: " << totalProcessorTimeUsed << " nanoseconds\n";
}