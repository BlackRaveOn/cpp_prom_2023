### Modifying sequence operations
Библиотека с набором функций для работы с контейнерами, например vector. 
По функционалу функции эквиваленты функциям из  https://en.cppreference.com/w/cpp/algorithm
Реализованы:
- [fill_seq](https://en.cppreference.com/w/cpp/algorithm/fill)
- [generate_seq](https://en.cppreference.com/w/cpp/algorithm/generate)
- [iter_swap_seq](https://en.cppreference.com/w/cpp/algorithm/iter_swap)
- [partition_seq](https://en.cppreference.com/w/cpp/algorithm/partition)
- [shuffle_seq](https://en.cppreference.com/w/cpp/algorithm/random_shuffle)
- [remove_seq](https://en.cppreference.com/w/cpp/algorithm/remove)
- [replace_seq](https://en.cppreference.com/w/cpp/algorithm/replace)
- [unique_seq](https://en.cppreference.com/w/cpp/algorithm/unique)

---
### Сборка проекта
git clone https://github.com/BlackRaveOn/cpp_prom_2023/tree/master/hw1
makedir build
cd build
cmake ..
make

---
### Выходные файлы
В случае успешной сборке в папке build появятся следующие файлы:
- exec - основная программа
- custom_integr_test - интеграционные тесты
- custom_unit_test - юнит тесты
