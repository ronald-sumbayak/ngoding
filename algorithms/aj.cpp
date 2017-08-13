#include <bits/stdc++.h>

using namespace std;
struct state{
    string data;
    struct state *prev,*left,*right,*up,*bottom;
    int step;
};
state *top=new state;

set<string>visited;

string solution="123456780";
int cnt=0;
void trace(state* now)
{
    if(now->prev!=NULL)
    {
        trace(now->prev);
    }
    else if (now->step == 0) {
        top->data=now->data;
        top->prev=now->prev;
        top->left=now->left;
        top->right=now->right;
        top->up=now->up;
        top->bottom=now->bottom;
        top->step=now->step;
        printf ("\nstep: %d\n", top->step);
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(now->data[3*i+j]=='0')
                printf("  ");
            else
                printf("%c ",now->data[3*i+j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void print(state* now)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%c ",now->data[3*i+j]);
        }
        printf("\n");
    }
    printf("Step: %d\n",now->step);
    system("cls");
    return;
}

bool completed(state *now)
{
    for(int i=0;i<now->data.length();i++)
    {
        if(now->data[i]!=solution[i])return false;
    }
    return true;
}
bool cantbeSolved(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j =i+1; j <9; j++)
            if (arr[j] && arr[i] &&  arr[i] > arr[j])
                inv_count++;
    return inv_count%2;
}

state* up(state* prev)
{
    state* now=new state;
    now->data=prev->data;
    for(int i=0;i<now->data.length();i++)
    {
        if(now->data[i]=='0')
        {
            swap(now->data[i],now->data[i+3]);
            break;
        }
    }
    now->prev=prev;
    now->prev->up=now;
    now->step=1+prev->step;
    
    now->up=NULL;
    now->left=NULL;
    now->right=NULL;
    now->bottom=NULL;
    return now;
}

state* down(state *prev)
{
    state *now=new state;
    now->data=prev->data;
    for(int i=0;i<now->data.length();i++)
    {
        if(now->data[i]=='0')
        {
            swap(now->data[i],now->data[i-3]);
            break;
        }
    }
    now->prev=prev;
    now->prev->bottom=now;
    now->step=1+prev->step;
    
    now->up=NULL;
    now->left=NULL;
    now->right=NULL;
    now->bottom=NULL;
    return now;
}

state* left(state* prev)
{
    state* now=new state;
    now->data=prev->data;
    for(int i=0;i<now->data.length();i++)
    {
        if(now->data[i]=='0')
        {
            swap(now->data[i],now->data[i+1]);
            break;
        }
    }
    now->prev=prev;
    now->prev->left=now;
    now->step=1+prev->step;
    
    now->up=NULL;
    now->left=NULL;
    now->right=NULL;
    now->bottom=NULL;
    return now;
}

state* right(state* prev)
{
    state *now=new state;
    now->data=prev->data;
    for(int i=0;i<now->data.length();i++)
    {
        if(now->data[i]=='0')
        {
            swap(now->data[i],now->data[i-1]);
            break;
        }
    }
    now->prev=prev;
    now->prev->right=now;
    now->step=1+prev->step;
    now->up=NULL;
    now->left=NULL;
    now->right=NULL;
    now->bottom=NULL;
    return now;
}

void printPreorder(struct state* node)
{
    if (node == NULL)
        return;
    
    /* first print data of node */
    printf("%c \n", node->left->data[5]);
    
    /* then recur on left sutree */
    //printPreorder(node->left);  
    
    /* now recur on right subtree */
    // printPreorder(node->right);
}

int main()
{
    queue<state*> qu;
    state *initial = new state;
    initial->data="";
    initial->step=0;
    initial->prev=NULL;
    initial->left=NULL;
    initial->right=NULL;
    initial->bottom=NULL;
    initial->up=NULL;
    int arrayfirst[10],angkake=0,inp,maxtep,flag=1;
    for(int i=0;i<9;i++)
    {
        cin>>inp;
        initial->data+=inp+'0';
        arrayfirst[angkake++]=inp;
    }
    scanf("%d",&maxtep);
    
    if(cantbeSolved(arrayfirst))
    {
        printf("Puzzle cant be solved\n");
        return 0;
    }
    qu.push(initial);
    state* now;
    while(!qu.empty())
    {
        cnt++;
        now=qu.front();
        
        if(now->step>maxtep)
        {
            flag=0;
            break;
        }
        qu.pop();
        //print(now);
        int save;
        for(int i=0;i<now->data.length();i++)
        {
            if(now->data[i]=='0')
            {
                save=i;
            }
        }
        
        if(completed(now))
        {
            printf("Solution found with %d step\n",now->step);
            trace(now);
            //printf("%c\n",now->prev->prev->prev->bottom->data[5]);
            while(!qu.empty())qu.pop();
            break;
        }
        if(visited.find(now->data)!=visited.end())
        {
            
            //printf("kedalaman %d berhenti dengan:\n",now->step);
            //trace(now);
            continue;
        }
        visited.insert(now->data);
        if(save>2)
        {
            qu.push(down(now));
        }
        
        if(save%3>0)
        {
            qu.push(right(now));
        }
        if(save<6)
        {
            qu.push(up(now));
        }
        if(save%3<2)
        {
            qu.push(left(now));
        }
        
    }
    if(!flag){
        printf("Tidak ada solusi dengan kedalaman: %d\n",maxtep);
    }
    //printPreorder(top);
    return 0;
}