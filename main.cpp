#include "graph.h"
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	char input[150];
	char label_one[50];
	char label_two[50];
	graph * main_graph = new graph();
	while(true){
		cout << "ADD EDGE, DELETE EDGE, ADD VERTEX, DELETE VERTEX, PATH, QUIT"<<endl;
		cin.getline(input,150);
		if(!strcmp("ADD EDGE",input)){
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			cout << label_one;
			strcpy(label_two,strtok(NULL,","));
			cout << label_one;
			main_graph->add_edge(label_one,label_two);
		}
		else if(!strcmp("DELETE EDGE",input)){
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			strcpy(label_two,strtok(NULL,","));
			main_graph->remove_edge(strtok(input,","),strtok(NULL,","));	
		}
		else if(!strcmp("ADD VERTEX",input)){
			cout << "Vertex label?"<<endl;
			cin.getline(input,150);
			main_graph->add_vertex(input);
		}
		else if(!strcmp("DELETE VERTEX",input)){
			cout << "Vertex label?"<<endl;
			cin.getline(input,150);
			main_graph->remove_vertex(input);
		}
		else if(!strcmp("PATH", input)){
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			strcpy(label_two,strtok(NULL,","));
			cout << label_one;
			cout << label_two;
			main_graph->dijkstra(label_one,label_two);
		}
		else if(!strcmp("PRINT",input)){
			main_graph->print();
		}
		else if(!strcmp("QUIT",input)){
			return 0;
		}
		else{
			cout << "Invalid"<<endl;
		}
	}
}
