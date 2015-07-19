#include <stdint.h>
#include <stdio.h>
#include "file.h"

int dummy_function(void)
{
  static int a = 0;
  a++;
  return a;
}

int main(void)
{
  uint16_t counter1 = 0, counter2 = 0, counter3 = 0;
  uint16_t value;

  printf("\nProgram start!\n");
  printf("counter1: %d\n", counter1);
  while (counter1 < 5)
  {
    counter2++;
    if (counter2 >= 60000)
    {
      counter2 = 0;
      counter3++;
      if (counter3 >= 10000)
      {
        counter3 = 0;
        counter1++;
        printf("counter1: %d\n", counter1);

        value = from_file(counter1, counter1);
        printf("Double counter 1: %d\n", value);

        dummy_function();
      }
    }
  }
  printf("Program end!\n");
  return 0;
}
