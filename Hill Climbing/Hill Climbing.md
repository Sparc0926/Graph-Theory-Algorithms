# Hill Climbing

Hill climbing is a sort of **integer programming** which **optimize** $z$ value subject to $z=f(x,y)$ on a discrete 3D space.

## k Queens

This is a typical problem applying this trick together with heuristic search. It requires placing $k$ queens on an $n\times n$ chess board with constraint that one can't attack any others.

Since one column can hold only one queen, we greedily put queens at different colums then move one of them along her column at a time. We also introduce the **heuristic** function $heu[x][y]$ to be the number of conflicts if the queen at colums $y$ is at $map[x][y]$.

In this problem, we have to optimize $heu[x][y]$.