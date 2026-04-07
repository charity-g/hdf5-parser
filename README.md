# hdf5 parser

HDF5 is a recursive file format, used to compress and organize large amounts of data, especially for research.

## Goals:

- Learn the structure of HDF5 file formats
- Use the C language in a recursive manner to parse HDF5
- Handle Parse both UTF-8 and ASCII 
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

### SUBGOAL 1

MVP of HDF5 parser:

- Read Superblock
- Read object headers
- Leaves and branches OOP system
- Navigate file system

Example dataset taken from `@sushanttwayana` on [kaggle](https://www.kaggle.com/datasets/sushanttwayana/birds-final-dataset-hdf5?resource=download-directory)
