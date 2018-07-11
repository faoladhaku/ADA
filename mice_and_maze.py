import collections
class Graph:
  def __init__(self):
    self.nodes = set()
    self.edges = collections.defaultdict(list)
    self.distances = {}
    self.first = 0
  def add_node(self, value):
        if len(self.nodes) == 0:
          self.first = value
          self.nodes.add(value)
        self.nodes.add(value)
  def add_edge(self, from_node, to_node, distance):
    self.edges[from_node].append(to_node)
    self.edges[to_node].append(from_node)
    self.distances[(from_node, to_node)] = distance
    self.distances[(to_node, from_node)] = distance
def dijsktra(graph, initial):
  visited = {initial: 0}
  path = {}
  ejercicio=0
  nodes = set(graph.nodes)
  while nodes: 
    min_node = None
    for node in nodes:
      if node in visited:
        if min_node is None:
          min_node = node
        elif visited[node] < visited[min_node]:
          min_node = node
    if min_node is None:
      break
    nodes.remove(min_node)
    current_weight = visited[min_node]
    for edge in graph.edges[min_node]:
      weight = current_weight + graph.distances[(min_node, edge)]
      if edge not in visited or weight < visited[edge]:
        ejercicio +=1
        visited[edge] = weight
        path[edge] = min_node
  return visited, path, ejercicio
g = Graph()
veces = input()

while(veces!=0):
    
    print("")
    numero_celdas = input()
    celda_ganadora = input()
    timer = input()
    conexiones = input()
    while(conexiones!=0):
        raw = raw_input()
        raw = raw.split(" ")
        for i in range(len(raw)):
            raw[i] = int(raw[i])
        print(raw)
        nodo1 = raw[0]
        nodo2 = raw[1]
        peso = raw[2]
        g.add_node(nodo1)
        g.add_node(nodo2)
        g.add_edge(nodo1,nodo2,peso)
        conexiones = conexiones -1;
    print dijsktra(g,g.first)
    veces = veces-1;