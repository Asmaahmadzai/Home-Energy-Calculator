#include <stdio.h>
#include "sput.h"
#include "declarations.h"

void test_monthly_energy(void) {
    sput_fail_unless(close_enough(calculate_monthly_energy(1000.0, 1.0), 30.0),
                     "1000 W for 1 hour/day = 30.00 kWh/month");
    sput_fail_unless(close_enough(calculate_monthly_energy(120.0, 5.0), 18.0),
                     "120 W for 5 hours/day = 18.00 kWh/month");
    sput_fail_unless(close_enough(calculate_monthly_energy(300.0, 8.0), 72.0),
                     "300 W for 8 hours/day = 72.00 kWh/month");
    sput_fail_unless(close_enough(calculate_monthly_energy(1000.0, 0.5), 15.0),
                     "1000 W for 0.5 hours/day = 15.00 kWh/month");
}

void test_monthly_cost(void) {
    sput_fail_unless(close_enough(calculate_monthly_cost(30.0), 4.50),
                     "30.00 kWh costs $4.50");
    sput_fail_unless(close_enough(calculate_monthly_cost(18.0), 2.70),
                     "18.00 kWh costs $2.70");
    sput_fail_unless(close_enough(calculate_monthly_cost(72.0), 10.80),
                     "72.00 kWh costs $10.80");
    sput_fail_unless(close_enough(calculate_monthly_cost(0.0), 0.0),
                     "0.00 kWh costs $0.00");
}

void test_fill_cost_array_and_total(void) {
    double power[3] = {120.0, 300.0, 1000.0};
    double hours[3] = {5.0, 8.0, 0.5};
    double costs[3] = {0.0, 0.0, 0.0};

    fill_cost_array(3, power, hours, costs);

    sput_fail_unless(close_enough(costs[0], 2.70), "Appliance 1 monthly cost is $2.70");
    sput_fail_unless(close_enough(costs[1], 10.80), "Appliance 2 monthly cost is $10.80");
    sput_fail_unless(close_enough(costs[2], 2.25), "Appliance 3 monthly cost is $2.25");
    sput_fail_unless(close_enough(calculate_total_cost(3, costs), 15.75),
                     "Total monthly cost is $15.75");
}

void test_highest_cost_index(void) {
    double costs[4] = {2.70, 10.80, 2.25, 8.00};
    sput_fail_unless(find_highest_cost(4, costs) == 1,
                     "find_highest_cost returns 0-based index 1 for the highest cost");
}

void test_dynamic_memory_helpers(void) {
    double *power = create_array(5);
    double *hours = create_array(5);
    double *costs = create_array(5);

    sput_fail_unless(power != NULL, "power array allocated successfully");
    sput_fail_unless(hours != NULL, "hours array allocated successfully");
    sput_fail_unless(costs != NULL, "costs array allocated successfully");
    sput_fail_unless(power != hours && power != costs && hours != costs,
                     "each create_array call returns a different memory block");

    if (power != NULL && hours != NULL && costs != NULL) {
        for (int i = 0; i < 5; i++) {
            power[i] = 100.0 + i;
            hours[i] = 1.0 + i;
            costs[i] = 0.0;
        }
        fill_cost_array(5, power, hours, costs);
        sput_fail_unless(costs[0] > 0.0 && costs[4] > 0.0,
                         "dynamically allocated arrays are writable and usable");
    }
    double temp1 = *power;
    double temp2 = *hours;
    double temp3 = *costs;
    free_array(power);
    free_array(hours);
    free_array(costs);

    sput_fail_unless(*power != temp1,"power pointer was freed");
    sput_fail_unless(*hours != temp2,"hours pointer was freed");
    sput_fail_unless(*costs != temp3,"costs pointer was freed");
}

int main(void) {
    sput_start_testing();
    sput_enter_suite("A02 Public Student Tests");

    sput_run_test(test_monthly_energy);
    sput_run_test(test_monthly_cost);
    sput_run_test(test_fill_cost_array_and_total);
    sput_run_test(test_highest_cost_index);
    sput_run_test(test_dynamic_memory_helpers);

    sput_leave_suite();
    sput_finish_testing();
    return 0;
}
