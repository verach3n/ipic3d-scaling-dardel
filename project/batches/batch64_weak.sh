#!/bin/sh -l
#SBATCH -J 64_DD2356_proj
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=64
#SBATCH --nodes=1
#SBATCH -e error_file_64.e
srun -n 64 ./iPIC3D ../inputfiles/64weak.inp > 64_weak.out
