#include "dynamicArray.h"

template <class T>
void DynamicArray<T>::increaseMaxNumElements(const int newsize){
    T* temp = new T[newsize];

    for (int i=0; i < currentMaxNumElements; i++){ 
        temp[i] = array[i];
    }

    delete[] array;
    currentMaxNumElements = newsize;
    array = temp;
}       
template <class T>
DynamicArray<T>::DynamicArray(){
    currentMaxNumElements = 1;
    currentNumElementsStored = 0;
    array = new T[currentMaxNumElements];
}
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& rhs){
    currentMaxNumElements = rhs.getCurrentMaxNumElements();
    currentNumElementsStored = rhs.getCurrentNumElementsStored();
    array = new T [rhs.getCurrentMaxNumElements()];

    for (int i = 0; i < currentMaxNumElements; i++){
        array[i] = rhs.array[i];
    }
}
template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs){
    delete[] array;  
    currentNumElementsStored = rhs.getCurrentNumElementsStored();
    currentMaxNumElements = rhs.getCurrentMaxNumElements();
    array = new T[currentMaxNumElements];
    for (int i=0; i < currentMaxNumElements; i++){
        array[i] = rhs.array[i];

    }
    return *this;
} 
template <class T>
DynamicArray<T>::DynamicArray(int newsize, T arr){
    currentMaxNumElements = newsize;
    currentNumElementsStored = newsize;
    array = new T[newsize];
    for (int i=0; i < newsize; i++){
        array[i] = arr; 
    }
}            
template <class T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}
template <class T>
int DynamicArray<T>::getCurrentNumElementsStored() const {
    return currentNumElementsStored;
}
template <class T>
int DynamicArray<T>::getCurrentMaxNumElements() const {
    return currentMaxNumElements;
}
template <class T>
void DynamicArray<T>::addElementToEndOfArr(const T& newitem){
    if (currentNumElementsStored == currentMaxNumElements){
        increaseMaxNumElements(currentMaxNumElements*2);
    }

    array[currentNumElementsStored] = newitem;
    currentNumElementsStored++;
}
template <class T>
T DynamicArray<T>::getElementAtIndex(const int i)const{
    return array[i];
}
template <class T>
void DynamicArray<T>::replaceElementAtIndex(int i, T newItem){
    array[i] = newItem;
}
template <class T>
void DynamicArray<T>::clearArray(){
    //~DynamicArray(); //clear it
    delete [] array;
    array = new T[1]; //give memory
    currentMaxNumElements = 1;
    currentNumElementsStored = 0;

}