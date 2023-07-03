# Create ply file
## Requirements
 - g++ (tested 11.3.0) 
 - CMake 3.2 (tested 3.27.20230614-g12518c7)
 - Point Cloud Library 1.2 (tested 1.12.1+dfsg-3build1)
 - Boost (tested 1.81.0)

## Installation
```linux
$ cmake .
$ make
```

## Usage
Linux
```
./cpp_cmake \ 
    -n=file_name \
    -p=point_num \
    -w=width_size # x,y,z are common \
    -c # if need color \
    -x=x_width \
    -y=y_width \
    -z=z_width
```
ez
```
./runme.sh (file_name)
```
