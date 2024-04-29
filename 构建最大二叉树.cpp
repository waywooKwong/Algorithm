#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

void putArray(int* a, vector<int> arr, int left, int right)
{   
    int index = left;
    //组内只有一个元素
    if(left == right){
        a[left] = arr[left];
        return;
    }
    for(int i=left;i<=right;i++)
    {
        if(arr[i]>arr[index]){
            index = i; 
        }
    }
    a[index]=arr[index];
    if(index != left){
        putArray(a,arr,left,index-1);
    }
    if(index != right){
        putArray(a,arr,index+1,right);
    }
}

void levelOrder(int* a, int size)
{
    queue<int> q;
    q.push(0); 
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        cout << a[index] << " ";
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        if (left_child < size) {
            q.push(left_child);
        }
        if (right_child < size) {
            q.push(right_child);
        }
    }
}

int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> arr;
    int num;
    while(iss >> num){
        arr.push_back(num);
    }
    int * a = new int[arr.size()];
    
    putArray(a,arr,0,arr.size()-1);
    levelOrder(a, arr.size());
    
    delete[] a; 
    return 0;
}
