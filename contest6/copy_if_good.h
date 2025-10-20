#include <algorithm>
#include <vector>

template <typename T>
void process(const std::vector<T>& data) {
    auto cnt = std::count_if(data.begin(), data.end(), [](const T& x) { return x > 0; });
    std::vector<T> filtered(cnt);

    auto filtered_last = std::copy_if(
        data.begin(),
        data.end(),
        filtered.begin(),
        [](const T& x) { return x > 0; }
    );

    print_results(filtered.begin(), filtered.end());
}