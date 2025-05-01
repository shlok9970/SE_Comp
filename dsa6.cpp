#include<iostream>
using namespace std;

class bfs {
public:
    int a[100][100], visited[100], visited1[100], visit[100], visit1[100];
    int n, m, front, rear, top, v, k, que[100], stk[100];
    
    bfs() {
        for (int i = 0; i < 100; i++) {
            visited[i] = 0;
            visited1[i] = 0;
            visit[i] = 0;
            visit1[i] = 0;
        }
        
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                a[i][j] = 0;
            }
        }
        top = 0;
        front = 0;
        rear = 0;
    }
    
    void adj_matrix() {
        cout << "Enter no. of vertices: ";
        cin >> n;
        cout << "Enter no. of edges: ";
        cin >> m;
        cout << "Enter the edges (vertex pairs):\n";
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
    }
    
    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void display_bfs(){
    	cout<<"Enter the initial vertex for BFS : ";
    	cin>>v;
    	cout<<"The BFS of the graph is: " << v<<" ";
    	
    	visited[v]=1;
    	k=1;
    	while(k<n){
    		for(int j=0;j<n;j++){
    			if(a[v][j] != 0 && visited[j] != 1 && visit[j] != 1){
    					
    				visit[j]=1;
    				que[rear]=j;
    				rear++;
    			}
    		}
    		v=que[front++];
    		cout<<v<<" ";
    		k++;
    	}
    }
  
    void display_dfs() {
    cout<<endl;
    cout << "Enter the initial vertex for DFS: ";
    cin >> v;
    cout << "The DFS of the graph is: ";

    visited1[v] = 1; 
    stk[top] = v; 
    top++;  

    while (top > 0) { 
         v = stk[--top]; 
         cout << v << " ";  
        
        for (int j = n - 1; j >= 0; j--) {
            if (a[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1) {
                visit1[j] = 1;
                stk[top] = j; 
                top++;  
            }
        }
       
    }
    cout << endl;
}

};

int main() {
    bfs o;
    o.adj_matrix();
    o.display();  
    o.display_bfs(); 
    o.display_dfs();   
    return 0;
}

