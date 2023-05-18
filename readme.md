# Cpp-in-Python

[![Python application](https://github.com/SajjadAemmi/Cpp-in-Python/actions/workflows/python-app.yml/badge.svg)](https://github.com/SajjadAemmi/Cpp-in-Python/actions/workflows/python-app.yml)

Run a C++ library in a Python script using ctypes

## installation
Install opencv (linux ubuntu)
```
sudo apt install libopencv-dev
```

## Build 
Compile C++ code to make `libsajjad.so` file in build directory using cmake or g++

### build using cmake
```
cmake -S . -B build
cmake --build build
```

### build using g++
```
mkdir build

# for compile library
g++ -fpic -shared sajjad.cpp -o build/libsajjad.so `pkg-config --libs --cflags opencv4`

# for compile app
g++ main.cpp -o build/myapp `pkg-config --libs --cflags opencv4`
```

## Run
Make sure C++ code compiled successfully via run the application
```
./build/myapp
```

Finally ask Python to use compiled C++ library
```
python run.py
```
