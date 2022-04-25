# Find Subsquares in a Two-Dimensional Matrix

This small project is a code exercise I was asked during an interview.

### Use clang-format to format code

    clang-format -i <files>

### Running clang-tidy - a static analysis tool

    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=Yes ..
    make -j8
    run-clang-tidy -header-filter='.*'
