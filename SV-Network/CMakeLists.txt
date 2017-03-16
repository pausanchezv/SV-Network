cmake_minimum_required(VERSION 3.5)
project(SV_Network)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES main.cpp class/Graph.h class/Node.h class/Edge.h class/Data.h class/DiGraph.h)
set(EXCS_FILES exceptions/Exceptions.h util/Functions.h algorithms/Paths.h algorithms/Traversal.h util/Stack.h util/Queue.h SV-Network.h util/Frontier.h util/Heap.h util/PriorityQueue.h arrays/ObjArray.h arrays/NodeArray.h algorithms/Dijkstra.h algorithms/Properties.h arrays/EdgeArray.h algorithms/Kruskal.h arrays/AdjMatrix.h algorithms/BreadthFirstSearch.h algorithms/DepthFirstSearch.h algorithms/UniformCostSearch.h IO/ReadGraphFromFile.h algorithms/AstarSearch.h arrays/MapArray.h algorithms/Heuristic.h algorithms/BacktrackingMST.h)
add_executable(SV_Network ${EXCS_FILES} ${SOURCE_FILES})