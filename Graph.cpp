#include "Graph.h"
#include <list>
#include <fstream>
#include <algorithm>
#include <limits>


//---------------------------------------------------------------------------------------------------------------------

Node* Graph::findNode(const std::string& id)
{
    // - soll einen Node mit der gegebenen id in m_nodes suchen
    // - gibt den Pointer auf den Node zurück, wenn er gefunden wurde.
    // - gibt NULL zurück, falls kein Node mit der id gefunden wurde.
    return NULL;

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend ein paar Nodes im Graph suchen.
    // Prüfen Sie, ob der Node gefunden wurden und geben Sie die ID auf der Kommandozeile aus!
}


//---------------------------------------------------------------------------------------------------------------------

Node& Graph::addNode(Node* pNewNode)
{
    // bitte diese Zeile entfernen, wenn Sie die Funktion implementieren:
    return *new Node("");

    // Überprüfen Sie, ob schon ein Node mit der gegeben id im Graph vorhanden ist!
    // Falls ja:
    //  - Exception werfen
    // Falls nein:
    //  - den neuen Node 'pNewNode' in m_nodes einfügen
    //  - Referenz auf den neuen Node zurück geben

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes in main.cpp erstellen
    // Testen Sie mit der Funktion 'findNode', ob die hinzugefügten Nodes im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

Edge& Graph::addEdge(Edge* pNewEdge)
{
    // bitte diese Zeile entfernen, wenn Sie die Funktion implementieren:
    return *new Edge(*new Node(), *new Node());

    // - die neue Edge 'pNewEdge' in m_edges einfügen
    // - Referenz auf die neue Edge zurück geben

	// - Testen Sie ob der Source- und Destination-Node von 'pNewEdge' schon im Graph vorhanden ist.
	// -> fügen Sie diese Nodes hinzu, falls nicht (nutzen Sie dafür Graph::addNode)

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // Testen Sie mit der Funktion 'findEdges', ob die hinzugefügten Edges im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

Graph::~Graph()
{
    // - soll alle Edges im Graph löschen (delete)
    // - soll alle Nodes im Graph löschen (delete)
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Node& rNode)
{
    // - alle Edges, die mit rNode verbunden sind, müssen entfernt werden!
	// - finden sie den Pointer mit der Adresse von 'rNode' in m_nodes.
    // 		- der Pointer auf rNode soll aus m_nodes entfernt werden!
    // 		- der Pointer auf rNode muss mit 'delete' freigegeben werden!

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend einzelne Nodes wieder löschen.
    // Testen Sie mit der Funktion 'findNode', ob die gelöschten Nodes noch im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Edge& rEdge)
{
    // - der Pointer auf rEdge muss aus m_edges entfernt werden!
    // - der Pointer auf rEdge muss mit 'delete' freigegeben werden!

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend einzelne Edges wieder löschen.
    // Testen Sie mit der Funktion 'findEdges', ob die gelöschten Edges noch im Graph vorhanden sind.
}


//---------------------------------------------------------------------------------------------------------------------

std::vector<Edge*> Graph::findEdges(const Node& rSrc, const Node& rDst)
{
    std::vector<Edge*> ret;

    // - findet alle edges, mit rSrc als Source-Node und rDst als Destination-Node.
    // - füge die Zeiger der Edges in den vector 'ret' ein.

    return ret;

    // TEST:
    // Testen Sie die Funktion, indem Sie indem Sie einen Graph mit ein paar Nodes und Edges in main.cpp erstellen
    // und anschließend ein paar Edges im Graph suchen.
    // Prüfen Sie, ob Edges gefunden wurden und geben Sie die gefunden Edges auf der Kommandozeile aus!
}

//---------------------------------------------------------------------------------------------------------------------

void Graph::findShortestPathDijkstra(std::deque<Edge*>& rPath, const Node& rSrcNode, const Node& rDstNode)
{
/*
Ein häufiges Anwendungsproblem für Graphen-Anwendungen besteht darin, 
den Pfad zwischen verschiedenen Nodes zu finden, die direkt oder indirekt über Edges miteinander verbunden sind.
Um den optimalsten Pfad(den mit den geringsten Kantengewichten) zu finden, gibt es den Dijkstra-Algorithmus!
Pseudocode (Quelle: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
>>>
function Dijkstra(Graph, source):

      create vertex set Q

      for each vertex v in Graph:             // Initialization
          dist[v] ← INFINITY                  // Unknown distance from source to v
          prev[v] ← UNDEFINED                 // Previous node in optimal path from source
          add v to Q                          // All nodes initially in Q (unvisited nodes)

      dist[source] ← 0                        // Distance from source to source

      while Q is not empty:
          u ← vertex in Q with min dist[u]    // Source node will be selected first
          remove u from Q

          for each neighbor v of u:           // where v is still in Q.
              alt ← dist[u] + length(u, v)
              if alt < dist[v]:               // A shorter path to v has been found
                  dist[v] ← alt
                  prev[v] ← u

      return dist[], prev[]
<<<

Betrachten Sie den Pseudocode und setzen Sie ihn in C++ um.
Sortieren Sie am Ende das Ergebnis in die richtige Reihenfolge um 
und geben sie die kürzeste Route zwischen rSrcNode und rDstNode als Liste von Edges zurück.

TEST:
Testen Sie diese Funktion, indem Sie einen Graph in main.cpp erstellen
und sich die kürzesteste Route zwischen 2 Nodes zurückgeben lassen.
*/

}


//---------------------------------------------------------------------------------------------------------------------

