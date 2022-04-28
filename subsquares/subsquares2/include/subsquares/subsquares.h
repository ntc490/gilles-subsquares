#ifndef SUBSQUARES_H__
#define SUBSQUARES_H__
// See documentation in cpp file

namespace n4n {

// --------------- Types ---------------

struct square {
    int row;
    int column;
    int size;
};

struct matrix_t {
    int* data;
    int size;
};

// --------------- Constants ---------------

constexpr const int min_square_size = 2;

// --------------- API Prototypes ---------------

bool find_max_subsquare(const matrix_t& matrix, square& subsquare_out);

}; // namespace n4n

#endif //  SUBSQUARES_H__
