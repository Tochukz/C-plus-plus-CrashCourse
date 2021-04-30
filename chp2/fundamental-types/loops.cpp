#include <cstdio>
#include <cstddef>

using namespace std;

int main() {
  int scores[] = {92, 78, 85, 69, 95};
  int scoresLength = sizeof(scores) / sizeof(int); // Old way
  char alphabets[27];

  int maximum = 0;
  for (size_t i = 0; i < scoresLength; i++) {
    if (scores[i] > maximum) {
        maximum = scores[i];
    }    
  }  
 
  int minimum = 100;
  // Range based for loop  
  for (int value : scores) {
    if (value < minimum) {
        minimum = value; 
    }
  }

  printf("Array Length = %d \n", scoresLength); // Array Length = 5 
  printf("Maximum Score = %d \n", maximum); // Maximum Score = 95
  printf("Minimum Score = %d \n", minimum); // Minimum Score = 69 

  for(int i=0; i < 26; i++) {
    alphabets[i] = i + 65;
  }
  alphabets[26] = 0;
  printf("%s \n", alphabets); // ABCDEFGHIJKLMNOPQRSTUVWXYZ 

  for (int j=0; j<26; j++) {
    alphabets[j] = j + 97;  
  }
  printf("%s \n", alphabets); // abcdefghijklmnopqrstuvwxyz

}

/**
The array length calculation, sizeof(scores) / sizeof(int),  happens at compile time, so there is no runtime cost in evaluating
the length of an array in this way. 
*/