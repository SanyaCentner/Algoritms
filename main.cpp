/*
Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
Требуется построить бинарное дерево, заданное наивным порядком вставки.
Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K
 добавляется в правое поддерево root; иначе в левое поддерево root.
Требования: Рекурсия запрещена. Решение должно поддерживать передачу функции сравнения снаружи.
2_3. Выведите элементы в порядке post-order (снизу вверх).
 */
#include <iostream>
#include <memory>
#include <vector>
#include <stack>

template<class T>
struct Node {
    Node(int value): left(nullptr), right(nullptr), value(value), prev_node(true) {}
    Node *left;
    Node *right;

    bool prev_node;

    T value;
};

template<class T>
struct DefaultComparator {
    bool operator() (const T& l, const T& r) const {
        return r <= l;
    }
};

template<class T, class Comparator=DefaultComparator<T>>
class Tree {
public:
    explicit Tree(Comparator comp = Comparator()): root(nullptr), comp(comp) {}

    void Add(T value) {
        if (root == nullptr) {
            root = new Node<T>(value);
            return;
        }
        Node<T> **cur_node = &root;
        while (true) {
            int comp_res = comp((*cur_node)->value, value);
            if (comp_res) {
                if ((*cur_node)->prev_node || (*cur_node)->left == nullptr) {
                    (*cur_node)->left = new Node<T>(value);
                    (*cur_node)->prev_node = false;
                    break;
                } else {
                    cur_node = &((*cur_node)->left);
                }
            } else {
                if ((*cur_node)->prev_node || (*cur_node)->right == nullptr) {
                    (*cur_node)->right = new Node<T>(value);
                    (*cur_node)->prev_node = false;
                    break;
                } else {
                    cur_node = &((*cur_node)->right);
                }
            }
        }
    }

    void print_tree() {
        std::shared_ptr<std::stack<Node<T>*>> s = get_stack();
        while (!s->empty()) {
            std::cout << s->top()->value << " ";
            s->pop();
        }
    }


    ~Tree() {
        std::shared_ptr<std::stack<Node<T>*>> s = get_stack();
        while (!s->empty()) {
            delete s->top();
            s->pop();
        }
    }

private:
    std::shared_ptr<std::stack<Node<T>*>> get_stack() {
        std::stack<Node<T>*> s1;
        std::stack<Node<T>*> s2;
        s1.push(root);
        while(true) {
            Node<T> *out = s1.top();
            s1.pop();
            if (out->left) {
                s1.push(out->left);
            }
            if (out->right) {
                s1.push(out->right);
            }
            s2.push(out);
            if (s1.empty()){
                break;
            }
        }
        return std::make_shared<std::stack<Node<T>*>>(s2);
    }

    Node<T> *root;
    Comparator comp;
};

void run(std::istream &is, std::ostream &os) {
    int n;
    is >> n;
    Tree<int> tree;
    for (int i = 0; i < n; ++i) {
        int number;
        is >> number;
        tree.Add(number);
    }
    tree.print_tree();
}

int main() {
    run(std::cin, std::cout);
    return 0;
}
