//
// Created by milittle on 2022/3/15.
//

#ifndef MODERNTEST_META_H
#define MODERNTEST_META_H

#endif //MODERNTEST_META_H

#include <type_traits>

//remove series
template <typename T> struct my_remove_cv {typedef T type;};
template <typename T> struct my_remove_cv<const T> {typedef T type;};
template <typename T> struct my_remove_cv<volatile T> {typedef T type;};
template <typename T> struct my_remove_cv<const volatile T> {typedef T type;};

template <typename T>
using my_remove_cv_t = typename my_remove_cv<T>::type;

template <typename T> struct my_remove_const {typedef T type;};
template <typename T> struct my_remove_const<const T> {typedef T type;};
template <typename T>
using my_remove_const_t = typename my_remove_const<T>::type;

template <typename T> struct my_remove_volatile {typedef T type;};
template <typename T> struct my_remove_volatile<volatile T> {typedef T type;};
template <typename T>
using my_remove_volatile_t = typename my_remove_volatile<T>::type;

//my is_same
template<typename T, typename U>
struct my_is_same : std::false_type {};

template<typename T>
struct my_is_same<T, T> : std::true_type {};

// my is_void and is_void_t
template <typename T>
struct my_is_void : my_is_same<void, typename my_remove_cv<T>::type> {};

template <typename T>
inline constexpr bool my_is_void_v = my_is_void<T>::value;

//my is_floating_point and is_floating_point_t
template <typename T>
struct my_is_floating_point : std::integral_constant<
        bool,
        my_is_same<float, typename my_remove_cv<T>::type>::value ||
        my_is_same<double, typename my_remove_cv<T>::type>::value ||
        my_is_same<long double, typename my_remove_cv<T>::type>::value
>{};
template <typename T>
inline constexpr bool my_is_floating_point_v = my_is_floating_point<T>::type;

//my is_integral and is_integral_v
template <typename T>
struct my_is_integral : std::integral_constant<
        bool,
        my_is_same<bool, typename my_remove_cv<T>::type>::value ||
        my_is_same<char, typename my_remove_cv<T>::type>::value ||
        my_is_same<char8_t, typename my_remove_cv<T>::type>::value ||
        my_is_same<char16_t, typename my_remove_cv<T>::type>::value ||
        my_is_same<char32_t, typename my_remove_cv<T>::type>::value ||
        my_is_same<wchar_t, typename my_remove_cv<T>::type>::value ||
        my_is_same<short, typename my_remove_cv<T>::type>::value ||
        my_is_same<int, typename my_remove_cv<T>::type>::value ||
        my_is_same<long, typename my_remove_cv<T>::type>::value ||
        my_is_same<long long, typename my_remove_cv<T>::type>::value
>{};
template <typename T>
inline constexpr bool my_is_integral_v = my_is_integral<T>::value;

//my is_null_pointer
template <typename T>
struct my_is_null_pointer : my_is_same<std::nullptr_t, typename my_remove_cv<T>::type>{};

//my is_array
template <typename T>
struct my_is_array : std::false_type {};

template <typename T>
struct my_is_array<T[]> : std::true_type {};

template <typename T, std::size_t N>
struct my_is_array<T[N]> : std::true_type {};

template <typename T>
inline constexpr bool my_is_array_t = my_is_array<T>::value;

template<typename T>
typename std::enable_if<my_is_integral_v<T>, int>::type
up(T t){
    t += 1;
    return t;
}