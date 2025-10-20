template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter TransformIf(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for (first != last) {
        if (condition(*first)) {
            *out = f(*first);
            ++out;
        }
        ++first;
    }
    return out;
}
