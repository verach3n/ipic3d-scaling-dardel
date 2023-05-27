#!/bin/sh -l
#SBATCH -J 512_DD2356_proj
#SBATCH -t 00:10:00
#SBATCH -A edu23.DD2356
# Number of nodes
#SBATCH -p main
#SBATCH --ntasks-per-node=128
#SBATCH --nodes=4
#SBATCH -e error_file_512.e
srun ./iPIC3D ../inputfiles/testGEM3Dsmall_512.inp > 512.out