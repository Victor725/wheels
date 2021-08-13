#include<exception>
#include<iostream>
using namespace std;

template<class T>
class lnk{
public:
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
    lnk<T>* head,*tail;  //tail points to last  head points to -1
    lnk<T>* setPos(int pos);
    int len;
public:
    lnklist(int s);
    ~lnklist();
    lnk<T>* headis(){
        return head;
    }
    lnk<T>* tailis(){
        return tail;
    }
    bool isEmpty();
    void clear();
    int length();
    bool append(T val);
    bool insert(int pos,T val);
    bool del(int pos);
    T getval(int pos);
    int getPos(T val);
    void show();
  };

template<class T>
lnklist<T>::lnklist(int s){
    //initialize head and tail
    head=new lnk<T>(nullptr);
    tail=nullptr;
    len=0;

    //get values
    for(int i=0;i<s;i++){
        T val;
        cin>>val;
        lnk<T>* p=new lnk<T>(val);
        if(i==0){
            head->next=p;
            tail=p;
            len++;
            continue;
        }
        append(val);
    }
}

template<class T>
lnklist<T>::~lnklist(){
    lnk<T>* p=head->next;
    while(p!=NULL){
        lnk<T>* tem=p;
        p=p->next;
        delete tem;
    }
    delete head;
    tail=NULL;
}

template<class T>
lnk<T>* lnklist<T>::setPos(int pos){
    if(pos<-1||pos>len-1) return NULL;
    if(pos==-1) return head;
    if(pos==len-1) return tail;
    lnk<T>* p=head->next;
    int count=0;
    while(p!=NULL&&count<pos){
        p=p->next;
        count++;
    }
    return p;
}

template<class T>
bool lnklist<T>::isEmpty(){
    if(len==0) return true;
    return false;
}

template<class T>
void lnklist<T>::clear(){
    if(len==0) return;
    lnk<T>* p=head->next;
    lnk<T>* tem;
    while(p!=NULL){
        tem=p;
        p=p->next;
        delete tem;
    }
    tail=NULL;
    head->next=NULL;
    len=0;
}

template<class T>
int lnklist<T>::length(){
    return len;
}

template<class T>
bool lnklist<T>::append(T val){
    lnk<T>* p=new lnk<T>(val);
    tail->next=p;
    tail=p;
    len++;
    return true;
}

template<class T>
bool lnklist<T>::insert(int pos,T val){
    if(pos<0||pos>=len) return false;
    try{
        lnk<T>* tem=new lnk<T>(val);
        //only have a little effect...
        if(pos==0){//add to the beginning
            tem->next=head->next;
            head->next=tem;
            len++;
            return true;
        }
        
        lnk<T>* p=setPos(pos-1);
        if(p!=NULL){
            tem->next=p->next;
            p->next=tem;
            len++;
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
    if(pos<0||pos>=len) return false;
    try{
        lnk<T>* p=setPos(pos-1);
        lnk<T>* tem=p->next;
        p->next=tem->next;
        delete tem;
        len--;
        return true;
    }
    catch(...){
        return false;
    }
}

template<class T>
T lnklist<T>::getval(int pos){
    if(pos<0||pos>=len) return false;
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

template<class T>
void lnklist<T>::show(){
    lnk<T>* p=head->next;
    int i=0;
    while(p!=NULL){
        if(i%5==0) cout<<endl;
        cout<<p->data<<"  ";
        i++;
        p=p->next;
    }
    cout<<endl;
}