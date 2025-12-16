/*! \file       solution.h
 *  \author     Miroslava Melnichuk
 *  \version    1.0
 *  \date       14.12.2025
 *
 *  Homework. Types aliases and definitions, and function skeletons.
 *
 *      → Provide your solution here and upload this only file to Ya.Contest! ←
 *
 */

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
// TODO: do not forget to include all necessary headers here!


using Ingredients = std::map<std::string, int>;

struct Dish {
    std::string name;
    std::set<std::string> ingredients;
};

using Dishes = std::vector<Dish>;
using DishesIngredients = std::pair<Dishes&, Ingredients&>;


//=========================[TASK 1]===========================================//

Ingredients readIngredients(std::istream& istr)
{
    Ingredients res;
    int t, tint;
    std::string tstr;
    istr >> t;
    for (int i = 0; i < t; ++i) {
        istr >> tstr >> tint;
        res[tstr] = tint;
    }
    return res;
}

// This is a complete implementation. Don't modify it, use it and consider it
// as an example
Dishes readDishes(std::istream& istr)
{
    Dishes res;

    size_t num;
    istr >> num;
    for (size_t i = 0; i < num; ++i)
    {
        Dish dish;
        istr >> dish.name;
        size_t ingNum;
        istr >> ingNum;
        for (size_t j = 0; j < ingNum; ++j)
        {
            std::string ingr;
            istr >> ingr;
            dish.ingredients.insert(ingr);
        }
        res.push_back(dish);
    }

    return res;
}

//=========================[TASK 2]===========================================//

std::ostream& operator<<(std::ostream& ostr, const Dish& dish)
{
    ostr << dish.name << ": ";
    for (auto it = dish.ingredients.begin(); it != dish.ingredients.end(); ++it) {
        ostr << *it;
        if (std::next(it) != dish.ingredients.end()) ostr << ", ";
    }
    return ostr;
}

//=========================[TASK 3]===========================================//

int calcCalories(const Dish& dish, const Ingredients& ingrs)
{
    int total = 0;
    for (auto it = dish.ingredients.begin(); it != dish.ingredients.end(); ++it) {
        total += ingrs.at(*it);
    }
    //another fancy way
    // int total = 0;
    // for (auto it = dish.ingredients.begin(); it != dish.ingredients.end(); ++it) {
    //     auto cal = ingrs.find(*it);
    //     if (cal != ingrs.end()) total += cal->second;
    // }
    return total;
}


//=========================[TASK 4]===========================================//


// This is a complete implementation. Don't modify it and consider it
// as an example.
//
// ! It is NOT mandatory to use this method in the program.
std::ostream& operator<<(std::ostream& ostr, const Dishes& dishes)
{
    for (const Dish& dish : dishes)
    {
        ostr << dish << "\n";
    }
    return ostr;
}


std::ostream& operator<<(std::ostream& ostr, const DishesIngredients& di)
{
    auto& dishes = di.first;
    auto& ingrs = di.second;
    for (const auto& d : dishes) {
        ostr << d << "; " << calcCalories(d, ingrs) << '\n';
    }
    return ostr;
}

//=========================[TASK 5]===========================================//

struct Comparator
{
    const Ingredients& ingrs;
    Comparator(const Ingredients& ingredients) : ingrs(ingredients) {}
    
    bool operator()(const Dish& d1, const Dish& d2) const {
        return calcCalories(d1, ingrs) > calcCalories(d2, ingrs);
    }

};


void sortDishesByCalories(DishesIngredients& di)
{
    std::sort(di.first.begin(), di.first.end(), Comparator(di.second));
}