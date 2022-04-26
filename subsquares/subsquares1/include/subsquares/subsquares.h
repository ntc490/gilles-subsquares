#ifndef SUBSQUARES_H__
#define SUBSQUARES_H__

namespace n4n {

// --------------- Types ---------------

struct square {
    int row;
    int column;
    int size;
};

// --------------- Constants ---------------

constexpr const int min_square_size = 2;
constexpr const int max_square_size = 8;
static_assert(min_square_size <= max_square_size);

// --------------- API Prototypes ---------------

bool find_max_subsquare(const int matrix[max_square_size][max_square_size],
                        square& subsquare_out);

}; // namespace n4n

#endif //  SUBSQUARES_H__
