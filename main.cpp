#include <iostream>

#include <type_traits>

#include "example.hpp"

constexpr const char tick[] = u8"\u2705";
constexpr const char cross[] = u8"\u274C";

template <typename T, typename Arg>
struct is_implicitly_constructible {
    static constexpr bool value =
            std::is_constructible<T, Arg>::value &&
            std::is_convertible<Arg, T>::value;
};

template <typename T>
void print_class_properties()
{
    std::cout << "Class is...\n";

    std::cout << "\tDefault constructible? " << "\t" <<
        (std::is_default_constructible<example>::value ? tick : cross) << '\n';

    std::cout << "\tConstructible from int? " << "\t" <<
        (std::is_constructible<example, int>::value ? tick : cross) << '\n';

    std::cout << "\tImplicitly constructible from int? " << "\t" <<
        (is_implicitly_constructible<T, int>::value ? tick : cross) << '\n';

    std::cout << "\tCopy constructible? " << "\t" <<
        (std::is_copy_constructible<example>::value ? tick : cross) << '\n';

    std::cout << "\tCopy assignable? " << "\t\t" <<
        (std::is_assignable<example&, const example&>::value ? tick : cross) << '\n';

    std::cout << "\tDestructible? " << "\t\t\t" <<
        (std::is_destructible<example>::value ? tick : cross) << '\n';
}

int main()
{
    print_class_properties<example>();
}