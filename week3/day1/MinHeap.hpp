
template <class T>
class MinHeap
{
private:
    int capacity;
    int size;
    T *arr;

public:
    MinHeap(int c) : size(0), capacity(c), arr(new T[capacity + 1]) {}

    ~MinHeap()
    {
        delete[] arr;
    }

    MinHeap(const MinHeap &) = delete;
    MinHeap &operator=(const MinHeap &) = delete;

    void swap(int a, int b)
    {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void insert(const T &val) // O(log n)
    {
        if (size == capacity)
        {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T *arr1 = new T[capacity + 1];
            for (int i = 1; i <= size; i++)
            {
                arr1[i] = arr[i];
            }
            delete[] arr;
            arr = arr1;
        }
        size++;
        int idx = size;
        arr[idx] = val;
        while (idx > 1)
        {
            if (arr[idx] < arr[idx / 2])
            {
                swap(idx, idx / 2);
                idx /= 2;
            }
            else
                break;
        }
    }

    T extractMin()
    {
        if (size == 0)
            throw std::range_error("Heap is impty");
        if (size == 1)
        {
            T val = arr[1];
            size--;
            return val;
        }
        T val = arr[1];
        arr[1] = arr[size];
        size--;
        int idx = 1;
        while (2 * idx <= size)
        {
            int child = 2 * idx; // Left child
            if (child + 1 <= size && arr[child + 1] < arr[child])
                child++;

            if (arr[idx] > arr[child])
            {
                swap(idx, child);
                idx = child;
            }
            else
                break;
        }
        return val;
    }

    void buildHeap(const std::vector<T> &v)
    {
        if (v.size() > capacity)
        {
            delete[] arr;
            capacity = v.size() * 2;
            arr = new T[capacity + 1];
        }

        size = v.size();
        for (int i = 0; i < size; i++)
            arr[i + 1] = v[i];

        for (int i = size / 2; i >= 1; i--)
        {
            int idx = i;
            while (2 * idx <= size)
            {
                int child = 2 * idx;
                if (child + 1 <= size && arr[child + 1] < arr[child])
                    child++;

                if (arr[idx] > arr[child])
                {
                    swap(idx, child);
                    idx = child;
                }
                else
                    break;
            }
        }
    }

    void heapSort(std::vector<T> &v)
    {
        buildHeap(v);
        for (int i = 0; i < v.size(); i++)
        {
            v[i] = extractMin();
        }
    }
};