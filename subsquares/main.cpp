#include "subsquares.h"
#include <iostream>

using namespace std;
using namespace n4n;

// --------------- Application ---------------

int main(int argc, char** argv)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 0, 0, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);
    if (found) {
        cout << "Found subsquare in matrix\n";
        cout << "x: " << result.column << "\n";
        cout << "y: " << result.row << "\n";
        cout << "size: " << result.size << "\n";
    } else {
        cout << "Did not find any subsquares in matrix\n";
    }

    return 0;
}
