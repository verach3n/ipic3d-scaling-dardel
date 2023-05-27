#!/bin/sh -l
#SBATCH -J 256_DD2356_proj
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=128
#SBATCH --nodes=2
#SBATCH -e error_file_256.e
srun -n 256 ./iPIC3D ../inputfiles/testGEM3Dsmall_256.inp > 256.out