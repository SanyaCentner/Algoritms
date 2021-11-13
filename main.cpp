//В операционной системе Technux есть планировщик процессов.
//Каждый процесс характеризуется:

//приоритетом P
//временем, которое он уже отработал t
//временем, которое необходимо для завершения работы процесса T
//Планировщик процессов выбирает процесс с минимальным значением P * (t + 1),
//выполняет его время P и кладет обратно в очередь процессов. Если выполняется
//условие t >= T, то процесс считается завершенным и удаляется из очереди.
//Требуется посчитать кол-во переключений процессора.

//Требования:

//В качестве очереди с приоритетом нужно использовать кучу.
//Куча должна быть реализована в виде шаблонного класса.
//Решение должно поддерживать передачу функции сравнения снаружи.
//Куча должна быть динамической.
//Формат ввода
//Сначала вводится кол-во процессов. После этого процессы в формате P T

#include <iostream>

//struct Process {
//     P{0};
//    size_t T{0};
//    size_t t{0};
//    size_t value() const { return P * (t + 1); }
//};
//
//
//struct Point {
//    Point()
//            : x(0), y(0) {
//
//    }
//
//    Point(int x, int y)
//            : x(x), y(y) {
//
//    }
//
//    int x, y;
//};
//
//std::istream &operator>>(std::istream &in, Point &p) {
//    in >> p.x >> p.y;
//    return in;
//}
//
//std::ostream &operator<<(std::ostream &out, Point &p) {
//    out << "(" << p.x << ", " << p.y << ")";
//    return out;
//}
//
//bool operator<(const Point &l, const Point &r) {
//    return l.x < r.x;
//}
//
//bool pointXComparator(const Point &l, const Point &r) {
//    return l.x < r.x;
//}
//
//bool pointYComparator(const Point &l, const Point &r) {
//    return l.x < r.x;
//}
//
//template <typename T>
//bool defaultComparator(const T &l, const T &r) {
//    return l < r;
//}
//
//template <typename T>
//class DefaultComparator {
//public:
//    bool operator()(const T &l, const T&r) const {
//        return l < r;
//    }
//};
//
//
//template <typename T>
//void mySort(T *arr, int l, int r, bool (*cmp)(const T&, const T&) = defaultComparator) {
//    for (int i = l; i < r; ++i) {
//        for (int j = l; j < r - 1; ++j) {
//            if (cmp(arr[j + 1], arr[j])) {
//                std::swap(arr[j + 1], arr[j]);
//            }
//        }
//    }
//}
//
//template <typename T, typename Comparator>
//void mySort2(T *arr, int l, int r, Comparator cmp) {
//    for (int i = l; i < r; ++i) {
//        for (int j = l; j < r - 1; ++j) {
//            if (cmp(arr[j + 1], arr[j])) {
//                std::swap(arr[j + 1], arr[j]);
//            }
//        }
//    }
//}
int binary_search(const int *mas, int first, int last, int count) {
    while (first < last) {
        int mid = (first + last) / 2;
        if (mid != 0) {
            if (mas[mid - 1] > mas[mid]) {
                return mid;
            } else {
                last = mid;
            }
        } else {
            if (mas[mid] < mas[count - 1]) {
                return mid;
            } else if ((mas[count - 1] < mas[mid]) && (mas[count - 2] >= mas[count - 1])) {
                return count - 1;
            } else {
                first = (first + count) / 2;
                last = count;
            }
        }

    }
//
//    return first;
}

#include <iostream>

class STACK {
public:
    int count;
    int size;
    int *node;

    // конструктор по умолчанию
    STACK() : count(0), size(8), node(new int[size]) {};

    STACK(size_t size) : count(0), size(size), node(new int[size]) {};

    /* Деструктор */
    ~STACK() {
        delete[] node;
    }

    void resize(int new_size) {
        int *temp;
        temp = new int[new_size];
        for (int i = 0; i < count; i++) temp[i] = node[i];
        size = new_size - count;
        delete[] node;
        node = temp;
        temp = nullptr;
    }

    void push(int x) {
        if (size != 0) {
            node[count] = x;
            count++;
            size--;
        } else {
            resize(count * 2);
            return push(x);
        }

    }

    int pop() {
        if (size == 0) {
            return 0; // стек пуст
        }
        size++;
        count--;
        return node[count];
    }
};


int main() {
    int n = 0;
//    std::cin >> n;
//    int *arr = new int[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i];
//    }
//
//    int bandera[7] = {1, 21, 22, 23, 24, 25, 2};
//    int kek = binary_search(bandera, 0, 7, 7);
//    std::cout << kek;

//    mySort2(arr, 0, n, DefaultComparator<int>());
//    for (int i = 0; i < n; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    delete[] arr;
//    std::cout << std::endl;
    int size = 800000;
    STACK stack(size);
    char c;
    while (((c = getchar()) != '\n') && (c != '\0')) {
        if (c == '(') {
            stack.push(1);
        } else if (c == ')') {
            stack.pop();
            if (stack.count < 0)
                break;
        }
    }
    if (stack.count == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}
