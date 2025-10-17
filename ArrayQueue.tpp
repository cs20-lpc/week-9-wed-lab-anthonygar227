template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    if (i > 0) {
        maxSize = i;
    } else {
        maxSize = 100;
    }

    buffer = new T[maxSize];
    this->length = 0;
    frontIndex = 0;

    backIndex = maxSize - 1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    if (buffer != nullptr) {
        delete[] buffer;
        buffer = nullptr;
    }
    this->length = 0;
    frontIndex = 0;
    backIndex = maxSize - 1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    if (maxSize > 0) {
        buffer = new T[maxSize];
        for (int i = 0; i < maxSize; i++) {
            buffer[i] = copyObj.buffer[i];
        }
    } else {
        buffer = nullptr;
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("error, queue is empty, cannot dequeue");
    }
    frontIndex++;
    if (frontIndex == maxSize) {
        frontIndex = 0;
    }
    this->length--;
    if (this->length == 0) {
        frontIndex = 0;
        backIndex = maxSize - 1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {
        throw string("error, queue is full, cannot enqueue");
    }
    backIndex++;
    if (backIndex == maxSize) {
        backIndex = 0;
    }
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
