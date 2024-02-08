#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct process{
    string process_id;
    int bt,ct,tat,wt;
};

class compare{
    public:
    bool operator() (process a, process b){
        return a.bt > b.bt;
    }
};

int main(){
    int n;
    priority_queue <process, vector<process> , compare> minheap;
    cout<<"Enter the number of processes"<<endl;
    cin >> n;

    vector <process> ans;
    for (int i=0; i<n; i++){
        process temp;
        cin >> temp.process_id >> temp.bt;
        minheap.push(temp);
    }

    float sum_tat = 0;
    float sum_wt = 0;
    int time = 0;
    for(int i=0; i<n; i++){
        process top = minheap.top();
        minheap.pop();
        time += top.bt;
        top.ct = time;
        top.tat = top.ct - 0;
        top.wt = top.tat - top.bt;

        sum_tat += top.tat;
        sum_wt += top.wt;
        ans.push_back(top);
    }

    cout<<"Process_id\tburst time\tturn around time\twaiting time\n";
    cout<<"----------\t----------\t----------------\t------------\n";

    for(auto item : ans){
        cout<<item.process_id<<"\t\t"<<item.bt<<"\t\t"<<item.tat<<"\t\t\t"<<item.wt<<endl;
    }
    cout<<"Average tat:"<<sum_tat/n<<endl;
    cout<<"Average wt:"<<sum_wt/n<<endl;
}