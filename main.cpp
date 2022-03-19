#include <iostream>
#include <vector>
int COUNT=0;
class MinHeap{
    private:
        std::vector<int> heap;
        static int getParent (int i){
            return (i-1)/2;
        }
        static int getLeft (int i){
            return (2*i+1);
        }

        static int getRight (int i){
            return (2*i+2);
        }

        void heapifyDown(int i){
            COUNT++;
            int left = getLeft(i);
            int right = getRight(i);
            int smallest =  i;

            if (left<getSize()&&heap[left]<heap[i]){
                smallest = left;
            }
            if (right<getSize()&& heap[right]<heap[smallest]){
                smallest = right;
            }

            if (smallest!=i){
                std::swap(heap[i],heap[smallest]);
                heapifyDown(smallest);
            }
        }
        void heapifyUp (int i){
            COUNT++;
            if (i && heap[getParent(i)]>heap[i]){
                std::swap(heap[i], heap[getParent(i)]);
                heapifyUp(getParent(i));
            }
        }

    public:
        MinHeap()= default;;
        explicit MinHeap(std::vector<int> &data){
            for(int value : data){
                push(value);
            }
        }
        ~MinHeap(){clear();}

        void clear(){
            heap.clear();
        }

        unsigned int getSize(){
            return heap.size();
        }

        bool isEmpty (){
            return getSize()==0;
        }
        void push (int value){
            heap.push_back(value);
            int index = getSize()-1;
            heapifyUp(index);

        }

        void print(){
            if (!isEmpty()){
                for (int i =0; i<getSize();i++){
                    std::cout<<heap[i]<<"\t";
                }
                std::cout<<std::endl;
            }
        }


};

int main() {
    srand( time(nullptr) );
    const int MAX_NUM = 2048;
    //best case
    std::cout<<"Best case:\n";
    MinHeap mh;
    for (int num = 8;num <=MAX_NUM;num*=2){
        for (int i = 0; i<num;i++){
            mh.push(i);
        }
//        mh.print();
        mh.clear();
        std::cout<<"for num = "<<num<<"\t count = "<<COUNT<<"\n";
        COUNT = 0;
    }


//   worst case
    std::cout<<"Worst case:\n";
    for (int num = 8;num <=MAX_NUM;num*=2){
        for (int i = num; i>0;i--){
            mh.push(i);
        }
//        mh.print();
        mh.clear();
        std::cout<<"for num = "<<num<<"\t count = "<<COUNT<<"\n";
        COUNT = 0;
    }


//    random case
    std::cout<<"Random case:\n";
    for (int num = 8;num <=MAX_NUM;num*=2){
        for (int i = 0; i<num;i++){
            mh.push(rand()%1000);
        }
//        mh.print();
        mh.clear();
        std::cout<<"for num = "<<num<<"\t count = "<<COUNT<<"\n";
        COUNT = 0;
    }


    return 0;
}
