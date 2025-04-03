# Scaling and Performance Profiling of iPIC3D on Dardel

This repository contains a course project conducted as part of **DD2356 – Methods in High Performance Computing** at KTH Royal Institute of Technology, Spring 2023.

The project evaluates the scalability and performance characteristics of the [iPIC3D](https://github.com/KTH-HPC/iPIC3D) particle-in-cell simulation code, executed on the **Dardel** supercomputer (NAISS Tier-1). The analysis combines scaling experiments, performance profiling, and system-level observations to identify bottlenecks and suggest improvements.

---

## 📁 Main Project Directory

👉 The main content of this work is in the [`project/`](./project) folder. It includes:

- Our **final report** (PDF), summarizing all experiments, results, and conclusions
- Strong and weak scaling experiments using up to 1024 MPI processes
- Performance profiling using CrayPat
- Comparison between **Cray MPICH** and **OpenMPI**
- Analysis of MPI communication overhead and I/O-related runtime imbalance
- Discussion of potential improvements based on observed performance behavior

Other folders in this repo are minor lab assignments from the same course and are not part of this project.

---

## 🧑‍💻 My Role

This fork is maintained to showcase my contributions to the project. I was primarily responsible for:

- **MPI and I/O performance analysis**
- Interpreting CrayPat profiling data
- Identifying communication bottlenecks and runtime imbalance
- Writing and compiling results into the final report
- Running and managing experiments on the **Dardel** cluster

---

## ⚙️ Tools & Environment

- Platform: **Dardel** (KTH/NAISS Tier-1 HPC system)
- Job scheduler: `Slurm`
- Profiling tools: `CrayPat`, `Cray Apprentice2`
- MPI implementations: Cray MPICH and OpenMPI
- Batch runs: 1–8 nodes, 64–1024 processes

---

## 🔗 Original Repository

This fork originates from the group submission repository:  
https://github.com/perttuj/dd2356-high-performance-computing  
Modifications here are solely for personal presentation purposes.

---

## 📄 Report

For detailed methods, results, and conclusions, see: [`project/Project_Report.pdf`](./project/Project_Report.pdf)
