#include <bits/stdc++.h>
using namespace std;

class Vector{
private:
    int *arr = nullptr;
    int SIZE=0;
    int capacity=0;

    void expand_capacity(){
        capacity *=2;
        int *arr2 = new int[capacity]{};
        for(int i=0;i<SIZE;++i){
            arr2[i]=arr[i];
        }
        swap(arr,arr2);
        delete[] arr;
        arr2=nullptr;
    }
public:
    Vector(int Size):SIZE(Size){
        if(Size<0)
            SIZE=1;
        capacity = SIZE+10;
        arr = new int[capacity] {};
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
    }
    int get_size(){
        return SIZE;
    }
    int Get(int idx){
        assert(idx>=0 && idx<SIZE);
        return arr[idx];
    }
    void Set(int idx, int val){
        assert(idx>=0 && idx<SIZE);
        arr[idx] =val;
    }
    void Print(){
        for(int i=0;i<SIZE; ++i){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    int Find(int val){
        for(int i=0;i<SIZE;++i){
            if(arr[i]==val){
                return i;
            }
        }
        return -1;
    }

    int get_front(){
        return arr[0];
    }
    int get_back(){
        return arr[SIZE-1];
    }

    void Push_back(int val){
        if(SIZE==capacity){
            expand_capacity();
        }
        arr[SIZE++]=val;
    }

    void Insert(int idx, int val){
        assert(idx>=0 && idx<SIZE);

        if(SIZE==capacity)
            expand_capacity();

        for(int p=SIZE-1; p>=idx;--p){
            arr[p+1]=arr[p];
        }

        arr[idx]=val;
        ++SIZE;

    }

    void right_rotate(){
        int temp=arr[SIZE-1];
        for(int i=SIZE-2;i>=0;--i){
            arr[i+1]=arr[i];
        }
        arr[0]=temp;
    }

    void left_rotate(){
        int temp=arr[0];
        for(int i=0;i<SIZE-1;++i){
            arr[i]=arr[i+1];
        }
        arr[SIZE-1]=temp;
    }
    void right_rotate(int times){
        int mod=times%SIZE;
        for(int i=0;i<mod;++i){
            right_rotate();
        }
    }

    int Pop(int idx){
        int num=arr[idx];
        for(int i=idx;i<SIZE-1;++i){
            arr[i]=arr[i+1];
        }
        SIZE--;
        return num;
    }

     int find_transposition(int value){
        int idx=Find(value);
        if(idx==-1){
            return -1;
        }else if(idx==0){
            return 0;
        }
        arr[idx]=arr[idx]+arr[idx-1];
        arr[idx-1]=arr[idx]-arr[idx-1];
        arr[idx]=arr[idx]-arr[idx-1];
        return idx-1;
     }

};
int main()
{
    Vector v(10);
    for(int i=0;i<10;++i){
        v.Set(i,i);
    }
	v.Print();//0 1 2 3 4 5 6 7 8 9
	v.right_rotate();
	v.Print();//9 0 1 2 3 4 5 6 7 8
	v.right_rotate();
	v.Print();//8 9 0 1 2 3 4 5 6 7
	v.right_rotate();
	v.Print();//8 9 0 1 2 3 4 5 6 7
    cout<<"====================\n";
    for(int i=0;i<10;++i){
        v.Set(i,i);
    }
    v.Print();//0 1 2 3 4 5 6 7 8 9
    v.left_rotate();
    v.Print();//1 2 3 4 5 6 7 8 9 0
    v.left_rotate();
    v.Print();//2 3 4 5 6 7 8 9 0 1
    v.left_rotate();
    v.Print();//3 4 5 6 7 8 9 0 1 2
    cout<<"====================\n";
    for(int i=0;i<10;++i){
        v.Set(i,i);
    }
    v.Print();//0 1 2 3 4 5 6 7 8 9
    v.right_rotate(3);
    v.Print();
    v.right_rotate(2000000000);
    v.Print();
    cout<<"====================\n";
    for(int i=0;i<10;++i){
        v.Set(i,i);
    }
    v.Print();
    v.find_transposition(3);
    v.Print();
    v.find_transposition(8);
    v.Print();
    v.find_transposition(5);
    v.Print();
    v.find_transposition(0);
    v.Print();
    cout<<"====================\n";
    for(int i=0;i<10;++i){
        v.Set(i,i);
    }
    v.Print();//0 1 2 3 4 5 6 7 8 9
    v.Pop(3);
    v.Print();//0 1 2 4 5 6 7 8 9
    v.Pop(7);
    v.Print();//0 1 2 4 5 6 7 9
    v.Pop(2);
    v.Print();//0 1 4 5 6 7 9

    return 0;
}
