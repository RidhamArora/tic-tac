#include<bits/stdc++.h>
using namespace std;
char arr[3][3];
void Init()
{
    char k='1';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=k;
            k+=1;
        }
    }
}
int Design(int i)
{
    int x;
    cout<<"          Player 1(x)     Player 2(O)               "<<endl;
    cout<<"          ___________________________               "<<endl;
    cout<<"          ---------------------------               "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"  "<<arr[i][j]<<"  |";
        }
        cout<<endl;
        cout<<"-----|"<<"-----|"<<"-----|"<<endl;
    }
    cout<<endl;
    cout<<endl;
    if(i!=20)
    {
    if(i%2!=0)
        cout<<"Payer 1(x) please choose your position  :  ";
    else
        cout<<"Payer 2(o) please choose your position  :  ";
    cin>>x;
    while(x<1&&x>9)
    {
        cin>>x;
    }
    }
    return x;
}
int check(int k)
{
    ///Horizontal check
    for(int i=0;i<3;i++)
    {
        if(arr[i][0]==arr[i][1]&&arr[i][0]==arr[i][2])
            return k%2;
    }
    ///Vertical Check
    for(int j=0;j<3;j++)
    {
        if(arr[0][j]==arr[1][j]&&arr[0][j]==arr[2][j])
            return k%2;
    }
    ///Diagonal check;
    if((arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[2][0]==arr[1][1]))
        return k%2;
    ///NO WIN Situation
    return 3;
}
int main()
{
    int k=1;
    Init();
    int ans=3;
    while(ans==3)
    {
        int y=Design(k);
        int i=y/3;
        int j=y%3-1;
        if(k%2!=0)
            arr[i][j]='x';
        else
            arr[i][j]='o';
        ans=check(k);
        k++;
        if(ans!=3)
        {
                system("cls");
                Design(20);
                break;
        }
        if(k==10)
        {
             system("cls");
             Design(20);
             break;
        }
        system("cls");
    }
    if(ans==3)
    cout<<"Match Draws ..."<<endl;
    if(ans==1)
    cout<<"Player 1 wins ..."<<endl;
    if(ans==0)
    cout<<"Player 2 wins ..."<<endl;
}
