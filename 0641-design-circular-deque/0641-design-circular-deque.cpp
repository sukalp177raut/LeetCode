class MyCircularDeque {
    vector<int> arr;
    int front;
    int count;
    int size;

public:
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        count = 0;
        size = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front + size - 1) % size;

        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        int rear = (front + count) % size;
        arr[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % size;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        int rear = (front + count - 1) % size;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        int rear = (front + count - 1) % size;

        return arr[rear];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == size; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */