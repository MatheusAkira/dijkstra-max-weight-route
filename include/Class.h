#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <list>
#include <queue>
#include <bits/stdc++.h>

typedef struct rodovia
{
    int u = 0;
    int v = 0;
    int w = 0;
} r;

typedef struct consultas
{
    int u = 0;
    int v = 0;
} c;

class Graph
{

public:
    void printpath(std::vector<int> &parent, int vertex, int target);
    int widest_path_problem(std::vector<std::vector<std::pair<int, int>>> &Graph,
                            int src, int target);
};

#endif