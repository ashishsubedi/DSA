class Graph:
    def __init__(self):
        self.vertices = {}
        self.routingTable = {}
        self.MST = None

    def addVertices(self, vertices, e=[]):
        '''
        Add array of vertices. If e is given, all vertices will be initialzed with e
        @param vertices: List of all vertices
        @param e: [Optional]List of vertices
        '''
        for v in vertices:
            if v not in self.vertices:
                self.vertices[v] = set(e)

    def addEdges(self, v, e):

        if v in self.vertices:
            for edge in e:
                self.vertices[v].add(edge)
        else:
            self.vertices[v] = set(e)

    def removeVertices(self, vertices):
        for v in vertices:
            if v in self.vertices:
                del self.vertices[v]

    def removeEdges(self, v, e):
        if v in self.vertices:
            for edge in e:
                if(edge in self.vertices[v]):
                    self.vertices[v].remove(edge)

    def neighbours(self, v):
        if v in self.vertices:
            return list(self.vertices[v])

    def BFS(self, startVertex, parent=None):
        visited = set()
        q = [(startVertex, parent)]
        spanningTree = Graph()
        routingTable = {}

        while len(q) > 0:
            v = q[0][0]
            p = q[0][1]
            q.remove(q[0])
            if(v not in visited):
                routingTable[v] = p
                visited.add(v)
                if p is not None:
                    if(v not in spanningTree.vertices):
                        spanningTree.addVertices([v], [p])
                    else:
                        spanningTree.addEdges(v, [p])
                    if(p not in spanningTree.vertices):
                        spanningTree.addVertices([p], [v])
                    else:
                        spanningTree.addEdges(p, [v])
                for n in self.neighbours(v):
                    if(n not in visited):
                        q.append((n, v))

        self.routingTable = routingTable
        if self.MST is None:
            self.MST = spanningTree
        return spanningTree

    def DFS(self, startVertex, parent=None):
        visited = set()
        q = [(startVertex, parent)]
        spanningTree = Graph()
        routingTable = {}

        while len(q) > 0:
            pair = q.pop()
            v = pair[0]
            p = pair[1]

            if(v not in visited):
                routingTable[v] = p
                visited.add(v)
                if p is not None:
                    if(v not in spanningTree.vertices):
                        spanningTree.addVertices([v], [p])
                    else:
                        spanningTree.addEdges(v, [p])
                    if(p not in spanningTree.vertices):
                        spanningTree.addVertices([p], [v])
                    else:
                        spanningTree.addEdges(p, [v])
                for n in self.neighbours(v):
                    if(n not in visited):
                        q.append((n, v))

        self.routingTable = routingTable

        return spanningTree


g = Graph()
g.addVertices([1, 2, 3, 4, 5, 6, 7])
g.addEdges(1, [2, 3])
g.addEdges(2, [1, 4, 5])
g.addEdges(3, [1, 4, 6])
g.addEdges(4, [2, 3, 5, 6])
g.addEdges(5, [2, 4])
g.addEdges(6, [3, 4])

mst = g.BFS(4)
st = g.DFS(4)
print(g.routingTable)
print(mst.vertices)
print(st.vertices)
