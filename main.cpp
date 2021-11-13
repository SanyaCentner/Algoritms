
//Во всех задачах из следующего списка следует написать структуру данных,
//обрабатывающую команды push* и pop*. Формат входных данных. В первой строке
//количество команд n. n ≤ 1000000. Каждая команда задаётся как 2 целых числа: a
//b. a = 1 - push front a = 2 - pop front a = 3 - push back a = 4 - pop back
//Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
//Для очереди используются команды 2 и 3. Для дека используются все четыре
//команды. Если дана команда pop*, то число b - ожидаемое значение. Если команда
//pop вызвана для пустой структуры данных, то ожидается “-1”. Формат выходных
//данных. Требуется напечатать YES - если все ожидаемые значения совпали. Иначе,
//если хотя бы одно ожидание не оправдалось, то напечатать NO. 3.2 Реализовать дек
//с динамическим зацикленным буфером. Требования: Дек должен быть реализован в
//виде класса.


//Реализовать дек с динамическим зацикленным буфером.
//Требования: Дек должен быть реализован в виде класса.

#include <iostream>

template <typename T>
class Deque {
public:
    //конструктор по умолчанию
    Deque() : count(0),  size(8), buffer(new T[size]), head(0), tail(0) {};

    Deque(size_t size) : count(0),  size(size), buffer(new T[size]), head(0), tail(0) {};

    ~Deque<T>() {delete[] buffer;};

    bool is_empty() const { return (count == size); }

    void resize(int new_size) {
        T *temp;
        temp = new T[new_size];
        for (int i = 0; i < count; i++) {
            temp[i] = buffer[i];
        }
        size = new_size - count;
        delete[] buffer;
        buffer = temp;
        temp = nullptr;
    }

    void shift(const T elem){
        T *temp;
        temp = new T[count + 1];
        for (int i = 0; i < count + 1; i++) {
            if (i == 0) {
                temp[i] = elem;
            } else {
                temp[i] = buffer[i - 1];
            }
        }
        delete[] buffer;
        buffer = temp;
        temp = nullptr;
    }
    int delete_head(){
        T *temp;
        temp = new T[count - 1];
        int top = buffer[0];
        for (int i = 0; i < count - 1; i++) {
            temp[i] = buffer[i + 1];
        }
        delete[] buffer;
        buffer = temp;
        temp = nullptr;
        return top;
    }

    void push_front(const T elem) {
        if (!is_empty() && (tail + 1 <= size) && (size != 0)) {
            shift(elem);
            tail++;
            count++;
            size--;
            return;
        } else {
            resize(size * 2);
            return push_front(elem);
        }
    }

    int pop_front() {
        if (tail == 0) {
            return -1;
        }
        int value = delete_head();
        size++;
        tail--;
        count--;
        return value;
    }

    void push_back(const T elem) {
        if (!is_empty() && (tail + 1 <= size) && (size != 0)) {
            buffer[tail] = elem;
            count++;
            tail++;
            size--;
            return;
        } else {
            resize(count * 2);
        }
    }

    int pop_back() {
        if (size == 0) {
            return -1; // стек пуст
        }
        size++;
        tail--;
        count--;
        return buffer[count];
    }

private:
    int count;
    int size;
    T* buffer;
    int head;
    int tail;

};

//void run(std::istream& in, std::ostream& out) {
//    Deque<int> deq;
//    auto commands{0};
//    int value{0}, get{0};
//    in >> commands;
//    for (int i{0}; i < commands; i++) {
//        int command{0};
//        in >> command >> value;
//        switch (command) {
//            case 1:
//                deq.push_front(value);
//                break;
//            case 2:
//                get = deq.pop_front();
//                if (get != value) {
//                    out << "NO\n";
//                    std::cout << "(popfront)awaiting=" << value << " but get=" << get
//                              << std::endl;
//                    return;
//                }
//                break;
//            case 3:
//                deq.push_back(value);
//                break;
//            case 4:
//                get = deq.pop_back();
//                if (get != value) {
//                    out << "NO\n";
//                    std::cout << "(popback)awaiting=" << value << " but get=" << get
//                              << std::endl;
//                    return;
//                }
//                break;
//            default:
//                out << "NO\n";
//                return;
//        }
//    }
//    out << "YES\n";
//    return;
//}
//void TEST() {
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//
//        in << "3" << std::endl
//           << "1 44" << std::endl
//           << "3 50" << std::endl
//           << "2 44" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#1\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "2" << std::endl << "2 -1" << std::endl << "3 10" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#2\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "2" << std::endl << "3 44" << std::endl << "2 66" << std::endl;
//        run(in, out);
//        assert(out.str() == "NO\n");
//        std::cout << "passed#3\n";
//    }
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "6" << std::endl
//           << "4 -1" << std::endl
//           << "3 5" << std::endl
//           << "4 5" << std::endl
//           << "1 10" << std::endl
//           << "4 10" << std::endl
//           << "2 -1" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#4\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "6" << std::endl
//           << "1 10" << std::endl
//           << "3 100" << std::endl
//           << "1 200" << std::endl
//           << "3 300" << std::endl
//           << "1 400" << std::endl
//           << "3 500" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#5\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "6" << std::endl
//           << "1 10" << std::endl
//           << "1 100" << std::endl
//           << "1 200" << std::endl
//           << "1 300" << std::endl
//           << "1 400" << std::endl
//           << "2 400" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#6\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "6" << std::endl
//           << "1 10" << std::endl
//           << "1 100" << std::endl
//           << "1 200" << std::endl
//           << "1 300" << std::endl
//           << "1 400" << std::endl
//           << "3 400" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#7\n";
//    }
//
//    {
//        Deque<int> deq;
//        std::stringstream in;
//        std::stringstream out;
//        in << "22" << std::endl
//           << "1 10" << std::endl
//           << "1 100" << std::endl
//           << "1 200" << std::endl
//           << "1 300" << std::endl
//           << "1 400" << std::endl
//           << "4 10" << std::endl
//           << "4 100" << std::endl
//           << "4 200" << std::endl
//           << "4 300" << std::endl
//           << "4 400" << std::endl
//           << "4 -1" << std::endl
//           << "4 -1" << std::endl
//           << "4 -1" << std::endl
//           << "1 100" << std::endl
//           << "4 100" << std::endl
//           << "4 -1" << std::endl
//           << "2 -1" << std::endl
//           << "3 0" << std::endl
//           << "2 0" << std::endl
//           << "3 0" << std::endl
//           << "2 0" << std::endl
//           << "4 -1" << std::endl;
//        run(in, out);
//        assert(out.str() == "YES\n");
//        std::cout << "passed#8\n";
//    }
//}
//

int main() {
    Deque<int> deq;
    int commands = 0;
    int get = 0;
    int value = 0;
    std::cin >> commands;
    for (int i = 0; i < commands; i++) {
        int command = 0;
        std::cin >> command >> value;
        switch (command) {
            case 1:
                deq.push_front(value);
                break;
            case 2:
                get = deq.pop_front();
                if (get != value) {
                    std::cout << "NO\n";
                }
                break;
            case 3:
                deq.push_back(value);
                break;
            case 4:
                get = deq.pop_back();
                if (get != value) {
                    std::cout << "NO\n";
                }
                break;
            default:
                std::cout << "NO\n";
                return 0;
        }
    }
    std::cout << "YES\n";
    return 0;
}

