# Home Energy Calculator
A C program that calculates monthly household electricity usage and estimated electricity costs for multiple appliances.

## Features
* Calculates monthly energy consumption in kWh
* Calculates monthly electricity cost per appliance
* Calculates total monthly household electricity cost
* Compares total cost against a user-defined budget
* Identifies the appliance with the highest monthly cost
* Validates appliance count, budget, power rating, and hours used
* Uses dynamic memory allocation with `malloc()` and `free()`
* Uses arrays, pointers, loops, and modular functions

## Technologies
* C
* CMake
* CLion

## Example
For appliances such as:
* TV: 120 W for 5 hours/day
* Computer: 300 W for 8 hours/day
* Microwave: 1000 W for 0.5 hours/day
The program calculates a total monthly electricity cost of:
`$15.75`
