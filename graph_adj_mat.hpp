#include "stack.hpp"

using namespace std;
///
//
//This is TOO BROKEN TO DO ANYTHING??
//
//

class Vertex
{
  public:
	string name;
	bool visited;
	int id;

	Vertex(string _name)
	{
		name = _name;
		visited = false;
	}
};

class Graph
{
	vector<Vertex> vertices;
	vector<vector<int>> adjMat;

  public:
	Graph(vector<Vertex> *_vertices)
	{
		for (int i = 0; i < (*_vertices).size(); i++)
		{

			vertices.push_back(_vertices->at(i));
			vertices[i].id = i;
		

			_vertices->at(i).id = i;
		}
		adjMat.resize(vertices.size());
		for (int i = 0; i < vertices.size(); i++)
		{
			
			adjMat[i].resize(vertices.size());
		}
	}

	void createEdge(Vertex v1, Vertex v2)
	{
		cout<<v1.id<<v2.id<<endl;
		adjMat[v1.id][v2.id] = 1;
		adjMat[v2.id][v1.id] = 1;
	}
	void printMatrix()
	{
		
		for (int i = 0; i < vertices.size(); i++)
		{
			for (int j = 0; j < vertices.size(); j++)
			{
				cout << adjMat[i][j] << " ";
			}
			cout << endl;
		}
	}
	void BFS(){

	}
	void DFS(){
		Stack<Vertex> stack;
		Vertex start = vertices[0];
		for(int i=0; i< vertices.size(); i++){
			for(int j = 0; j <= vertices.size()/2; j++)
			{
				//IDK WHAT I AM DOING LOL. Please use Adjacancy list
			}
		}
		
	}
};
