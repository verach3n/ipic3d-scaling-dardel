#!/bin/sh -l
#SBATCH -J 128_DD2356_proj
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=128
#SBATCH --nodes=1
#SBATCH -e error_file_128.e
srun -n 128 ./iPIC3D ../inputfiles/128weak.inp > 128_weak.out

