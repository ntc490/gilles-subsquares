#include "subsquares.h"
#include <algorithm>

namespace n4n {

// --------------- Helper Prototypes ---------------

static bool
check_all_possible_squares(const int matrix[max_square_size][max_square_size],
                           int min_required_size,
                           square& subsquare_out);
static bool is_square(const int matrix[max_square_size][max_square_size],
                      const square& s);

// --------------- API Functions ---------------

// Given 'matrix' comprised of 0 or 1 values, 0 = white and 1 = black, find the
// largest subsquare defined by a black outline and return it in
// 'subsquare_out'. Return value is true if found, or false if no subsquares
// found. subsquare_out.size will be set to 0 when no subsquares are found.
//
// CAVEAT: 'subsquare_out.size' will always be modified by this function.
bool find_max_subsquare(const int matrix[max_square_size][max_square_size],
                        square& subsquare_out)
{
    // Start by signalling an invalid square
    subsquare_out.size = 0;

    for (int row = 0; row < max_square_size; row++) {
        // OPTIMIZATION4: Stop checking if we don't have enough rows
        // left for something bigger than what we already found
        int max_possible_height = max_square_size - row;
        if (max_possible_height < subsquare_out.size) {
            break;
        }

        // Used to probe inside matrix
        square test_square;
        test_square.row = row;

        for (int column = 0; column < max_square_size; column++) {
            test_square.column = column;
            // OPTIMIZATION3: Send current subsquare size to constrain sizes
            bool found = check_all_possible_squares(
                matrix, subsquare_out.size, test_square);
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
static bool
check_all_possible_squares(const int matrix[max_square_size][max_square_size],
                           int min_required_size,
                           square& subsquare_out)
{
    // OPTIMIZATION3: Don't test for smaller subsquares than we've
    // already found, or for invalid squares
    const int min_size = std::max(min_square_size, min_required_size);

    // OPTIMIZATION2: We're constrained by matrix dimensions
    const int start_size = std::min(max_square_size - subsquare_out.column,
                                    max_square_size - subsquare_out.row);

    // OPTIMIZATION1: Look for largest size first
    for (int size = start_size; size >= min_size; size--) {
        subsquare_out.size = size;
        if (is_square(matrix, subsquare_out)) {
            return true;
        }
    }
    return false;
}

// Test for a square defined by lines of '1' values inside matrix defined by
// row, column, and size of 's'. Return true when 's' is a valid square, or
// false if not.
//
// Caveat: No bounds test on 'matrix' square size and matrix
static bool is_square(const int matrix[max_square_size][max_square_size],
                      const square& s)
{
    // Validate top horizontal line
    for (int i = s.column; i < (s.column + s.size); i++) {
        if (matrix[s.row][i] != 1) {
            return false;
        }
    }

    // Validate sides of square - could loop 0 times for smallest squares
    for (int i = s.row + 1; i <= (s.row + s.size - 1); i++) {
        if ((matrix[i][s.column] != 1) ||
            (matrix[i][s.column + s.size - 1] != 1)) {
            return false;
        }
    }

    // Validate bottom horizontal line
    for (int i = s.column; i < s.column + s.size; i++) {
        if (matrix[s.row + s.size - 1][i] != 1) {
            return false;
        }
    }

    return true;
}

}; // namespace n4n
