template<class T>
class lnk{
    T data;
    lnk<T>* next;
    lnk(T data0,lnk<T>* nextval){
        data=data0;
        next=nextval;
    }
    lnk(lnk<T>* nextval){
        next=nextval;
    }
};

template<class T>
class lnklist{
private:
    lnk<T>* head,tail;
    lnk<T>* setPos(int pos);
public:
    lnklist(int s);
    ~lnklist();
    bool isEmpty();
    void clear();
    int length();
    bool append(T val);
    bool insert(int pos,T val);
    bool del(int pos);
    T getval(int pos);
    int getPos(T val);
  };

template<class T>
lnk<T>* lnklist<T>::setPos(int pos){

}

template<class T>
lnklist<T>::lnklist(int s){

}

template<class T>
lnklist<T>::~lnklist(){

}

template<class T>
bool lnklist<T>::isEmpty(){

}

template<class T>
void lnklist<T>::clear(){

}

template<class T>
int lnklist<T>::length(){

}

template<class T>
bool lnklist<T>::append(T val){

}

template<class T>
bool lnklist<T>::insert(int pos,T val){

}

template<class T>
bool lnklist<T>::del(int pos){

}

template<class T>
T lnklist<T>::getval(int pos){

}

template<class T>
int lnklist<T>::getPos(T val){

}