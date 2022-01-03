//
// Created by mirza on 12/25/21.
//

template<typename T>
class List {
public:
    // Dodaj na početak, tj. index 0
    virtual void addToBegin(T element) = 0;

    // Dodaj na kraj tj. na zadnji index
    virtual void add(T element) = 0;

    // Uzmi element sa pocetka (indexa 0) i vrati ga.
    virtual T popFromStart() = 0;

    // Uzmi element sa kraja i vrati ga.
    virtual T pop() = 0;

    // Provjeri da li je lista prazna
    virtual bool isEmpty() = 0;

    // Operator []
    virtual T operator[](int index) = 0;

    // Vrati velicinu lista
    virtual int getSize() = 0;
};

template<typename T>
class LinkedList : public List<T> {
    struct Node {
        Node *nextNode;
        T value;
        Node(T value, Node* nextNode) {
            this->value = value;
            this->nextNode = nextNode;
        }
    };
    Node *head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }
    void addToBegin(T element) override {
        head = new Node(element, head);
        size++;
    }

    void add(T element) override {
        if(head == nullptr) head = new Node(element, nullptr);
        else if(head->nextNode == nullptr) head->nextNode = new Node(element, nullptr);
        else {
            Node *node = head;
            while (node->nextNode != nullptr) node = node->nextNode;
            node->nextNode = new Node(element, nullptr);
        }
        size++;
    }

    T popFromStart() override {
        if(head == nullptr) return 0;
        T el = head->value;
        Node *node = head->nextNode;
        delete head;
        head = head->nextNode;
        head = node;
        size--;
        return el;
    }

    T pop() override {
        if(head == nullptr) return 0;
        T value;
        if(head->nextNode == nullptr) {
            value = head->value;
            delete head; head = nullptr;
            size--;
            return value;
        } else {
            Node *tail = head;
            Node *prev_tail = head;
            while(tail->nextNode != nullptr) {
                prev_tail = tail;
                tail = tail->nextNode;
            }
            value = tail->value;
            delete tail;
            prev_tail->nextNode = nullptr;
            size--;
            return value;
        }
    }

    bool isEmpty() override {
        return head == nullptr;
    }

    T operator[](int index) override {
        if(index >= size) return 0;
        if(index == 0) return this->head->value;
        Node* node = head;
        for (int i = 0; i < index; i++) node = node->nextNode;
        return node->value;
    }

    int getSize() override {
        return this->size;
    }
};

template<typename T, int DEFAULT_MAX = 5>
class ArrayList : public List<T>{
private:
    T *array;
    int size;
    int max;
    void expandArray() {
        if(size < max) return;
        max += DEFAULT_MAX;
        T *tempArray = new T[(max)];
        for(int i = 0; i < size; i++) tempArray[i] = array[i];
        delete[] array; array = tempArray;
    }
public:
    ArrayList() {
        array = new T[DEFAULT_MAX];
        size = 0;
        max = DEFAULT_MAX;
    }
    void addToBegin(T element) override {
        if(size >= max) this->expandArray();
        for(int i = this->size; i >= 0; i--) array[i] = array[i - 1];
        array[0] = element;
        this->size++;
    }

    void add(T element) override {
        if(size >= max) this->expandArray();
        array[size++] = element;
    }

    T popFromStart() override {
        T el = array[0];
        array[0] = 0;
        for (int i = 1; i < size; i++) array[i - 1] = array[i];
        size--;
        return el;
    }

    T pop() override {
        if(size == 0) return 0;
        T element = array[--size];
        array[size] = 0;
        return element;
    }

    bool isEmpty() override {
        return this->size < 1;
    }

    T operator[](int index) override {
        if(index >= this->size) return 0;
        return array[index];
    }

    int getSize() override {
        return this->size;
    }
};
