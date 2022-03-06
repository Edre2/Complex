# Complex

This is an implementation of a class to handle complex numbers in `c++`. \
There are also a `mandelbrot.cpp` and `julia.cpp` file, which can draw two sets of complex numbers. Thhis graphics are made withe the `olcPixelGameEngine` made by @OneLoneCoder.

# How to use it

You can read `main.cpp` to get howthe class works. \
For the other files, you can run `mandelbrot` or `julia` on GNU/Linux, or compile them with the commands :
``` bash
g++ -o julia complex.cpp julia.cpp -std=c++17 -lX11 -lGL -lpthread -lpng -lstdc++fs && ./julia
g++ -o mandelbrot complex.cpp mandelbrot.cpp -std=c++17 -lX11 -lGL -lpthread -lpng -lstdc++fs && ./mandelbrot
```
For the julia set, you can change the value of `c` at the top of the `julia.cpp` file, and see how the set hanges (I recommend you to take the values entered).

# License

The `olcPixelGameEngine` is published under the `OLC-3` license (see in the file itself).
The rest of the code is published under the `GPL v3`.