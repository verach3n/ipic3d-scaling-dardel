#!/bin/sh -l
#SBATCH -J 1024_DD2356_proj
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=128
#SBATCH --nodes=8
#SBATCH -e error_file_1024.e
srun ./iPIC3D ../inputfiles/testGEM3Dsmall_1024.inp > 1024.out