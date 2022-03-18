#include <iostream>
#include <vector>

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
            if (i && heap[getParent(i)]>heap[i]){
                std::swap(heap[i], heap[getParent(i)]);
                heapifyUp(getParent(i));
            }
        }

    public:
        MinHeap(){};
        MinHeap(std::vector<int> &data){
            for(int value : data){
                heap.push_back(value);
                int index = getSize()-1;
                heapifyUp(index);
            }
        }
        ~MinHeap(){heap.clear();}

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
                for(int i =0; i<getSize();i++){

                }
            }
        }


};

int main() {

    return 0;
}
