# Find Subsquares in a Two-Dimensional Matrix

### Summary

This small project is a coding exercise I worked on during an
interview. The challenge is to find the largest subsquare within a
matrix, where a 0 is a white dot and a 1 is black dot. Subsquares are
defined by lines comprised of black cells/dots.


### Assumptions

I made a few basic assumptions when reading the problem:

* A square has a 'size', which is the length of either side. Both
  sides must be equal in length because that's the definition of a
  square.
* The search matrix is also square.
* A square cannot have a size smaller than 2. A size of 1 is a "dot",
  not a square.


### Project Features

This project is a completely functional solution to the interview
question I worked on. There's a simple "driver" program, unit tests,
and a library.

This project consists of two different library implementations. I felt
this might demonstrate my ability to contrast and compare different
ways to solve a problem. It seemed like my interviewer may have felt
my approach was unconventional. I include more detail in the next
section.


### Dealing with multi-dimensional arrays

The primary way I see people writing functions to deal with
multi-dimensional arrays is with a function signature as shown
below. This method works, but the size of the array is hard-coded into
the signature.

    bool find_max_subsquare(const int matrix[4][4], square& subsquare)

I had a question that included multi-dimensional arrays earlier in my
interviewing loop. I remember making a mistake with the syntax for the
"C/C++" array, and noticed what looked like the interviewer making a
note of it. As I usually do, I went through the question in detail
after the interview was over. I made sure I could answer it correctly
if someone asked the same question or one like it in the
future. During that exercise, I realized there were benefits to
flatten out the matrix using an approach as shown below.

    bool find_max_subsquare(const int* matrix, const int matrix_size,
                            square& subsquare_out)

The resultant machine code for reading cells in the array performs
similarly in both cases. The width of each row is either hardcoded in
the function signature or provided in the 'matrix_size' variable. The
compiler generates very similar code for each function. The second
implementation allows the author to write a single function to handle
many different matrix sizes. The first approach requires a separate
function definition for each matrix size.

I created two libraries that can be utilized in very similar
manners. However, the second implementation allows me to search input
data of variable size with the same library.


### Optimizations for Subsquare Finding

The solution code must search through each cell of an input
matrix. There are ways to make this faster. Please see comments in the
code for hints about these optimizations. Comments are in the
subsquares.cpp files.

During the interview, we covered optimizations 1 - 3. My interviewer
gave me the first one. Optimization 2 seemed obvious but is as much of
a buffer overflow guard as it is an "optimization". While we talked
about optimization 3, I did not include it in the initial pseudo-code
I wrote.

Optimization 4 is one I came up with while writing the complete
working code. If we've found a subsquare larger than the number of
remaining rows, we can stop looking. I do a similar thing within each
row when we only have a few columns left.

Optimization 5 is something I realized when I was trying to optimize
performance for an empty matrix. It makes testing for subsquares when
there are very few black cells much quicker. The time complexity for
an empty input matrix is O(n).


### Time Complexity

If we read every cell in a two-dimensional array once, the time
complexity is O(n), where 'n' is the number of cells. If the matrix is
4x4, 'n' is 16.

When talking about the time complexity of the subsquare finding
algorithm, my interviewer and I seemed to be on slightly different
pages initially. I initially was thinking through a solution I hoped
could be O(n) by using an algorithm that used a lot of memory. Somehow
we decided that 'n' was the width/height of the array and that's why
it was O(n).

After thinking about it more, though, the algorithm is O(n) because
the naive implementation iterates through each cell at a top-most
level, and then at each cell, it reads through the array to detect
every potential size of a square that could exist at that
location. While we don't read every cell to identify a single
subsquare, the total number of cells to check for all subsquare sizes
is approximately 'n' cells. Thus we read 'n' cells while anchoring
ourselves at each of the 'n' cells. This sequence of events is where
we get O(n*n), or O(n^2).

The optimized solution here is often O(n), depending on the input
data. A matrix with no black cells would normally be a worst-case
scenario for an unoptimized solution, but requires fewer than 'n'
reads using this code. The time complexity is O(n) for that scenario.


### CMake

This project leverages a basic cmake framework. It provides a lot of
functionality for very little work; including accurate dependencies,
easy integration of unit tests, platform portability, and others.

You can exclude the googletest feature, for example, by invoking cmake
as shown below.

    mkdir build
    cd build
    cmake -DCOMPILE_TESTS=no ..
    make -j8

You can run the googletest framework with the following incantation.

    mkdir build
    cd build
    cmake ..
    make -j8
    ctest


### Format The Code Using clang-format

I included a clang-format config file for clang-format version 6. It
makes maintaining a consistent coding style a snap. I use clang-format
for almost every C++ project I do now.

    clang-format -i <files>


### Running clang-tidy - Static Analysis

The clang-tidy tool is a static code analyzer. It catches everything
compling with -Wall does, and much more. I set this up for almost
every C++ project I do now, and ran it for this code to ensure there
weren't any simple bugs.

    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=Yes ..
    make -j8
    run-clang-tidy -header-filter='.*'
