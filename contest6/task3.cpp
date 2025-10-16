template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return first;
    Iter result = first, current_el = first;
    ++current_el;
    while (current_el != last) {
        if (*current_el != *result) {
            ++result;
            *result = *current_el;
        }
        ++current_el;
    }
    return ++result;
}
