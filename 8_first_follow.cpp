#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

void findfirst(char, int, int);
void removeLeftrecursion();
void findFollow();
#define RULECOUNT 3
char rules[RULECOUNT][10];
int countt, n = 0, o = 0, p;
char calc_first[10][10];
char calc_follow[10][10];
int m = 0;
char nt[10];

char production[10][10];
char first[10];

void initializeRules()
{
    strcpy(rules[0], "E=E+T|T");
    strcpy(rules[1], "T=T*F|F");
    strcpy(rules[2], "F=id");
}

int main() 
{
    initializeRules();
    removeLeftrecursion();
    int printcheck, jm = 0, k, ptr = -1;
    char c;
    char done[countt];

    for (k = 0; k < countt; k++) 
    {
        printcheck = 0;
        c = production[k][0];
        int point2 = 0;
        int flag = 0;

        for (int kay = 0; kay <= ptr; kay++)
            if (c == done[kay])
                flag = 1;

        if (flag == 1)
            continue;

        findfirst(c, 0, 0);
        ptr += 1;
        done[ptr] = c;
        if (c < 'U') {
            printcheck = 1;
            nt[o] = c;
            p=0;
            cout << "First(" << c << ") = { ";
        }
        calc_first[k][point2++] = c;

        for (int i = 0 + jm; i < n; i++) {
            int l = 0, chk = 0;

            for (l = 0; l < point2; l++) 
            {
                if (first[i] == calc_first[k][l]) 
                {
                    chk = 1;
                    break;
                }
            }
            if (chk == 0) 
            {
                if (printcheck == 1)
                {    
                    cout << first[i] << " ";
                    calc_first[k][point2++] = first[i];
                    calc_follow[o][p++] = first[i];
                    // cout << calc_follow[o][p-1] << " ";
                }
            }
        }
        if (printcheck == 1)
        {
            cout << "}" << endl;
            o++;
        }
        jm = n;
    }
    findFollow();
}

void removeLeftrecursion()
{
    
    char subproduction[2][10];
    char rule[10];
    char nonterminal;
    char alpha[5];
    char beta[5];

    for (int i = 0; i < RULECOUNT; i++) 
    {
        nonterminal = rules[i][0];
        int k = 0;
        rule[0] = '\0'; 
        for (int j = 2; j < 10; j++) 
        {
            if (rules[i][j] == '\0') 
            {
                strcpy(subproduction[k], rule);
                break;
            } 
            else if (rules[i][j] == '|') 
            {
                strcpy(subproduction[k], rule);
                rule[0] = '\0'; 
                k++;
            } 
            else 
            {
                strncat(rule, &rules[i][j], 1); 
            }
        }
        for (int r = 0; r <= k; r++) 
        {
            if (subproduction[r][0] == nonterminal) 
            {
                strcpy(alpha, subproduction[r] + 1);
                strcpy(beta, subproduction[r + 1]);
                sprintf(production[countt++], "%c=%s%c", nonterminal, beta, 'U' + i);
                sprintf(production[countt++], "%c=%s%c", 'U' + r, alpha, 'U' + i);
                sprintf(production[countt++], "%c=#", 'U' + r);
                break;
            } 
            else 
            {
                strcpy(production[countt++], rules[i]);
            }
        }
    }
}

void findfirst(char c, int q1, int q2) 
{
    int j;

    if (!(isupper(c))) 
    {
        first[n++] = c;
    }
    for (j = 0; j < countt; j++) 
    {
        if (production[j][0] == c) 
        {
            if (production[j][2] == '#') 
            {
                if (production[q1][q2] == '\0')
                    first[n++] = '#';
                else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) 
                {
                    findfirst(production[q1][q2], q1, (q2 + 1));
                }
                else
                    first[n++] = '#';
            } 
            else if (!isupper(production[j][2])) 
            {
                first[n++] = production[j][2];
            } 
            else 
            {
                findfirst(production[j][2], j, 3);
            }
        }
    }
}

void removeDuplicates(vector<char>& vec)
{
    sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
}

void findFollow()
{
    
    // nt[0] = 'E';
    // nt[1] = 'T';
    // nt[2] = 'F';
    int k;
    vector<char> follow[3];
    follow[0].push_back('$');   //starting character
    for(int i=0; i<3; i++)
    {
        for (int k=0; k<RULECOUNT; k++)
        {
            for(int j=2; j<10; j++)
            {
                if(rules[k][j] == nt[i])
                {
                    if(rules[k][j+1] == '|' or rules[k][j+1] == '\0')
                    {
                        follow[i].push_back(rules[k][0]);
                    }
                    else
                    {
                        if(isupper(rules[k][j+1]))
                        {
                            //follow[i].push_back(first(rules[k][j+1]))
                            int q;
                            for(q=0; q<3; q++)
                            {
                                if(nt[q] == rules[k][j+1])
                                    break;
                            }
                            follow[i].insert(follow[i].end(), begin(calc_follow[q]), end(calc_follow[q]));
                            removeDuplicates(follow[i]);
                        }
                        else
                        {
                            follow[i].push_back(rules[k][j+1]);
                        }
                    }
                }

            }
        }
    }

    for (int i=0; i<3; i++)
    {
        removeDuplicates(follow[i]);
    }

    for(int i=0; i<3; i++)
    {
        for (char j : follow[i]) 
        {
            if(isupper(j))
            {
                follow[i].erase(remove(follow[i].begin(), follow[i].end(), j), follow[i].end());
                for(k=0; k<3; k++)
                {
                    if (nt[k] == j)
                        break;
                }
                follow[i].insert(follow[i].end(), follow[k].begin(), follow[k].end());
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        cout << "Follow(" << nt[i] << ") = { ";
        for (char j : follow[i]) {
            cout << j << " ";
        }
        cout << "}" << endl;
    }
}