#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <climits>
using std::string;

/**
 * Read a string from the user
 *
 * @param prompt the message to show the user
 * @returns the string entered
 */
string read_string(string prompt);

/**
 * Read an integer from the user
 *
 * @param prompt the message to show the user
 * @returns the integer entered
 */
int read_integer(string prompt, int min_value = INT_MIN, int max_value = INT_MAX);

bool read_bool(string prompt);

/**
 * Read a double from the user
 *
 * @param prompt the message to show the user
 * @returns the double entered
 */
double read_double(string prompt);

#endif