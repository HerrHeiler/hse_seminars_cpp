template <typename InIter, typename OutIter>
OutIter ReverseCopy(InIter first, InIter last, OutIter out) {
    if (last == first) return out;
    while (last != first) {
        *out = *last;
        ++out;
        --last;
    }
    *out = *last;
    ++out;
    return out;
}