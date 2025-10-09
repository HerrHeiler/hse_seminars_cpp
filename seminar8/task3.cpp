#include <iostream>
#include <functional>

template<typename T>
T findMax(const T* a) {
    T maxi = a[0];
    for (int i = 1; i < a.length(); ++i) {
        if (a[i] > maxi) {
            maxi = a[i];
        }
    }
    return maxi;
}

//template<typename T, typename Compare = std::less<T> >
