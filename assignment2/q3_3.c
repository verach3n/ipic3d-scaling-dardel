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

double omp_sum(double *x, size_t size)
{
    double sum_val = 0.0;
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++)
    {
        sum_val += x[i];
    }
    return sum_val;
}

double omp_critical_sum(double *x, size_t size)
{
    double sum_val = 0.0;
    #pragma omp parallel for
    for (size_t i = 0; i < size; i++)
    {
        #pragma omp critical
        {
            sum_val += x[i];
        }
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
    int threads[] = {1, 2, 4, 8, 16, 20, 24, 28, 32};

    for(j = 0; j < 9; j++){
        omp_set_num_threads(threads[j]);
        for(i = 0; i < 10; i++){
            start_time = omp_get_wtime();
            sum_val = omp_critical_sum(str, SIZE);
            run_time[i] = omp_get_wtime() - start_time;

            sum_time += run_time[i];
        }
        double mean = sum_time / 10;

        for(i = 0; i < 10; i++){
            variance += pow(run_time[i] - mean, 2);
        }
        variance /= 10;
        SD = sqrt(variance);

        printf("Critical \n");
        printf("Thread: %d \n", threads[j]);
        printf("Standard Deviation of Run time: %f \n", SD);
        printf("Average Run time: %f \n", mean);
        printf("**********************\n");
    }

    printf("-----------------------------------------\n");

   for(j = 0; j < 9; j++){
        omp_set_num_threads(threads[j]);
        for(i = 0; i < 10; i++){
            start_time = omp_get_wtime();
            sum_val = omp_sum(str, SIZE);
            run_time[i] = omp_get_wtime() - start_time;

            sum_time += run_time[i];
        }
        double mean = sum_time / 10;

        for(i = 0; i < 10; i++){
            variance += pow(run_time[i] - mean, 2);
        }
        variance /= 10;
        SD = sqrt(variance);

        printf("Parallel \n");
        printf("Thread: %d \n", threads[j]);
        printf("Standard Deviation of Run time: %f \n", SD);
        printf("Average Run time: %f \n", mean);
        printf("**********************\n");
    }
    return 0;
}