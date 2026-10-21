/* lab4part2.c - Bolt torque check.
   main and print_readings are given. Write the other three functions
   at the bottom of this file. Do not change main. */
#include <stdio.h>

#define CAP     10
#define SPEC_LO 40
#define SPEC_HI 50

int read_readings(int a[], int cap);
void print_readings(int a[], int n);
int count_out_of_spec(int a[], int n, int lo, int hi);
int find_value(int a[], int n, int target);

int main(void)
{
    int torque[CAP];
    int target;

    printf("Enter up to %d torque readings in N.m (-1 to stop):\n", CAP);
    int n = read_readings(torque, CAP);
    if (n == 0) {
        printf("No data.\n");
        return 1;
    }

    print_readings(torque, n);
    printf("Out of spec (%d-%d N.m): %d\n", SPEC_LO, SPEC_HI,
           count_out_of_spec(torque, n, SPEC_LO, SPEC_HI));

    printf("Search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Error: invalid input.\n");
        return 1;
    }
    int where = find_value(torque, n, target);
    if (where < 0) {
        printf("%d not found.\n", target);
    } else {
        printf("%d found at index %d.\n", target, where);
    }
    return 0;
}

/* Given: prints "Readings (n):" and each value. */
void print_readings(int a[], int n)
{
    printf("Readings (%d):", n);
    for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

/* ---- Write read_readings, count_out_of_spec and find_value below this line ---- */
int read_readings(int a[], int cap) {
    int count = 0;
    int value;
    while (count < cap && scanf("%d", &value) == 1) {
        if (value == -1) {
            break;
        }
        a[count] = value;
        count++;
    }
    return count;
}

int count_out_of_spec(int a[], int n, int lo, int hi){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < lo || a[i] > hi) {
            count++;
        }
    }
    return count;
}

int find_value(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
}
