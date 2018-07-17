import numpy as np
from numpy import inf
def llenarmatrizf():
    a = 0

#graph = np.array([[0,2,100,3,100,100,100],[100,0,7,100,1,100,100],[100,100,0,100,100,2,100],[100,1,100,0,100,100,100],[100,100,7,100,0,100,4],[100,100,100,100,4,0,2],[1,100,100,1,100,100,0]])
graph = np.array([[inf,1,1,inf],[1,inf,inf,1],[1,inf,inf,1],[inf,1,1,inf]])
prueba= np.zeros((3,2))
print ("Adjacency matrix")
print (graph)
v = len(graph)
ejercicio =0
p = np.zeros(graph.shape)
for i in range(0,v):
    for j in range(0,v):
        p[i,j] = graph[i,j]
        
       
for k in range(0,v):
    print ('D',k+1,"--------------------")
    for i in range(0,v):
        for j in range(0,v):
            if p[i,j] > p[i,k] + p[k,j]:
                print (i+1,"-",j+1,":",p[i,j],"holi")
                p[i,j] = p[i,k] + p[k,j]
                ejercicio = ejercicio+1
                print (">",p[i,k],'+',p[k,j],'=',p[i,j],"change")
            else:
                print (i+1,"-",j+1,":",p[i,j],"noli")
                print ("<=",p[i,k],'+',p[k,j],'=',p[i,j],"sheki")
print (p,ejercicio)

