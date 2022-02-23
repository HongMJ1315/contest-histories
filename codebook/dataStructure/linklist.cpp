struct linklist{
    struct node{
        int value;
        node *front, *back;
        node(){
            front = back = nullptr;
        }
    }*begin, *end;
    int size = 0;
    linklist(){
        begin = end = new node();
        size = 0;
    }
    void push_back(int k){
        node *tmp;
        if(size == 0){
            begin->value = k;
            size++;
            return;
        }
        tmp = begin;
        node *a = new node();
        a->value = k;
        while(tmp->back != nullptr){
            tmp = tmp->back;
        }
        tmp->back = a;
        a->front = tmp;
        end = a;
        size++;
    }
    void insert(int loc, int k){
        node *tmp = begin, *a = new node(), *tmp2 = tmp;
        a->value = k;
        int now = 0;
        while(now != loc){
            now++;
            tmp2 = tmp;
            tmp = tmp->back;
        }
        tmp2->back = a;
        tmp->front = a;
        a->front = tmp->front;
        a->back = tmp;
        size++;
    }
    void push_front(int k){
        if(size == 0){
            begin->value = k;
            size++;
            return;
        }
        node *a = new node();
        a->value = k;
        begin->front = a;
        a->back = begin;
        begin = a;
        size++;
    }
    void remove(int loc){
        node *tmp = begin, *tmp2 = begin;
        int now = 0;
        while(now != loc){
            now++;
            tmp2 = tmp;
            tmp = tmp->back;
        }
        tmp2->back = tmp->back;
        tmp->back->front = tmp2;
        delete tmp;
        size--;
    }
    void pop_back(){
        if(size == 1){
            size = 0;
            return;
        }
        end = end->front;
        delete end->back;
        end->back = nullptr;
        size--;
    }
    void pop_front(){
        if(size == 1){
            size = 0;
            return;
        }
        begin = begin->back;
        delete begin->front;
        begin->front = nullptr;
        size--;
    }
    void print(){
        node *tmp = begin;
        while(tmp != nullptr and size != 0){
            //print something
            tmp = tmp->back;
        }
    }
    int front(){ return begin->value; }
    int back(){ return end->value; }
    bool empty(){ return size == 0; }
};