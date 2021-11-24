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

using std::endl, std::cin, std::cout;

struct Process {
    int P;
    int T;
    int t;

    int value() const { return P * (t + 1); }
};

class Default_Comparator {
public:
    bool operator()(const Process &one, const Process &two) const {
        return one.value() < two.value();
    }
};

template<class T, class Comparator = Default_Comparator>
class Heap {
public:
    Heap(T *_buffer, int _count) : buffer(_buffer), count(_count), size(0) {
        buildHeap(_count);
    };

    ~Heap() { delete[] buffer;}

    bool is_empty() const { return count == 0; }

    const T &min() const { return buffer[0]; }

    void resize() {
        int new_size = count * 2;
        T *temp = new T[new_size];
        for (int i = 0; i < count; i++) {
            temp[i] = buffer[i];
        }
        delete[] buffer;
        buffer = temp;
        size = new_size - count;
        temp = nullptr;
    }

    void pop() {
        assert(!is_empty());
        auto result = buffer[0];
        buffer[0] = std::move(buffer[--count]);
        size++;
        if (!is_empty()) {
            siftDown(0);
        }
    };

    void push(const T &&element) {
        if (size == 0) {
            resize();
            return push(std::move(element));
        }
        buffer[count++] = element;
        size--;
        siftUp(count - 1);
    }

private:
    T *buffer;
    int count;
    int size;

    Heap(const Heap &) = delete;

    Heap &operator=(const Heap &) = delete;

    Heap &operator=(Heap &&) = delete;

    Comparator cmp;

    void siftUp(int child) {
        if (child != 0) {
            int parent = (child - 1) / 2;
            if (parent > 0) {
                if (cmp(buffer[parent], buffer[child])) {
                    return;
                }
                std::swap(buffer[child], buffer[parent]);
                child = parent;
            }
        }
    }

    void siftDown(int parent) {
        int child_left = 2 * parent + 1;
        int child_right = 2 * parent + 2;
        int min = parent;
        if (child_left < count && cmp(buffer[child_left], buffer[parent])) {
            min = child_left;
        } else if (child_right < count && cmp(buffer[child_right], buffer[parent])) {
            min = child_right;
        }
        if (min != parent) {
            std::swap(buffer[parent], buffer[min]);
            siftDown(min);
        }
    }

    void buildHeap(int count) {
        for (int i = 0; i < count; ++i) {
            siftDown(i);
        }
    }
};

void Processing(Heap<Process> &&processes) {
    int switchings = 0;
    while (!processes.is_empty()) {
        switchings++;

        Process min = processes.min();
        processes.pop();
        min.t += min.P;
        if (min.t < min.T) {
            processes.push(std::move(min));
        }
    }
    std::cout << switchings;
}


int main() {
    int n = 0;
    std::cin >> n;
    auto array = new Process[n];
    for (int i = 0; i < n; i++) {
        int P = 0;
        int T = 0;
        std::cin >> P >> T;
        Process Proc{P, T, 0};
        array[i] = Proc;
    }
    Processing(Heap<Process>(array, n));
    return 0;
}
