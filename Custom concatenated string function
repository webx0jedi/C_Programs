#include "exercise.h"
#include <stdio.h>

void concat_strings(char *str1, const char *str2) {
  //loop for finding "\0"
  int i = 0;
  while (str1[i] != '\0'){
    i++;
  }
  //new loop that appends characters together
  int j = 0;
  while (str2[j] != '\0'){
    str1[i++] = str2[j++];
  }
  str1[i] = '\0'; //terminates concatenated string
}
