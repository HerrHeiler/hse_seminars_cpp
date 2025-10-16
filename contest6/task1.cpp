#include <iostream>
//#include "task1.h"

template <typename It, typename Pred> bool AnyOf(It first, It last, Pred f) {
    fl = false;
    while (first != last){
        if (f(first)) fl = true;
        ++first;
    }
    return fl;
}