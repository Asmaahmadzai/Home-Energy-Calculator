#ifndef DECLARATIONS_H
#define DECLARATIONS_H

/*
 * Home Energy Usage Calculator
 */

#define DAYS_IN_MONTH 30
#define ELECTRICITY_RATE 0.15

double get_budget(void);
int get_num_appliances(void);
double* create_array(int size);
void input_appliance_data(int n, double *power, double *hours);
double calculate_monthly_energy(double watts, double hours_per_day);
double calculate_monthly_cost(double monthly_energy);
void fill_cost_array(int n, const double *power, const double *hours, double *costs);
double calculate_total_cost(int n, const double *costs);
int find_highest_cost(int n, const double *costs);
void print_report(int n, const double *power, const double *hours, const double *costs, double budget);
void free_array(double *array);

#endif
