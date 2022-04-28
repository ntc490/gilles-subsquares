#include "subsquares.h"
#include <gtest/gtest.h>
using namespace n4n;

TEST(NoSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}

TEST(EmtpySquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}

TEST(FullSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 8);
}

TEST(EmbeddedSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 8);
}

TEST(TopLeftSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 1, 1, 1, 0, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 3);
}

TEST(TopRightSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 1, 0, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 4);
    EXPECT_EQ(result.size, 4);
}

TEST(BottomRightSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 2);
    EXPECT_EQ(result.column, 2);
    EXPECT_EQ(result.size, 6);
}

TEST(BottomLeftSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 0, 1, 1, 1, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 6);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 2);
}

// Ensures that Optimization 5 doesn't cause square detection to fail
TEST(OptimizedTailSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 2);
    EXPECT_EQ(result.column, 2);
    EXPECT_EQ(result.size, 3);
}

TEST(LotsOfHitsNoSquare, Basic)
{
    // clang-format off
    int matrix[max_square_size][max_square_size] = {
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1 },
    };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}
