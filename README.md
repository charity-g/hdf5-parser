# hdf5 parser

HDF5 is a recursive file format.

Taken from wikipedia, there are two primary items in an HDF5 file:
"
- Datasets, which are typed multidimensional arrays
- Groups, which are container structures that can hold datasets and other groups
"

## Goals:

- Use the C language in a recursive manner to parse HDF5
- Learn the structure of HDF5 file formats
- Implement a B+ Tree to index table objects
- Handle Parse both UTF-8 and ASCII 
- Learn how to write unit tests in C
- Learn how to benchmark parsers properly