#include "assignment/binary_search_iterative.hpp"

namespace assignment {

  std::optional<int> BinarySearchIterative::Search(const std::vector<int>& arr, int search_elem) const {

    // Tips:
    // 1. Заведите две переменные: (а) индекс левой границы и (б) индекс правой границы.
    // 2. Поиск ведется пока индекс левой границы не превысил индекс правой.
    // 3. Каждую итерацию вычисляйте индекс середины внутри области, задаваемой индексами левой и правой границы.
    // 4. Рассмотрите 3 случая:
    //    1) Целевой элемент равен элементу посередине.
    //    2) Целевой элемент меньше элемента посередине (область поиска сокращается).
    //    3) Целевой элемент больше элемента посередине (область поиска сокращается).

    int left = 0;
    int right = static_cast<int>(arr.size());

    while (left < right) {
      int middle = left + ((right-left)/2);

      if (search_elem == arr[middle]) {
        return middle;
      }

      if (search_elem < arr[middle]) {
        right = middle;
      }

      if (search_elem > arr[middle]) {
        left = middle + 1;
      }
    }

    return std::nullopt;
  }

}  // namespace assignment
