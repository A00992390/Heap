#include "heap.hpp"
int main()
{
    // initialize heap
    vector<int> v;
    cout << "empty heap? " << boolalpha << heap<int>::get_instance(v).is_empty() << endl;
    // add 5 integers
    heap<int>::get_instance(v).push(28);
    heap<int>::get_instance(v).push(17);
    heap<int>::get_instance(v).push(35);
    heap<int>::get_instance(v).push(20);
    heap<int>::get_instance(v).push(15);
    // print heap
    cout << "after adding 5 ints: " << heap<int>::get_instance(v) << endl;
    cout << "empty heap? " << boolalpha << heap<int>::get_instance(v).is_empty() << endl;
    // pop the two max then print
    heap<int>::get_instance(v).pop();
    heap<int>::get_instance(v).pop();
    cout << "after pop two max ints: " << heap<int>::get_instance(v) << endl;
    // push two more
    heap<int>::get_instance(v).push(19);
    heap<int>::get_instance(v).push(17);
    cout << "after adding two ints: " << heap<int>::get_instance(v) << endl;
    cout << "The sie of heap: " << heap<int>::get_instance(v).size() << endl;
    heap<int>::get_instance(v).clear();
    cout << "after clearing heap, isEmpty: " << heap<int>::get_instance(v).is_empty() << endl;

    return 0;
}
