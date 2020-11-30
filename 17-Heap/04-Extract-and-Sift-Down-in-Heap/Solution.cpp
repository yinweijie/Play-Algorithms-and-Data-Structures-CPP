/// 347. Top K Frequent Elements
/// https://leetcode.com/problems/top-k-frequent-elements/description/
///
/// 课程中在这里暂时没有介绍这个问题
/// 该代码主要用于使用Leetcode上的问题测试我们的MaxHeap类

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:

template<typename T>
class Array
{
private:
    T* m_data;
    int m_size;
    int m_capacity;

    friend ostream& operator<<(ostream& os, const Array<T>& array)
    {
        os << "Array: size = " << array.m_size << " , capacity = " << array.m_capacity << endl;
        os << "[";
        for(int i = 0; i < array.m_size; i++)
        {
            os << array.m_data[i];
            if(i != array.m_size - 1)
            {
                os << ", ";
            }
        }
        os << "]";

        return os;
    }

    void resize(int newCapacity)
    {
        T* toDel = m_data;
        m_data = new T[newCapacity];
        m_capacity = newCapacity;

        for(int i = 0; i < m_size; i++)
        {
            m_data[i] = toDel[i];
        }

        delete[] toDel;
    }
public:
    Array(int capacity = 10) : m_capacity(capacity)
    {
        m_data = new T[capacity];
        m_size = 0;
    }

    int getCapacity() const
    {
        return m_capacity;
    }

    int getSize() const
    {
        return m_size;
    }

    int isEmpty() const
    {
        return m_size == 0;
    }

    // 向所有元素后添加一个新元素
    void addLast(T e)
    {
        add(m_size, e);
    }

    // 在所有元素前添加一个新元素
    void addFirst(T e)
    {
        add(0, e);
    }

    // 在index索引的位置插入一个新元素e
    void add(int index, T e)
    {
        if(index < 0 || index > m_size)
        {
            throw std::invalid_argument("Add failed. Require index >= 0 and index <= size.");
        }

        if(m_size == m_capacity)
        {
            resize(2 * m_capacity);
        }

        for(int i = m_size - 1; i >= index; i--)
        {
            m_data[i + 1] = m_data[i];
        }

        m_data[index] = e;

        m_size++;
    }

    T get(int index) const
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        return m_data[index];
    }

    void set(int index, T e)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Get failed. Index is illegal.");
        }

        m_data[index] = e;
    }

    // 查找数组中是否有元素e
    bool contains(T e)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] == e)
            {
                return true;
            }
        }

        return false;
    }

    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(T e)
    {
        for(int i = 0; i < m_size; i++)
        {
            if(m_data[i] == e)
            {
                return i;
            }
        }

        return -1;
    }

    // 从数组中删除index位置的元素, 返回删除的元素
    T remove(int index)
    {
        if(index < 0 || index >= m_size)
        {
            throw std::invalid_argument("Remove failed. Index is illegal.");
        }

        T ret = m_data[index];

        for(int i = index + 1; i < m_size; i++)
        {
            m_data[i - 1] = m_data[i];
        }

        m_size--;

        if(m_size == m_capacity / 2)
        {
            resize(m_capacity / 2);
        }

        return ret;
    }

    // 从数组中删除第一个元素, 返回删除的元素
    T removeFirst()
    {
        return remove(0);
    }

    // 从数组中删除最后一个元素, 返回删除的元素
    T removeLast()
    {
        return remove(m_size - 1);
    }

    // 从数组中删除元素e
    void removeElement(T e)
    {
        int index = find(e);

        if(index != -1)
        {
            remove(index);
        }
    }

    void swap(int i, int j)
    {
        if(i < 0 || i >= m_size || j < 0 || j >= m_size)
        {
            throw std::invalid_argument("Index is illegal.");
        }

        T tmp = m_data[i];
        m_data[i] = m_data[j];
        m_data[j] = tmp;
    }
};

private:

template <typename T>
class MaxHeap
{
private:
    Array<T> m_data;

public:
    MaxHeap(int capacity) : m_data(capacity) { }

    MaxHeap() = default;

    // 返回堆中的元素个数
    int size()
    {
        return m_data.getSize();
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty()
    {
        return m_data.isEmpty();
    }

private:
    // 返回完全二叉树的数组表示中，一个索引所表示的元素的父亲节点的索引
    int parent(int index)
    {
        if(index == 0)
        {
            throw std::invalid_argument("index-0 doesn't have parent.");
        }

        return (index - 1) / 2;
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    int leftChild(int index)
    {
        return (index * 2) + 1;
    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
    int rightChild(int index)
    {
        return (index * 2) + 2;
    }

public:
    // 向堆中添加元素
    void add(T e)
    {
        m_data.addLast(e);
        siftUp(m_data.getSize() - 1);
    }

private:
    void siftUp(int k)
    {
        while(k > 0 && m_data.get(k) > m_data.get(parent(k)))
        {
            m_data.swap(k, parent(k));
            k = parent(k);
        }
    }

public:
    // 看堆中的最大元素
    T findMax()
    {
        if(m_data.getSize() == 0)
        {
            throw std::invalid_argument("Can not findMax when heap is empty.");
        }

        return m_data.get(0);
    }

    // 取出堆中最大元素
    T extractMax()
    {
        T res = findMax();

        m_data.swap(0, m_data.getSize() - 1);
        m_data.removeLast();
        siftDown(0);

        return res;
    }

private:
    void siftDown(int k)
    {
        while(leftChild(k) < m_data.getSize())
        {
            int j = leftChild(k);
            if(j + 1 < m_data.getSize() && m_data.get(j + 1) > m_data.get(j))
            {
                j++;
            }

            if(m_data.get(k) >= m_data.get(j))
            {
                break;
            }

            m_data.swap(k, j);
            k = j;
        }
    }
};

class Freq {
public:
    int e, freq;

    Freq() = default;

    Freq(int e, int freq){
        this->e = e;
        this->freq = freq;
    };

    bool operator<(const Freq& rhs) const {
        return freq < rhs.freq;
    }
    bool operator<=(const Freq& rhs) const {
        return freq <= rhs.freq;
    }

    bool operator>(const Freq& rhs) const {
        return freq > rhs.freq;
    }
    bool operator>=(const Freq& rhs) const {
        return freq >= rhs.freq;
    }

    bool operator==(const Freq& rhs) const {
        return freq == rhs.freq;
    }
};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m_map;
        for(int num: nums){
            if(m_map.find(num) != m_map.end())
                m_map[num] += 1;
            else
                m_map.insert(std::pair<int, int>(num, 1));
        }

        MaxHeap<Freq> maxHeap;
        for(auto it = m_map.begin(); it != m_map.end(); it++){
            int key = it->first;
            int value = it->second;
            if(maxHeap.size() < k){
                maxHeap.add(Freq(key, value));
            }
            else if(value > maxHeap.findMax().freq){
                maxHeap.extractMax();
                maxHeap.add(Freq(key, value));
            }
        }

        vector<int> res;
        while(!maxHeap.isEmpty())
            res.push_back(maxHeap.extractMax().e);
        return res;
    }
};

void printList(vector<int> nums){
    for(auto num: nums)
        cout << num << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};;
    int k = 2;
    printList((Solution()).topKFrequent(nums, k));

    return 0;
}