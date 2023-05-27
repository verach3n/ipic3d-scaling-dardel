#!/bin/sh -l
#SBATCH -J DD2356_proj_128
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=128
#SBATCH --nodes=1
#SBATCH -e error_file_128.e
srun ./iPIC3D ../inputfiles/testGEM3Dsmall.inp > 128.out