## Build and Execution
- `nmake exec_windows`  (windows)
    - internal build: `clang -I -c prog1.c -emit-llvm -o build/prog1.bc`
        - clang -> compiler from https://clang.llvm.org/docs/index.html
        - -I C:\"Program Files (x86)"\"Windows Kits"\10\Include\10.0.18362.0\ucrt -> add directory to include search path 
        - -emit-llvm -> Use the LLVM representation for assembler and object files
        - -o fileName -> Write output to a file 
- `make exec_linux`  (linux)