#include "simple_system_common.h"
#include <stdint.h>

// RISC-V CSR register access macros
#define read_csr(reg) ({ uint32_t __tmp; asm volatile ("csrr %0, " #reg : "=r"(__tmp)); __tmp; })

#define N 10  // Number of Fibonacci numbers to generate

void fibonacci(int n) {
    uint32_t a = 0, b = 1, c;
    puthex(a);
    putchar('\n');
    puthex(b);
    putchar('\n');

    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        puthex(c);
        putchar('\n');
    }
}

int main() {
    puts("Fibonacci Sequence (Hex):\n");

    // Start measuring performance counters
    uint32_t start_cycles = read_csr(mcycle);
    uint32_t start_instrs = read_csr(minstret);

    fibonacci(N);

    // Stop measuring
    uint32_t end_cycles = read_csr(mcycle);
    uint32_t end_instrs = read_csr(minstret);

    puts("\nSimulation Statistics");
    puts("=====================\n");

    puts("Executed cycles:  ");
    puthex(end_cycles - start_cycles);
    putchar('\n');

    puts("Instructions Retired: ");
    puthex(end_instrs - start_instrs);
    putchar('\n');

    return 0;
}


