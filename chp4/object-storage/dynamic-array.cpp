#include <cstdio>

void printArray(int* scores, size_t size) {
  for (size_t i=0; i < size; i++) {
    printf("%d ", scores[i]);
  }
  printf("\n");
}

int main() {
    int* counts = new int[10];

    size_t scoreLen { 5 };
    int* scores = new int[scoreLen] { 87, 95, 64 };

    printArray(scores, scoreLen); // 87 95 64 0 0 
    printArray(counts, 10);       // 6920856 6881472 838860850 30097 6920856 6881472 1701011824 1882014556 762541420 1937075312

    delete[] counts;
    delete[] scores;
    printArray(scores, scoreLen); // 87 95 64 0 0
    printArray(counts, 10);       // 6920856 6881472 838860850 30097 6920856 6881472 1701011824 1882014556 762541420 1937075312

}

/**
 You must make sure that dynamic objects you allocate are also deallocated. Failure to do so causes memory leaks 
 in which memory that is no longer needed by your program isn't released.   
*/ 
