
/*
    Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой
адресацией. Хранимые строки непустые и состоят из строчных латинских букв. Хеш-функция строки должна быть
реализована с помощью вычисления значения многочлена методом Горнера. Начальный размер таблицы должен быть
равным 8-ми. Перехеширование выполняйте при добавлении элементов в случае, когда коэффициент заполнения
таблицы достигает 3/4. Структура данных должна поддерживать операции добавления строки в множество,
удаления строки из множества и проверки принадлежности данной строки множеству.

1_1. Для разрешения коллизий используйте квадратичное пробирование.
i-ая проба g(k, i)=g(k, i-1) + i (mod m). m - степень двойки.

 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define MAX_ALPHA 0.75

enum state_t {
    EMPTY,
    DELETE,
    NOT_EMPTY
};

struct Elem {
    std::string key;
    state_t state;

    Elem &operator=(const Elem &rhs) = default;
};

size_t hasher(const std::string &str) {
    size_t hash = 0;
    size_t prime = 55;
    for (int i = 0; i < str.size(); i++) {
        hash = hash * prime + str[i];
    }
    return hash;
}

class HashTable {

public:
    HashTable() : size(0), items_count(0), elems(size) {}

    bool Add(const std::string &str) {
        if (size == 0) {
            size = 8;
            elems.resize(size);
            for (auto elem: elems) {
                elem.state = EMPTY;
            }
        }

        if (Has(str)) {
            return false;
        }

        if ((items_count / size) >= MAX_ALPHA) {
            grow();
        }

        size_t hash = hasher(str) % size;
        size_t prev = 0;
        for (size_t i = 0; i < size; ++i) {
            if (elems[hash].state == EMPTY || elems[hash].state == DELETE) {
                elems[hash] = {str, NOT_EMPTY};
                ++items_count;
                return true;
            }
            prev = hash;
            hash = (prev + i + 1) % size;
        }
        return false;
    }

    bool Delete(const std::string& str) {
        if (!Has(str)) {
            return false;
        }

        size_t ind = hasher(str) % size;
        size_t prev_ind = 0;
        for (size_t i = 0; i < size; ++i) {
            if (elems[ind].state == EMPTY) {
                return false;
            }
            if (elems[ind].key == str) {
                elems[ind].state = DELETE;
                elems[ind].key = "";
                --items_count;
                return true;
            }
            prev_ind = ind;
            ind = (prev_ind + i + 1) % size;
        }
        return false;
    }

    bool Has(const std::string &str) {
        size_t hash = hasher(str) % size;
        size_t prev = 0;
        for (size_t i = 0; i < size; ++i) {
            if (elems[hash].state == EMPTY) {
                return false;
            }
            if (elems[hash].key == str) {
                return true;
            }
            prev = hash;
            hash = (prev + i + 1) % size;
        }
        return false;
    }

private:

    void grow() {
        size_t new_size = size * 2;
        std::vector<Elem> new_elems(new_size);
        for (const auto& elem: elems) {
            size_t hash = hasher(elem.key) % new_size;
            size_t prev = 0;
            for (size_t i = 0; i < new_size; ++i) {
                if (new_elems[hash].state == EMPTY) {
                    break;
                }
                prev = hash;
                hash = (prev + i + 1) % new_size;
            }
            new_elems[hash] = elem;
        }
        elems = new_elems;
        size = new_size;
    }

    size_t size;
    size_t items_count;
    std::vector<Elem> elems;

};

void run(std::istream &is, std::ostream &os) {
    std::string key = "";
    char operation = '\0';

    HashTable hash_table;
    while (is >> operation >> key) {
        switch (operation) {
            case '+':
                os << (hash_table.Add(key) ? "OK" : "FAIL") << std::endl;
                break;
            case '-':
                os << (hash_table.Delete(key) ? "OK" : "FAIL") << std::endl;
                break;
            case '?':
                os << (hash_table.Has(key) ? "OK" : "FAIL") << std::endl;
                break;
            default:
                os << "FAIL" << std::endl;
        }
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}