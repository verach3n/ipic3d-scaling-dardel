#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 10000000

static double str[SIZE];

void generate_random(double *input, size_t size)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        input[i] = rand() / (double)(RAND_MAX);
    }
}

double serial_sum(double *x, size_t size)
{
  double sum_val = 0.0;

  for (size_t i = 0; i < SIZE; i++) {
    sum_val += x[i];
  }

  return sum_val;
}

int main(int argc, char *argv[]) {

    int i;
	double sum_val = 0.0;
    double sum_time = 0.0;
    double variance = 0.0;
    double SD;
	double start_time;

	generate_random(str, SIZE);

	double run_time[50];

    for(i = 0; i < 50; i++){
        start_time = omp_get_wtime();
        sum_val = serial_sum(str, SIZE);
        run_time[i] = omp_get_wtime() - start_time;

        sum_time += run_time[i];
    }
    double mean = sum_time / 50;

    for(i = 0; i < 50; i++){
        variance += pow(run_time[i] - mean, 2);
    }
    variance /= 50;
    SD = sqrt(variance);

	printf("Standard Deviation of Run time: %f \n", SD);
	printf("Average Run time: %f \n", sum_time / 50);
    return 0;
}