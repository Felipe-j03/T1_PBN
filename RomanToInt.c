#include <stdio.h>
#include <string.h> 

int c2i(char c){
  switch (c)
  {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X': 
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}


int romanToInt(char *s) {

  if (!s)
    return 0;

  // I = 1
  // V = 5
  // X = 10
  // L = 50
  // C = 100
  // D = 500
  // M = 1000

  int result = 0;
  char *p = s;
  char *p2 = *p++;
  char c2;
  char c;
  
  while((c = *p++) != '\0'){

    int currentValue = c2i(c);
    int nextValue = 0;

    if ((c2 = *p2++) != '\0') {
      nextValue = c2i(c2);
    }
    if (nextValue > currentValue) {
      result += nextValue - currentValue;
    } else {
      result += currentValue;
    }
  }
  return result;
}