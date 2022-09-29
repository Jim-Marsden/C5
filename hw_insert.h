//
// Created by Jim Marsden on 9/21/22.
//

#ifndef C5_HW_INSERT_H
#define C5_HW_INSERT_H
#include <cstdlib>

int *insert_f(const int *array, size_t length, size_t index, int value);
// Mastering Algorithms with C
namespace mac {
    template<class T, class Size_T>
    T *insert(const T *array, Size_T length, Size_T index, T const & value);
}

namespace mac{
    namespace{
            template<class T>
            T *create_1_element_array(T const &value);

            template<class T, class Size_T>
            T *append(T const &value, T const *array, Size_T length);

            template<class T, class Size_T>
            T *add(T const &value, T const *array, Size_T length, Size_T index);
        }

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

/**
 * @brief creates a new array and adds the value to the index. Will throw an exception if it's unable to create the array
 * @tparam T The type for the array and the value
 * @tparam Size_T the size type for the array
 * @param array the array we will be copying
 * @param length the size of the array value
 * @param index where to add the value
 * @param value the value to be added at index
 * @return A pointer to a newly created array with value added at index.
 */
template<class T, class Size_T = decltype(sizeof(1))>
T *mac::insert(const T *array, Size_T length, Size_T index, T const & value) {

    // Where we will put our new array
    T *result;

    if(length + 1 <= index){result = nullptr; }
    else if (length == 0U) { result = mac::create_1_element_array<T>(value); }
    else if (index == 0U) { result = mac::append(value, array, length); }
    else { result = mac::add(value, array, length, index); }

    // Only delete array if everything is valid.
    if(result != nullptr) {
        delete[]array;
    }
    return result;
}


namespace mac{
    namespace {

        /**
         * @brief creates an array with one element of value.
         * @tparam T The type of the element and the array
         * @param value the value to to be added to the single element array.
         * @return returns a pointer of type T to an array with a single element
         */
        template<class T>
        T *create_1_element_array(T const &value){
            auto new_array = new T[1U]; // NOLINT(clion-misra-cpp2008-18-4-1)
            new_array[0] = value;
            return new_array;
        }

        /**
         * @brief Makes a new array and adds value to the front.
         * @tparam T The type of the array and value
         * @tparam Size_T the size type for the array
         * @param value the value to append to the front
         * @param array old array to copy
         * @param length the size of the array
         * @return a new pointer to an array that has the new element added
         */
        template<class T, class Size_T>
        T *append(T const &value, T const *array, Size_T length){
            // the array we will return
            auto new_array = new T[length + 1U]; // NOLINT(clion-misra-cpp2008-18-4-1)
            // copies every element one element at a time. where the new array is offset by one
            for (unsigned i = 0U; i < length; ++i) {
                new_array[i + 1U] = array[i];
            }
            // finally we add the front element
            new_array[0] = value;
            return new_array;
        }

        /**
         *
         * @tparam T The type of the array and value
         * @tparam Size_T The size type for the array
         * @param value The value to insert into the array
         * @param array The array to copy
         * @param length The size of the array
         * @param index
         * @return
         */
        template<class T, class Size_T>
        T *add(T const &value, T const *array, Size_T length, Size_T index){
            // The array to copy to and return
            auto new_array = new T[length + 1U]; // NOLINT(clion-misra-cpp2008-18-4-1)

            // Copies every element from array to new array unless i is the target index
            for (unsigned i = 0U; i < length; ++i) {
                new_array[i] = (i == index) ? value : array[i];
            }

            // To assign the final element
            new_array[length] = (length == index) ? value : array[length - 1U];
            return new_array;
        }
    }
}


#endif //C5_HW_INSERT_H
