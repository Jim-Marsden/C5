#include <cstdlib>

namespace helper {
    template<class T>
    static T *insert(T const &value);

    template<class T, class Size_T>
    static T *insert(T const &value, T const *array, Size_T length);

    template<class T, class Size_T>
    static T *insert(T const &value, T const *array, Size_T length, Size_T index);
}

/**
 * @name: int *insert(int *array, int length, int index, int value);
 * @param The array of ints into which a new value should be inserted.
 * @param length The number of elements in the array.
 * @param index The location where the value should be inserted into the array.
 * @param value The value that should be inserted into the array.
 * @return A new array of ints containing the contents of the original array plus the new value
inserted at the given index. NULL will be returned should something goes wrong.
 */
int *insert_f(int const *array, size_t length, size_t index, int value) {
    int *result;
    if (length == 0U) { result = helper::insert(value); }
    else if (index == 0U) { result = helper::insert(value, array, length); }
    else { result = helper::insert(value, array, length, index); }

    delete[]array;

    return result;
}

/**
 * @brief To create an add an element to an array
 * @tparam T the type of the array
 * @param value the element to add to the returning array.
 * @return a dynamic array that has a single element of value
 */
template<class T>
static T *helper::insert(const T &value) {
    auto new_array = new int[1U]; // NOLINT(clion-misra-cpp2008-18-4-1)
    new_array[0] = value;
    return new_array;
}

/**
 * @brief adds an element to the front of an array and increases the size.
 * @tparam T The type of the array
 * @tparam Size_T the size of the current array
 * @param value the value to add to front of the array
 * @param array the array to copy into the return value
 * @param length the size of the array param
 * @return a new array of type T with an added element
 */
template<class T, class Size_T>
static T *helper::insert(T const &value, T const *array, Size_T length) {
    auto new_array = new int[length + 1U]; // NOLINT(clion-misra-cpp2008-18-4-1)
    for (unsigned i = 0U; i < length; ++i) {
        new_array[i + 1U] = array[i];
    }
    new_array[0] = value;
    return new_array;
}

/**
 * @brief adds an element to an index of an array and increases the size.
 * @tparam T The type of the array
 * @tparam Size_T the size of the current array
 * @param value the value to add to front of the array
 * @param array the array to copy into the return value
 * @param length the size of the array param
 * @param index the index to add the new element
 * @return a new array of type T with an added element
 */
template<class T, class Size_T>
static T *helper::insert(const T &value, const T *array, Size_T length, Size_T index) {
    auto new_array = new int[length + 1U]; // NOLINT(clion-misra-cpp2008-18-4-1)
    for (unsigned i = 0U; i < length; ++i) {
        new_array[i] = i == index ? value : array[i];
    }
    new_array[length] = length == index ? value : array[length - 1U];
    return new_array;
}
