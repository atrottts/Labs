/* readings.h - reading and printing cell voltages. Do not edit. */
#ifndef READINGS_H
#define READINGS_H

#define MAX_CELLS 12

/* Reads voltages from the keyboard into v[] until the user types -1,
   types something that is not a number, or cap values are stored.
   Returns the number of values stored. */
int read_voltages(double v[], int cap);

/* Prints one line per cell, numbered from 1:  "Cell  1: 3.71 V" */
void print_voltages(double v[], int n);

#endif
