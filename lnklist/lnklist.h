#include<exception>

template<class T>
class lnk{
    T data;
    lnk<T>* next;
    lnk(T data0,lnk<T>* nextval=NULL){
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
    lnk<T>* head,tail;  //tail points to last  head points to -1
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
    if(pos==-1) return head;
    lnk<T>* p=head->next;
    int count=0;
    while(p!=NULL&&count<pos){
        p=p->next;
        count++;
    }
    return p;
}

template<class T>
lnklist<T>::lnklist(int s){

}

template<class T>
lnklist<T>::~lnklist(){

}

template<class T>
bool lnklist<T>::isEmpty(){
    if(head->next==NULL) return true;
    return false;
}

template<class T>
void lnklist<T>::clear(){
    lnk<T>* p=head->next;
    lnk<T>* tem;
    while(p!=NULL){
        tem=p;
        p=p->next;
        delete tem;
    }
    tail=NULL;
}

template<class T>
int lnklist<T>::length(){
    int i=0;
    lnk<T>* p=head->next;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    return i;
}

template<class T>
bool lnklist<T>::append(T val){
    lnk<T>* p=new lnk<T>(val);
    tail->next=p;
    tail=p;
    return true;
}

template<class T>
bool lnklist<T>::insert(int pos,T val){
    lnk<T>* p=setPos(pos-1);
    try{
        if(p!=NULL){
            lnk<T>* tem=new lnk<T>(val);
            tem->next=p->next;
            p->next=tem;
            return true;
        }
        else return false;
    }
    catch(...){
        return false;
    }
}

template<class T>
bool lnklist<T>::del(int pos){
    try{
        lnk<T>* p=setPos(pos-1);
        lnk<T>* tem=p->next;
        p->next=tem->next;
        delete tem;
        return true;
    }
    catch(...){
        return false;
    }
}

template<class T>
T lnklist<T>::getval(int pos){
    lnk<T>* p=setPos(pos);
    return p->data;
}

template<class T>
int lnklist<T>::getPos(T val){
    lnk<T>* p=head->next;
    int i=0;
    while(p!=NULL){
        if(p->data==val){
            return i;
        }
        p=p->next;
        i++;
    }    
    return -1;
}