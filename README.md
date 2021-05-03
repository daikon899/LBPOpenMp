This repository contains an implementation of [Local Binary Pattern algorithm](https://en.wikipedia.org/wiki/Local_binary_patterns) in OpenMP.

## Run
To execute the code you need to:
1. Create a folder named "input"
2. Insert an image inside input folder
3. Compile and execute the program specifying the image name like
```
LBPSequential img.jpg
```
At the end of the run an output folder with histogram will be generated.

This implementation of k-means algorithm is intended for execution time comparison wrt 
[squential C++ version](https://github.com/MarcoSolarino/LBPSequential/tree/master) and 
[CUDA version](https://github.com/daikon899/LBP_CUDA)
