#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/* DEFINING PROBLEM STATEMENT CLEARLY :
For GPS Navigation we will have a graph, in that I will have source and its destination,and it will be directed, it will have a cost associated with it.
So, user input would be :
1) graph
2) source
3) destination

User Format for graph would be source
Source and it destination
then corresponding to destination again destinations

*/


/*
Assumptions:
1) Souce and destination should be present in graph
*/ 

struct Node{
	int data;
	vector<struct Node *> connected;
	vector<int> cost;
};

struct Graph{
	vector<Node *> startingNodes;
};

void shortestPath1(Node *n,Node *dest,int sumCost,vector<Node *> visited,int &minDist){

	if(find(visited.begin(),visited.end(),n)!=visited.end())
		return;

	if(sumCost>=minDist)
		return;
	
	if(n==dest){
		minDist = sumCost;
		return;
	}
	
	visited.push_back(n);
	
	int size=(n->connected).size();
	for(int i=0;i<size;i++){
		shortestPath1((n->connected)[i],dest,sumCost+((n->cost)[i]),visited,minDist);
	}
	
}

int shortestPath(Node *source,Node *dest){
	int minDist = INT_MAX;
	vector<Node *> visited;
	shortestPath1(source,dest,0,visited,minDist);
	return minDist;
}

Node* find(vector<Node *> &visited,int nodeData){

	for(Node* node:visited){
		if(node->data==nodeData)
			return node;
	}	
	return NULL;
}

void DFS1(Node *n,int data,Node *ans){
	if(n->data==data){
		ans = n;
		return;
	}
	
	for(Node *temp:n->connected){
		DFS1(temp,data,ans);
		if(ans!=NULL){
			break;
		}
	}	
}

Node* DFS(Graph* g,int data){
	Node *ans=NULL;
	for(Node *n:g->startingNodes){
		DFS1(n,data,ans);
		if(ans!=NULL){
			break;
		}
	}
	return ans;
}

int main(){

	int nIndegreeZero,idx,data;
	cin>>nIndegreeZero;
	vector<int> IndegreeZero;
	for(idx=0;idx<nIndegreeZero;idx++){
		cin>>data;
		IndegreeZero.push_back(data);
	}

	int noOfNodes;		
	cin>>noOfNodes;

	int i = 0 , j;
	int nodeData;
	int n_const;  // no. of connected nodes, this will also be used for no. of cost   
	int connectedData;
	int costData;
	vector<Node *> visited;
	Node *node;
	Node *conn;
	Graph *G = new Graph;
	
	while(i<noOfNodes){
	
		cin>>nodeData;
		node = find(visited,nodeData);
		
		if(node==NULL){
			node = new Node;
			node->data = nodeData;
			visited.push_back(node);
		}
					
		cin>>n_const;
		
		j = 0;
		while(j<n_const){
			cin>>connectedData;
			conn = find(visited,connectedData);						
			if(conn==NULL){
				conn = new Node;
				conn->data = connectedData;
				visited.push_back(conn);
			}
			
			(node->connected).push_back(conn);
			
			j++;
		}
		
		j = 0;
		while(j<n_const){
			cin>>costData;
			(node->cost).push_back(costData);			
			
			j++;
		}
		
		if(find(IndegreeZero.begin(),IndegreeZero.end(),nodeData)!=IndegreeZero.end()){
			(G->startingNodes).push_back(node);		
		}		
	
		i++;
	}
	
	//cout<<"Destination Found";
	
	int src,dest;
	
	//cout<<"Enter Source Node :";
	cin>>src;
	
	//cout<<"Enter Destination";
	cin>>dest;
	
	Node *source = DFS(G,src);
	Node *destination = DFS(G,dest);	
	
	cout<<shortestPath(source,destination);	

	return 0;
}





