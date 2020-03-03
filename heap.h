#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>

using namespace std;

template<typename T>
class Level{

public:
    Level(int l, int t=4):level(l),tab(t){}
    friend ostream& operator << (ostream& outs, const Level& print_me)
    {
        outs<<"[L: "<<print_me.level<<"]"<<setw(print_me.tab * print_me.level)<<"";
        return outs;
    }
private:
    int level;
    int tab;
};

template<typename T>
class Heap{
public:
    Heap()
    {
        how_many = 0;
    }
    void insert(const T& insert_me);
    T Pop();

    bool is_empty() const
    {
        return (how_many==0)?true:false;
    }

    int size() const
    {
        return how_many;
    }
    int capacity() const
    {
        return CAPACITY;
    }
    friend ostream& operator << (ostream& outs, const Heap & print_me)
    {
        print_me.print_tree(outs);
        return outs;
    }
    int get_how_many(){
        return how_many;
    }
private:
    static const int CAPACITY = 60000;
    T array[CAPACITY];
    unsigned int how_many;

    void print_tree(ostream& outs = cout) const
    {
        print_tree(0,0,outs);
    }
    void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const;

    bool is_leaf(int i) const;

    unsigned int parent_index(int i) const
    {
        return ((i-1)/2);
    }
    int left_child_index(int i)const
    {
        return 2*i+1;
    }
    int right_child_index(int i) const
    {
        return 2*i+2;
    }
    int big_child_index(int i) const;

    void swap_with_parent(int parentIndex, int childIndex);

    void checkinsert(int justInserted);
    void checkpop(int Justedpop);
};

template<typename T>
void Heap<T>::insert(const T& insert_me)
{
    unsigned int i =0;
    array[how_many] = insert_me;
    ++how_many;
    i = how_many -1;

    checkinsert(i);
}

template<typename T>
void Heap<T>::checkinsert(int justInserted)
{
    int currentParent = parent_index(justInserted);

    if(array[justInserted] > array[currentParent])
    {
        swap_with_parent(currentParent, justInserted);
        checkinsert(currentParent);
    }
}

template<typename T>
void Heap<T>::swap_with_parent(int parentIndex, int childIndex)
{
    T parentValue = array[parentIndex];
    T childValue = array[childIndex];
    array[parentIndex] = childValue;
    array[childIndex] = parentValue;
}


template<typename T>
T Heap<T>::Pop()
{
    assert(how_many>0);
    T last_value = array[0];

    array[0]=array[how_many-1];
    how_many--;

    checkpop(0);
    return last_value;
}

template<typename T>
void Heap<T>::checkpop(int Justedpop)
{
    if(array[(Justedpop)]>array[left_child_index(Justedpop)]&&array[Justedpop]>array[right_child_index(Justedpop)]&& Justedpop!=how_many)
    {
        return;
    }
    else
    {
        if(!is_leaf(Justedpop))
        {
            if(array[left_child_index(Justedpop)]>array[right_child_index(Justedpop)])
            {
                swap_with_parent(Justedpop,left_child_index(Justedpop));
                checkpop(left_child_index(Justedpop));
            }
            else
            {
                swap_with_parent(Justedpop,right_child_index(Justedpop));
                checkpop(right_child_index(Justedpop));
            }
        }
    }
}
template<typename T>
void Heap<T>::print_tree(unsigned int root, int level, ostream& outs) const
{

    if(root<how_many)
    {
        print_tree(right_child_index(root),level+1);
        outs << Level<T>(level);
        outs << array[root] << endl;
        print_tree(left_child_index(root),level+1);
    }
}

template<typename T>
bool Heap<T>::is_leaf(int i) const
{
    if(left_child_index(i)>=how_many&&right_child_index(i)>=how_many)
        return true;
    else
        return false;
}

template<typename T>
int Heap<T>::big_child_index(int i) const
{
    if(array[left_child_index(i)]>array[right_child_index(i)])
        return left_child_index(i);
    else
        return right_child_index(i);
//    return (array[left_child_index(i)]>array[right_child_index(i)])?array[left_child_index(i)]:array[right_child_index(i)];
}

#endif // HEAP_H
