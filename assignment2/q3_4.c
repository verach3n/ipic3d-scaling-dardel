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

double omp_local_sum(double *x, size_t size, int threads)
{
    double local_sum[threads];
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++)
    {
        local_sum[omp_get_thread_num()] += x[i];
    }

    double sum_val = 0.0;
    for (size_t i = 0; i < threads; i++)
    {
        sum_val += local_sum[i];
    }
    return sum_val;
}

int main(int argc, char *argv[]) {

    int i, j;
	double sum_val = 0.0;
    double sum_time = 0.0;
    double variance = 0.0;
    double SD;
	double start_time;
	generate_random(str, SIZE);
	double run_time[10];
    int threads[] = {1, 32, 64, 128};

    for(j = 0; j < 4; j++){
        omp_set_num_threads(threads[j]);
        for(i = 0; i < 50; i++){
            start_time = omp_get_wtime();
            sum_val = omp_local_sum(str, SIZE, threads[j]);
            run_time[i] = omp_get_wtime() - start_time;

            sum_time += run_time[i];
        }
        double mean = sum_time / 50;

        for(i = 0; i < 50; i++){
            variance += pow(run_time[i] - mean, 2);
        }
        variance /= 50;
        SD = sqrt(variance);

        printf("Thread: %d \n", threads[j]);
        printf("Standard Deviation of Run time: %f \n", SD);
        printf("Average Run time: %f \n", mean);
        printf("**********************\n");
    }

    return 0;
}