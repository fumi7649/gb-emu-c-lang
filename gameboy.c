#include <stdio.h>
#include <time.h>

#define CPU_CLOCK_HZ 4194304ULL
#define M_CYCLE_CLOCK 4ULL
#define M_CYCLE_NANOS (M_CYCLE_CLOCK * 1000000000ULL / CPU_CLOCK_HZ)

int main() {
    struct timespec s_time, current_time;
    unsigned long long e;
    unsigned long long elapsed = 0;

    timespec_get(&s_time, TIME_UTC);
    while (1) {
        timespec_get(&current_time, TIME_UTC);
        e = current_time.tv_nsec - s_time.tv_nsec;
        for (int i = 0; i < (e - elapsed) / M_CYCLE_CLOCK; i++) {
            printf("%lld", elapsed);
            elapsed += M_CYCLE_NANOS;
        }
    }
}
