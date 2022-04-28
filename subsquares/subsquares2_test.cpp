#include "subsquares.h"
#include <gtest/gtest.h>
using namespace n4n;

TEST(NoSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}

TEST(EmtpySquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}

TEST(FullSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 8);
}

TEST(EmbeddedSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 8);
}

TEST(TopLeftSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1, 1, 0, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 0, 0, 0, 1,
        1, 0, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 3);
}

TEST(TopRightSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 1, 0, 0, 1,
        1, 1, 1, 0, 1, 0, 0, 1,
        1, 0, 1, 0, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 4);
    EXPECT_EQ(result.size, 4);
}

TEST(BottomRightSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 2);
    EXPECT_EQ(result.column, 2);
    EXPECT_EQ(result.size, 6);
}

TEST(BottomLeftSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        0, 0, 1, 0, 0, 0, 0, 1,
        1, 1, 1, 0, 0, 0, 0, 1,
        1, 1, 0, 1, 1, 1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 6);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 2);
}

// Ensures that Optimization 5 doesn't cause square detection to fail
TEST(OptimizedTailSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 0, 0,
        0, 0, 1, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
    };
    matrix_t matrix = { matrix_data, 8 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 2);
    EXPECT_EQ(result.column, 2);
    EXPECT_EQ(result.size, 3);
}

TEST(SmallSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1,
        1, 0, 1,
        1, 1, 1,
    };
    matrix_t matrix = { matrix_data, 3 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 3);
}

TEST(SmallSquare2, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1, 0,
        1, 0, 1, 0,
        1, 1, 1, 0,
	0, 0, 0, 0
    };
    matrix_t matrix = { matrix_data, 4 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 3);
}

TEST(SmallNoSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 1,
        1, 0, 1,
        1, 1, 0,
    };
    matrix_t matrix = { matrix_data, 3 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, false);
    EXPECT_EQ(result.size, 0);
}

TEST(SmallestSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1,
        1, 1,
    };
    matrix_t matrix = { matrix_data, 2 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 2);
}

TEST(BiggerTopLeftSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    matrix_t matrix = { matrix_data, 16 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 0);
    EXPECT_EQ(result.column, 0);
    EXPECT_EQ(result.size, 2);
}

TEST(BiggerSucceededSquare, FlexibleIface)
{
    // clang-format off
    int matrix_data[] = {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    matrix_t matrix = { matrix_data, 16 };
    // clang-format on

    square result;
    auto found = find_max_subsquare(matrix, result);

    EXPECT_EQ(found, true);
    EXPECT_EQ(result.row, 10);
    EXPECT_EQ(result.column, 8);
    EXPECT_EQ(result.size, 4);
}
