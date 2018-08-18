//---------------------------------------------------------------------------------------//
// <File Folder='Hihocoder_WeekExercise' Name='Week23_Graph_ShortestPath1'>              //
//     <Topic>      Hihocoder_WeekExercise                                   </Topic>    //
//     <Problem>    Graph: Shortest Path                                     </Problem>  //
//     <Strategy>   Dijkstra Algorithm                                       </Strategy> //
//     <OJLink>     http://hihocoder.com/problemset/problem/1081             </OJLink>   //
//     <OJResult>   AC                                                       </OJResult> //
// </File>                                                                               //
//---------------------------------------------------------------------------------------//

// typedef char bool;
// enum { false, true };
// typedef  int              int;
typedef  unsigned int        uint;
typedef  unsigned char       uint8_t;
typedef  unsigned short      uint16_t;
typedef  unsigned int        uint32_t;
typedef  unsigned long long  uint64_t;
typedef  char                int8_t;
typedef  short               int16_t;
typedef  int                 int32_t;
typedef  long long           int64_t;
#define  uintMax  ( 0xFFFFFFFF )

#define  DivFloor(a, d)   (   (  a            ) / (d) * (d)   )
#define  DivCeil(a, d)    (   ( (a) + (d) - 1 ) / (d) * (d)   )

#include <stdio.h>
#include <string.h>
#include <math.h>


// Adjacency List: ALHE, Adjacency List Head Entry;  ALTE, Adjacency List Tail Entry

#define V_MAXSIZE  ( 1 << 10      )
#define E_MAXSIZE  ( 1 << 14 << 1 )
uint V, E;

struct ALHE_T    // Indexed from 1
{
    uint head;
} ALHE[V_MAXSIZE];
struct ALTE_T    // Indexed from 1
{
	uint dest;
    uint weight;
	uint next;
} ALTE[E_MAXSIZE];

bool C[V_MAXSIZE];
uint D[V_MAXSIZE];
// uint P[V_MAXSIZE];
uint ShortestPath_Dijkstra(uint S, uint T)
{
    uint v;
    for(v = 0; v <= V; ++ v)
    {
        C[v] = false, D[v] = uintMax;
    }

    C[S] = true, D[S] = 0;
    uint p;
    for(p = ALHE[S].head; p; p = ALTE[p].next)
    {
        if ( D[ALTE[p].dest] > ALTE[p].weight )
        {
            D[ALTE[p].dest] = ALTE[p].weight;
        }
    }

    uint i;
    for(i = 1; i <= V - 1; ++ i)  // (V-1) edges in the MST
    {
        uint a = uintMax, q;
        for(v = 1; v <= V; ++ v)
        {
            if ( !C[v] && (D[v] < a) )
                a = D[p = v];
        }
        C[p] = true;
        for(q = ALHE[p].head; q; q = ALTE[q].next)
        {
            if ( !C[ALTE[q].dest] && (D[p] + ALTE[q].weight < D[ALTE[q].dest]) )
            {
                D[ALTE[q].dest] = D[p] + ALTE[q].weight;
//              P[ALTE[j].dest] = p;
            }
        }
    }

    return D[T];
}

int main()
{
    uint S, T;
    scanf("%u %u %u %u", &V, &E, &S, &T);
    uint e = 0;
    while (e != 2 * E)
    {
        uint a, b, w;
        scanf("%u %u %u", &a, &b, &w);
        ++ e;
        ALTE[e].dest = b;
        ALTE[e].weight = w;
        ALTE[e].next = ALHE[a].head;
        ALHE[a].head = e;
        ++ e;
        ALTE[e].dest = a;
        ALTE[e].weight = w;
        ALTE[e].next = ALHE[b].head;
        ALHE[b].head = e;
    }
    uint ans = ShortestPath_Dijkstra(S, T);
    printf("%u\n", ans);
    return 0;
}