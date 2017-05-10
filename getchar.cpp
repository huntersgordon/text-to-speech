#include <iostream>
#include <string>

using namespace std;

int main(){

char ans;

for(;;){

     for(;;){

ans = getchar();

if(ans == ' '){

break;

}
else{

cout<<ans;
}


}


     }

/*

char ans = 'n';

string cumulative;

a:

cumulative = "say ";


while(ans != ' '){
ans = getchar();

if (ans == (unsigned char)' ') break;

cumulative += ans;


}

if (ans == 'q') exit(EXIT_SUCCESS);


system(cumulative.c_str());

goto a;
*/


return 0;


}
