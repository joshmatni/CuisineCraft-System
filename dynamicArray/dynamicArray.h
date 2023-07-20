#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;


template<class T> class DynamicArray {
        T* array;   
        int currentMaxNumElements ;   
        int currentNumElementsStored;   
        
        void increaseMaxNumElements(const int newsize);

    public:

        DynamicArray();

        DynamicArray(const DynamicArray<T>& rhs);
        
        DynamicArray<T>& operator=(const DynamicArray<T>& rhs);

        DynamicArray(int newsize, T arr);

        ~DynamicArray() ;
        
        int getCurrentNumElementsStored() const ;
        int getCurrentMaxNumElements() const ;

        void addElementToEndOfArr(const T& newitem);
        T getElementAtIndex(const int i)const;
        void replaceElementAtIndex(int i, T newItem);
        void clearArray();

};

#endif
