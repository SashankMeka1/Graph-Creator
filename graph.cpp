#include "graph.h"
#include <iostream>
#include <cstring>
using namespace std;
graph::graph(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20;j++){//clear adjacency matrix
			adj_mat[j][i] =0;
		}
	}
}
void graph::add_vertex(char * label){//add vertex
	if(capacity < 20){
		strcpy(label_ls[capacity],label);
		cout << label_ls[capacity];
		capacity++;
		
	}
}
void graph::add_edge(char *label_one,char*label_two){//add edge both vertices as directed
	cout << label_one;
	cout << label_two;
	int idx_one = 21;
	int idx_two = 21;
	for(int i = 0; i<capacity;i++){
		if(!strcmp(label_ls[i],label_one)){
			idx_one = i;
		}
		else if (!strcmp(label_ls[i],label_two)){
			idx_two = i;
		}
	}
	if(idx_one==21 or idx_two==21){
		cout << "One of the vertices does not exist"<<endl;
		return;
	}
	adj_mat[idx_one][idx_two]=adj_mat[idx_two][idx_one] = 1;
}
void graph::remove_vertex(char * label){
	int idx = 21;//set all connections to 0 remove from label list
	bool found = 0;
	for(int i = 0;i < capacity;i++){
		if(!strcmp(label,label_ls[i])){
			if(!found){
				idx = i;
				found = 1;
			}
			adj_mat[idx][i]=adj_mat[i][idx]=0;
			if(i>=idx and i<capacity-1){
				strcpy(label_ls[i],label_ls[i+1]);
			}
		}
	}
	capacity--;
}
void graph::remove_edge(char *label_one,char *label_two){
	int idx_one;//set connection to 0 both ways
	int idx_two;
	for(int i =0; i < capacity; i++){
		if(!strcmp(label_ls[i],label_one)){
			idx_one = i;		
		}
		else if(!strcmp(label_ls[i],label_two)){
			idx_two = i;
		}
	}
	adj_mat[idx_one][idx_two]=adj_mat[idx_two][idx_one] = 0;
}
void graph::min_distance(int idx){//recursive for each edge check if next edge leads to modify spset
	for(int i = 0; i < 20; i++){
		if(adj_mat[idx][i] and i!=idx){
			if(sptset[i]>sptset[idx] + adj_mat[idx][i]){
				sptset[i] = sptset[idx] + adj_mat[idx][i];
				min_distance(i);
			}
		}
	}
}
void graph::print(){//print adjacency matrix(for debug)
	for(int i = 0; i < capacity;i++){
		for(int j = 0; j<capacity;j++){
			cout << adj_mat[i][j]<<" ";
		}
		cout << endl;
	}
}
void graph::dijkstra(char * label_one, char*label_two){
	int idx_one =21;
	int idx_two = 21;
	cout << label_ls[0];//dijkstra check immedaite connections from source and recursive on them and modify sptset
	cout << label_ls[1];
	cout << label_ls[2]<<endl;
	for(int i = 0;i < capacity; i++){
		if(!strcmp(label_one,label_ls[i])){
			idx_one = i;		
		}
		else if(!strcmp(label_two,label_ls[i])){
			idx_two = i;
		}
	}
	cout << idx_one;
	cout << idx_two;
	if(idx_one == 21 or idx_two == 21){
		cout << "One of the vertices does not exist"<<endl;
		return;
	}
	for(int i = 0; i < capacity; i++){
		sptset[i] = 1000;
	}
	for(int i = 0; i < 20; i++){
		if(adj_mat[i][idx_one]){
			sptset[i] = adj_mat[i][idx_one];
			min_distance(i);
		}
	}
	if(*(label_ls[idx_two])!= 1000){
		cout << "The shortest path costs "<< sptset[idx_two]<<endl;
	}
	else{
		cout << "There is no path"<<endl;
	}

}
