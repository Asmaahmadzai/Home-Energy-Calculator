#include <stdio.h>
#include "declarations.h"
/*
 * Home Energy Usage Calculator
 */
int main(void) {
    double budget;
    int num_appliances;
    double *power;
    double *hours;
    double *costs;
    printf("Welcome to the Home Energy Usage Calculator\n");
    budget = get_budget();
    if (budget <= 0) {
        printf("Invalid budget\n");
        return 0;
    }
    num_appliances = get_num_appliances();
    if (num_appliances < 1 || num_appliances > 100) {
        printf("Invalid number of appliances\n");
        return 0;
    }
    power = create_array(num_appliances);
    hours = create_array(num_appliances);
    costs = create_array(num_appliances);
    input_appliance_data(num_appliances, power, hours);
    fill_cost_array(num_appliances,
                    power,
                    hours,
                    costs);
    print_report(num_appliances,
                 power,
                 hours,
                 costs,
                 budget);
    free_array(power);
    free_array(hours);
    free_array(costs);
    power = NULL;
    hours = NULL;
    costs = NULL;
    return 0;
}
