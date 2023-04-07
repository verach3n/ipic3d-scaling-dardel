#define N 5000
#include <stdio.h>
#include <sys/time.h>

double mysecond();

int main(){
  int i, j;
  double t1, t2; // timers                                                         
  double a[N], b[N], c[N]; // arrays  
  const int n = 5000;
  double scalar = 1.0;
  const int outer_loops = 10;
  // warm up the cache
  for (int i = 0; i < n; i++) {
      a[i] = (double)i;
      b[i] = (double)i;
      c[i] = 0.0;
  }                          
  // init arrays                                                                   
  for (i = 0; i < N; i++){
    a[i] = 47.0;
    b[i] = 3.1415;
  }

  // measure perfomance
  double total_time = 0.0;
  for (int j = 0; j < outer_loops; j++) {
      double start_time = mysecond();
      for (int i = 0; i < n; i++) {
          c[i] += a[i] * b[i] * scalar;
      }
      total_time += mysecond() - start_time;
  }

  // Print results
  double avg_time = total_time / outer_loops;
  printf("Minimum execution time: %f s\n", avg_time);
  printf("Average execution time: %f s\n", avg_time);
  return 0;
}

// function with timer                                                             
double mysecond(){
  struct timeval tp;
  struct timezone tzp;
  int i;

  i = gettimeofday(&tp,&tzp);
  return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}