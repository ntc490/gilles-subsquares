#include "subsquares.h"
#include <algorithm>

namespace n4n {

// --------------- Helper Prototypes ---------------

static bool check_all_possible_squares(const matrix_t& matrix,
                                       int min_required_size,
                                       square& subsquare_out);
static bool is_square(const matrix_t& matrix, const square& s,
                      int& longest_side);
static int read_matrix(const matrix_t& matrix, int row, int column);

// --------------- API Functions ---------------

// Given 'matrix' comprised of 0 or 1 values, 0 = white and 1 = black, find the
// largest subsquare defined by a black outline and return it in
// 'subsquare_out'. Return value is true if found, or false if no subsquares
// found. subsquare_out.size will be set to 0 when no subsquares are found.
//
// CAVEAT: 'subsquare_out.size' will always be modified by this function.
bool find_max_subsquare(const matrix_t& matrix, square& subsquare_out)
{
    // Start by signalling an invalid square
    subsquare_out.size = 0;

    for (int row = 0; row < matrix.size; row++) {
        // OPTIMIZATION4: Stop checking if we don't have enough rows
        // left for something bigger than what we already found
        int max_possible_height = matrix.size - row;
        if (max_possible_height < subsquare_out.size) {
            break;
        }

        // Used to probe inside matrix
        square test_square;
        test_square.row = row;

        for (int column = 0; column < matrix.size; column++) {
            test_square.column = column;
            // OPTIMIZATION3: Send current subsquare size to constrain sizes
            bool found = check_all_possible_squares(matrix, subsquare_out.size,
                                                    test_square);
            if (found && (test_square.size > subsquare_out.size)) {
                subsquare_out = test_square;
            }
        }
    }
    return subsquare_out.size > 0;
}

// --------------- Helper Functions ---------------

// Check if there's a square of 'n' valid sizes starting at row and column of
// 'subsquare_out'. Iterate through all applicable sizes without reading outside
// of input 'matrix'. Start from maximum possible and work smaller to obviate
// the need to search for samller subsquares. Retrun true if we find something,
// or false if not. Max subsquare is returned in 'subsquare_out' on success.
static bool check_all_possible_squares(const matrix_t& matrix,
                                       int min_required_size,
                                       square& subsquare_out)
{
    // OPTIMIZATION3: Don't test for smaller subsquares than we've
    // already found, or for invalid squares
    const int min_size = std::max(min_square_size, min_required_size);

    // OPTIMIZATION2: We're constrained by matrix dimensions
    const int start_size = std::min(matrix.size - subsquare_out.column,
                                    matrix.size - subsquare_out.row);

    // OPTIMIZATION1: Look for largest size first
    int longest_side;
    for (int size = start_size; size >= min_size; size--) {
        subsquare_out.size = size;
        if (is_square(matrix, subsquare_out, longest_side)) {
            return true;
        }
        // OPTIMIZATION5
        if (longest_side < size) {
            size = longest_side + 1;
        }
    }
    return false;
}

// Test for a square defined by lines of '1' values inside matrix defined by
// row, column, and size of 's'. Return true when 's' is a valid square, or
// false if not.
//
// Caveat: No bounds test on 'matrix' square size and matrix
static bool is_square(const matrix_t& matrix, const square& s,
                      int& longest_side)
{
    longest_side = 0;

    // Validate top horizontal line
    for (int i = s.column; i < (s.column + s.size); i++) {
        if (read_matrix(matrix, s.row, i) != 1) {
            return false;
        }
        // OPTIMIZATION5: Track longest side for future tests
        longest_side++;
    }

    // Validate sides of square - could loop 0 times for smallest squares
    for (int i = s.row + 1; i <= (s.row + s.size - 1); i++) {
        if ((read_matrix(matrix, i, s.column) != 1) ||
            (read_matrix(matrix, i, s.column + s.size - 1) != 1)) {
            return false;
        }
    }

    // Validate bottom horizontal line
    for (int i = s.column; i < s.column + s.size; i++) {
        if (read_matrix(matrix, s.row + s.size - 1, i) != 1) {
            return false;
        }
    }

    return true;
}

// Using this function makes it easy to measure how many reads the
// library makes.
static int read_matrix(const matrix_t& matrix, int row, int column)
{
    return matrix.data[column + (row * matrix.size)];
}

}; // namespace n4n
