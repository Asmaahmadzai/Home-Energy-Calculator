#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "declarations.h"
/*
 * SYSC1006 - Assignment 02
 * Home Energy Usage Calculator
 * Student Name: Asma Ahmadzai
 * Student ID: 101333739
 */
double get_budget(void) {
    double budget;
    printf("Enter your monthly electricity budget: ");
    scanf("%lf", &budget);
    return budget;
}
int get_num_appliances(void) {
    int n;
    printf("Enter the number of appliances: ");
    scanf("%d", &n);
    return n;
}
double* create_array(int size) {
    double *array = (double *) malloc(size * sizeof(double));
    assert(array != NULL);
    return array;
}
void input_appliance_data(int n, double *power, double *hours) {
    for (int i = 0; i < n; i++) {
        printf("Appliance %d\n", i + 1);
        printf("Enter power rating (Watts): ");
        scanf("%lf", &power[i]);
        if (power[i] <= 0) {
            printf("Invalid power rating\n");
            power[i] = 0;
        }
        printf("Enter hours used per day: ");
        scanf("%lf", &hours[i]);
        if (hours[i] < 0 || hours[i] > 24) {
            printf("Invalid hours used\n");
            hours[i] = 0;
        }
    }
}
double calculate_monthly_energy(double watts, double hours_per_day) {
    double daily_energy;
    double monthly_energy;
    daily_energy = (watts * hours_per_day) / 1000.0;
    monthly_energy = daily_energy * DAYS_IN_MONTH;
    return monthly_energy;
}
double calculate_monthly_cost(double monthly_energy) {
    return monthly_energy * ELECTRICITY_RATE;
}
void fill_cost_array(int n,
                     const double *power,
                     const double *hours,
                     double *costs) {
    for (int i = 0; i < n; i++) {
        double monthly_energy =
                calculate_monthly_energy(power[i], hours[i]);
        costs[i] = calculate_monthly_cost(monthly_energy);
    }
}
double calculate_total_cost(int n, const double *costs) {
    double total = 0;

    for (int i = 0; i < n; i++) {
        total += costs[i];
    }
    return total;
}
int find_highest_cost(int n, const double *costs) {
    int highest_index = 0;

    for (int i = 1; i < n; i++) {
        if (costs[i] > costs[highest_index]) {
            highest_index = i;
        }
    }
    return highest_index;
}
void print_report(int n,
                  const double *power,
                  const double *hours,
                  const double *costs,
                  double budget) {
    double total_cost = calculate_total_cost(n, costs);
    int highest = find_highest_cost(n, costs);
    printf("\nMonthly Energy Report\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Appliance %d\n", i + 1);
        printf(" Power Rating: %.2f W\n", power[i]);
        printf(" Hours/Day: %.2f\n", hours[i]);
        printf(" Monthly Cost: $%.2f\n", costs[i]);
    }
    printf("-----------------------------------------------\n");
    printf("Total Monthly Cost: $%.2f\n", total_cost);
    printf("Budget: $%.2f\n", budget);
    if (total_cost <= budget) {
        printf("Under Budget By: $%.2f\n",
               budget - total_cost);
    } else {
        printf("Over Budget By: $%.2f\n",
               total_cost - budget);
    }
    printf("Highest Cost Appliance: %d\n", highest + 1);
    printf("-----------------------------------------------\n");
}
void free_array(double *array) {
    free(array);
}
