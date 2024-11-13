import sys

def floyd_warshall(graph):
    V = len(graph)
    dist = [[sys.maxsize] * V for _ in range(V)]
    next_vertex = [[-1] * V for _ in range(V)]

    # Initialize the distance and next_vertex matrices
    for i in range(V):
        for j in range(V):
            if graph[i][j] != 0:
                dist[i][j] = graph[i][j]
                next_vertex[i][j] = j
            if i == j:
                dist[i][j] = 0

    # Floyd-Warshall algorithm
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != sys.maxsize and dist[k][j] != sys.maxsize and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next_vertex[i][j] = next_vertex[i][k]

    return dist, next_vertex

def construct_path(next_vertex, u, v):
    if next_vertex[u][v] == -1:
        return []
    path = [u]
    while u != v:
        u = next_vertex[u][v]
        path.append(u)
    return path

def print_solution(dist, next_vertex):
    V = len(dist)
    print("Shortest path distance matrix:")
    for i in range(V):
        for j in range(V):
            if dist[i][j] == sys.maxsize:
                print("INF", end=" ")
            else:
                print(dist[i][j], end=" ")
        print()

    print("\nNext vertex matrix:")
    for i in range(V):
        for j in range(V):
            print(next_vertex[i][j], end=" ")
        print()

def main():
    # Example input
    graph = [
        [0, 3, 8, 0, -4],
        [0, 0, 0, 1, 7],
        [4, 0, 0, 0, 0],
        [0, 2, -5, 0, 0],
        [0, 0, 0, 6, 0]
    ]

    num_vertices = 5
    source_vertex = 2
    destination_vertex = 5

    # Adjusting for 0-based indexing
    source_vertex -= 1
    destination_vertex -= 1

    dist, next_vertex = floyd_warshall(graph)
    print_solution(dist, next_vertex)

    path = construct_path(next_vertex, source_vertex, destination_vertex)
    if path:
        print(f"\nShortest Path from vertex {source_vertex + 1} to vertex {destination_vertex + 1}: {'-->'.join(map(lambda x: str(x + 1), path))}")
        print(f"Path weight: {dist[source_vertex][destination_vertex]}")
    else:
        print(f"\nNo path from vertex {source_vertex + 1} to vertex {destination_vertex + 1}")

if __name__ == "__main__":
    main()
