import os
import h5py
import numpy as np
from pathlib import Path

print(Path.cwd())
data_dir = "../example_data"

print(f"Creating directory {data_dir} if it doesn't exist...")
os.makedirs(data_dir, exist_ok=True)
os.chdir(data_dir)

print(Path.cwd())

def generate_minimal_hdf5():
    with h5py.File("minimal.h5", "w") as f:
        f.create_dataset("dset", data=np.array([42], dtype=np.int32))

def generate_minimal_hdf5_with_group():
    with h5py.File("minimal2.h5", "w") as f:
        g = f.create_group("group")
        g.create_dataset("dset", data=[1,2,3])

if __name__ == "__main__":
    generate_minimal_hdf5_with_group()
    