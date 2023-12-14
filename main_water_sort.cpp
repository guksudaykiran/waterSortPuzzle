#include <bits/stdc++.h>
using namespace std;


#include <unistd.h>

int n;
vector<stack<char>> arr;
set<vector<stack<char>>> mp;
vector<pair<int,int>> ans;

bool isSolved(stack<char> st){
    if(st.empty()) return 1;

    if(st.size()!=4) return 0;

    char ch=st.top();

    while(!st.empty()){
        if(ch!=st.top()){
            return 0;
        }
        st.pop();
    }

    return 1;
}

bool solve(){

    if(mp.find(arr)!=mp.end()){
        return 0;
    }

    mp.insert(arr);

    int c=0;

    for(int i=0;i<n;i++){
        if(!isSolved(arr[i])){
            for(int j=0;j<n;j++){
                if(i==j || arr[j].size()>=4){
                    continue;
                }

                if(!arr[j].empty() && arr[j].top()!=arr[i].top()){
                    continue;
                }

                char ch=arr[i].top();
                int t=0;

                while(!arr[i].empty() && arr[i].top()==ch){
                    arr[i].pop();
                    t++;
                }

                if(t+arr[j].size()>4 || (arr[j].empty() && arr[i].empty())){
                    while(t--){
                        arr[i].push(ch);
                    }
                    continue;
                }
                
                for(int k=0;k<t;k++){
                    arr[j].push(ch);
                }
                ans.push_back({i,j});
                // cout<<"a->"<<i<<"-"<<j<<endl;
                if(solve()){
                    return 1;
                }
                // cout<<"r->"<<j<<"-"<<i<<endl;
                ans.pop_back();
                for(int k=0;k<t;k++){
                    arr[j].pop();
                    arr[i].push(ch);
                }
            }
        }else{
            c++;
        }
    }

    return c==n;
}

int main(){

    arr.clear();
    mp.clear();
    ans.clear();

    cout<<"Enter total no of tubes: ";
    cin>>n;

    cout<<"\n\nplease give "<<n-2<<"water levels from bottom to top character wise:\n\n\n";

    arr=vector<stack<char>> (n);

    for(int i=0;i<n-2;i++){
        string s;
        cin>>s;
        for(auto it : s){
            arr[i].push(it);
        }
    }

    if(!solve()){
        cout<<"\n\nsorry"<<endl<<endl;
        sleep(5);
        return 0;
    }

    cout<<"\n\n\nfollow this steps:\n\n\n";

    for(auto it : ans){
        cout<<it.first+1<<"-"<<it.second+1<<endl;
    }

    cout<<"\n\nHope Now its easy for you!\n";


    cout<<"\n\n\nif solved type 1,  else 0:\n\n";
    int k;
    cout<<"type: ";
    cin>>k;

    if(k!=1){
        cout<<"\n\nplease give correct input!!!\n\n";
        sleep(5);
    }else{
        cout<<"\n\nBye Darling!!!\n\n";
        sleep(5);
    }

    return 0;
}
