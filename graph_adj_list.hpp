#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vertex
{
public:
	string name;
	bool visited;

	vector<Vertex *> adjList;

	Vertex(string _name)
	{
		name = _name;
		visited = false;
	}
};

class Graph
{
public:
vector<Vertex*> vertices;
	Graph(vector<Vertex*>  _vertices)
	{
		vertices = _vertices;
	}

	void createEdge(Vertex *v1, Vertex *v2){
		v1->adjList.push_back(v2);
		v2->adjList.push_back(v1);
	}

	void BFS(Vertex* v){

		vector<Vertex*> queue;
		v->visited = true;
		queue.push_back(v);
		while(!queue.empty()){
			Vertex * current = queue.front();
			queue.erase(queue.begin());
			cout<< current->name <<endl;

			for(int i=0; i< current->adjList.size(); i++){
				if(!current->adjList[i]->visited){
					current->adjList[i]->visited = true;
					queue.push_back(current->adjList[i]);
				}
			}
		}
		

	}

	void DFS(Vertex *v){
		vector<Vertex*> stack;
		
	}

};