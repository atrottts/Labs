/* stats.h - statistics on an array of voltages. Do not edit.
   Both functions need n >= 1. Neither prints anything. */
#ifndef STATS_H
#define STATS_H

/* Returns the mean of v[0..n-1]. */
double mean_of(double v[], int n);

/* Returns the index of the first value below limit, or -1 if none is. */
int first_below(double v[], int n, double limit);

#endif
