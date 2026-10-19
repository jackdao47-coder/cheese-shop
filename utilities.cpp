#include "utilities.h"
#include "splashkit.h"

string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

int read_integer(string prompt, int min_value, int max_value)
{
  string line = read_string(prompt);
  while (!is_integer(line))
  {
    write_line("Please enter a whole number.");
    line = read_string(prompt);
  }
  return to_integer(line);
}

double read_double(string prompt)
{
  string line = read_string(prompt);
  while (!is_double(line))
  {
    write_line("Please enter a number.");
    line = read_string(prompt);
  }
  return to_double(line);
}

bool read_bool(string prompt)
{
  string line = read_string(prompt);
  for (char &c : line) c = tolower(c);

  while (line != "true" && line != "false")
  {
    write_line("Please enter true or false.");
    line = read_string(prompt);
    for (char &c : line) c = tolower(c);
  }
  return (line == "true");
}