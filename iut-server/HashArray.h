#ifndef HASHARRAY_H
#define HASHARRAY_H

#include <array>
#include <string>
#include <functional>

namespace std {
template <>
struct hash<std::array<std::string, 6>> {
    std::size_t operator()(const std::array<std::string, 6>& arr) const {
        std::size_t h = 0;
        for (const auto& str : arr) {
            h ^= std::hash<std::string>()(str) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};
}

bool operator==(const std::array<std::string, 6>& lhs, const std::array<std::string, 6>& rhs) {
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

#endif // HASHARRAY_H
