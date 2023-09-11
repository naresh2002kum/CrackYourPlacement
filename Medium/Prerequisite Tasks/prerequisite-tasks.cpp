//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	   // cout<<"size : "<<endl;
	    unordered_map<int,list<int>>adjlist;
	    for(int i=0;i<P;i++){
	    
	       int u = prerequisites[i].first;
          int v = prerequisites[i].second;

	        adjlist[u].push_back(v);
	    }
	    /*
	    
	    vector<vector<int>>adjlist(N);
	    for(int i=0;i<P;i++){
	    
	       int u = prerequisites[i].first;
          int v = prerequisites[i].second;

	        adjlist[u].push_back(v);
	    }
	    
	     for(int i=0;i<P;i++){
	        for(int j=0;j<adjlist[i].size();j++){
	            cout<<adjlist[i][j]<<" ";
	        }
	        cout<<endl;
	     }
	    
	    */
// 	   vector<int> adjlist[N];
// 		for (auto it : adjlist) {
// 			for(int i=0;i<(it.second).size();i++) cout<<adjlist[it.second][i]<<" ";
// 			cout<<endl;
// 		}
	    
	    vector<int>indegree(N,0);
	  
		for (int i = 0; i < N; i++) {
			for (auto it : adjlist[i]) {
				indegree[it]++;
			}
		}
		
		queue<int>q;
		for(int i=0;i<N;i++){
		    if(indegree[i]==0){
		        q.push(i);
		        
		    }
		    
		}
// 		if(q.size()==0) return false;
		
		vector<int>topo;
		
		while(!q.empty()){
		    int node=q.front();
		    q.pop();
		    topo.push_back(node);
		   
		    
		    for(auto it:adjlist[node]){
		      indegree[it]--;
		        if(indegree[it]==0){
		            q.push(it);
		        }
		    }
		}
// 		cout<<"size : "<<topo.size()<<endl;
		if(topo.size()==N) return true;
		else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends