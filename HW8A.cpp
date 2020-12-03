#include <iostream>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c){
        for(int i=0; i<c; i++)
                if(q[i]==q[c] || ((c-i)==abs(q[c]-q[i])))
                        return false;
        return true;
}

void print(int q[]){
        static int solution=0;
        int i, j, k, l;
        typedef char box[5][7];
        box bb, bq, wb, wq, *board[8][8];

        for(int i=0; i<5; i++){
                for(int j=0; j<7; j++){
                        wb[i][j]=' ';
                        bb[i][j]=char(219);
                }
        }


        for(i = 0; i < 5; i++){
                for(j = 0; j < 7; j++){
                        wq[i][j] = ' ';
                        wq[1][1] = char(219);
                        wq[2][1] = char(219);
                        wq[3][1] = char(219);
                        wq[3][2] = char(219);
                        wq[3][3] = char(219);
                        wq[3][4] = char(219);
                        wq[3][5] = char(219);
                        wq[2][3] = char(219);
                        wq[1][3] = char(219);
                        wq[1][5] = char(219);
                        wq[2][5] = char(219);

                        bq[i][j] = char(219);
                        bq[1][1] = ' ';
                        bq[2][1] = ' ';
                        bq[3][1] = ' ';
                        bq[3][2] = ' ';
                        bq[3][3] = ' ';
                        bq[3][4] = ' ';
                        bq[3][5] = ' ';
                        bq[2][3] = ' ';
                        bq[1][3] = ' ';
                        bq[1][5] = ' ';
                        bq[2][5] = ' ';
                }
        }

        for(int i=0; i<8; i++)
                for(int j=0; j<8; j++)
                        if((i+j)%2==0)
                                board[i][j]= &wb;
                        else
                                board[i][j]= &bb;

        for(i = 0; i < 8; i++)
        {
                if((q[i] + i) % 2 == 0)
                        board[q[i]][i] = &wq;
                else
                        board[q[i]][i] = &bq;
        }

        cout<<"Solution # "<< ++solution << ":"<<endl;

        cout<<"  ";
        for(int i=0; i<7*8; i++){
                cout<<"_";
        }
        cout<<endl;

        for(int i=0; i<8; i++){
                for(int k=0; k<5; k++){
                        cout<<" "<<char(179);
                        for(int j=0; j<8; j++){
                                for(int l=0; l<7; l++){
                                        cout<<(*board[i][j])[k][l];
                                }
                        }
                        cout<<char(179)<<endl;
                }
        }

        cout<<"  ";
        for(int i=0; i<7*8; i++)
                cout<<char(196);
        cout<<endl;
}

int main(){
        int q[8];
        int c=0;
        q[c]=0;
        while(c>=0){
                c++;
                if(c>7){
                        print(q);
                        c--;
                }
                else
                        q[c]=-1;
                while(c>=0&&c<8){
                        q[c]++;
                        if(q[c]==8)
                                c--;
                        else
                                if(ok(q,c)==true){
                                        break;
                                }}}
        return 0;
}
