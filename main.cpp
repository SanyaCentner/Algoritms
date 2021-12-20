/*
4_2. Порядковые статистики. Дано число N и N строк. Каждая строка содержит команду добавления или
удаления натуральных чисел, а также запрос на получение k-ой порядковой статистики. Команда добавления
числа A задается положительным числом A, команда удаления числа A задается отрицательным числом “-A”.
Запрос на получение k-ой порядковой статистики задается числом k.
Требования: скорость выполнения запроса - O(log n).
 */


#include <cassert>
#include <cmath>
#include <iostream>
#include <stack>

template<class T>
class AVL_tree {

public:
    struct Node {
        explicit Node(T key): key(key), height(1), left(nullptr), right(nullptr), number_node(1) {}
        T key;
        unsigned char height = 1;
        Node *left{nullptr};
        Node *right{nullptr};
        size_t number_node = 1;

    };
    AVL_tree() = default;
    explicit AVL_tree(const AVL_tree &) = delete;
    explicit AVL_tree(const AVL_tree &&) = delete;
    AVL_tree &operator=(const AVL_tree &) = delete;
    AVL_tree &operator=(const AVL_tree &&) = delete;
    ~AVL_tree() {
        std::stack<Node *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            Node *temp = nodes.top();
            nodes.pop();
            if (temp->right != nullptr) {
                nodes.push(temp->right);
            }
            if (temp->left != nullptr) {
                nodes.push(temp->left);
            }
            delete temp;
        }
    }

    T kth(size_t pos) {
        return Find_ktn(root, pos);
    }

    void Add(T key) {
        root = addInternal(root, key);
    };
    void Remove(T key){
        root = removeInternal(root, key);
    };
private:

    unsigned char getHeight(Node *node) {
        return (node ? node->height : 0);
    }

    int getBalance(Node *node) {
        return (getHeight(node->right) - getHeight(node->left));
    }

    void fixHeight(Node *node) {
        unsigned char heigt_left = getHeight(node->left);
        unsigned char heigt_right = getHeight(node->right);
        node->height = (heigt_left > heigt_right ? heigt_left : heigt_right) + 1;
    }

    int CountNodes(Node *node) {
        return (node ? node->number_node : 0);
    }

    void FixCountNodes(Node *node) {
        int nl = CountNodes(node->left);
        int nr = CountNodes(node->right);
        node->number_node = nl + nr + 1;
    }
    Node *root = nullptr;

    Node *addInternal(Node *node, T key) {
        if (!node) {
            return new Node(key);
        }
        node -> number_node++;
        if (node->key <= key) {
            node->right = addInternal(node->right, key);
        } else {
            node->left = addInternal(node->left, key);
        }
        return doBalance(node);
    }

    Node *removeInternal(Node *node, T key) {
        if (!node) {
            return nullptr;
        }
        node->number_node--;
        if (node->key < key) {
            node->right = removeInternal(node->right, key);
        } else if (node->key > key) {
            node->left = removeInternal(node->left, key);
        } else {
            Node *left = node->left;
            Node *right = node->right;
            delete node;

            if (!right) {
                return left;
            }

            Node *min = nullptr;
            if (right->left != nullptr) {
                Node *parentMin = findMin(right);
                min = parentMin->left;
                parentMin->left = min->right;
                min->right = right;
            } else {
                min = right;
            }
            min->left = left;
            return doBalance(min);
        }
        return doBalance(node);
    }

    Node *findMin(Node *node) {
        node->number_node--;
        Node *parent = node->left;
        Node *child = parent->left;
        return (child != nullptr) ? findMin(child) : node;
    }

    Node *find_and_remove_min(Node *node, Node *min) {
        if (!node->left) {
            min = node;
            return node->right;
        }
        node->left = find_and_remove_min(node->left, min);
        return doBalance(node);
    }

    Node *rotateRight(Node *node) {
        Node *tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;

        fixHeight(node);
        fixHeight(tmp);
        FixCountNodes(node);
        FixCountNodes(tmp);
        return tmp;
    }

    Node *rotateLeft(Node *node) {
        Node *tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        fixHeight(node);
        fixHeight(tmp);
        FixCountNodes(node);
        FixCountNodes(tmp);
        return tmp;
    }

    Node *doBalance(Node *node) {
        fixHeight(node);
        FixCountNodes(node);
        if (getBalance(node) == 2) {
            if (getBalance(node->right) < 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if (getBalance(node) == -2) {
            if (getBalance(node->left) > 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }

    T Find_ktn(Node *node, size_t pos) {
        assert(node != nullptr);
        size_t position = CountNodes(node->left);
        if (pos == position) {
            return node->key;
        }
        if (pos < position) {
            return Find_ktn(node->left, pos);
        }
        return Find_ktn(node->right, pos - position - 1);
    }


};

void run(std::istream &in, std::ostream &out) {
    int n = 0;
    in >> n;
    AVL_tree<int> tree;
    for (int  i = 0; i < n; i++) {
        int number = 0, kth = 0;
        in >> number >> kth;
        if (number >= 0) {
            tree.Add(number);
        } else {
            tree.Remove(std::abs(number));
        }
        out << tree.kth(kth) << std::endl;
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}

