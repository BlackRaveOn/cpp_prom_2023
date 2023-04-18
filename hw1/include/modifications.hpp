#pragma once

#include <random>
#include <ctime>


template<class ForwardIterator, class T>
void fill_seq(ForwardIterator first, ForwardIterator last, const T& value) {
    while (first != last) {
        *first++ = value;
    }
}

template<class ForwardIterator, class Generator>
void generate_seq(ForwardIterator first, ForwardIterator last, Generator gen) {
    while (first != last) {
        *first++ = gen();
    }
}

template<typename ForwardIterator>
void iter_swap_seq(ForwardIterator a, ForwardIterator b) {
    auto temp = *a;
    *a = *b;
    *b = temp;
}

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator partition_seq(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    ForwardIterator left = first;
    ForwardIterator right = last - 1;
    while (left <= right) {
        while (left <= right && pred(*left)) {
            left++;
        }
        while (left <= right && !pred(*right)) {
            right--;
        }
        if (left <= right) {
            iter_swap_seq(left, right);
            left++;
            right--;
        }
    }
    return left;
}

template<typename RandomAccessIterator, class Generator>
void shuffle_seq(RandomAccessIterator first, RandomAccessIterator last, Generator gen) {
    // Shuffle the sequence
    for (auto i = first; i != last; ++i) {
        auto j = first + gen() % (last - first);
        iter_swap_seq(i, j);
    }
}

template<typename ForwardIterator, typename T>
ForwardIterator remove_seq(ForwardIterator first, ForwardIterator last, const T& value) {
    ForwardIterator result = first;

    // Copy each element that is not equal to value to the result iterator
    for (ForwardIterator it = first; it != last; ++it) {
        if (*it != value) {
            *result = std::move(*it);
            ++result;
        }
    }
    return result;
}


template<typename ForwardIterator, typename T>
void replace_seq(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value) {
    // Replace each occurrence of old_value with new_value
    for (ForwardIterator it = first; it != last; ++it) {
        if (*it == old_value) {
            *it = new_value;
        }
    }
}


template<typename ForwardIterator>
ForwardIterator unique_seq(ForwardIterator first, ForwardIterator last) {
    if (first == last) {
        return last;
    }

    ForwardIterator result = first;

    // Copy each unique element to the result iterator
    for (ForwardIterator it = first + 1; it != last; ++it) {
        if (*it != *result) {
            ++result;
            *result = std::move(*it);
        }
    }

    return ++result;
}