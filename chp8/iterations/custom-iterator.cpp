#include <cstdio>

struct Params {
  int start;
  int stop;
  int step;
};

struct ScoreRange {
  ScoreRange(Params params): params { params }, current { params.start } {}

  int operator++() {
    current += params.step;
    return current;
  }

  bool operator!=(const int x)  {
    return x >= current;
  }

  int operator*() const {
    return current;
  }

  ScoreRange& begin() {
    return *this;
  }
  
  int end() {
   return params.stop;;
  }

  private: 
    const Params params;
    int current;
};

int main() {
  Params params {75, 100, 5};
  ScoreRange range { params };
  const auto end = range.end();
  for (auto x = range.begin(); x != end; ++x) {
    const auto i = *x;
    printf("%d ", i);
  }
}

/**
 Output:
   75 80 85 90 95 100 

*/