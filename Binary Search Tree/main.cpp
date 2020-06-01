#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void print (int start, int finish, int arr[]){
    if(start == finish){
        cout << arr[start] << " ";
        return;
    }
    int mid = (finish + start) / 2;
    cout<<arr[mid]<<" ";
    if((mid-1)>=start)
        print(start, mid - 1, arr);
    if((mid+1)<=finish)
        print(mid+1, finish, arr);
}

int main() {
    int n;
    cout<< "enter how many nodes" << endl;
    cin>>n;

    TreeType<int> inputTree;
    for(int i=0; i<n; i++){
        int in = 0;
        cin>>in;
        inputTree.InsertItem(in);
    }


    cout<<"Total Leaf of the BST is :"<<inputTree.TotalLeaf()<<endl;
    cout<<"Height of the BST is :"<<inputTree.heightTree()<<endl;

    return 0;

}
