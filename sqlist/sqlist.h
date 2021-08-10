#ifndef _SQLIST_H_
#define  _SQLIST_H_

#include<iostream>
using namespace std;

template <class T>
class sqlist{
    T* list;
    int maxsize;
    int cursize;
    int pos;
public:
    sqlist(int size){
        maxsize=size;
        cursize=pos=0;
        list=new T[maxsize];
    }
    ~sqlist(){
        delete [] list;
    }
    void clear(){
        delete [] list;
        list=new T[maxsize];
    }
    int length();
    bool append(T val);
    bool insert(int pos,T val);
    bool del(int pos);
    bool setval(int pos,T val);
    T getval(int pos);
    int getPos(T val);
};




template<class T>
int sqlist<T>::length(){
    return cursize;
}



template<class T>
bool sqlist<T>::append(T val){
    if(cursize>=maxsize){
        cout<<"the list is overflow"<<endl;
        return false;
    }
    list[cursize++]=val;
    return true;
}



template<class T>
bool sqlist<T>::insert(int pos,T val){
    if(cursize>=maxsize){
        cout<<"the list is overflow"<<endl;
        return false;
    }
    if(pos<0||pos>cursize){
        cout<<"wrong position!(insert)"<<endl;
        return false;
    }
    //后面的元素后移
    for(int i=cursize;i>pos;i--){
        list[i]=list[i-1];
    }
    list[pos]=val;
    cursize++;
    return true;
}



template<class T>
bool sqlist<T>::del(int pos){
    if(cursize<=0){
        cout<<"this list is empty now!"<<endl;
        return false;
    }
    if(pos<0||pos>cursize){
        cout<<"wrong position!(del)"<<endl;
        return false;
    }
    //后面的元素前移
    for(int i=pos;i<cursize-1;i++){
        list[i]=list[i+1];
    }
    cursize--;
    return true;
}



template<class T>
bool sqlist<T>::setval(int pos,T val){
    if(pos<0||pos>cursize){
        cout<<"wrong position!(setval)"<<endl;
        return false;
    }
    list[pos]=val;
    return true;
}



template<class T>
T sqlist<T>::getval(int pos){
    if(pos<0||pos>cursize){
        cout<<"wrong position!(getval)"<<endl;
        return false;
    }
    return list[pos];
}



template<class T>
int sqlist<T>::getPos(T val){
    for(int i=0;i<cursize;i++){
        if(list[i]==val){
            return i;
        }
    }
    return -1;
}

#endif
