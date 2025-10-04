#pragma once
#include <tuple>

namespace godot {

    // We can easily extrapolate this to TRIANGULATIONS for a marching cubes algorithm
    inline constexpr const int ARRAY_TEST[5] = {1, 2, 3, 4, 5};

    inline constexpr const std::tuple<int, int> TUPLE_TEST = {5, 6};

    inline constexpr const std::tuple<int, int> ARRAY_TUPLE_TEST[5] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
    };

}
