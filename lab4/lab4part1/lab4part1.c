/* lab4part1.c - Gear train table.
   main and print_rule are given. Write the other three functions
   at the bottom of this file. Do not change main. */
#include <stdio.h>

#define DRIVER_TEETH 15
#define DRIVEN_TEETH 36
#define INPUT_RPM    1800.0
#define MAX_STAGES   4
#define RULE_WIDTH   33

double gear_ratio(int driver, int driven);
double stage_power(double ratio, int stages);
double output_rpm(double input_rpm, double total_ratio);
void print_rule(int width);

int main(void)
{
    double ratio = gear_ratio(DRIVER_TEETH, DRIVEN_TEETH);

    printf("Gear train: %d-tooth driver, %d-tooth driven\n",
           DRIVER_TEETH, DRIVEN_TEETH);
    printf("Ratio per stage: %.2f\n", ratio);
    print_rule(RULE_WIDTH);
    printf("Stages   Total ratio   Output rpm\n");
    print_rule(RULE_WIDTH);
    for (int s = 0; s <= MAX_STAGES; s++) {
        double total = stage_power(ratio, s);
        printf("%6d %13.2f %12.2f\n", s, total, output_rpm(INPUT_RPM, total));
    }
    print_rule(RULE_WIDTH);
    return 0;
}

/* Given: prints width dashes, then a newline. */
void print_rule(int width)
{
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

/* ---- Write gear_ratio, stage_power and output_rpm below this line ---- */
double gear_ratio(int driver, int driven) {
    return (double)driven/driver;
}

double stage_power(double ratio, int stages) {
    if (stages <= 0) {
        return 1.0;
    }
    return ratio * stage_power(ratio, stages - 1);
}

double output_rpm(double input_rpm, double total_ratio) {
    return input_rpm/total_ratio;
}