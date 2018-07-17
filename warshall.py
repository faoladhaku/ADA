import numpy as np
from numpy import inf
#graph = np.array([[0,2,100,3,100,100,100],[100,0,7,100,1,100,100],[100,100,0,100,100,2,100],[100,1,100,0,100,100,100],[100,100,7,100,0,100,4],[100,100,100,100,4,0,2],[1,100,100,1,100,100,0]])
#graph = np.array([[inf,1,1,inf],[1,inf,inf,1],[1,inf,inf,1],[inf,1,1,inf]])
prueba= np.zeros((3,2))

veces= int(input())
while(veces!=0):
    numero_celdas = int(input())
    graph = np.zeros((numero_celdas,numero_celdas))
    for i in range(numero_celdas):
        for j in range(numero_celdas):
            graph[i][j] = inf
    celda_ganadora = input()
    timer = input()
    num_conexiones = int(input())
    while(num_conexiones!=0):
        rawi =  input()
        conexion = rawi.split(" ")
        for i in range(len(conexion)):
            conexion[i] = int(conexion[i])
        graph[conexion[0]-1][conexion[1]-1] = conexion[2]
        print(graph) 
        num_conexiones = num_conexiones-1
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
                    if(i == celda_ganadora):
                        ejercicio = ejercicio+1
                    print (">",p[i,k],'+',p[k,j],'=',p[i,j],"change")
                else:
                    
                    print (i+1,"-",j+1,":",p[i,j],"noli")
                    print ("<=",p[i,k],'+',p[k,j],'=',p[i,j],"sheki")
    veces = veces-1
print (p,ejercicio)

