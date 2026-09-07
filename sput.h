#ifndef SPUT_H
#define SPUT_H
#include <stdio.h>
#include <math.h>

static int sput_checks = 0;
static int sput_failed = 0;

#define sput_start_testing() do { sput_checks = 0; sput_failed = 0; printf("Starting tests...\n"); } while(0)
#define sput_enter_suite(name) do { printf("\nSuite: %s\n", name); } while(0)
#define sput_run_test(fn) do { printf("- %s\n", #fn); fn(); } while(0)
#define sput_fail_unless(cond, msg) do { \
    sput_checks++; \
    if (cond) printf("  [OK] %s\n", msg); \
    else { printf("  [FAILED] %s\n", msg); sput_failed++; } \
} while(0)
#define sput_leave_suite() do { } while(0)
#define sput_finish_testing() do { \
    printf("\n%d check(s), %d ok, %d failed (%.2f%%)\n", \
           sput_checks, sput_checks - sput_failed, sput_failed, \
           sput_checks ? (100.0 * sput_failed / sput_checks) : 0.0); \
} while(0)

static int close_enough(double a, double b) { return fabs(a - b) < 0.0001; }

#endif
