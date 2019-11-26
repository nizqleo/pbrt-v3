# CMake generated Testfile for 
# Source directory: /home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex/src/tests
# Build directory: /home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(wtest "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/wtest")
add_test(rtest "/usr/local/bin/cmake" "-DOUT=/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/rtest.out" "-DDATA=/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex/src/tests/rtestok.dat" "-DCMD=/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/rtest" "-P" "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex/src/tests/compare_test.cmake")
add_test(ftest "/usr/local/bin/cmake" "-DOUT=/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/ftest.out" "-DDATA=/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex/src/tests/ftestok.dat" "-DCMD=/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/ftest" "-P" "/home/nizq/Downloads/computer graphic/pbrt-v3/src/ext/ptex/src/tests/compare_test.cmake")
add_test(halftest "/home/nizq/Downloads/computer graphic/pbrt-v3/build/src/ext/ptex/src/tests/halftest")
