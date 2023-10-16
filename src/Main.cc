#include "Class.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ifstream file;
    std::string lineFile;
    std::string::iterator it;
    int n = 0;
    int m = 0;
    int q = 0;
    int idxLine = 0;
    int pos = 0;
    int tamanho = 0;
    int idxRodovia = 0;
    int idxConsulta = 0;
    int cidadeInicial = 0;
    int cidadeFinal = 0;
    r rodovia[100000];
    c consulta[1000];
    std::vector<std::vector<std::pair<int, int>>> graph;

    file.open(argv[1]);
    if (file.is_open())
    {
        while (getline(file, lineFile))
        {
            // std::cout<< lineFile <<std::endl; //test
            if (idxLine == 0)
            {
                pos = lineFile.find(" ");
                n = std::stoi(lineFile.substr(0, pos));
                // std::cout << n << std::endl; //test

                tamanho = pos + 1;
                pos = lineFile.find(" ", pos + 1);
                m = std::stoi(lineFile.substr(tamanho, pos - tamanho));
                // std::cout<< m <<std::endl; //test

                tamanho = pos + 1;
                pos = lineFile.find(" ", pos + 1);
                q = std::stoi(lineFile.substr(tamanho, pos - tamanho));
                // std::cout<< q <<std::endl; //test

                idxLine++;
                continue;
            }

            else if (idxLine > 0 && idxLine <= m)
            {
                idxRodovia = idxLine;
                pos = lineFile.find(" ");
                rodovia[idxRodovia].u = std::stoi(lineFile.substr(0, pos));
                // std::cout<< rodovia[idxRodovia].u <<std::endl; //test

                tamanho = pos + 1;
                pos = lineFile.find(" ", pos + 1);
                rodovia[idxRodovia].v = std::stoi(lineFile.substr(tamanho, pos - tamanho));
                // std::cout<< rodovia[idxRodovia].v <<std::endl; //test

                tamanho = pos + 1;
                pos = lineFile.find(" ", pos + 1);
                rodovia[idxRodovia].w = std::stoi(lineFile.substr(tamanho, pos - tamanho));
                // std::cout<< rodovia[idxRodovia].w <<std::endl; //test*/

                idxLine++;
            }

            else
            {
                idxConsulta = idxLine - m;
                pos = lineFile.find(" ");
                consulta[idxConsulta].u = std::stoi(lineFile.substr(0, pos));
                // std::cout<< consulta[idxConsulta].u <<std::endl; //test

                tamanho = pos + 1;
                pos = lineFile.find(" ", pos + 1);
                consulta[idxConsulta].v = std::stoi(lineFile.substr(tamanho, pos - tamanho));
                // std::cout<< consulta[idxConsulta].v <<std::endl; //test
                idxLine++;
            }
        }
    }

    else
    {
        std::cout << "Unable to open file";
        return 0;
    }

    graph.assign(n + 1, std::vector<std::pair<int, int>>());
    Graph g;

    for (int i = 1; i <= m; i++)
    {
        // std::cout<<"*****"<<std::endl; //test
        // std::cout<<rodovia[i].u<<std::endl;//test
        // std::cout<<rodovia[i].v<<std::endl;//test
        // std::cout<<rodovia[i].w<<std::endl;//test
        int u = rodovia[i].u;
        int v = rodovia[i].v;
        int w = rodovia[i].w;
        // A ordem no par é (distância, vértice)//test
        graph[u].push_back(std::make_pair(w, v));
    }

    for (int i = 1; i <= q; i++)
    {
        // std::cout<<consulta[i].u<<std::endl;
        // std::cout<<consulta[i].v<<std::endl;
        cidadeInicial = consulta[i].u;
        cidadeFinal = consulta[i].v;
        int maxDistance = g.widest_path_problem(graph, cidadeInicial, cidadeFinal);
        std::cout << maxDistance << std::endl;
    }
    file.close();
}