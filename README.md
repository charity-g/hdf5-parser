# hdf5 parser

HDF5 is a recursive file format, used to compress and organize large amounts of data, especially for research.

## Goals:

- Following Beej's guide: https://beej.us/guide/bgc/html/
- Learn the structure of HDF5 file formats
- Handle Parse both UTF-8 and ASCII 
- Use the C language in a recursive manner to parse HDF5
- Implement a B+ Tree to index table objects
- Learn how to write unit tests in C
- Learn how to benchmark my own custom parsers against hdf5 C API

### SUBGOAL 0

HDF5 files

Taken from wikipedia, there are two primary items in an HDF5 file:
```
- Datasets, which are typed multidimensional arrays
- Groups, which are container structures that can hold datasets and other groups
```

Components 
- Superblock
- Object headers
- Groups + datasets (basic)
- B-tree (symbol table or chunk index)

General setup for tools:
- Use python `h5py` to generate minimal files 
- Use `h5dump` to view these files for debugging purposes

Superblock header should include information:
- about hdf5 file version
- Contain a header: `\x89HDF\r\n\x1a\n`

### SUBGOAL 1


ascii + utf8
- read C files in a variety of different ways
- Read C files as bytes
- Read C files in ASCII
- Read C files in UTF8
- On-the-fly figure out if file is ascii or utf-8 encoded
- Read dynamically

`gcc -o parser main.c errorUtils.c errorUtils.h`
`gcc -g playground.c -o playground.exe`

### SUBGOAL 2

MVP of HDF5 parser:
- Read File as Superblock
- Leaves and branches OOP system
- Read object headers, attributes etc
- Navigate file system

### SUBGOAL 3

- purely theoretical level of separatin between disk and memory
    - implement b tree
    - implement b+ tree
- actually using disk and memory
    - understanding file streams, and allocation of memory

## Developer

1) Fork this repository
2) Generate and/or download example h5 data
    - Generate h5 data through python
    - Example complex h5 dataset taken from `@sushanttwayana` on [kaggle](https://www.kaggle.com/datasets/sushanttwayana/birds-final-dataset-hdf5?resource=download-directory)
3) Implement the subgoals
4) benchmark compare to mine and official HDF5 C API
 
How to run the C code for parsing:
- Compile C function
    - requires compiler installe, ie: gcc
    - `gcc main.c -o main`
- Run compiled object file with command line argument


# Learning C
https://pynative.com/c-programming-exercises/
- basic https://pynative.com/c-programming-exercises-for-beginners/

