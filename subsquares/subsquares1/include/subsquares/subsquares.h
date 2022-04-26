#ifndef SUBSQUARES_H__
#define SUBSQUARES_H__

namespace n4n {

// --------------- Types ---------------

struct square {
    int row;
    int column;
    int width;
};

// --------------- Constants ---------------

constexpr const int min_square_width = 2;
constexpr const int max_square_width = 8;
static_assert(min_square_width <= max_square_width);

// --------------- API Prototypes ---------------

bool find_max_subsquare(const int matrix[max_square_width][max_square_width],
                        square& subsquare_out);

}; // namespace n4n

#endif //  SUBSQUARES_H__
