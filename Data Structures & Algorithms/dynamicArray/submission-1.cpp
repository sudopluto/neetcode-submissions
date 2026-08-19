class DynamicArray {
    int capacity;
    int size;
    int* buff;

    void resize() {
        this->capacity *= 2;

        int* new_buff = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            new_buff[i] = this->buff[i];
        }

        delete[] this->buff;
        this->buff = new_buff;
    }

public:

    DynamicArray(int capacity)
    : capacity(capacity), size(0), buff(nullptr)
    {
       buff = new int[capacity];
    }

    int get(int i) const {
        return this->buff[i];
    }

    void set(int i, int n) {
        this->buff[i] = n;
    }

    void pushback(int n) {
        if (this->size == this->capacity) {
            this->resize();
        }

        this->buff[this->size++] = n;
    }

    int popback() {
        return this->buff[--this->size];
    }

    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }
};
